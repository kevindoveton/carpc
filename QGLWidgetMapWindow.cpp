#include "QGLWidgetMapWindow.h"

#include <QColor>
#include <QDebug>
#include <QFile>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QString>

int kAnimationDuration = 10000;

MapWindow::MapWindow(QMapboxGLSettings settings, QObject *parent)
	: m_map(parent, settings)
	, m_bearingAnimation(&m_map, "bearing")
	, m_zoomAnimation(&m_map, "zoom")
{
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





}


void MapWindow :: addRoute()
{
	// The data source for the route line and markers
	QFile geojson(":/resources/mapbox/testRoute3.json");
	if (!geojson.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QByteArray data = geojson.readAll();
	QVariantMap routeSource;
	routeSource["type"] = "geojson";
	routeSource["data"] = QString(data);
	m_map.addSource("routeSource", routeSource);

	// The route, painted on top of the route case
	QVariantMap route;
	route["id"] = "route";
	route["type"] = "line";
	route["source"] = "routeSource";
	m_map.addLayer(route);

	m_map.setPaintProperty("route", "line-color", QColor(255,0,0));
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
