#include "supersimon.h"
#include "ui_supersimon.h"

SuperSimon::SuperSimon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SuperSimon)
{
    std::cout << "Debut construction SIMON" << std::endl;
    ui->setupUi(this);

    // TEST BOUTON PERSO
    ui->butSim1->setFixedSize(50,50);
    ui->butSim1->setStyleSheet(QString::fromUtf8(
                                   "QPushButton {"
                                   "border-image:url(:/files/simon1NotClickedTransp.png);"
                                   "}"
                                   "QPushButton::pressed {"
                                   "border-image:url(:/files/simon1NotClickedTransp.png);"
                                   "}"
                                   ));




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

    //création des QMediaPlayer pour jouer des sons pendant le simon

    //QMediaPlayer playOne = new QMediaPlayer;
    //this->playOne = new QMediaPlayer;
    //playOne->setMedia(QUrl::fromLocalFile(":/files/one.mp3"));
    //playOne->setMedia(QUrl::fromLocalFile("files/one.mp3"));
    //playOne->setMedia(QUrl::from("qrc:/files/three.mp3"));
    this->urlOne = new QUrl("qrc:/files/one.mp3");
    //playOne->setMedia(urlOne);
    //playOne->setVolume(50);
    //playOne->play();


    //QMediaPlayer playTwo = new QMediaPlayer;
    //this->playTwo = new QMediaPlayer;
    //playTwo->setMedia(QUrl::fromLocalFile(":/files/two.mp3"));
    //playTwo->setMedia(QUrl::fromLocalFile("files/two.mp3"));
    this->urlTwo = new QUrl("qrc:/files/two.mp3");
    //playOne->setMedia(urlTwo);
    //playTwo->setVolume(50);
    //playTwo->play();

    //QMediaPlayer playThree = new QMediaPlayer;
    //this->playThree = new QMediaPlayer;
    //playThree->setMedia(QUrl::fromLocalFile(":/files/three.mp3"));
    //playThree->setMedia(QUrl::fromLocalFile("files/three.mp3"));
    this->urlThree = new QUrl("qrc:/files/three.mp3");
    //playOne->setMedia(urlThree);
    //playThree->setVolume(50);
    //playThree->play();

    //QMediaPlayer playFour = new QMediaPlayer;
    //this->playFour = new QMediaPlayer;
    //playFour->setMedia(QUrl::fromLocalFile(":/files/four.mp3"));
    //playFour->setMedia(QUrl::fromLocalFile("files/four.mp3"));
    this->urlFour= new QUrl("qrc:/files/four.mp3");
    //playOne->setMedia(urlFour);
    //playFour->setVolume(50);
    //playFour->play();

    playerSimon = new QMediaPlayer;
    playerSimon->setVolume(50);
    // playlist
    playSeq = new QMediaPlaylist;
    //playerSimon->setPlaylist(playSeq);



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
    ui->labLireSeq->setText("");

    char nextChar;
    std::string seq = this->modele->getSequence();
    //for sur string de séquence pour remplir
    //labLireSeq et lire l'audio en même temps

    // chaine a mettre sous la lecture
    std::string seqLue = "";

    std::cout << "on va faire pour la lecture " << this->modele->getSeqLen() << " boucles" << std::endl;
    for (int i=0;i<this->modele->getSeqLen();++i)
    {
        //nextChar=str.at(seq);
        nextChar=seq.at(i);
        std::cout << "le nextchar est " << nextChar << std::endl;
        switch(nextChar){
        case('1'):{
            //ui->labLireSeq->setText(QString::fromStdString(ui->labLireSeq->text().toStdString()) + "one ");
            seqLue += "one ";
            //playOne->play();
            this->playSeq->addMedia(*urlOne);
            break;
        }
        case('2'):{
            //ui->labLireSeq->setText(QString::fromStdString(ui->labLireSeq->text().toStdString()) + "two ");
            seqLue += "two ";
            //playTwo->play();
            this->playSeq->addMedia(*urlTwo);
            break;
        }
        case('3'):{
            //ui->labLireSeq->setText(QString::fromStdString(ui->labLireSeq->text().toStdString()) + "three ");
            seqLue += "three ";
            //playThree->play();
            this->playSeq->addMedia(*urlThree);
            break;
        }
        case('4'):{
            //ui->labLireSeq->setText(QString::fromStdString(ui->labLireSeq->text().toStdString()) + "four ");
            seqLue += "four ";
            //playFour->play();
            this->playSeq->addMedia(*urlFour);
            break;
        }
        }
        //délai pour éviter une superposition des mp3
        //QThread::msleep(1000);
        //int sec = 2;
        //this->delay(sec);
    }
    ui->labLireSeq->setText(QString::fromStdString(seqLue));
    //this->playSeq->setCurrentIndex(1);
    std::cout << "la playlist contient " << playSeq->mediaCount() << std::endl;
    playerSimon->setPlaylist(playSeq);
    playerSimon->setVolume(50);
    playerSimon->play();

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

    // faire du bruit
    switch(pindex){
    case(1):{
        this->playerSimon->setMedia(*urlOne);
        this->playerSimon->play();
        break;
    }
    case(2):{
        this->playerSimon->setMedia(*urlTwo);
        this->playerSimon->play();
        break;
    }
    case(3):{
        this->playerSimon->setMedia(*urlThree);
        this->playerSimon->play();
        break;
    }
    case(4):{
        this->playerSimon->setMedia(*urlFour);
        this->playerSimon->play();
        break;
    }
    }

}



void SuperSimon::updateViewSimon()
{
    ui->labLireSeq->setText(QString::fromStdString(modele->getSequence()));
    ui->labLifeRemaining->setText(QString::fromStdString(std::to_string(modele->getLives())));
    ui->labScore->setText(QString::fromStdString(std::to_string(modele->getScore())));
    ui->labSeqNumber->setText(QString::fromStdString(std::to_string(modele->getSeqLen())));

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
