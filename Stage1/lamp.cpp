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

    ui->btnPower->setCheckable(true);
    connect(ui->btnPower,SIGNAL(clicked()), lampView,SLOT(changeState()));
}

LampWidget::~LampWidget()
{
    delete ui;
}

