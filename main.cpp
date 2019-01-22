#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    // Comment to check Slack interface
    
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QLabel *label = new QLabel("Hello Qt!");
    label->show();

    return a.exec();
}
