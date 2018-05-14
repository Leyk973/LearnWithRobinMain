#ifndef MEMORYADDONS_H
#define MEMORYADDONS_H

#include <QWidget>
#include <QPushButton>
// va contenir les classes des cartes et autre joyeusetés
/// \todo il faudra un générateur de stylesheet efficace

// on va tenir un vecteur de paires <int,std::string> qui fera le lien entre un idPaire et le chemin de la carte correspondante
// l'id 0 contiendra le chemin vers le dos de la carte


class MemoryIndexCards {
    public:

    /// Constructeur à partir d'un fichier csv
    /// \todo implémenter
    MemoryIndexCards(std::string &pathcsv);

};



class MemoryCard: public QPushButton {

public:
    /*MemoryCard();*/

    /// Constructeur
    /// \param pathBackCard chemin vers l'image du dos de la carte
    /// \param pathFlipCard chemin vers l'image de la face de la carte
    /// \param val_pair index de la paire dans le tableau des paires
    MemoryCard(std::string &pathBackCard, std::string &pathFlipCard, int &val_pair);

    /// Destructeur
    ~MemoryCard(void);

    /// Donner l'index de la paire
    int getValuePair(void);

    //

private:

    /// L'id de la paire qui correspond
    int value_pair;

    // image de fond

};


#endif // MEMORYADDONS_H
