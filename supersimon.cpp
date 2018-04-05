#include "supersimon.h"
#include "ui_supersimon.h"

SuperSimon::SuperSimon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuperSimon)
{
    std::cout << "Debut construction SIMON" << std::endl;
    ui->setupUi(this);
    modele=new ModSimon;

    std::cout << "Debut construction DEUX" << std::endl;
    QObject::connect(ui->butResScore, SIGNAL(clicked(bool)),this,SLOT(resetScoreClicked()));
    std::cout << "Debut construction TROIS" << std::endl;
    QObject::connect(ui->butSeqEdit, SIGNAL(clicked(bool)),this,SLOT(editSequenceClicked()));
    std::cout << "Debut construction QUATRE" << std::endl;
    QObject::connect(ui->butLireSeq, SIGNAL(clicked(bool)),this,SLOT(readSequenceClicked()));
    /*QObject::connect(ui->butAddLife, SIGNAL(clicked(bool)),this,SLOT(lifeClicked(1)));
    QObject::connect(ui->butRemLife, SIGNAL(clicked(bool)),this,SLOT(lifeClicked(-1)));
    QObject::connect(ui->butSim1, SIGNAL(clicked(bool)),this,SLOT(simonClicked(1)));
    QObject::connect(ui->butSim2, SIGNAL(clicked(bool)),this,SLOT(simonClicked(2)));
    QObject::connect(ui->butSim3, SIGNAL(clicked(bool)),this,SLOT(simonClicked(3)));
    QObject::connect(ui->butSim4, SIGNAL(clicked(bool)),this,SLOT(simonClicked(4)));*/

    std::cout << "Fin construction SIMON" << std::endl;
}

SuperSimon::~SuperSimon()
{
    std::cout<<"Destruction SuperSimon"<<std::endl;
    delete ui;
}

void SuperSimon::readSequence()
{

}

void SuperSimon::editSequence()
{

}

void SuperSimon::addLife()
{
   this->modele->addLife();
}

void SuperSimon::remLife()
{
    this->modele->remLife();
}

void SuperSimon::resScore()
{
    this->modele->setScore(0);
}

void SuperSimon::addToSequence(int numToAdd)
{
    this->modele->setSequence(this->modele->getSequence()+=std::to_string(numToAdd));
    this->checkSeqLenght();
}

void SuperSimon::checkSeqLenght()
{
    //if (this->modele->getSequence()::size==4)
    //    this->sendSeqForCheck();
}

bool SuperSimon::sendSeqForCheck()
{
    return this->modele->checkSequence(this->modele->getSequence());
}

/// --------------------------------------------------------------------------
/// SLOTS
/// --------------------------------------------------------------------------

void SuperSimon::resetScoreClicked()
{
    std::cout<<"score reset"<<std::endl;
    this->resScore();
    ui->labScore->setText(QString::number(this->modele->getScore()));
}

void SuperSimon::editSequenceClicked()
{
    std::cout<<"edit sequence"<<std::endl;
    this->editSequence();
}

void SuperSimon::readSequenceClicked()
{
    std::cout<<"read sequence"<<std::endl;
    this->readSequence();
}

void SuperSimon::lifeClicked(const int pindex)
{
    std::cout<<"life clicked"<<std::endl;
    switch (pindex)
    {
    case 1 : this->addLife(); break;
    case -1 : this->remLife(); break;
    default:; break;
    }
}

void SuperSimon::simonClicked(const int pindex)
{
    std::cout<<"simon clicked"<<std::endl;
    this->addToSequence(pindex);
}
