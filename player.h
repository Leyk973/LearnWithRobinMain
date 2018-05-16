#ifndef PLAYER_H
#define PLAYER_H
#include "tools.h"

#include "commonlibs.h"
#include "includeviews.h"

class Player
{
public:

    /// \brief Constructeur par défaut
    /// \details Donne le nom "Jean-Jacques" par défaut
    Player();

    /// \brief Saisir le nom du joueur
    void setName(std::string &);

    /// \brief Obtenir le nom du joueur
    std::string getName(void);

private:

    /// \brief Nom du joueur
    std::string name;

};

#endif // PLAYER_H
