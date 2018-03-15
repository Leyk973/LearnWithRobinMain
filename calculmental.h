#ifndef CALCULMENTAL_H
#define CALCULMENTAL_H

#include "includeviews.h"
#include "modcalcul.h"

namespace Ui {
class CalculMental;
}

class CalculMental : public QWidget
{
    Q_OBJECT
public:
    explicit CalculMental(QWidget *parent = nullptr);
    ~CalculMental();

    void setScore(QString pScore);
    QString getScore(void);
    QString getOpe1(void);
    QString getOpe2(void);
    QString getOperator(void);
    QString getExpRes(void);

    /// demander un nouveau calcul au modèle
    void askNewCalc(void);

    /// verifier le resultat, et s'il est bon ajouter un point et demander un nouveau calcul
    bool checkResult(QString resPropose);

    /// ajouter un point
    void addPoint(void);

    /// demander les mots des nombres
    QString getOpe1Str(void);
    QString getOpe2Str(void);

public slots:
    void resetScore();
    void dispNewCalc();
    void submitRes();

private:
    Ui::CalculMental *ui;
    ModCalcul *modele;
};

#endif // CALCULMENTAL_H
