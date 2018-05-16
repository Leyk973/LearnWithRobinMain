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
    /// \brief Constructeur et destructeur
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu(void);

signals:
    /// \brief Signal pour lancer le jeu calcul mental
    void clickedCalcul(void);

    /// \brief Signal pour lancer le jeu super simon
    void clickedSimon(void);

    /// \brief Signal pour lancer le jeu memory
    void clickedMemory(void);

public slots:
    /// \note on va garder la syntaxe goFor, c'est bien :)
    /// \brief Appui sur le bouton calcul mental
    void goForCalcul(void);

    /// \brief Appui sur le bouton super simon
    void goForSimon(void);

    /// \brief Appui sur le bouton memory
    void goForMemory(void);

private:
    /// \brief Interface utilisateur
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
