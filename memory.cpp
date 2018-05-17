#include "memory.h"
#include "ui_memory.h"


Memory::Memory(QWidget *parent) :
    QWidget(parent)//,
    //ui(new Ui::Memory)
{
    std::cout << "Creation Memory" << std::endl;
    //ui->setupUi(this);

    modMemo = new ModMemory;

    /// \todo ordonner / ranger un peu cette fonction

    // Premier layout, score et autres
    QHBoxLayout *premierLayoute = new QHBoxLayout;
    labScore = new QLabel("Score : 0");
    premierLayoute->addWidget(labScore);

    /// \todo faire en sorte de régler le nombre de cartes selon la difficulté
    this->nbcards=this->getNbCards();

    // gestion du tableau de cartes
    //std::shared_ptr<QPushButton> tabCards (new QPushButton[nbcards],std::default_delete<QPushButton[]>());
    //tabCards = new QPushButton[nbcards];



    QHBoxLayout * layoutGlob = new QHBoxLayout;
    theGrid = new QGridLayout;

    /// \todo gérer le nombre de lignes et colonnes par rapport au nombre de cartes
    /// par exemple avec une approche de la racine carrée par la valeur inférieure
    /// pour les lignes, puis continuer à remplir dans les cases en revenant à la
    /// ligne à chaque fin de ligne, jusqu'à l'écoulement des cartes
    int monpetitcompteur = 0;
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            std::string l = std::to_string(monpetitcompteur);
            cardsVector.push_back(new QPushButton(QString::fromStdString(l)));
            cardsVector.at(monpetitcompteur)->setFixedSize(150,150);
            std::string nameCard = "card_" + l;
            cardsVector.at(monpetitcompteur)->setObjectName(QString::fromStdString(nameCard));

            setupCardFromModel(monpetitcompteur);

            std::cout << "carte créée : " << cardsVector.at(monpetitcompteur)->objectName().toStdString() << std::endl;
            theGrid->addWidget(cardsVector.at(monpetitcompteur),i,j);

            QObject::connect(cardsVector.at(monpetitcompteur),&QPushButton::clicked,this,&Memory::carteClic);

            ++monpetitcompteur;
        }
    }

    layoutGlob->addLayout(premierLayoute);
    layoutGlob->addLayout(theGrid);

    this->setLayout(layoutGlob);

    std::cout << "Fin Creation Memory" << std::endl;
}

Memory::~Memory()
{
    std::cout<<"Destruction Memory"<<std::endl;
    //delete ui;

    this->emptyAndDeleteVector();
    delete labScore;
    delete theGrid;
}


int Memory::getNbCards()
{
    /// \todo récupérer dans le modèle après
    return 16;
}

void Memory::emptyAndDeleteVector()
{
    for (std::vector< QPushButton * >::iterator it = cardsVector.begin() ; it != cardsVector.end(); ++it)
    {
      delete (*it);
    }
    cardsVector.clear();
}

void Memory::setupCardFromModel(int ind)
{
    if(modMemo->cardIsOpen(ind))
    {
        std::string chemin = this->getCardFromPaire(modMemo->getPaireCarte(ind));
        /*cardsVector.at(ind)->setStyleSheet(QString::fromUtf8(
                                               "QPushButton {"
                                               "border-image:url(:/files/" + chemin +");"
                                               "}"
                                               "QPushButton::pressed {"
                                               "border-image:url(:/files/" + chemin +");"
                                               "}"
                                               ));*/
        QString monStyle (QString::fromStdString("QPushButton {\nborder-image:url(:/files/"
                                                 + chemin + ");\n}\nQPushButton::pressed {\n"
                                                 + "border-image:url(:/files/" + chemin +");\n"
                                                 + "}"));

        cardsVector.at(ind)->setStyleSheet(monStyle);

    } else {
        cardsVector.at(ind)->setStyleSheet(QString::fromUtf8(
                                               "QPushButton {"
                                               "border-image:url(:/files/card_back.png);"
                                               "}"
                                               "QPushButton::pressed {"
                                               "border-image:url(:/files/card_back.png);"
                                               "}"
                                               ));
    }
}

std::string Memory::getCardFromPaire(int paire)
{
    std::string cheminPaire;
    switch (paire)
    {
    case 0:{
        cheminPaire="bird.jpg";
        break;
    }
    case 1:{
        cheminPaire="cat.jpg";
        break;
    }
    case 2:{
        cheminPaire="Cow.jpg";
        break;
    }
    case 3:{
        cheminPaire="dog.jpg";
        break;
    }
    case 4:{
        cheminPaire="fish.png";
        break;
    }
    case 5:{
        cheminPaire="horse.png";
        break;
    }
    case 6:{
        cheminPaire="rabbit.png";
        break;
    }
    case 7:{
        cheminPaire="sheep.jpg";
        break;
    }
    default:{
        cheminPaire="card_back.png";
        break;
    }
    }
    return cheminPaire;
}

int Memory::getIndiceFromName(QPushButton *but)
{
    std::string nameObj=but->objectName().toStdString();

    std::cout << "nom du bazar : " << nameObj << std::endl;

    nameObj=nameObj.substr(5,2); //indice

    std::cout << "nom du bazar avant deux : " << nameObj << std::endl;

    int indice = std::stoi(nameObj);

    std::cout << "nom du bazar deux : " << indice << std::endl;

    return indice;
}

void Memory::carteClic()
{
    int indice = getIndiceFromName((QPushButton*)sender());

    modMemo->openCard(indice);

    setupCardFromModel(indice);


}
