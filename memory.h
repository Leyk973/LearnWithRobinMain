#ifndef MEMORY_H
#define MEMORY_H


#include <QWidget>
#include <QPainter>
#include <QRect>
#include "includeviews.h"
#include "commonlibs.h"


namespace Ui {
class Memory;
}

class Memory : public QWidget
{
    Q_OBJECT

public:
    explicit Memory(QWidget *parent = 0);
    ~Memory();
    void paintEvent(QPaintEvent*);

    int getNbCards(void);

private:
    Ui::Memory *ui;
    QRect *tabCardRects;

    int nbcards;

};

#endif // MEMORY_H
