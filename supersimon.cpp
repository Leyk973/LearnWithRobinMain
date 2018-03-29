#include "supersimon.h"
#include "ui_supersimon.h"

SuperSimon::SuperSimon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuperSimon)
{
    std::cout << "Creation SuperSimon" << std::endl;
    ui->setupUi(this);
    modele=new ModSimon;
    std::cout << "Fin Creation SuperSimon" << std::endl;
}

SuperSimon::~SuperSimon()
{
    std::cout << "Destruction SuperSimon" << std::endl;
    delete ui;
}






void SuperSimon::simonClicked(int pInt)
{
    std::cout << "hallo poto t'as clik sur " << pInt << std::endl;
}

void SuperSimon::lifeClicked(int pInt)
{

}

void SuperSimon::readSequenceClicked()
{

}

void SuperSimon::editSequenceClicked()
{

}

void SuperSimon::resetScoreClicked()
{

}


