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
private:
    QGraphicsPolygonItem * pantalla, * base;
    bool state=false;
};

#endif // LAMPVIEW_H
