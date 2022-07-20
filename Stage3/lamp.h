#ifndef LAMP_H
#define LAMP_H

#include <QWidget>
#include "lampview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LampWidgett; }
QT_END_NAMESPACE

class LampWidgett : public QWidget
{
    Q_OBJECT

public:
    LampWidgett(QWidget *parent = nullptr);
     int channel;
    ~LampWidgett();

public slots:
     void fchanged(int c);

private:
    Ui::LampWidgett *ui;
    LampView *lampView1, *lampView2;

};
#endif // LAMP_H
