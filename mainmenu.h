#ifndef MAINMENU_H
#define MAINMENU_H

#include "includeviews.h"
#include "commonlibs.h"

namespace Ui {
    class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    /// Constructeur et destructeur
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu(void);

signals:
    /// Signal pour lancer le jeu calcul mental
    void clickedCalcul(void);

    /// Signal pour lancer le jeu super simon
    void clickedSimon(void);

    /// Signal pour lancer le jeu memory
    void clickedMemory(void);

public slots:
    /// \note on va garder la syntaxe goFor, c'est bien :)
    /// Appui sur le bouton calcul mental
    void goForCalcul(void);

    /// Appui sur le bouton super simon
    void goForSimon(void);

    /// Appui sur le bouton memory
    void goForMemory(void);

private:
    /// Interface utilisateur
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
