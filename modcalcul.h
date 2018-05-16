#ifndef MODCALCUL_H
#define MODCALCUL_H
#include "commonlibs.h"

class ModCalcul
{
public:
    /// \brief Constructeur et destructeur
    ModCalcul(void);
    ModCalcul(const ModCalcul& modToCopy);
    ModCalcul(ModCalcul *modToCopy);
    ~ModCalcul(void);

    /// \brief Possibilités setOperateurs
    enum posSetOp { OPE_ALL, OPE_EASY, OPE_NORM };

    /// \brief Constructeur et initialisation du premier calcul
    ModCalcul(int bmin, int bmax, posSetOp setOpe);

    /// \brief Définir les bornes des chiffres proposés pour la somme
    void setBornes(int bmin, int bmax);

    /// \brief Définir quel set d'opérateurs employer
    /// \todo gérer ça
    /// \param setOp parmi OPE_ALL, OPE_EASY, OPE_NORM
    void iniSetOperateurs(posSetOp setOp);

    /// \brief Créer un calcul
    void iniCalcul(void);

    /// \brief Donner les opérandes
    int getOperande1(void);
    int getOperande2(void);

    /// \brief Donner les min et max
    int getOpeMin(void);
    int getOpeMax(void);

    /// \brief Donner l'opérateur
    std::string getOperateur(void);

    /// \brief Donner le résultat
    int getResult(void);

    /// \brief Verifier le résultat
    bool verifRes(int prop);

    /// \brief Gestion du score
    void resetScore(void);
    int getScore(void);
    void setScore(int nS);
    void onePoint(void);

    /// \brief Donner les nombres en toutes lettres
    /// \todo implémenter
    std::string getOpe1Str(void);
    std::string getOpe2Str(void);

private:
    /// \brief Donne un entier aléatoire entre min et max inclus
    int giveRandom(int min,  int max);

    /// \brief Opérateurs disponibles
    /// \todo en faire un tableau de std::string ? initialisé au setOperateurs
    /// \details Pour l'instant, on n'autorise que l'addition

    /// \brief Bornes pour les opérandes
    int opeMin, opeMax;

    /// \brief Opérandes actuels
    int opeGauche, opeDroite;

    /// \brief Opérateur actuel
    std::string opeActuel;

    /// \brief Résultat actuel
    int resultatAttendu;

    /// \test TEMPORAIRE
    int score;

    /// \brief Transformer un int en string (english)
    std::string numToWords(int val);

};

#endif // MODCALCUL_H
