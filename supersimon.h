#ifndef SUPERSIMON_H
#define SUPERSIMON_H

#include "includeviews.h"
#include "modsimon.h"

namespace Ui {
class SuperSimon;
}

class SuperSimon : public QWidget
{
    Q_OBJECT

public:
    explicit SuperSimon(QWidget *parent = nullptr);
    ~SuperSimon();

    void readSequence(void);

    void editSequence(void);

    void addLife(void);

    void remLife(void);

    void resScore(void);

    /// ajoute l'entier representant un bouton au QString seqEntered
    /// appelle checkSeqLenght
    void addToSequence(int);

    /// verifie la taille de seqEntered
    /// appelle sendSeqForCheck si taille attendue atteinte
    void checkSeqLenght(void);

    /// envoie la sequence au modèle pour vérification
    bool sendSeqForCheck(void);

public slots:
    /// appui sur bouton du simon
    void simonClicked(const int);

    /// appui sur un modificateur de vie
    void lifeClicked(const int);

    /// appui sur read sequence
    void readSequenceClicked(void);

    /// appui sur edit sequence
    void editSequenceClicked(void);

    /// appui reset score
    void resetScoreClicked(void);


private:
    Ui::SuperSimon *ui;
    ModSimon *modele;

    /// sequence entrée par appui sur les boutons
    QString seqEntered;

    /// taille attendue, à récupérer du modèle
    int expectedLength;

};

#endif // SUPERSIMON_H
