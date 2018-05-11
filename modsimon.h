#ifndef MODSIMON_H
#define MODSIMON_H
#include "commonlibs.h"

class ModSimon
{
public:

    /// Constructeur destructeur
    ModSimon();
    ~ModSimon(void);

    /// difficulte (de 1 facile à 3 difficile)
    //void setDifficulte(int);

    /// SCORE
    void setScore(int);
    int getScore(void);

    ///LIVES
    /// Vérifier quand on la modifie qu'elle ne passe pas en dessous de 0
    void setLives(int);
    int getLives(void);
    void addLife(void);
    void remLife(void);


    /// SEQUENCE
    void setSequence(std::string);
    std::string getSequence(void);

    void setSeqLen(int);
    int getSeqLen(void);

    /// verifier séquence entrée
    bool checkSequence (std::string);

    /// definir la séquence des couleurs
    /// le parametre est le nombre de clignotements
    void createSequence();

    /// set le scoreToReach selon la difficulté
    /// \todo implémenter difficulté
    void iniScoreToReach(void);

    int giveRandom(int,int);

private:

    /// difficulté
    /// \todo implémenter
    // std::string : difficulté

    /// remaining lives
    int lives;

    /// current sequence
    std::string sequence;

    /// current sequence length
    int seqLen;

    /// score
    int score;

    /// score à atteindre
    int scoreToReach;

    /// consequences of good sequence
    void goodSeq(void);

    /// consequences of bad sequence
    void badSeq(void);

};

#endif // MODSIMON_H
