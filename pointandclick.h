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
    explicit PointAndClick(QWidget *parent = 0);
    ~PointAndClick();

private:
    Ui::PointAndClick *ui;
};

#endif // POINTANDCLICK_H
