#include "supersimon.h"
#include "ui_supersimon.h"

SuperSimon::SuperSimon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuperSimon)
{
    ui->setupUi(this);
    modele=new ModSimon;
}

SuperSimon::~SuperSimon()
{
    delete ui;
}
