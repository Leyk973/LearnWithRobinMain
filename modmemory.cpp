#include "modmemory.h"
#include "commonlibs.h"

/// ModMemory
ModMemory::ModMemory()
{
    std::cout << "Creation ModMemory" << std::endl;

    this->nbCartesRestantes=16;
    this->nbCartesRetournees=0;

    for (int i = 0; i < 16 ; ++ i)
    {
        MemoryCard carte;
        cards.push_back(carte);
    }

    shuffleCards();


    std::cout << "Fin Creation ModMemory" << std::endl;
}

ModMemory::~ModMemory()
{
    // nothing
    /// \todo supprimer contenu des vecteurs et les vider
}

void ModMemory::shuffleCards()
{
    // remplissage d'un vecteur contenant les paires
    std::vector<int> vecPaires;

    for (int i = 0; i < 8 ; ++ i)
    {
        vecPaires.push_back(i);
        vecPaires.push_back(i);
    }

    // melange des paires
    std::random_shuffle(vecPaires.begin(), vecPaires.end());

    //attribution des paires de 1 à 7
    for (int i = 0; i < 16; ++i)
    {
        cards.at(i).setPaire(vecPaires.at(i));
    }

}

bool ModMemory::cardIsOpen(int & ind)
{
    return cards.at(ind).isRetournee();
}

void ModMemory::openCard(int & ind)
{
    // verifier si flipped card est rempli
    if (nbCartesRetournees>1)
    {
        std::cout << "clic avec deux cartes ouvertes" <<std::endl;
        closeCards();

        ++score;

        if(!cards.at(ind).isRetournee())
        {
            cards.at(ind).flipCard();
        }
        ++nbCartesRetournees;

        flippedCards.first = ind;

    } else { // si pas rempli
        std::cout << "clic avec zero ou une cartes ouvertes" <<std::endl;
        ++score;

        if(!cards.at(ind).isRetournee())
        {
            cards.at(ind).flipCard();
        }
        ++nbCartesRetournees;

        if (nbCartesRetournees>1)
        {
            flippedCards.second=ind;
            checkFlippedCards();
        } else {
            flippedCards.first=ind;
        }
    }

}

void ModMemory::closeCards()
{
    for(std::vector<MemoryCard>::iterator it = cards.begin(); it != cards.end(); ++it)
    {
        if (it->isRetournee() && !it->isAssociee())
        {
            it->flipCard();
        }
    }

    nbCartesRetournees = 0;
    flippedCards.first=-1;
    flippedCards.second=-1;

    /// \todo
    /// COMPLETER en retournant les trucs de flipped card
    /// et verifier qu'on ne manipule pas flippedcard dans
    /// les methodes ou l'on devrait manipuler cards
    ///
    /// \todo
    /// arreter d'etre malade
}

int ModMemory::getNbCartesRetournees()
{
    return this->nbCartesRetournees;
}

std::pair<int,int> ModMemory::getFlippedCards()
{
    return flippedCards;
}


bool ModMemory::checkFlippedCards()
{
    return checkCards(flippedCards.first,flippedCards.second);
}

int ModMemory::getNbCartesRestantes()
{
    return nbCartesRestantes;
}

int ModMemory::getScore()
{
    return this->score;
}


bool ModMemory::checkCards(int & ind1, int & ind2)
{
    //std::cout << "test asso :" << ind1 << " ET " << ind2 << std::endl;
    int pai1 = cards.at(ind1).getPaire();
    int pai2 = cards.at(ind2).getPaire();

    //std::cout << "les paires sont :" << pai1 << " ET " << pai2 << std::endl;

    if (pai1 == pai2)
    {
        cards.at(ind1).foundCard();
        cards.at(ind2).foundCard();
        nbCartesRestantes--;
        nbCartesRestantes--;
        std::cout << "IL RESTE TANT DE CARTES :::   " << nbCartesRestantes<<std::endl;
        return true;
    } else {
        return false;
    }
}

int ModMemory::getIndiceCarte(int & ind)
{
    return cards.at(ind).getIndice();
}

int ModMemory::getPaireCarte(int & ind)
{
    return cards.at(ind).getPaire();
}

bool ModMemory::cardIsPaired(int & ind)
{
    return cards.at(ind).isAssociee();
}

/// MemoryCard
MemoryCard::MemoryCard()
{
    indice=-1;
    paire=-1;
    retournee=false;
    associee=false;
}

MemoryCard::~MemoryCard()
{
    //nothing
}

/// MemoryCard
MemoryCard::MemoryCard(const MemoryCard &memCop)
{
    indice=memCop.indice;
    paire=memCop.paire;
    retournee=memCop.retournee;
    associee=memCop.associee;
}

MemoryCard::MemoryCard(int& ind, int& pai, bool ret, bool asso)
{
    indice=ind;
    paire=pai;
    retournee=ret;
    associee=asso;
}

void MemoryCard::flipCard()
{
    if (retournee)
    {
        retournee=false;
    } else {
        retournee=true;
    }
}

void MemoryCard::foundCard()
{
    this->associee=true;
}

void MemoryCard::setIndice(int &ind)
{
    this->indice=ind;
}

int MemoryCard::getIndice()
{
    return indice;
}

void MemoryCard::setPaire(int &pai)
{
    paire=pai;
}

int MemoryCard::getPaire()
{
    return paire;
}

bool MemoryCard::isRetournee()
{
    return retournee;
}

bool MemoryCard::isAssociee()
{
    return associee;
}



