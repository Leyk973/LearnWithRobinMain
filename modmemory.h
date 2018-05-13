#ifndef MODMEMORY_H
#define MODMEMORY_H

/// classe pour les cartes de memory
class MemoryCard
{
public:

    // constructeur
    MemoryCard(void);

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

    // getters

    //setters


private:
    int score;

    /// nombre de paires du memory en cours
    int nbPaires;

    /// nombre de cartes du memory en cours
    int nbCards;



};



#endif // MODMEMORY_H
