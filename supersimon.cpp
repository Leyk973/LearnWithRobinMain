#include "supersimon.h"
#include "ui_supersimon.h"

SuperSimon::SuperSimon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuperSimon)
{
    std::cout << "Debut construction SIMON" << std::endl;
    ui->setupUi(this);
    modele=new ModSimon;

    // longueur attendue
    this->expectedLength = modele->getSeqLen();

    std::cout << "Debut construction DEUX" << std::endl;
    QObject::connect(ui->butResScore, SIGNAL(clicked(bool)),this,SLOT(resetScoreClicked()));
    std::cout << "Debut construction TROIS" << std::endl;
    QObject::connect(ui->butSeqEdit, SIGNAL(clicked(bool)),this,SLOT(editSequenceClicked()));
    std::cout << "Debut construction QUATRE" << std::endl;
    QObject::connect(ui->butLireSeq, SIGNAL(clicked(bool)),this,SLOT(readSequenceClicked()));
    // lives-related buttons
    QObject::connect(ui->butAddLife, SIGNAL(clicked(bool)),this,SLOT(addLifeClicked()));
    QObject::connect(ui->butRemLife, SIGNAL(clicked(bool)),this,SLOT(remLifeClicked()));
    // simon-related buttons
    QObject::connect(ui->butSim1, SIGNAL(clicked(bool)),this,SLOT(simonClickedRedirect()));
    QObject::connect(ui->butSim2, SIGNAL(clicked(bool)),this,SLOT(simonClickedRedirect()));
    QObject::connect(ui->butSim3, SIGNAL(clicked(bool)),this,SLOT(simonClickedRedirect()));
    QObject::connect(ui->butSim4, SIGNAL(clicked(bool)),this,SLOT(simonClickedRedirect()));

    std::cout << "Fin construction SIMON" << std::endl;
}

SuperSimon::~SuperSimon()
{
    std::cout<<"Destruction SuperSimon"<<std::endl;
    delete ui;
}

void SuperSimon::readSequence()
{
    ui->labLireSeq->setText(QString::fromStdString(modele->getSequence()));
    ui->labSeqNumber->setText(QString::fromStdString(std::to_string(modele->getSeqLen())));
}

void SuperSimon::editSequence()
{
    /// \todo implémenter
}

void SuperSimon::addLife()
{
   this->modele->addLife();
   std::string mammouth = std::to_string(this->modele->getLives());
   this->ui->labLifeRemaining->setText(QString::fromStdString(mammouth));
}

void SuperSimon::remLife()
{
    this->modele->remLife();
    std::string mammouth = std::to_string(this->modele->getLives());
    this->ui->labLifeRemaining->setText(QString::fromStdString(mammouth));
}

void SuperSimon::resScore()
{
    this->modele->setScore(0);
}

void SuperSimon::addToSequence(int numToAdd)
{
    //this->modele->setSequence(this->modele->getSequence()+=std::to_string(numToAdd));
    this->seqEntered.append(QString::fromStdString(std::to_string(numToAdd)));

    std::cout << "seqentered actuel : " << seqEntered.toStdString() << std::endl;

    this->checkSeqLenght();
}

void SuperSimon::checkSeqLenght()
{


    if(seqEntered.length()==expectedLength) {
        this->sendSeqForCheck();
    } else if(seqEntered.length() > expectedLength){
        std::cout << "euh, y a un probleme patron[supersimon::checkseqlength]" << std::endl;
    } else {
        //nothing, pas encore atteint la longueur de la sequence
    }
}

bool SuperSimon::sendSeqForCheck()
{
    // dans le si, on fait déjà les opérations sur le modèle, il faut donc simplement
    // mettre à jour la vue après
    if (this->modele->checkSequence(seqEntered.toStdString())) {
        std::cout << "bonne sequence, felicitations de supersimon";
        // longueur attendue
    }
    this->updateViewSimon();
    this->expectedLength=modele->getSeqLen();
    this->seqEntered=QString::fromStdString("");
    //return true;
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

void SuperSimon::addLifeClicked()
{
    std::cout<<"addLife clicked"<<std::endl;
    this->addLife();
}

void SuperSimon::remLifeClicked()
{
    std::cout<<"remLife clicked"<<std::endl;
    this->remLife();
}

void SuperSimon::simonClickedRedirect()
{
    QPushButton *button = (QPushButton *)sender();
    emit simonClicked(button->text()[0].digitValue());
}

void SuperSimon::simonClicked(const int pindex)
{
    std::cout<<"simon clicked " << pindex <<std::endl;
    this->addToSequence(pindex);
}




void SuperSimon::updateViewSimon()
{
    ui->labLireSeq->setText(QString::fromStdString(modele->getSequence()));
    ui->labLifeRemaining->setText(QString::fromStdString(std::to_string(modele->getLives())));
    ui->labScore->setText(QString::fromStdString(std::to_string(modele->getScore())));
    ui->labSeqNumber->setText(QString::fromStdString(std::to_string(modele->getSeqLen())));

    /// \todo mettre a jour les textes
}
