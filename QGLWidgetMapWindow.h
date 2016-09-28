#ifndef QWIDGETGLMAPWINDOW_H
#define QWIDGETGLMAPWINDOW_H


#include <QGLWidget>
#include <QMapboxGL>
#include <QPropertyAnimation>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class QKeyEvent;
class QMouseEvent;
class QWheelEvent;

class MapWindow : public QGLWidget
{
	Q_OBJECT

public:
	MapWindow(QMapboxGLSettings _settings, QObject *parent = nullptr);
	void setLightStyle();
	void setDarkStyle();
	void construct(QMapboxGLSettings settings);
	void addRoute();

protected slots:
	void animationValueChanged();
	void animationFinished();

private:

	// QGLWidget implementation.
	void keyPressEvent(QKeyEvent *ev) final;
	void mousePressEvent(QMouseEvent *ev) final;
	void mouseMoveEvent(QMouseEvent *ev) final;
	void wheelEvent(QWheelEvent *ev) final;

	void initializeGL() final;
	void resizeGL(int w, int h) final;
	void paintGL() final;

	QPointF m_lastPos;
	QMapboxGL m_map;

	QPropertyAnimation m_bearingAnimation;
	QPropertyAnimation m_zoomAnimation;

	unsigned m_animationTicks = 0;
	unsigned m_frameDraws = 0;

	bool m_sourceAdded = false;


};

#endif // QWIDGETGLMAPWINDOW_H
