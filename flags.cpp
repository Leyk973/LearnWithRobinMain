#include "flags.h"
#include "ui_flags.h"

Flags::Flags(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Flags)
{
    std::cout << "Creation Flags" << std::endl;
    ui->setupUi(this);
    std::cout << "Fin Creation Flags" << std::endl;
}

Flags::~Flags()
{
    std::cout<<"Destruction Flags"<<std::endl;
    delete ui;
}
