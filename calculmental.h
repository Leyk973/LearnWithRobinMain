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
    /// Constructeur et destructeur
    explicit CalculMental(QWidget *parent = nullptr);
    ~CalculMental();

    /// SCORE
    void setScore(QString pScore);
    QString getScore(void);

    /// \obsolete Récupérer les opérandes en lettres
    QString getOpe1(void);
    QString getOpe2(void);

    /// Récupérer l'opérateur
    QString getOperator(void);

    /// Récupérer le résultat de l'expression
    QString getExpRes(void);

    /// Demander un nouveau calcul au modèle
    void askNewCalc(void);

    /// Vérifier le resultat, et s'il est bon ajouter un point et demander un nouveau calcul
    bool checkResult(QString resPropose);

    /// Ajouter un point au score
    void addPoint(void);

    /// Get les opérandes en lettres
    QString getOpe1Str(void);
    QString getOpe2Str(void);

public slots:
    /// Appui sur bouton reset score
    void resetScore();

    /// Appui sur bouton nouveau calcul
    void dispNewCalc();

    /// Appui sur bouton soumettre résultat
    void submitRes();

private:
    /// Interface utilisateur
    Ui::CalculMental *ui;

    /// Modèle
    ModCalcul *modele;
};

#endif // CALCULMENTAL_H
