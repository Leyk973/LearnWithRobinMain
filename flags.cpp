#include "flags.h"
#include "ui_flags.h"

Flags::Flags(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Flags)
{
    ui->setupUi(this);
}

Flags::~Flags()
{
    delete ui;
}
