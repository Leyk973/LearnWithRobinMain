#ifndef TOOLS_H
#define TOOLS_H

#include "commonlibs.h"
#include "includeviews.h"
#include <fstream>

class Tools
{
public:

    /// \brief Enregistrer le score d'un joueur
    /// \param player nom du joueur
    /// \param score score pour le jeu
    /// \param game jeu en question
    static void SavePlayerScoreForGame(std::string player,int score, std::string game);


private:
    Tools();
};

#endif // TOOLS_H
