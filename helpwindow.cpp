#include "helpwindow.h"
#include <QLabel>
#include <QGridLayout>

helpWindow::helpWindow()
{
    //Creates the help window and the names seen on the help window

    QWidget* new_Help_Window = new QWidget;

    QGridLayout* centerlayout = new QGridLayout; // layout

    new_Help_Window->setStyleSheet("background-color:rgb(200, 220, 250);"); // Menu background is light blue

    //Sets the centerlayout as the layout for the help window

    new_Help_Window->setWindowTitle("Help Window");

    new_Help_Window->setLayout(centerlayout);

    //Sets the size of the help window

    int x=new_Help_Window->width()*0.7;
    int y=new_Help_Window->height()*0.7;
    new_Help_Window->setFixedSize(x,y);

    new_Help_Window->show();
}
