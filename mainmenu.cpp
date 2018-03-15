#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    /// \test nouvelle syntaxe connexion signal slot
    QObject::connect(ui->buttonCalcul,&QPushButton::clicked,this,&MainMenu::goForCalcul);
}

MainMenu::~MainMenu()
{
    std::cout<<"Destruction MainMenu"<<std::endl;
    delete ui;
}

void MainMenu::goForCalcul()
{
    std::cout<<"MainMenu::goForCalcul()"<<std::endl;
    emit clickedCalcul();
}
