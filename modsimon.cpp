#include "modsimon.h"

ModSimon::ModSimon()
{
    std::cout << "Creation ModSimon" << std::endl;
    this->lives=3;
    this->score=0;    
    this->seqLen=1;
    this->createSequence();
    this->iniScoreToReach();
    std::cout << "Fin Creation ModSimon" << std::endl;
}

ModSimon::~ModSimon(void)
{
    // nada
    std::cout << "Destruction ModSimon" << std::endl;
}

///
void ModSimon::setScore(int pScore)
{
    this->score=pScore;
}

int ModSimon::getScore()
{
    return this->score;
}

void ModSimon::setLives(int pLives)
{
    this->lives=pLives;
}

int ModSimon::getLives()
{
    return this->lives;
}

void ModSimon::addLife()
{
    ++this->lives;
}

void ModSimon::remLife()
{
    if(this->lives>0)
    {
        --this->lives;
    }
    else
    {
        std::cout << "nan mais t'as plus de vies frere" << std::endl;
    }
}

void ModSimon::setSequence(std::string pSeq)
{
    this->sequence=pSeq;
}

std::string ModSimon::getSequence()
{
    return this->sequence;
}

void ModSimon::setSeqLen(int psn)
{
    this->seqLen=psn;
}

int ModSimon::getSeqLen()
{
    return this->seqLen;
}

bool ModSimon::checkSequence(std::string seqToCheck)
{
    if (seqToCheck==this->sequence)
    {
        this->goodSeq();
        return true;
    }
    else
    {
        this->badSeq();
        return false;
    }
}

void ModSimon::iniScoreToReach()
{
    this->scoreToReach=5;
}

int ModSimon::giveRandom(int min, int max)
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


void ModSimon::createSequence()
{
    //azerty
    int nbBoucles = this->seqLen;
    std::string res="";

    for (int i=0;i<nbBoucles; ++i)
    {
        //std::cout << "nbBoucles : " << nbBoucles << " ET i : " << i << std::endl;
        res.append(std::to_string(this->giveRandom(1,4)));
    }
    std::cout << "la sequence actuelle est " << res << std::endl;
    this->sequence=res;
}

void ModSimon::goodSeq()
{
    this->setScore(this->getScore() + 1);

    /// en cas de victoire
    /// \todo faire des trucs
    if (this->score >= this->scoreToReach) {
        std::cout << "WEEEEEEEEEEE HAAAAAAAAAVE A CHAAAAAAAMPIOOOOOOOOOOOON" << std::endl;
    }
//  else {
    this->setSeqLen(this->getSeqLen() + 1);
    this->createSequence();
    /// \todo completer
//  }
}

void ModSimon::badSeq()
{
    std::cout << "trompage dans la sequencure" << std::endl;
    this->remLife();
    /// \todo completer
}
