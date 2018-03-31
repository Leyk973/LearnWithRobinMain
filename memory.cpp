#include "memory.h"
#include "ui_memory.h"

Memory::Memory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Memory)
{
    std::cout << "Creation Memory" << std::endl;
    ui->setupUi(this);

    /// \todo faire en sorte de régler le nombre de cartes selon la difficulté
    this->nbcards=this->getNbCards();

    std::cout << "Fin Creation Memory" << std::endl;
}

Memory::~Memory()
{
    std::cout<<"Destruction Memory"<<std::endl;
    delete ui;
}

/// nope, on va plutôt y aller avec des widgets pour les cartes
void Memory::paintEvent(QPaintEvent *)
{
    QPainter * myPaint = new QPainter(this);

    myPaint->setBrush(Qt::blue);

    /// \todo vérifier ce que ça fait
    /// je pense que c'est pour stocker les rectangles dessinés dans le tableau mentionné
    /// ça sert peut-être à rien ici
    myPaint->drawRects(this->tabCardRects,this->nbcards);



}

/// futures fonctions liées au modèle pour quand il y aura un modèle
/// \todo faire un modèle

int Memory::getNbCards()
{
    /// \todo récupérer dansle modèle après
    return 16;
}
