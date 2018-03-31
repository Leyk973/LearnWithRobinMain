#include "modcalcul.h"

/// Constructeur et destructeur
ModCalcul::ModCalcul()
{
    std::cout << "Creation ModCalcul" << std::endl;
    srand(time(NULL));
    opeMin=0; opeMax=150;
    opeGauche=1; opeDroite=1;
    opeActuel="+";
    resultatAttendu=2;
    score=0;
    std::cout << "Fin Creation ModCalcul" << std::endl;
}

/// \note ne va probablement pas être vraiment utilisé
ModCalcul::ModCalcul(const ModCalcul& modToCopy)
{
    srand(time(NULL));
    this->opeMin=modToCopy.opeMin;
    this->opeMax=modToCopy.opeMax;
    this->opeGauche=modToCopy.opeGauche;
    this->opeDroite=modToCopy.opeDroite;
    this->opeActuel=modToCopy.opeActuel;
    this->resultatAttendu=modToCopy.resultatAttendu;
    this->score=modToCopy.score;
}

/// \note probablement pas non plus
ModCalcul::ModCalcul(ModCalcul *ptrMod)
{
    srand(time(NULL));
    this->opeMin=ptrMod->getOpeMin();
    this->opeMax=ptrMod->getOpeMax();
    this->opeGauche=ptrMod->getOperande1();
    this->opeDroite=ptrMod->getOperande2();
    this->opeActuel=ptrMod->getOperateur();
    this->resultatAttendu=ptrMod->getResult();
    this->score=ptrMod->getScore();
}

ModCalcul::~ModCalcul()
{
    std::cout<<"Destruction ModCalcul"<<std::endl;
}


#if 0
// Randomiser des choses
int iSecret;

/* initialize random seed: */
srand (time(NULL));

/* generate secret number between 12 and 167: */
iSecret = rand() % 167 + 12;
#endif

int ModCalcul::giveRandom(int min, int max)
{
    //srand (time(NULL));
    int res;
    if (min <= max) {
        res = rand() % max + min;
    } else {
        res = rand() % min + max;
    }

    return res;
}

/// Constructeur et initialisation du premier calcul
ModCalcul::ModCalcul(int bmin, int bmax, posSetOp setOpe)
{
    opeMin=bmin; opeMax=bmax;
    opeGauche=this->giveRandom(opeMin,opeMax);
    opeDroite=this->giveRandom(opeMin,opeMax);
    if (setOpe!=OPE_ALL){
        opeActuel="+";
    }
    else
    {
        opeActuel="+";
    }

    resultatAttendu=opeGauche+opeDroite;
    score=0;
}

/// Définir les bornes des chiffres proposés pour la somme
void ModCalcul::setBornes(int bmin, int bmax)
{
    opeMin=bmin; opeMax=bmax;
}

/// Définir quel set d'opérateurs employer
/// \todo gérer ça
/// \param setOp parmi OPE_ALL, OPE_EASY, OPE_NORM
void ModCalcul::iniSetOperateurs(posSetOp setOp)
{
    // rien nada keutchy
}

/// Creer un calcul
void ModCalcul::iniCalcul(void)
{
    opeGauche=this->giveRandom(opeMin,opeMax);
    // std::cout << "OPE GAUCHE" << opeGauche << std::endl;
    opeDroite=this->giveRandom(opeMin,opeMax);
    // std::cout << "OPE DROITE" << opeDroite << std::endl;
    opeActuel="+";
    resultatAttendu=opeGauche+opeDroite;
}

/// Donner les opérandes
int ModCalcul::getOperande1(void)
{
    return opeGauche;
}

int ModCalcul::getOperande2(void)
{
    return opeDroite;
}

int ModCalcul::getOpeMin()
{
    return opeMin;
}

int ModCalcul::getOpeMax()
{
    return opeMax;
}

/// Donner l'opérateur
std::string ModCalcul::getOperateur(void)
{
    return opeActuel;
}

/// Donner le résultat
int ModCalcul::getResult(void)
{
    return resultatAttendu;
}

/// Gestion du score (test)
void ModCalcul::resetScore(void)
{
    score = 0;
}

int ModCalcul::getScore(void)
{
    return score;
}

void ModCalcul::setScore(int nS)
{
    score = nS;
}

void ModCalcul::onePoint(void)
{
    ++score;
}



/// Verification du résultat
bool ModCalcul::verifRes(int prop)
{
    if (prop == resultatAttendu)
    {
        return true;
    } else {
        return false;
    }
}

std::string ModCalcul::getOpe1Str()
{
    std::string op1 = this->numToWords(this->opeGauche);
    return op1;
}

std::string ModCalcul::getOpe2Str()
{
    std::string op2 = this->numToWords(this->opeDroite);
    return op2;
}


std::string ModCalcul::numToWords(int val)
{
    const char * const ones[20] = {"zero", "one", "two", "three","four","five","six","seven",
    "eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
    "eighteen","nineteen"};
    const char * const tens[10] = {"", "ten", "twenty", "thirty","forty","fifty","sixty","seventy",
    "eighty","ninety"};

    std::string res="";

    if(val<0)
    {
        res="minus ";
        res.append(this->numToWords(-val));
    }
    else if(val >= 1000)
    {
        res.append(this->numToWords(val/1000));
        res.append(" thousand");
        if(val % 1000)
        {
            if(val % 1000 < 100)
            {
                res.append(" and");
            }
            res.append(" ");
            res.append(this->numToWords(val % 1000));
        }
    }
    else if(val >= 100)
    {
        res.append(this->numToWords(val / 100));
        res.append(" hundred");
        if (val % 100)
        {
            res.append(" and ");
            res.append(this->numToWords(val % 100));
        }
    }
    else if(val >= 20)
    {
        res.append(tens[val / 10]);
        if(val % 10)
        {
            res.append(" ");
            res.append(numToWords(val % 10));
        }
    }
    else
    {
        res.append(ones[val]);
    }
    return res;
}


/// NUMBERS TO WORDS
/// \author pr6989 - StackOverflow
/// \link https://stackoverflow.com/a/13579961
#if 0
#include<iostream>
using namespace std;
void expand(int);
int main()
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    expand(num);
}
void expand(int value)
{
    const char * const ones[20] = {"zero", "one", "two", "three","four","five","six","seven",
    "eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
    "eighteen","nineteen"};
    const char * const tens[10] = {"", "ten", "twenty", "thirty","forty","fifty","sixty","seventy",
    "eighty","ninety"};

    if(value<0)
    {
        cout<<"minus ";
        expand(-value);
    }
    else if(value>=1000)
    {
        expand(value/1000);
        cout<<" thousand";
        if(value % 1000)
        {
            if(value % 1000 < 100)
            {
                cout << " and";
            }
            cout << " " ;
            expand(value % 1000);
        }
    }
    else if(value >= 100)
    {
        expand(value / 100);
        cout<<" hundred";
        if(value % 100)
        {
            cout << " and ";
            expand (value % 100);
        }
    }
    else if(value >= 20)
    {
        cout << tens[value / 10];
        if(value % 10)
        {
            cout << " ";
            expand(value % 10);
        }
    }
    else
    {
        cout<<ones[value];
    }
    return;
}


#endif

