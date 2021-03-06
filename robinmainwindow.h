#ifndef ROBINMAINWINDOW_H
#define ROBINMAINWINDOW_H

#include <QMainWindow>
#include "mainmenu.h"
#include "calculmental.h"
#include "supersimon.h"
#include "memory.h"
#include "flags.h"
#include <QStackedWidget>
#include "player.h"


namespace Ui {
class RobinMainWindow;
}

class RobinMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// \brief Constructeur et destructeur
    explicit RobinMainWindow(QWidget *parent = 0);
    ~RobinMainWindow();

    /// \brief Getter setter
    void setAtMenu(bool am);
    bool getAtMenu(void);

public slots:
    /// \brief Slot d'attente de fin de jeu
    /// \details Fait apparaitre une popup de récapitulation
    void gameEnded(std::pair<std::string,int> asso);

    /// \brief Signal pour retourner au menu principal
    void backToMenu(void);

    /// \brief Signal pour lancer le calcul mental
    void openCalcul(void);

    /// \brief Signal pour lancer le super simon
    void openSimon(void);

    /// \brief Signal pour lancer le memory
    void openMemory(void);

    /// \brief Sauvegarde de score de test
    void saveScoreTest(void);

    /// \brief Changement de joueur
    void changePlayer(void);
private:
    /// \brief Interface utilisateur
    Ui::RobinMainWindow *ui;

    /// \brief Permet de savoir si l'on est dans le menu ou non
    bool atMenu;

    /// \warning A manipuler avec précaution
    /// \brief Supprime le widget central (le pointeur)
    void deleteCentralWidget(void);

    /// \brief Le stackedWidget qui contient les widgets à afficher
    QStackedWidget * widStack;

    /// \brief Joueur de cette session
    Player * joueurSession;

};

#endif // ROBINMAINWINDOW_H
