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

namespace Ui {
class Memory;
}

class Memory : public QWidget
{
    Q_OBJECT

public:
    explicit Memory(QWidget *parent = 0);
    ~Memory();
    void paintEvent(QPaintEvent*);

    int getNbCards(void);

    // retourner une carte en changeant sa stylesheet
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

    /// NE PAS OUBLIER DE delete[] dans le destructeur
    //QPushButton * tabCards;
    std::vector<QPushButton *> cardsVector;

    int nbcards;

    QGridLayout * theGrid;

    // nombre de clics
    QLabel * labScore;

    // vider le vecteur de boutons
    void emptyAndDeleteVector(void);

};

#endif // MEMORY_H
