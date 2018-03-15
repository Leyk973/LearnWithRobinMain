#ifndef MAINMENU_H
#define MAINMENU_H

#include "includeviews.h"
#include "commonlibs.h"

namespace Ui {
    class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu(void);

signals:
    void clickedCalcul(void);
    void clickedSimon(void);

public slots:
    /// \note on va garder la syntaxe goFor, c'est bien :)
    void goForCalcul(void);
    void goForSimon(void);

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
