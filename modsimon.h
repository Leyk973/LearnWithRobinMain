#ifndef MODSIMON_H
#define MODSIMON_H
#include "commonlibs.h"

class ModSimon
{
public:

    /// \brief Constructeur destructeur
    ModSimon();
    ~ModSimon(void);

    /// \brief Difficulté (de 1 facile à 3 difficile)
    //void setDifficulte(int);

    /// \brief SCORE
    void setScore(int);
    int getScore(void);

    /// \brief LIVES
    /// \details Vérifier quand on la modifie qu'elle ne passe pas en dessous de 0
    void setLives(int);
    int getLives(void);
    void addLife(void);
    void remLife(void);


    /// \brief SEQUENCE
    void setSequence(std::string);
    std::string getSequence(void);

    void setSeqLen(int);
    int getSeqLen(void);

    /// \brief Vérifier la séquence entrée
    bool checkSequence (std::string);

    /// \brief Définir la séquence des couleurs
    void createSequence();

    /// \brief Set le scoreToReach selon la difficulté
    /// \todo implémenter difficulté
    void iniScoreToReach(void);

    int giveRandom(int,int);

private:

    /// \brief Difficulté
    /// \todo implémenter
    // std::string : difficulté

    /// \brief Vies restantes
    int lives;

    /// \brief Séquence actuelle
    std::string sequence;

    /// \brief Longueur de la séquence actuelle
    int seqLen;

    /// \brief Score actuel
    int score;

    /// \brief Score à atteindre
    int scoreToReach;

    /// \brief Conséquences d'une bonne séquence
    void goodSeq(void);

    /// \brief Conséquences d'une mauvaise séquence
    void badSeq(void);

};

#endif // MODSIMON_H
