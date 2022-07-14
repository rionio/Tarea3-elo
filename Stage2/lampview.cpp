#include "lampview.h"
#include <QDebug>

LampView::LampView(QObject *parent) : QGraphicsScene(parent)
{
    pantalla = new QGraphicsPolygonItem();
    QRectF rectangle(0.0,20.0,40.0,-20.0);
    pantalla->setPolygon(rectangle);
    pantalla->setBrush(Qt::black);
    base = new QGraphicsPolygonItem();
    QPolygonF b;
    b.append(QPointF(18,20));
    b.append(QPointF(18,50));
    b.append(QPointF(13,50));
    b.append(QPointF(10,53));
    b.append(QPointF(10,60));
    b.append(QPointF(30,60));
    b.append(QPointF(30,53));
    b.append(QPointF(27,50));
    b.append(QPointF(22,50));
    b.append(QPointF(22,20));
    base ->setPolygon(b);
    base ->setBrush(Qt::blue);
    addItem(pantalla);
    addItem(base);
}
void LampView::changeState()
{
    state = !state;
    if (state) pantalla->setBrush(QColor(b,b,b));
    else pantalla->setBrush(Qt::black);
}
void LampView::changeIntensity(int i)
{
    b = i;
}
int LampView::getIntensity(){
    return b;
}
void LampView::setIntensity(){
    if(state) pantalla->setBrush(QColor(b,b,b));
}
LampView::~LampView(){
    delete pantalla;
    delete base;
}
