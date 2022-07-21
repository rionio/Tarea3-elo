#ifndef LAMP_H
#define LAMP_H

#include <QWidget>
#include "lampview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LampWidget; }
QT_END_NAMESPACE

class LampWidget : public QWidget
{
    Q_OBJECT

public:
    LampWidget(QWidget *parent = nullptr);
    ~LampWidget();
    int channel;

public slots:
        void onSpinBoxChanged(int c);

private:
    Ui::LampWidget *ui;
    LampView *lampView1, *lampView2;

};
#endif // LAMP_H
