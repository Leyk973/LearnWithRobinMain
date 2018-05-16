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

    /// \brief Mettre en forme un bouton
    void putInShape(QPushButton*);

    /// \brief Mettre en forme un bouton pour travaux
    void putInShapeWIP(QPushButton*);


signals:
    /// \brief Signal pour lancer le jeu calcul mental
    void clickedCalcul(void);

    /// \brief Signal pour lancer le jeu super simon
    void clickedSimon(void);

    /// \brief Signal pour lancer le jeu memory
    void clickedMemory(void);

    /// \brief Signal pour lancer le jeu puzzle
    void clickedPuzzle(void);

public slots:
    /// \note on va garder la syntaxe goFor, c'est bien :)
    /// \brief Appui sur le bouton calcul mental
    void goForCalcul(void);

    /// \brief Appui sur le bouton super simon
    void goForSimon(void);

    /// \brief Appui sur le bouton memory
    void goForMemory(void);

    /// \brief Appui sur puzzle
    /// \test pour l'instant sert à tester la sauvegarde
    void goForPuzzle(void);

private:
    /// \brief Interface utilisateur
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
