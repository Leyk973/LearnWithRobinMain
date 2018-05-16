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
    /// \brief Constructeur et destructeur
    explicit CalculMental(QWidget *parent = nullptr);
    ~CalculMental();

    /// \brief SCORE
    void setScore(QString pScore);
    QString getScore(void);

    /// \obsolete Récupérer les opérandes en lettres
    QString getOpe1(void);
    QString getOpe2(void);

    /// \brief Récupérer l'opérateur
    QString getOperator(void);

    /// \brief Récupérer le résultat de l'expression
    QString getExpRes(void);

    /// \brief Demander un nouveau calcul au modèle
    void askNewCalc(void);

    /// \brief Vérifier le resultat, et s'il est bon ajouter un point et demander un nouveau calcul
    bool checkResult(QString resPropose);

    /// \brief Ajouter un point au score
    void addPoint(void);

    /// \brief Get les opérandes en lettres
    QString getOpe1Str(void);
    QString getOpe2Str(void);

public slots:
    /// \brief Appui sur bouton reset score
    void resetScore();

    /// \brief Appui sur bouton nouveau calcul
    void dispNewCalc();

    /// \brief Appui sur bouton soumettre résultat
    void submitRes();

private:
    /// \brief Interface utilisateur
    Ui::CalculMental *ui;

    /// \brief Modèle
    ModCalcul *modele;
};

#endif // CALCULMENTAL_H
