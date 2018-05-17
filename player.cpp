#include "player.h"

Player::Player()
{
    name="PlayerOne";
}

void Player::setName(std::string & nam)
{
    name=nam;
}

std::string Player::getName()
{
    return this->name;
}
