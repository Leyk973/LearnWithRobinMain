#include "robinmainwindow.h"
#include "ui_robinmainwindow.h"
#include <QIcon>

/// \todo bien penser a connecter les boutons nécessaires quand on charge un widget
/// quand le bouton menu sera passé dans chaque widget notamment

/**
 * @brief RobinMainWindow::RobinMainWindow
 * INDEX des jeux dans le QStackedWidget d'affichage
 * 0 MENU
 * 1 CALCUL
 * 2 SIMON
 * 3 MEMORY
 * 4 FLAGS
 * 5 PUZZLE
 * 6 POINT
 */



RobinMainWindow::RobinMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RobinMainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/files/robin.png"));

    std::cout << "Debut construction MAIN 1" << std::endl;
    MainMenu *menuPrincipal = new MainMenu();

    // joueur
    this->joueurSession = new Player;


    // tentative style bouton menu
    // TEST BOUTON PERSO
    ui->ButtonMenu->setFixedSize(300,50);
    ui->ButtonMenu->setStyleSheet(QString::fromUtf8(
                                      "QPushButton {"
                                      "border-image:url(:/files/boutonMenu.png);"
                                      "}"
                                      "QPushButton::pressed {"
                                      "border-image:url(:/files/boutonMenuClicked.png);"
                                      "}"
                                      ));
    ui->ButtonMenu->setText("");

    ui->ButtonHelp->setFixedSize(300,50);
    ui->ButtonHelp->setStyleSheet(QString::fromUtf8(
                                      "QPushButton {"
                                      "border-image:url(:/files/boutonHelp.png);"
                                      "}"
                                      "QPushButton::pressed {"
                                      "border-image:url(:/files/boutonHelpClicked.png);"
                                      "}"
                                      ));
    ui->ButtonHelp->setText("");


    std::cout << "Debut construction MAIN 2" << std::endl;

    //RobinMainWindow::setCentralWidget(menuPrincipal);
    QObject::connect(ui->ButtonMenu, &QPushButton::clicked,this,&RobinMainWindow::backToMenu);
    this->atMenu=true;

    /// \test changer la fenetre
    /// on peut tenter vu que QWidget hérite de QObject
    QObject::connect(menuPrincipal,&MainMenu::clickedCalcul,this,&RobinMainWindow::openCalcul);
    QObject::connect(menuPrincipal,&MainMenu::clickedSimon,this,&RobinMainWindow::openSimon);
    QObject::connect(menuPrincipal,&MainMenu::clickedMemory,this,&RobinMainWindow::openMemory);


    /// \test test très fort
    QObject::connect(menuPrincipal,&MainMenu::clickedPuzzle,this,&RobinMainWindow::saveScoreTest);




    std::cout << "Debut construction MAIN 3" << std::endl;

    Memory * theMemory = new Memory(this);
    SuperSimon * theSimon = new SuperSimon(this);
    CalculMental * theCalcul = new CalculMental(this);

    std::cout << "Debut construction MAIN 4" << std::endl;

    /// creation widStack
    this->widStack = new QStackedWidget;

    this->widStack->addWidget(menuPrincipal);
    this->widStack->addWidget(theCalcul);
    this->widStack->addWidget(theSimon);
    this->widStack->addWidget(theMemory);




    /// affichage du menu
    this->widStack->setCurrentWidget(menuPrincipal);

    std::cout << "Debut construction MAIN 5" << std::endl;
    RobinMainWindow::setCentralWidget(this->widStack);

    std::cout << "Debut construction MAIN 6" << std::endl;


    std::cout << "L'index est " << this->widStack->currentIndex() << std::endl;

}

RobinMainWindow::~RobinMainWindow()
{
    /// \todo faire une fonction qui vide le widget
    delete widStack;
    delete ui;
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
        //deleteCentralWidget();
        std::cout << "DEBUT backToMenu centralWidget : " << RobinMainWindow::centralWidget() << std::endl;
        //MainMenu *menuPrincipal = new MainMenu();
        //RobinMainWindow::setCentralWidget(menuPrincipal);
        //QObject::connect(menuPrincipal,&MainMenu::clickedCalcul,this,&RobinMainWindow::openCalcul);
        //QObject::connect(menuPrincipal,&MainMenu::clickedSimon,this,&RobinMainWindow::openSimon);
        //QObject::connect(menuPrincipal,&MainMenu::clickedMemory,this,&RobinMainWindow::openMemory);
        this->widStack->setCurrentIndex(0);
        this->atMenu=true;
        std::cout << "FIN backToMenu centralWidget : " << RobinMainWindow::centralWidget() << std::endl;
    }
    else
    {
        std::cout << "Deja au menu" << std::endl;
    }
}


void RobinMainWindow::openCalcul()
{
    /// \todo completer
    std::cout << "On a cliqué sur calcul" << std::endl;
    this->atMenu=false;
    //deleteCentralWidget();
    //CalculMental * calcul = new CalculMental();
    //RobinMainWindow::setCentralWidget(calcul);
    this->widStack->setCurrentIndex(1);
    std::cout << "openCalcul centralWidget : " << RobinMainWindow::centralWidget() << std::endl;
}

void RobinMainWindow::openSimon()
{
    /// \todo completer
    std::cout << "On a cliqué sur calcul" << std::endl;
    this->atMenu=false;
    //deleteCentralWidget();
    //SuperSimon * simon = new SuperSimon();
    //RobinMainWindow::setCentralWidget(simon);
    this->widStack->setCurrentIndex(2);
    std::cout << "openSimon centralWidget : " << RobinMainWindow::centralWidget() << std::endl;

}

void RobinMainWindow::openMemory()
{
    /// \todo completer
    std::cout << "On a cliqué sur memory" << std::endl;
    this->atMenu=false;
    //deleteCentralWidget();
    //Memory * memus = new Memory();
    //RobinMainWindow::setCentralWidget(memus);
    this->widStack->setCurrentIndex(3);
    std::cout << "openMemory centralWidget : " << RobinMainWindow::centralWidget() << std::endl;

}

void RobinMainWindow::saveScoreTest()
{
    Tools::SavePlayerScoreForGame(joueurSession->getName(),42,"LOG4LOG");
}
