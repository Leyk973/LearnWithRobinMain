#include "modsimon.h"

ModSimon::ModSimon()
{
    this->lives=3;
    this->score=0;
    this->createSequence(1);
    this->seqNum=1;
    this->iniScoreToReach();
}

ModSimon::~ModSimon(void)
{
    // nada
}

