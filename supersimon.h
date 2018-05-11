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

    /// \todo voir si on passerait pas plein de fonction public en private
    /// vu que de toutes façons elles ne sont pas appelées hors de la classe
    /// pour la plupart

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

    /// mettre à jour la vue
    void updateViewSimon(void);

public slots:
    /// appui sur bouton du simon
    /// redirection vers simonClicked avec la valeur du bouton
    void simonClickedRedirect();

    /// appui sur bouton du simon
    void simonClicked(const int);

    /// redirection vers lifeClicked avec la valeur du bouton
    void addLifeClicked();

    /// appui sur un modificateur de vie
    void remLifeClicked();

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
