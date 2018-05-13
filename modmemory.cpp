#include "modmemory.h"
#include "commonlibs.h"

/// ModMemory
ModMemory::ModMemory()
{
    std::cout << "Creation ModMemory" << std::endl;
    std::cout << "Fin Creation ModMemory" << std::endl;
}

ModMemory::~ModMemory()
{
    // nothing
}

bool ModMemory::cardIsOpen(int & ind)
{
    return cards.at(ind).isRetournee();
}

void ModMemory::openCard(int & ind)
{
    if(!cards.at(ind).isRetournee())
    {
        cards.at(ind).flipCard();
    }
}

void ModMemory::closeCard(int & ind)
{
    /*if(flippedCards.at(ind).isRetournee())
    {
        flippedCards.at(ind).flipCard();
    }*/

    /// \todo
    /// COMPLETER en retournant les trucs de flipped card
    /// et verifier qu'on ne manipule pas flippedcard dans
    /// les methodes ou l'on devrait manipuler cards
    ///
    /// \todo
    /// arreter d'etre malade


}

bool ModMemory::checkCards(int & ind1, int & ind2)
{
    int pai1 =
}

int ModMemory::getIndiceCarte(int & ind)
{
    return flippedCards.at(ind).getIndice();
}

int ModMemory::getPaireCarte(int & ind)
{
    return flippedCards.at(ind).getPaire();
}

bool ModMemory::cardIsPaired(int & ind)
{
    return flippedCards.at(ind).isAssociee();
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



