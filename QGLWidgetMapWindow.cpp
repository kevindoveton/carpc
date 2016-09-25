#include "QGLWidgetMapWindow.h"

#include <QColor>
#include <QDebug>
#include <QFile>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QString>

int kAnimationDuration = 10000;

MapWindow::MapWindow(QObject *parent)
	: m_map(parent, _settings)
	, m_bearingAnimation(&m_map, "bearing")
	, m_zoomAnimation(&m_map, "zoom")
{
	_settings.setCacheDatabasePath("mbgl-cache.db");
	_settings.setCacheDatabaseMaximumSize(20 * 1024 * 1024);
	_settings.setAccessToken(qgetenv("MAPBOX_ACCESS_TOKEN"));
	connect(&m_map, SIGNAL(needsRendering()), this, SLOT(updateGL()));

	// Set default location to 31 Anaconda Drive, North Haven.
	m_map.setCoordinateZoom(QMapbox::Coordinate(-34.7958563, 138.4881648), 10);

	QFile lightStyle(":/resources/mapbox/light.json");
	if (!lightStyle.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QByteArray style = lightStyle.readAll();
	m_map.setStyleJson(QString(style));

	connect(&m_zoomAnimation, SIGNAL(finished()), this, SLOT(animationFinished()));
	connect(&m_zoomAnimation, SIGNAL(valueChanged(const QVariant&)), this, SLOT(animationValueChanged()));




	// The data source for the route line and markers
	QVariantMap routeSource;
	routeSource["type"] = "geojson";
	routeSource["data"] = "{ {\"type\": \"Feature\", \"properties\" : { \"name\" : \"route\" }, \"geometry\": {\
						  \"coordinates\": [\
							[\
							  138.488198,\
							  -34.795344\
							],\
							[\
							  138.488716,\
							  -34.795368\
							],\
							[\
							  138.489599,\
							  -34.795347\
							],\
							[\
							  138.489746,\
							  -34.795343\
							],\
							[\
							  138.489807,\
							  -34.795316\
							],\
							[\
							  138.489904,\
							  -34.795251\
							]\
						  ],\
						  \"type\": \"LineString\"\
						}}}\"";
	m_map.addSource("routeSource", routeSource);
	// The route case, painted before the route
	QVariantMap routeCase;
	routeCase["id"] = "routeCase";
	routeCase["type"] = "line";
	routeCase["source"] = "routeSource";
	m_map.addLayer(routeCase);

	m_map.setPaintProperty("routeCase", "line-color", QColor("white"));
	m_map.setPaintProperty("routeCase", "line-width", 20.0);
	m_map.setLayoutProperty("routeCase", "line-join", "round");
	m_map.setLayoutProperty("routeCase", "line-cap", "round");

	// The route, painted on top of the route case
	QVariantMap route;
	route["id"] = "route";
	route["type"] = "line";
	route["source"] = "routeSource";
	m_map.addLayer(route);

	m_map.setPaintProperty("route", "line-color", QColor("blue"));
	m_map.setPaintProperty("route", "line-width", 8.0);
	m_map.setLayoutProperty("route", "line-join", "round");
	m_map.setLayoutProperty("route", "line-cap", "round");


}




void MapWindow::animationFinished()
{

}

void MapWindow::animationValueChanged()
{
	m_animationTicks++;
}



void MapWindow::keyPressEvent(QKeyEvent *ev)
{

}

void MapWindow::mousePressEvent(QMouseEvent *ev)
{
#if QT_VERSION < 0x050000
	m_lastPos = ev->posF();
#else
	m_lastPos = ev->localPos();
#endif

//	if (ev->type() == QEvent::MouseButtonPress) {
//		if (ev->buttons() == (Qt::LeftButton | Qt::RightButton)) {

//		}
//	}

	if (ev->type() == QEvent::MouseButtonDblClick) {
		if (ev->buttons() == Qt::LeftButton) {
			m_map.scaleBy(2.0, m_lastPos);
		} else if (ev->buttons() == Qt::RightButton) {
			m_map.scaleBy(0.5, m_lastPos);
		}
	}

	ev->accept();
}

void MapWindow::mouseMoveEvent(QMouseEvent *ev)
{
#if QT_VERSION < 0x050000
	QPointF delta = ev->posF() - m_lastPos;
#else
	QPointF delta = ev->localPos() - m_lastPos;
#endif

	if (!delta.isNull()) {
		if (ev->buttons() == Qt::LeftButton && ev->modifiers() & Qt::ShiftModifier) {
			m_map.setPitch(m_map.pitch() - delta.y());
		} else if (ev->buttons() == Qt::LeftButton) {
			m_map.moveBy(delta);
		} else if (ev->buttons() == Qt::RightButton) {
#if QT_VERSION < 0x050000
			m_map.rotateBy(m_lastPos, ev->posF());
#else
			m_map.rotateBy(m_lastPos, ev->localPos());
#endif
		}
	}

#if QT_VERSION < 0x050000
	m_lastPos = ev->posF();
#else
	m_lastPos = ev->localPos();
#endif
	ev->accept();
}

void MapWindow::wheelEvent(QWheelEvent *ev)
{
	if (ev->orientation() == Qt::Horizontal) {
		return;
	}

	float factor = ev->delta() / 1200.;
	if (ev->delta() < 0) {
		factor = factor > -1 ? factor : 1 / factor;
	}

	m_map.scaleBy(1 + factor, ev->pos());
	ev->accept();
}

void MapWindow::initializeGL()
{
	QMapbox::initializeGLExtensions();
}

void MapWindow::resizeGL(int w, int h)
{
	QSize size(w, h);
	m_map.resize(size);
}

void MapWindow::paintGL()
{
	m_frameDraws++;
	m_map.render();
}
