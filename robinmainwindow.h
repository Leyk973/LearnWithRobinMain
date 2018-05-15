#ifndef ROBINMAINWINDOW_H
#define ROBINMAINWINDOW_H

#include <QMainWindow>
#include "mainmenu.h"
#include "calculmental.h"
#include "supersimon.h"
#include "memory.h"
#include <QStackedWidget>


namespace Ui {
class RobinMainWindow;
}

class RobinMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// Constructeur et destructeur
    explicit RobinMainWindow(QWidget *parent = 0);
    ~RobinMainWindow();

    /// Getter setter
    void setAtMenu(bool am);
    bool getAtMenu(void);

public slots:
    /// Signal pour retourner au menu principal
    void backToMenu(void);

    /// Signal pour lancer le calcul mental
    void openCalcul(void);

    /// Signal pour lancer le super simon
    void openSimon(void);

    /// Signal pour lancer le memory
    void openMemory(void);

private:
    /// Interface utilisateur
    Ui::RobinMainWindow *ui;

    /// Permet de savoir si l'on est dans le menu ou non
    bool atMenu;

    /// \warning A manipuler avec précaution
    /// Supprime le widget central (le pointeur)
    void deleteCentralWidget(void);

    /// Le stackedWidget qui contient les widgets à afficher
    QStackedWidget * widStack;

};

#endif // ROBINMAINWINDOW_H
