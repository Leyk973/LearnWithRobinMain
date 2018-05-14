#ifndef SUPERSIMON_H
#define SUPERSIMON_H

#include "includeviews.h"
#include "modsimon.h"
#include <QMediaPlayer>
#include <QTime>
#include <QMediaPlaylist>

namespace Ui {
class SuperSimon;
}

class SuperSimon : public QWidget
{
    Q_OBJECT

    // \todo voir si on passerait pas plein de fonction public en private
    // vu que de toutes façons elles ne sont pas appelées hors de la classe
    // pour la plupart

public:

    /// Constructeur destructeur
    explicit SuperSimon(QWidget *parent = nullptr);
    ~SuperSimon();

    /// Lire la séquence actuelle (joue et affiche en toutes lettres le nom des couleurs)
    void readSequence(void);

    /// Editer la séquence à jouer
    void editSequence(void);

    /// Ajouter une vie au joueur
    void addLife(void);

    /// Retirer une vie au joueur
    void remLife(void);

    /// Réinitialiser le score
    void resScore(void);

    /// Ajoute l'entier représentant un bouton au QString seqEntered
    /// Appelle checkSeqLenght
    void addToSequence(int);

    /// Vérifie la taille de seqEntered
    /// Appelle sendSeqForCheck si la taille attendue est atteinte
    void checkSeqLenght(void);

    /// Envoie la séquence au modèle pour vérification
    bool sendSeqForCheck(void);

    /// Mettre à jour la vue
    void updateViewSimon(void);

    /// Attend sec secondes
    void delay(int & sec);


public slots:
    /// Appui sur bouton du simon
    /// Redirection vers simonClicked avec la valeur du bouton
    void simonClickedRedirect();

    /// Appui sur bouton du simon
    void simonClicked(const int);

    /// Redirection vers lifeClicked avec la valeur du bouton
    void addLifeClicked();

    /// Appui sur un modificateur de vie
    void remLifeClicked();

    /// Appui sur read sequence
    void readSequenceClicked(void);

    /// Appui sur edit sequence
    void editSequenceClicked(void);

    /// Appui sur reset score
    void resetScoreClicked(void);

    /// Supprime les éléments responsables du son
    void deleteAudio(void);

private:
    /// Interface utilisateur
    Ui::SuperSimon *ui;

    /// Modèle
    ModSimon *modele;

    /// Séquence entrée par appui sur les boutons
    QString seqEntered;

    /// Taille attendue, à récupérer du modèle
    int expectedLength;

    /// \test
    /// Url des fichiers audio
    //QMediaPlayer * playOne;
    QUrl * urlOne;
    //QMediaPlayer * playTwo;
    QUrl * urlTwo;
    //QMediaPlayer * playThree;
    QUrl * urlThree;
    //QMediaPlayer * playFour;
    QUrl * urlFour;

    /// Playlist pour lire la séquence
    QMediaPlaylist * playSeq;

    /// Player pour lire les mp3
    QMediaPlayer * playerSimon;

};

#endif // SUPERSIMON_H
