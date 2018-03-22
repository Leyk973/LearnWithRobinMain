#ifndef MODSIMON_H
#define MODSIMON_H


class ModSimon
{
public:

    /// Constructeur destructeur
    ModSimon();
    ~ModSimon(void);

    /// difficulte (de 1 facile à 3 difficile)
    //void setDifficulte(int);

    /// definir la séquence des couleurs
    /// le parametre est le nombre de clignotements
    void createSequence(int);

private:
    int seqNumbers[];

};

#endif // MODSIMON_H
