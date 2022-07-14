#include "lamp.h"
#include "ui_lamp.h"
#include "lampview.h"

LampWidget::LampWidget(QWidget *parent):
    QWidget(parent)
    , ui(new Ui::LampWidget)
{
    ui->setupUi(this);
    lampView = new LampView(ui->LampsView);
    ui ->LampsView->setScene(lampView);

    ui->sldIntesity->setSliderPosition(lampView->getIntensity());
    connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView,SLOT(changeIntensity(int)));
    connect(ui->sldIntesity,SIGNAL(valueChanged(int)),lampView,SLOT(setIntensity()));


    ui->btnPower->setCheckable(true);
    connect(ui->btnPower,SIGNAL(clicked()), lampView,SLOT(changeState()));
}

LampWidget::~LampWidget()
{
    delete ui;
}

