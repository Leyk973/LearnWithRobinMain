#ifndef POINTANDCLICK_H
#define POINTANDCLICK_H

#include <QWidget>

namespace Ui {
class PointAndClick;
}

class PointAndClick : public QWidget
{
    Q_OBJECT

public:
    /// \brief Constructeur et destructeur
    explicit PointAndClick(QWidget *parent = 0);
    ~PointAndClick();

private:
    /// \brief Interface utilisateur
    Ui::PointAndClick *ui;
};

#endif // POINTANDCLICK_H
