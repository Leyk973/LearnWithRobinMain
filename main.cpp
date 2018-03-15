#include "robinmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RobinMainWindow w;
    w.show();

    return a.exec();
}
