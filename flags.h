#ifndef FLAGS_H
#define FLAGS_H

#include <QWidget>
#include "includeviews.h"

namespace Ui {
class Flags;
}

class Flags : public QWidget
{
    Q_OBJECT

public:
    explicit Flags(QWidget *parent = 0);
    ~Flags();

private:
    Ui::Flags *ui;
};

#endif // FLAGS_H
