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

    /// constructeur à partir d'un fichier csv
    /// \todo implémenter
    MemoryIndexCards(std::string &pathcsv);

    /// constructeur pour les exemples

};



class MemoryCard: public QPushButton {

public:
    /*MemoryCard();*/

    /// constructeur
    /// \param pathBackCard chemin vers l'image du dos de la carte
    /// \param pathFlipCard chemin vers l'image de la face de la carte
    /// \param val_pair index de la paire dans le tableau des paires
    MemoryCard(std::string &pathBackCard, std::string &pathFlipCard, int &val_pair);

    ~MemoryCard(void);

    // donner l'index de la carte
    int getValuePair(void);

    //

private:

    // l'id de la paire qui correspond
    int value_pair;

    // image de fond

};


#endif // MEMORYADDONS_H
