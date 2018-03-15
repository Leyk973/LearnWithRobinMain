#ifndef ROBINMAINWINDOW_H
#define ROBINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class RobinMainWindow;
}

class RobinMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RobinMainWindow(QWidget *parent = 0);
    ~RobinMainWindow();

    /// setter getter
    void setAtMenu(bool am);
    bool getAtMenu(void);

public slots:
    void backToMenu(void);
    void openCalcul(void);
    void openSimon(void);

private:
    Ui::RobinMainWindow *ui;
    bool atMenu;

    /// \warning a manipuler avec precaution
    /// supprime le widget central (le pointeur)
    void deleteCentralWidget(void);


};

#endif // ROBINMAINWINDOW_H
