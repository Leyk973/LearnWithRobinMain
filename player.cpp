#include "player.h"

Player::Player()
{
    name="Jean-Jacques";
}

void Player::setName(std::string & nam)
{
    name=nam;
}

std::string Player::getName()
{
    return this->name;
}
