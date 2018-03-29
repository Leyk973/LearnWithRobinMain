#include "memory.h"
#include "ui_memory.h"

Memory::Memory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Memory)
{
    std::cout << "Creation Memory" << std::endl;
    ui->setupUi(this);

    this->tabCardRects=new QRect[16];
    std::cout << "Fin Creation Memory" << std::endl;
}

Memory::~Memory()
{
    std::cout<<"Destruction Memory"<<std::endl;
    delete ui;
}

void Memory::paintEvent(QPaintEvent *)
{
    QPainter * myPaint = new QPainter(this);

    myPaint->setBrush(Qt::blue);
}
