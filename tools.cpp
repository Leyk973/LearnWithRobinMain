#include "tools.h"

Tools::Tools()
{
    // nothing
}

void Tools::SavePlayerScoreForGame(std::string player, int score, std::string game)
{
    std::string nomFichier;
    nomFichier=player;
    nomFichier+=".scoreLWR";

    time_t temps;
    struct tm datetime;
    char dateFormatee[32];

    time(&temps);
    datetime = *localtime(&temps);

    // recupération de la date en format correct
    strftime(dateFormatee, 32, "%d/%m/%Y-%H:%M", &datetime);

    std::ofstream fichierJoueur(nomFichier.c_str(),std::ios::out | std::ios::app);

    if (fichierJoueur)
    {
        std::cout << "ENREGISTREMENT EN COURS" << std::endl;
        fichierJoueur << game << "_::_" << score << "_::_" << dateFormatee << std::endl;
        fichierJoueur.close();
    } else {
        std::cerr << "probleme ouverture fichier joueur" << std::endl;
    }


}
