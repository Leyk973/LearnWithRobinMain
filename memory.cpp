#include "memory.h"
#include "ui_memory.h"


Memory::Memory(QWidget *parent) :
    QWidget(parent)//,
    //ui(new Ui::Memory)
{
    std::cout << "Creation Memory" << std::endl;
    //ui->setupUi(this);

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
            cardsVector.at(monpetitcompteur)->setFixedSize(100,100);
            std::string nameCard = "card_" + l;
            cardsVector.at(monpetitcompteur)->setObjectName(QString::fromStdString(nameCard));
            cardsVector.at(monpetitcompteur)->setStyleSheet(QString::fromUtf8(
                                                                "QPushButton {"
                                                                "border-image:url(:/files/boutonTestNotClicked.png);"
                                                                "}"
                                                                "QPushButton::pressed {"
                                                                "border-image:url(:/files/boutonTestClicked.png);"
                                                                "}"
                                                                ));
            std::cout << "carte créée : " << cardsVector.at(monpetitcompteur)->objectName().toStdString() << std::endl;
            theGrid->addWidget(cardsVector.at(monpetitcompteur),i,j);
            ++monpetitcompteur;
        }
    }


    /*boutonDeTestQuiSertARien1 = new QPushButton("1");
    boutonDeTestQuiSertARien2 = new QPushButton("2");
    boutonDeTestQuiSertARien3 = new QPushButton("3");
    boutonDeTestQuiSertARien4 = new QPushButton("4");
    theGrid->addWidget(boutonDeTestQuiSertARien1,0,0);
    theGrid->addWidget(boutonDeTestQuiSertARien2,1,0);
    theGrid->addWidget(boutonDeTestQuiSertARien3,2,0);
    theGrid->addWidget(boutonDeTestQuiSertARien4,0,1);*/

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

    /*delete boutonDeTestQuiSertARien1;
    delete boutonDeTestQuiSertARien2;
    delete boutonDeTestQuiSertARien3;
    delete boutonDeTestQuiSertARien4;*/
    //delete tabCardRects;
    delete theGrid;
}

/// nope, on va plutôt y aller avec des widgets pour les cartes
void Memory::paintEvent(QPaintEvent *)
{
    QPainter * myPaint = new QPainter(this);

    myPaint->setBrush(Qt::blue);

    /// \todo vérifier ce que ça fait
    /// je pense que c'est pour stocker les rectangles dessinés dans le tableau mentionné
    /// ça sert peut-être à rien ici
    // myPaint->drawRects(this->tabCardRects,this->nbcards);



}

/// futures fonctions liées au modèle pour quand il y aura un modèle
/// \todo faire un modèle

int Memory::getNbCards()
{
    /// \todo récupérer dansle modèle après
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

