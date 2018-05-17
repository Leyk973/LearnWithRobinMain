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
    /// \brief Constructeur et destructeur
    explicit Memory(QWidget *parent = 0);
    ~Memory();

    /// \brief Met à jour l'interface
    /// \obsolete
    /// void paintEvent(QPaintEvent*);

    /// \brief Récupère le nombre de cartes
    int getNbCards(void);

    /// \brief Donner les informations
    /// \details Verifie si la carte est retournée ou non et lui
    /// attribue une stylesheet correspondant à cela en se basant
    /// pour son image si elle est retournée sur la paire du modele
    void setupCardFromModel(int ind);

    /// \brief Retourne le nom de fichier attendu pour la paire
    std::string getCardFromPaire(int paire);

    /// \brief Trouver l'indice de la carte depuis son nom
    int getIndiceFromName(QPushButton*but);

    /// \brief  retourner toutes les cartes non appairées
    void closeAllCards(void);

    /// \brief Declencher fin du jeu
    void sendEndOfGame(void);

    /// \brief Verifier si fin du jeu
    bool checkEndOfGame(void);

signals:
    /// \brief fin du jeu
    void endOfGame(std::pair<std::string,int> asso);

public slots:

    /// \brief Clic sur une carte
    void carteClic(void);

private:

    /// \brief Vecteur qui contient les pointeurs vers les boutons créés dynanmiquement par le programme
    /// NE PAS OUBLIER DE delete[] dans le destructeur
    //QPushButton * tabCards;
    std::vector<QPushButton *> cardsVector;

    /// \brief Nombre de cartes
    int nbcards;

    /// \brief Grille sur laquelle les cartes sont placées
    QGridLayout * theGrid;

    /// \brief Affiche le score
    // nombre de clics
    QLabel * labScore;

    /// \brief Vider et supprimer le vecteur de boutons
    void emptyAndDeleteVector(void);

    /// \brief Modèle
    ModMemory * modMemo;

};

#endif // MEMORY_H
