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

    /// \brief Constructeur destructeur
    explicit SuperSimon(QWidget *parent = nullptr);
    ~SuperSimon();

    /// \brief Lire la séquence actuelle (joue et affiche en toutes lettres le nom des couleurs)
    void readSequence(void);

    /// \brief Editer la séquence à jouer
    void editSequence(void);

    /// \brief Ajouter une vie au joueur
    void addLife(void);

    /// \brief Retirer une vie au joueur
    void remLife(void);

    /// Réinitialiser le score
    void resScore(void);

    /// \brief Ajoute l'entier représentant un bouton au QString seqEntered
    /// \details Appelle checkSeqLenght
    void addToSequence(int);

    /// \brief Vérifie la taille de seqEntered
    /// \details Appelle sendSeqForCheck si la taille attendue est atteinte
    void checkSeqLenght(void);

    /// \brief Envoie la séquence au modèle pour vérification
    bool sendSeqForCheck(void);

    /// \brief Mettre à jour la vue
    void updateViewSimon(void);

    /// \brief Attend sec secondes
    void delay(int & sec);

    /// \brief Declencher fin du jeu
    void sendEndOfGame(void);

    /// \brief Verifier si fin du jeu
    bool checkEndOfGame(void);

signals:
    /// \brief fin du jeu
    void endOfGame(std::pair<std::string,int> asso);


public slots:
    /// \brief Appui sur bouton du simon
    /// \details Redirection vers simonClicked avec la valeur du bouton
    void simonClickedRedirect();

    /// \brief Appui sur bouton du simon
    void simonClicked(const int);

    /// \brief Redirection vers lifeClicked avec la valeur du bouton
    void addLifeClicked();

    /// \brief Appui sur un modificateur de vie
    void remLifeClicked();

    /// \brief Appui sur read sequence
    void readSequenceClicked(void);

    /// \brief Appui sur edit sequence
    void editSequenceClicked(void);

    /// \brief Appui sur reset score
    void resetScoreClicked(void);

    /// \brief Supprime les éléments responsables du son
    void deleteAudio(void);

private:
    /// \brief Interface utilisateur
    Ui::SuperSimon *ui;

    /// \brief Modèle
    ModSimon *modele;

    /// \brief Séquence entrée par appui sur les boutons
    QString seqEntered;

    /// \brief Taille attendue, à récupérer du modèle
    int expectedLength;

    /// \test
    /// \brief Url des fichiers audio
    //QMediaPlayer * playOne;
    QUrl * urlOne;
    //QMediaPlayer * playTwo;
    QUrl * urlTwo;
    //QMediaPlayer * playThree;
    QUrl * urlThree;
    //QMediaPlayer * playFour;
    QUrl * urlFour;

    /// \brief Playlist pour lire la séquence
    QMediaPlaylist * playSeq;

    /// \brief Player pour lire les mp3
    QMediaPlayer * playerSimon;

};

#endif // SUPERSIMON_H
