#ifndef MEMORY_H
#define MEMORY_H


#include <QWidget>
#include <QPainter>
#include <QRect>
#include "includeviews.h"
#include "commonlibs.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <memory>
#include "modmemory.h"

namespace Ui {
class Memory;
}

class Memory : public QWidget
{
    Q_OBJECT

public:
    /// Constructeur et destructeur
    explicit Memory(QWidget *parent = 0);
    ~Memory();

    /// Met à jour l'interface
    void paintEvent(QPaintEvent*);

    /// Récupère le nombre de cartes
    int getNbCards(void);

    /// Retourne une carte en changeant sa stylesheet
    void flipCard(QPushButton*);

private:
    //Ui::Memory *ui;
    //QRect *tabCardRects;

    // on va plutôt avoir un tableau de boutons (qui seront des cartes à terme)

    // boutons de test
    /*QPushButton * boutonDeTestQuiSertARien1;
    QPushButton * boutonDeTestQuiSertARien2;
    QPushButton * boutonDeTestQuiSertARien3;
    QPushButton * boutonDeTestQuiSertARien4;*/

    /// Vecteur qui contient les pointeurs vers les boutons créés dynanmiquement par le programme
    /// NE PAS OUBLIER DE delete[] dans le destructeur
    //QPushButton * tabCards;
    std::vector<QPushButton *> cardsVector;

    /// Nombre de cartes
    int nbcards;

    /// Grille sur laquelle les cartes sont placées
    QGridLayout * theGrid;

    /// Affiche le score
    // nombre de clics
    QLabel * labScore;

    /// Vider et supprimer le vecteur de boutons
    void emptyAndDeleteVector(void);

    /// Modèle
    ModMemory * modMemo;

};

#endif // MEMORY_H
