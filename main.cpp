#include "mainwindow.h"
#include "analogclock.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    analogclock clock;
    clock.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    clock.setWindowState(clock.windowState()^Qt::WindowFullScreen);
    clock.show();

    return a.exec();
}
