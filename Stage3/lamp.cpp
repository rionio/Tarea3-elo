#include <iostream>
#include "lamp.h"
#include "ui_lamp.h"
#include "lampview.h"
using namespace std;

void LampWidgett::fchanged(int c){
    cout << "nmero ql " << c << endl;
    channel = c;
}
LampWidgett::LampWidgett(QWidget *parent):
    QWidget(parent)
    , ui(new Ui::LampWidgett)
{
    ui->setupUi(this);
    lampView1 = new LampView(ui->LampsView);
    lampView2 = new LampView(ui->LampsView2);

    ui ->LampsView->setScene(lampView1);
    ui ->LampsView2->setScene(lampView2);

    connect(ui->bxChannel,SIGNAL(valueChanged(int)),this,SLOT(fchanged(int)));

    if(channel == 2){
         cout << "chan 1 " << this->channel << endl;
        ui->btnPower->setCheckable(true);
        ui->sldIntesity->setSliderPosition(lampView1->getIntensity());

        connect(ui->btnPower,SIGNAL(clicked()), lampView1,SLOT(changeState()));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView1,SLOT(changeIntensity(int)));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView1,SLOT(setIntensity()));
    }
    else if(channel == 3){
        cout << "chan 0 " << this->channel << endl;
        ui->btnPower->setCheckable(true);
        ui->sldIntesity->setSliderPosition(lampView1->getIntensity());

        connect(ui->btnPower,SIGNAL(clicked()), lampView1,SLOT(changeState()));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView1,SLOT(changeIntensity(int)));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView1,SLOT(setIntensity()));
    }
    else{
        cout << "chan else " << this->channel << endl;
        ui->btnPower->setCheckable(true);
        ui->sldIntesity->setSliderPosition(lampView2->getIntensity());

        connect(ui->btnPower,SIGNAL(clicked()), lampView2,SLOT(changeState()));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView2,SLOT(changeIntensity(int)));
        connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView2,SLOT(setIntensity()));

    }

}

LampWidgett::~LampWidgett()
{
    delete ui;
}

