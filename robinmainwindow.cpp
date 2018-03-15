#include "robinmainwindow.h"
#include "ui_robinmainwindow.h"
#include "mainmenu.h"
#include "calculmental.h"
#include "supersimon.h"

/// \todo bien penser a connecter les boutons nécessaires quand on charge un widget
/// quand le bouton menu sera passé dans chaque widget notamment


RobinMainWindow::RobinMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RobinMainWindow)
{
    ui->setupUi(this);

    /// \test
    /// A PRIORI CA MARCHE
    MainMenu *menuPrincipal = new MainMenu();
    RobinMainWindow::setCentralWidget(menuPrincipal);
    QObject::connect(ui->ButtonMenu, &QPushButton::clicked,this,&RobinMainWindow::backToMenu);
    this->atMenu=true;
    /// \test changer la fenetre
    /// on peut tenter vu que QWidget hérite de QObject
    QObject::connect(menuPrincipal,&MainMenu::clickedCalcul,this,&RobinMainWindow::openCalcul);
    QObject::connect(menuPrincipal,&MainMenu::clickedSimon,this,&RobinMainWindow::openSimon);
}

RobinMainWindow::~RobinMainWindow()
{
    delete ui;
}



void RobinMainWindow::openCalcul()
{
    /// \todo completer
    std::cout << "On a cliqué sur calcul" << std::endl;
    this->atMenu=false;
    deleteCentralWidget();
    CalculMental * calcul = new CalculMental();
    RobinMainWindow::setCentralWidget(calcul);
}

void RobinMainWindow::openSimon()
{
    /// \todo completer
    std::cout << "On a cliqué sur calcul" << std::endl;
    this->atMenu=false;
    deleteCentralWidget();
    SuperSimon * simon = new SuperSimon();
    RobinMainWindow::setCentralWidget(simon);

}

void RobinMainWindow::deleteCentralWidget()
{
    delete RobinMainWindow::centralWidget();
}

void RobinMainWindow::setAtMenu(bool am)
{
    this->atMenu=am;
}

bool RobinMainWindow::getAtMenu()
{
    return this->atMenu;
}


/// ------------------------------------------------------------------
/// SLOTS
/// ------------------------------------------------------------------


/// \todo bien penser a reconnecter tout
void RobinMainWindow::backToMenu()
{
    std::cout << "On a cliqué sur Menu" << std::endl;
    if (!atMenu)
    {
        deleteCentralWidget();
        MainMenu *menuPrincipal = new MainMenu();
        RobinMainWindow::setCentralWidget(menuPrincipal);
        QObject::connect(menuPrincipal,&MainMenu::clickedCalcul,this,&RobinMainWindow::openCalcul);
        QObject::connect(menuPrincipal,&MainMenu::clickedSimon,this,&RobinMainWindow::openSimon);
        this->atMenu=true;
    }
    else
    {
        std::cout << "Deja au menu" << std::endl;
    }
}
