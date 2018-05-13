#ifndef MODMEMORY_H
#define MODMEMORY_H

#include "commonlibs.h"
#include <vector>

/// classe pour les cartes de memory
class MemoryCard
{
public:

    // constructeur
    MemoryCard(void);

    /// constructeur complet
    /// \param 1 indice
    /// \param 2 paire
    /// \param 3 retournee
    /// \param 4 associee
    MemoryCard(int&, int&, bool, bool);

    ~MemoryCard(void);

    /// inverse l'état retournee de la carte
    void flipCard(void);

    /// met associee a vrai
    void foundCard(void);

    void setIndice(int & ind);
    int getIndice(void);

    void setPaire(int & pai);
    int getPaire(void);

    bool isRetournee(void);

    bool isAssociee(void);


private:

    // indice de la carte dans le memory [0-15]
    int indice;

    // indice de la paire dans le memory [0-7]
    int paire;

    // etat de la carte [retournée ou pas]
    bool retournee;

    // paire trouvee ?
    bool associee;
};

class ModMemory
{
public:
    ModMemory();
    ~ModMemory();

    /// mélanger les cartes dans le vecteur
    /// \details principe : la vue va associer les cartes
    /// de son vecteur avec celles du modele en prenant leurs
    /// indices dans leurs vecteurs respectifs, et le modele va
    /// communiquer les informations des MemoryCards, mélangées donc.
    /// Tout ça pour dire que pas besoin de mélanger ou synchroniser
    /// la vue et le modèle entre eux.
    void shuffleCards(void);

    /// \warning tous les indices demandes sour forme d'int sont
    /// les indice du vecteur, pas les attributs indice des MemoryCards elles-mêmes

    /// verifie si la carte est ouverte (valeur visible)
    bool cardIsOpen(int&);

    /// retourner une carte vers face visible
    /// l'ajoute au vecteur flippedcards
    void openCard(int&);

    /// retourne les cartes de flipped cards
    void closeCards(int&);

    /// verifier si les cartes sont de la même paire
    bool checkCards(int&, int&);

    /// indice de la carte
    /// utile seulement pour le shuffle
    /// et encore, peut-être
    int getIndiceCarte(int&);

    /// paire de la carte
    int getPaireCarte(int&);

    /// verifie si la carte est associee
    bool cardIsPaired(int&);



    // getters

    //setters


private:
    /// nombre de coups
    /// + petit = + mieux
    int score;

    /// nombre de paires du memory en cours
    int nbPaires;

    /// nombre de cartes du memory en cours
    int nbCards;

    /// la liste des cartes
    std::vector<MemoryCard> cards;

    /// la liste des cartes retournees
    /// quand elle a plus de 2 elements, on enleve les deux
    /// plus anciens
    std::vector<MemoryCard> flippedCards;



};



#endif // MODMEMORY_H
