#ifndef SUPERSIMON_H
#define SUPERSIMON_H

#include "includeviews.h"
#include "modsimon.h"

namespace Ui {
class SuperSimon;
}

class SuperSimon : public QWidget
{
    Q_OBJECT
public:
    explicit SuperSimon(QWidget *parent = nullptr);
    ~SuperSimon();

private:
    Ui::SuperSimon *ui;
    ModSimon *modele;
};

#endif // SUPERSIMON_H
