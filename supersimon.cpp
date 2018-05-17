#include "supersimon.h"
#include "ui_supersimon.h"

SuperSimon::SuperSimon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuperSimon)
{
    std::cout << "Debut construction SIMON" << std::endl;
    ui->setupUi(this);

    /**
     * Pour info
     * 1 : blue
     * 2 : green
     * 3 : red
     * 4 : yellow
     **/

    ui->butLireSeq->setFixedSize(200,200);
    ui->butLireSeq->setStyleSheet(QString::fromUtf8(
                                   "QPushButton {"
                                   "border-image:url(:/files/speaker.png);"
                                   "}"
                                   "QPushButton::pressed {"
                                   "border-image:url(:/files/speaker.png);"
                                   "}"
                                   ));

    // TEST BOUTON PERSO
    ui->butSim1->setFixedSize(200,200);
    ui->butSim1->setStyleSheet(QString::fromUtf8(
                                   "QPushButton {"
                                   "border-image:url(:/files/blue.png);"
                                   "}"
                                   "QPushButton::pressed {"
                                   "border-image:url(:/files/blue.png);"
                                   "}"
                                   ));

    ui->butSim2->setFixedSize(200,200);
    ui->butSim2->setStyleSheet(QString::fromUtf8(
                                   "QPushButton {"
                                   "border-image:url(:/files/green.png);"
                                   "}"
                                   "QPushButton::pressed {"
                                   "border-image:url(:/files/green.png);"
                                   "}"
                                   ));

    ui->butSim3->setFixedSize(200,200);
    ui->butSim3->setStyleSheet(QString::fromUtf8(
                                   "QPushButton {"
                                   "border-image:url(:/files/red.png);"
                                   "}"
                                   "QPushButton::pressed {"
                                   "border-image:url(:/files/red.png);"
                                   "}"
                                   ));

    ui->butSim4->setFixedSize(200,200);
    ui->butSim4->setStyleSheet(QString::fromUtf8(
                                   "QPushButton {"
                                   "border-image:url(:/files/yellow.png);"
                                   "}"
                                   "QPushButton::pressed {"
                                   "border-image:url(:/files/yellow.png);"
                                   "}"
                                   ));

    modele=new ModSimon;

    // longueur attendue
    this->expectedLength = modele->getSeqLen();

    QObject::connect(ui->butLireSeq, SIGNAL(clicked(bool)),this,SLOT(readSequenceClicked()));

    // simon-related buttons
    QObject::connect(ui->butSim1, SIGNAL(clicked(bool)),this,SLOT(simonClickedRedirect()));
    QObject::connect(ui->butSim2, SIGNAL(clicked(bool)),this,SLOT(simonClickedRedirect()));
    QObject::connect(ui->butSim3, SIGNAL(clicked(bool)),this,SLOT(simonClickedRedirect()));
    QObject::connect(ui->butSim4, SIGNAL(clicked(bool)),this,SLOT(simonClickedRedirect()));

    std::cout << "Fin construction SIMON" << std::endl;

    //création des QMediaPlayer pour jouer des sons pendant le simon

    this->urlOne = new QUrl("qrc:/files/blue.mp3");
    this->urlTwo = new QUrl("qrc:/files/green.mp3");
    this->urlThree = new QUrl("qrc:/files/red.mp3");
    this->urlFour= new QUrl("qrc:/files/yellow.mp3");

    playerSimon = new QMediaPlayer;
    playerSimon->setVolume(50);

    // playlist
    playSeq = new QMediaPlaylist;


    updateViewSimon();

}

SuperSimon::~SuperSimon()
{
    std::cout<<"Destruction SuperSimon"<<std::endl;
    //delete playOne;
    //delete playTwo;
    //delete playThree;
    //delete playFour;
    this->deleteAudio();
    delete ui;
}

