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
    explicit RobinMainWindow(QWidget *parent = 0);
    ~RobinMainWindow();

    /// setter getter
    void setAtMenu(bool am);
    bool getAtMenu(void);

public slots:
    void backToMenu(void);
    void openCalcul(void);
    void openSimon(void);
    void openMemory(void);

private:
    Ui::RobinMainWindow *ui;
    bool atMenu;

    /// \warning a manipuler avec precaution
    /// supprime le widget central (le pointeur)
    void deleteCentralWidget(void);

    /// le stackedWidget qui contient les widgets à afficher
    QStackedWidget * widStack;

};

#endif // ROBINMAINWINDOW_H
