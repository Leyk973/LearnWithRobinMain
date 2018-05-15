#ifndef MODMEMORY_H
#define MODMEMORY_H

#include "commonlibs.h"
#include <vector>

/// Classe pour les cartes de memory
class MemoryCard
{
public:

    /// Constructeur par défaut
    MemoryCard(void);

    /// Constructeur complet
    /// \param 1 indice
    /// \param 2 paire
    /// \param 3 retournee
    /// \param 4 associee
    MemoryCard(int&, int&, bool, bool);

    /// Destructeur
    ~MemoryCard(void);

    /// Inverse l'état retournee de la carte
    void flipCard(void);

    /// Met associee à vrai
    void foundCard(void);

    /// Get-set l'indice d'une carte
    void setIndice(int & ind);
    int getIndice(void);

    /// Get-set une paire
    void setPaire(int & pai);
    int getPaire(void);

    /// Renvoie l'état de la carte (retournée ou non)
    bool isRetournee(void);

    /// Renvoie l'état de la paire (associée ou non)
    bool isAssociee(void);


private:

    /// Indice de la carte dans le memory [0-15]
    int indice;

    /// Indice de la paire dans le memory [0-7]
    int paire;

    /// Etat de la carte [retournée ou pas]
    bool retournee;

    /// Etat de la paire [trouvée ou pas]
    bool associee;
};

/// Classe du modèle
class ModMemory
{
public:
    /// Constructeur et destructeur
    ModMemory();
    ~ModMemory();

    /// Mélanger les cartes dans le vecteur
    /// \details Principe : la vue va associer les cartes
    /// de son vecteur avec celles du modèle en prenant leurs
    /// indices dans leurs vecteurs respectifs, et le modèle va
    /// communiquer les informations des MemoryCards, mélangées donc.
    /// Tout ça pour dire que pas besoin de mélanger ou synchroniser
    /// la vue et le modèle entre eux.
    void shuffleCards(void);

    /// \warning Tous les indices demandés sour forme d'int sont
    /// les indice du vecteur, pas les attributs indices des MemoryCards elles-mêmes

    /// Vérifie si la carte est retournée
    bool cardIsOpen(int&);

    /// Retourner une carte face visible
    /// L'ajoute au vecteur flippedcards
    void openCard(int&);

    /// Retourne les cartes de flippedcards face cachée
    void closeCards(int&);

    /// Vérifier si les cartes appartiennent à la même paire
    bool checkCards(int&, int&);

    /// Indice de la carte
    /// Utile seulement pour le shuffle
    int getIndiceCarte(int&);

    /// Paire de la carte
    int getPaireCarte(int&);

    /// Vérifie si la carte est associée
    bool cardIsPaired(int&);



    // getters

    //setters


private:
    /// Nombre de coups
    /// Le plus petit le mieux
    int score;

    /// Nombre de paires du memory en cours
    int nbPaires;

    /// Nombre de cartes du memory en cours
    int nbCards;

    /// Liste des cartes
    std::vector<MemoryCard> cards;

    /// La liste des cartes retournées
    /// Quand elle a plus de 2 éléments, on enlève les deux
    /// les plus anciens
    std::vector<MemoryCard> flippedCards;



};



#endif // MODMEMORY_H