void SuperSimon::readSequence()
{
    // vidage de la playlist
    if(this->playSeq->clear())
    {
        std::cout << "liste de lecture videe" << std::endl;
    } else {
        std::cout << "probleme lors du vidage de la liste de lecture" << std::endl;
    }

    ui->labSeqNumber->setText("SIMON --- " + QString::fromStdString(std::to_string(modele->getSeqLen())));
    //ui->labLireSeq->setText("");

    char nextChar;
    std::string seq = this->modele->getSequence();
    //for sur string de séquence pour remplir
    //labLireSeq et lire l'audio en même temps

    // chaine a mettre sous la lecture
    std::string seqLue = "";

    std::cout << "on va faire pour la lecture " << this->modele->getSeqLen() << " boucles" << std::endl;
    for (int i=0;i<this->modele->getSeqLen();++i)
    {
        nextChar=seq.at(i);
        std::cout << "le nextchar est " << nextChar << std::endl;
        switch(nextChar){
        case('1'):{
            seqLue += "one ";
            this->playSeq->addMedia(*urlOne);
            break;
        }
        case('2'):{
            seqLue += "two ";
            this->playSeq->addMedia(*urlTwo);
            break;
        }
        case('3'):{
            seqLue += "three ";
            this->playSeq->addMedia(*urlThree);
            break;
        }
        case('4'):{
            seqLue += "four ";
            this->playSeq->addMedia(*urlFour);
            break;
        }
        }
    }
    std::cout << "la playlist contient " << playSeq->mediaCount() << std::endl;
    playerSimon->setPlaylist(playSeq);
    playerSimon->setVolume(50);
    playerSimon->play();

}

void SuperSimon::editSequence()
{
    /// \obsolete
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
    this->seqEntered.append(QString::fromStdString(std::to_string(numToAdd)));

    std::cout << "seqentered actuel : " << seqEntered.toStdString() << std::endl;

    this->checkSeqLenght();
}

void SuperSimon::checkSeqLenght()
{


    if(seqEntered.length()==expectedLength) {
        this->sendSeqForCheck();
    } else if(seqEntered.length() > expectedLength){
        std::cout << "euh, y a un probleme [supersimon::checkseqlength]" << std::endl;
    } else {
        //nothing, pas encore atteint la longueur de la sequence
    }
}

bool SuperSimon::sendSeqForCheck()
{
    // dans le si, on fait déjà les opérations sur le modèle, il faut donc simplement
    // mettre à jour la vue après
    if (this->modele->checkSequence(seqEntered.toStdString())) {
        this->readSequence();
        std::cout << "bonne sequence";
    }
    this->updateViewSimon();
    this->expectedLength=modele->getSeqLen();
    this->seqEntered=QString::fromStdString("");
    if (this->checkEndOfGame())
    {
        this->sendEndOfGame();
    }
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
    //ui->labLireSeq->setText(QString::fromStdString(modele->getSequence()));
    ui->labLifeRemaining->setText(QString::fromStdString("Remaining lives : " + std::to_string(modele->getLives())));
    ui->labScore->setText(QString::fromStdString("Score : " + std::to_string(modele->getScore())));
    ui->labSeqNumber->setText("SIMON --- " + QString::fromStdString(std::to_string(modele->getSeqLen())));

    /// \todo mettre a jour les textes
}


/// \test
void SuperSimon::delay(int & sec)
{
    QTime dieTime= QTime::currentTime().addSecs(sec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void SuperSimon::deleteAudio()
{
    delete urlOne;
    delete urlTwo;
    delete urlThree;
    delete urlFour;
    delete playSeq;
    delete playerSimon;
}


void SuperSimon::sendEndOfGame(void)
{
    std::pair<std::string,int> paireALancer;
    std::string jeu = "SIMON";
    int leScore = this->expectedLength - 1 + modele->getLives();
    paireALancer.first=jeu;
    paireALancer.second=leScore;
    std::cout << "SIGNAL DE FIN LANCE::Reinitialisation" << std::endl;
    ModSimon * nouveauMod = new ModSimon;
    delete this->modele;
    this->modele = nouveauMod;
    this->expectedLength = modele->getSeqLen();
    this->updateViewSimon();

    emit endOfGame(paireALancer);
}

bool SuperSimon::checkEndOfGame()
{
    if (modele->getLives()<=0 || modele->getScore() >= modele->getScoreToReach())
    {
        return true;
    } else {
        return false;
    }
}
