#include "pointandclick.h"
#include "ui_pointandclick.h"

PointAndClick::PointAndClick(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PointAndClick)
{
    ui->setupUi(this);
}

PointAndClick::~PointAndClick()
{
    delete ui;
}
