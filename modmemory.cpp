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
        closeCards();
    }

    ++score;

    if(!cards.at(ind).isRetournee())
    {
        cards.at(ind).flipCard();
    }
    ++nbCartesRetournees;

    if (nbCartesRetournees>1)
    {
        checkFlippedCards();
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

std::pair<> ModMemory::getFlippedCards()
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


bool ModMemory::checkCards(int & ind1, int & ind2)
{
    int pai1 = cards.at(ind1).getPaire();
    int pai2 = cards.at(ind2).getPaire();

    if (pai1 == p2)
    {
        cards.at(ind1).foundCard();
        cards.at(ind2).foundCard();
        nbCartesRestantes-=2;
        return true;
    } else {
        return false;
    }
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

/// MemoryCard
MemoryCard::MemoryCard(MemoryCard & memCop)
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



