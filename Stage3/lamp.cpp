#include "lamp.h"
#include "ui_lamp.h"
#include "lampview.h"

LampWidget::LampWidget(QWidget *parent):
    QWidget(parent)
    , ui(new Ui::LampWidget)
{
    ui->setupUi(this);
    lampView1 = new LampView(ui->LampsView);
    lampView2 = new LampView(ui->LampsView2);

    ui ->LampsView->setScene(lampView1);
    ui ->LampsView2->setScene(lampView2);

    connect(ui->bxChannel,SIGNAL(valueChanged(int)),this,SLOT(on_spinBox_changed(int)));

    if(channel == 2){
        ui->btnPower->setCheckable(true);
        ui->sldIntesity->setSliderPosition(lampView1->getIntensity());

        connect(ui->btnPower,SIGNAL(clicked()), lampView1,SLOT(changeState()));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView1,SLOT(changeIntensity(int)));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView1,SLOT(setIntensity()));
    }
    else{
        ui->btnPower->setCheckable(true);
        ui->sldIntesity->setSliderPosition(lampView2->getIntensity());

        connect(ui->btnPower,SIGNAL(clicked()), lampView2,SLOT(changeState()));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView2,SLOT(changeIntensity(int)));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView2,SLOT(setIntensity()));

    }

}
void LampWidget::on_spinBox_changed(int c){
    channel = c;
}
LampWidget::~LampWidget()
{
    delete ui;
}

