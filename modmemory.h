#ifndef MODMEMORY_H
#define MODMEMORY_H

#include "commonlibs.h"
#include <vector>
#include <algorithm>

/// Classe pour les cartes de memory
class MemoryCard
{
public:

    /// \brief Constructeur par défaut
    MemoryCard(void);

    /// \brief Constructeur par copie
    MemoryCard(MemoryCard &);

    /// \brief Constructeur complet
    /// \param 1 indice
    /// \param 2 paire
    /// \param 3 retournee
    /// \param 4 associee
    MemoryCard(int&, int&, bool, bool);

    /// \brief Destructeur
    ~MemoryCard(void);

    /// \brief Inverse l'état retournee de la carte
    void flipCard(void);

    /// \brief Met associee à vrai
    void foundCard(void);

    /// \brief Get-set l'indice d'une carte
    void setIndice(int & ind);
    int getIndice(void);

    /// \brief Get-set une paire
    void setPaire(int & pai);
    int getPaire(void);

    /// \brief Renvoie l'état de la carte (retournée ou non)
    bool isRetournee(void);

    /// \brief Renvoie l'état de la paire (associée ou non)
    bool isAssociee(void);


private:

    /// \brief Indice de la carte dans le memory [0-15]
    int indice;

    /// \brief Indice de la paire dans le memory [0-7]
    int paire;

    /// \brief Etat de la carte [retournée ou pas]
    bool retournee;

    /// \brief Etat de la paire [trouvée ou pas]
    bool associee;
};

///
/// Classe du modèle
///
class ModMemory
{
public:
    ///
    /// \brief Constructeur
    ModMemory();

    /// \brief Destructeur
    ~ModMemory();

    /// \brief Mélanger les cartes dans le vecteur
    /// \details Principe : la vue va associer les cartes
    /// de son vecteur avec celles du modèle en prenant leurs
    /// indices dans leurs vecteurs respectifs, et le modèle va
    /// communiquer les informations des MemoryCards, mélangées donc.
    /// Tout ça pour dire que pas besoin de mélanger ou synchroniser
    /// la vue et le modèle entre eux.
    ///
    /// En somme, le shuffle attribue les paires
    void shuffleCards(void);

    /// \warning Tous les indices demandés sour forme d'int sont
    /// les indice du vecteur, pas les attributs indices des MemoryCards elles-mêmes

    /// \brief Vérifie si la carte est retournée
    bool cardIsOpen(int&);

    /// \brief Retourner une carte face visible
    /// \details L'ajoute a la paire flippedCards
    void openCard(int&);

    /// \brief Retourne les cartes de flippedcards face cachée
    void closeCards(void);

    /// \brief Vérifier si les cartes appartiennent à la même paire
    bool checkCards(int&, int&);

    /// \brief Indice de la carte
    /// \details Utile seulement pour le shuffle
    int getIndiceCarte(int&);

    /// \brief Paire de la carte
    int getPaireCarte(int&);

    /// \brief Vérifie si la carte est associée
    bool cardIsPaired(int&);

    /// \brief Getter
    int getNbCartesRetournees(void);

    /// \brief Getter de la paire de cartes retournées
    std::pair<int,int> getFlippedCards(void);

    /// \brief Pour vérifier les cartes retournées
    bool checkFlippedCards(void);


    /// \brief Getter
    int getNbCartesRestantes(void);



private:
    /// \brief Nombre de coups
    /// \details Le plus petit le mieux
    int score;

    /// \brief Nombre de paires du memory en cours
    int nbPaires;

    /// \brief Nombre de cartes du memory en cours
    int nbCartesRestantes;

    /// \brief Liste des cartes
    std::vector<MemoryCard> cards;

    /// \brief Quantité de cartes retournees
    int nbCartesRetournees;

    /// \brief Indices des cartes retournées
    std::pair<int,int> flippedCards;

};



#endif // MODMEMORY_H
