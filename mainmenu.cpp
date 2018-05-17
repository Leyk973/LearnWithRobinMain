#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    std::cout << "Creation MainMenu" << std::endl;
    ui->setupUi(this);

    putInShape(ui->buttonCalcul);
    putInShapeWIP(ui->buttonFlags);
    putInShape(ui->buttonMemory);
    putInShapeWIP(ui->buttonPointClick);
    putInShapeWIP(ui->buttonPuzzle);
    putInShape(ui->buttonSimon);
    ui->buttonSimon->setText("SIMON");
    ui->buttonCalcul->setText("MENTAL CALCULATION");
    ui->buttonFlags->setText("FLAGS");
    ui->buttonMemory->setText("MEMORY");
    ui->buttonPointClick->setText("POINT AND CLICK");
    ui->buttonPuzzle->setText("PUZZLE");

    /// \test nouvelle syntaxe connexion signal slot
    QObject::connect(ui->buttonCalcul,&QPushButton::clicked,this,&MainMenu::goForCalcul);
    QObject::connect(ui->buttonSimon,&QPushButton::clicked,this,&MainMenu::goForSimon);
    QObject::connect(ui->buttonMemory,&QPushButton::clicked,this,&MainMenu::goForMemory);

    QObject::connect(ui->buttonPuzzle,&QPushButton::clicked,this,&MainMenu::goForPuzzle);

    std::cout << "Fin Creation MainMenu" << std::endl;
}


void MainMenu::putInShape(QPushButton * but)
{
    but->setFixedSize(500,250);
    but->setFont(QFont("Helvetica",26));
    but->setStyleSheet(QString::fromUtf8(
                           "QPushButton {"
                           "border-image:url(:/files/fondBouton.png);"
                           "}"
                           "QPushButton::pressed {"
                           "border-image:url(:/files/fondBoutonClicked.png);"
                           "}"
                           ));

}

void MainMenu::putInShapeWIP(QPushButton * but)
{
    putInShape(but);
    but->setStyleSheet(QString::fromUtf8(
                           "QPushButton {"
                           "border-image:url(:/files/fondBoutonTravaux.png);"
                           "}"
                           "QPushButton::pressed {"
                           "border-image:url(:/files/fondBoutonTravaux.png);"
                           "}"
                           ));

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

void MainMenu::goForSimon()
{
    std::cout<<"MainMenu::goForSimon()"<<std::endl;
    emit clickedSimon();
}

void MainMenu::goForMemory()
{
    std::cout<<"MainMenu::goForMemory()"<<std::endl;
    emit clickedMemory();
}

void MainMenu::goForPuzzle()
{
    //std::cout << "ENREGISTREMENT TEST GOFORPUZZLE" << std::endl;
    emit clickedPuzzle();
}
