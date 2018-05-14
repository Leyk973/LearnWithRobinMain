#ifndef MODSIMON_H
#define MODSIMON_H
#include "commonlibs.h"

class ModSimon
{
public:

    /// Constructeur destructeur
    ModSimon();
    ~ModSimon(void);

    /// Difficulté (de 1 facile à 3 difficile)
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

    /// Vérifier la séquence entrée
    bool checkSequence (std::string);

    /// Définir la séquence des couleurs
    void createSequence();

    /// Set le scoreToReach selon la difficulté
    /// \todo implémenter difficulté
    void iniScoreToReach(void);

    int giveRandom(int,int);

private:

    /// Difficulté
    /// \todo implémenter
    // std::string : difficulté

    /// Vies restantes
    int lives;

    /// Séquence actuelle
    std::string sequence;

    /// Longueur de la séquence actuelle
    int seqLen;

    /// Score actuel
    int score;

    /// Score à atteindre
    int scoreToReach;

    /// Conséquences d'une bonne séquence
    void goodSeq(void);

    /// Conséquences d'une mauvaise séquence
    void badSeq(void);

};

#endif // MODSIMON_H
