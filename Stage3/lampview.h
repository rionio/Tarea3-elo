#ifndef LAMPVIEW_H
#define LAMPVIEW_H

#include <QGraphicsPolygonItem>
#include <QGraphicsScene>

class LampView : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit LampView(QObject *parent = nullptr);
    ~LampView();
public slots:
    void changeState();
    void changeIntensity(int i);
    int getIntensity();
    void setIntensity();
private:
    QGraphicsPolygonItem * pantalla, * base;
    bool state=false;
    int b = 255;
};

#endif // LAMPVIEW_H
