#ifndef PUZZLE_H
#define PUZZLE_H

#include <QWidget>

namespace Ui {
class Puzzle;
}

class Puzzle : public QWidget
{
    Q_OBJECT

public:
    /// Constructeur et destructeur
    explicit Puzzle(QWidget *parent = 0);
    ~Puzzle();

private:
    /// Interface utilisateur
    Ui::Puzzle *ui;
};

#endif // PUZZLE_H
