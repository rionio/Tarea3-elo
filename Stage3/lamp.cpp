#include "lamp.h"
#include <iostream>
#include "ui_lamp.h"
#include "lampview.h"

using namespace std;

LampWidget::LampWidget(QWidget *parent):
    QWidget(parent)
    , ui(new Ui::LampWidget)
{
    ui->setupUi(this);
    lampView1 = new LampView(ui->LampsView);
    lampView2 = new LampView(ui->LampsView2);

    ui ->LampsView->setScene(lampView1);
    ui ->LampsView2->setScene(lampView2);



cout << connect(ui->bxChannel,SIGNAL(valueChanged(int)),this,SLOT(onSpinBoxChanged(int)))<< endl;

    if(channel == 2){
        cout << "chan 2 " << this->channel << endl;
        ui->btnPower->setCheckable(true);
        ui->sldIntesity->setSliderPosition(lampView1->getIntensity());

        connect(ui->btnPower,SIGNAL(clicked()), lampView1,SLOT(changeState()));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView1,SLOT(changeIntensity(int)));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView1,SLOT(setIntensity()));
    }
    else{
        cout << "chan 3 " << this->channel << endl;
        ui->btnPower->setCheckable(true);
        ui->sldIntesity->setSliderPosition(lampView2->getIntensity());



        connect(ui->btnPower,SIGNAL(clicked()), lampView2,SLOT(changeState()));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView2,SLOT(changeIntensity(int)));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView2,SLOT(setIntensity()));
        if(channel == 2){
            disconnect(ui->bxChannel,SIGNAL(valueChanged(int)),this,SLOT(onSpinBoxChanged(int)));
        }
    }

}
void LampWidget::onSpinBoxChanged(int c){
    channel = c;
    emit
    cout << "nmero ql " << c << endl;
}
LampWidget::~LampWidget()
{
    delete ui;
}

