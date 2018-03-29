#include "robinmainwindow.h"
#include "ui_robinmainwindow.h"

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
    //RobinMainWindow::setCentralWidget(menuPrincipal);
    QObject::connect(ui->ButtonMenu, &QPushButton::clicked,this,&RobinMainWindow::backToMenu);
    this->atMenu=true;
    /// \test changer la fenetre
    /// on peut tenter vu que QWidget hérite de QObject
    QObject::connect(menuPrincipal,&MainMenu::clickedCalcul,this,&RobinMainWindow::openCalcul);
    QObject::connect(menuPrincipal,&MainMenu::clickedSimon,this,&RobinMainWindow::openSimon);
    QObject::connect(menuPrincipal,&MainMenu::clickedMemory,this,&RobinMainWindow::openMemory);



    Memory * theMemory = new Memory();
    SuperSimon * theSimon = new Simon();
    CalculMental * theCalcul = new CalculMental();

    this->widStack->addWidget(theMemory);
    this->widStack->addWidget(theSimon);
    this->widStack->addWidget(theCalcul);
    this->widStack->addWidget(menuPrincipal);

    RobinMainWindow::setCentralWidget(this->widStack);





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
    std::cout << "openCalcul centralWidget : " << RobinMainWindow::centralWidget() << std::endl;
}

void RobinMainWindow::openSimon()
{
    /// \todo completer
    std::cout << "On a cliqué sur calcul" << std::endl;
    this->atMenu=false;
    deleteCentralWidget();
    SuperSimon * simon = new SuperSimon();
    RobinMainWindow::setCentralWidget(simon);
    std::cout << "openSimon centralWidget : " << RobinMainWindow::centralWidget() << std::endl;

}

void RobinMainWindow::openMemory()
{
    /// \todo completer
    std::cout << "On a cliqué sur memory" << std::endl;
    this->atMenu=false;
    deleteCentralWidget();
    Memory * memus = new Memory();
    RobinMainWindow::setCentralWidget(memus);
    std::cout << "openMemory centralWidget : " << RobinMainWindow::centralWidget() << std::endl;

}

void RobinMainWindow::deleteCentralWidget()
{
    std::cout << "deleteCentralWidget Step 1 : " << RobinMainWindow::centralWidget() << std::endl;
    delete RobinMainWindow::centralWidget();
    std::cout << "deleteCentralWidget Step 2 : " << RobinMainWindow::centralWidget() << std::endl;
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
        std::cout << "DEBUT backToMenu centralWidget : " << RobinMainWindow::centralWidget() << std::endl;
        MainMenu *menuPrincipal = new MainMenu();
        RobinMainWindow::setCentralWidget(menuPrincipal);
        QObject::connect(menuPrincipal,&MainMenu::clickedCalcul,this,&RobinMainWindow::openCalcul);
        QObject::connect(menuPrincipal,&MainMenu::clickedSimon,this,&RobinMainWindow::openSimon);
        QObject::connect(menuPrincipal,&MainMenu::clickedMemory,this,&RobinMainWindow::openMemory);
        this->atMenu=true;
        std::cout << "FIN backToMenu centralWidget : " << RobinMainWindow::centralWidget() << std::endl;
    }
    else
    {
        std::cout << "Deja au menu" << std::endl;
    }
}
