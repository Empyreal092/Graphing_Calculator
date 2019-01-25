#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //MainWindow w;
    //w.show();

    QWidget *window = new QWidget;
    window -> setWindowTitle("Main Entry Menu:");

    window->show();

    QLabel *title_prompt = new QLabel("Choose the feature:");
    QPushButton* button_Euler = new QPushButton("Euler's method");
    QPushButton* button_Bisec = new QPushButton("Bisection");
    QPushButton* button_Inter = new QPushButton("Interpolation");

    //QObject::connect(button_Euler, SIGNAL(clicked()), &app, SLOT(quit()));
    QGridLayout *layout = new QGridLayout;
    layout -> addWidget(title_prompt,0,0,Qt::AlignCenter);
    layout -> addWidget(button_Euler,1,0);
    layout -> addWidget(button_Bisec,2,0);
    layout -> addWidget(button_Inter,3,0);

    window->setLayout(layout);

    return app.exec();
}
