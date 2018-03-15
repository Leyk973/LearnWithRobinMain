#include "puzzle.h"
#include "ui_puzzle.h"

Puzzle::Puzzle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Puzzle)
{
    ui->setupUi(this);
}

Puzzle::~Puzzle()
{
    delete ui;
}
