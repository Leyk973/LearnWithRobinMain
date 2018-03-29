#include "calculmental.h"
#include "ui_calculmental.h"

CalculMental::CalculMental(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculMental)
{
    std::cout << "Creation CalculMental" << std::endl;
    ui->setupUi(this);
    modele=new ModCalcul;

    // connecter bouton submit
    QObject::connect(ui->ButtonSubmit, SIGNAL(clicked(bool)),this,SLOT(submitRes()));
    QObject::connect(ui->ButtonNewOpe, SIGNAL(clicked(bool)),this,SLOT(dispNewCalc()));
    QObject::connect(ui->ButtonResetScore, SIGNAL(clicked(bool)),this,SLOT(resetScore()));

    this->dispNewCalc();
    std::cout << "Fin Creation CalculMental" << std::endl;
}

CalculMental::~CalculMental()
{
    std::cout<<"Destruction CalculMental"<<std::endl;
    delete ui;
}

void CalculMental::setScore(QString pScore)
{
    this->modele->setScore(pScore.toInt());
}

QString CalculMental::getScore()
{
    int sco=this->modele->getScore();
    //std::string retScoStr = std::to_string(sco);
    return QString::fromStdString(std::to_string(sco));
}

QString CalculMental::getOpe1()
{
    int ope1=this->modele->getOperande1();
    return QString::fromStdString(std::to_string(ope1));
}

QString CalculMental::getOpe2()
{
    int ope2=this->modele->getOperande2();
    return QString::fromStdString(std::to_string(ope2));
}

QString CalculMental::getOperator()
{
    std::string ope=this->modele->getOperateur();
    return QString::fromStdString(ope);
}

QString CalculMental::getExpRes()
{
    int res=this->modele->getResult();
    return QString::fromStdString(std::to_string(res));
}

bool CalculMental::checkResult(QString resPropose)
{
    bool res=this->modele->verifRes(resPropose.toInt());
    return res;
}

void CalculMental::askNewCalc()
{
    this->modele->iniCalcul();
    //ui->LabNum1->setText(this->getOpe1());
    ui->LabNum1->setText(this->getOpe1Str());
    //ui->LabNum2->setText(this->getOpe2());
    ui->LabNum2->setText(this->getOpe2Str());
    ui->LabOpe->setText(this->getOperator());
    ui->LabResAtt->setText(this->getExpRes());
}

void CalculMental::addPoint()
{
    this->modele->onePoint();
}

QString CalculMental::getOpe1Str()
{
    std::string op1 = this->modele->getOpe1Str();
    return QString::fromStdString(op1);
}

QString CalculMental::getOpe2Str()
{
    std::string op2 = this->modele->getOpe2Str();
    return QString::fromStdString(op2);
}

/// --------------------------------------------------------------------------
/// SLOTS
/// --------------------------------------------------------------------------

void CalculMental::submitRes()
{
    //this->setScore(ui->TextInput->text());
    //ui->LabScore->setText(this->getScore());
    bool goodRes=this->checkResult(ui->TextInput->text());
    if(goodRes)
    {
        this->addPoint();
        ui->LabScore->setText(this->getScore());
        this->askNewCalc();
    }
    else
    {
        // nada
    }
}

void CalculMental::dispNewCalc()
{
    this->askNewCalc();
}

void CalculMental::resetScore()
{
    this->modele->resetScore();
    ui->LabScore->setText(this->getScore());
}
