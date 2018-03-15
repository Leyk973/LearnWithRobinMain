#ifndef MODCALCUL_H
#define MODCALCUL_H
#include "commonlibs.h"

class ModCalcul
{
public:
    /// Constructeur et destructeur
    ModCalcul(void);
    ModCalcul(const ModCalcul& modToCopy);
    ModCalcul(ModCalcul *modToCopy);
    ~ModCalcul(void);

    /// Possibilités setOperateurs
    enum posSetOp { OPE_ALL, OPE_EASY, OPE_NORM };

    /// Constructeur et initialisation du premier calcul
    ModCalcul(int bmin, int bmax, posSetOp setOpe);

    /// Définir les bornes des chiffres proposés pour la somme
    void setBornes(int bmin, int bmax);

    /// Définir quel set d'opérateurs employer
    /// \todo gérer ça
    /// \param setOp parmi OPE_ALL, OPE_EASY, OPE_NORM
    void iniSetOperateurs(posSetOp setOp);

    /// Creer un calcul
    void iniCalcul(void);

    /// Donner les opérandes
    int getOperande1(void);
    int getOperande2(void);

    /// Donner les min et max
    int getOpeMin(void);
    int getOpeMax(void);

    /// Donner l'opérateur
    std::string getOperateur(void);

    /// Donner le résultat
    int getResult(void);

    /// Verifier le résultat
    bool verifRes(int prop);

    /// Gestion du score (test)
    void resetScore(void);
    int getScore(void);
    void setScore(int nS);
    void onePoint(void);

    /// donner les nombres en toutes lettres
    /// \todo implémenter
    std::string getOpe1Str(void);
    std::string getOpe2Str(void);

private:
    /// Donne un entier aléatoire entre min et max inclus
    int giveRandom(int min,  int max);

    /// Opérateurs disponibles
    /// \todo en faire un tableau de std::string ? initialisé au setOperateurs
    ///  Pour l'instant, on n'autorise que l'addition

    /// bornes pour les opérandes
    int opeMin, opeMax;

    /// Opérandes actuels
    int opeGauche, opeDroite;

    /// Opérateur actuel
    std::string opeActuel;

    /// Résultat actuel
    int resultatAttendu;

    /// \test TEMPORAIRE
    int score;

    /// transformer un int en string (english)
    std::string numToWords(int val);

};

#endif // MODCALCUL_H
