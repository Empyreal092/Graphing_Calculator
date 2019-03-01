#include "creditswindow.h"
#include <QLabel>
#include <QGridLayout>

creditsWindow::creditsWindow()
{
    //Creates the credits window and the names seen on the credits window

    QWidget* new_Credits_Window = new QWidget;
    QLabel* name_Ryan = new QLabel("Ryan Du");
    QLabel* name_Anita = new QLabel("Anita Chen");
    QLabel* name_Firat = new QLabel("Firat Taxpulat");
    QLabel* contributors = new QLabel("Contributors:");

    QGridLayout* centerlayout = new QGridLayout; // layout

    //Adds the different widgets to the centerlayout

    centerlayout->addWidget(contributors, 0, 0, Qt::AlignCenter);
    centerlayout->addWidget(name_Ryan, 1, 0, Qt::AlignCenter);
    centerlayout->addWidget(name_Anita, 2, 0, Qt::AlignCenter);
    centerlayout->addWidget(name_Firat, 3, 0, Qt::AlignCenter);

    //Changes the font size for each name on the credits page

    QFont arialFontSize20( "Arial", 20, QFont::Bold);
    QFont arialFontSize45( "Arial", 20, QFont::Bold);

    contributors->setFont(arialFontSize45);
    name_Ryan->setFont(arialFontSize20);
    name_Anita->setFont(arialFontSize20);
    name_Firat->setFont(arialFontSize20);

    //Sets different colors for each name on the credits page

    contributors->setStyleSheet("background-color:rgb(120, 0, 80); " // Plot button is blue
                               "color: white; " // Font is white
                               "border-style: outset; " // Outer border
                               "border-width: 2 px; " // Border is 2 px
                               "border-color: beige; " // Border color is beige
                               "padding: 13 px;"); // Padding is 13 px

    name_Ryan->setStyleSheet("background-color:rgb(60, 70, 30); " // Plot button is blue
                               "color: white; " // Font is white
                               "border-style: outset; " // Outer border
                               "border-width: 2 px; " // Border is 2 px
                               "border-color: beige; " // Border color is beige
                               "padding: 9 px;"); // Padding is 9 px

    name_Anita->setStyleSheet("background-color:rgb(60, 0, 0); " // Plot button is blue
                               "color: white; " // Font is white
                               "border-style: outset; " // Outer border
                               "border-width: 2 px; " // Border is 2 px
                               "border-color: beige; " // Border color is beige
                               "padding: 9 px;"); // Padding is 9 px

    name_Firat->setStyleSheet("background-color:rgb(0, 0, 100); " // Plot button is blue
                               "color: white; " // Font is white
                               "border-style: outset; " // Outer border
                               "border-width: 2 px; " // Border is 2 px
                               "border-color: beige; " // Border color is beige
                               "padding: 9 px;"); // Padding is 9 px

    //Sets the centerlayout as the layout for the credits window

    new_Credits_Window->setWindowTitle("Credits Window");

    new_Credits_Window->setLayout(centerlayout);

    //Sets the size of the credits window

    int x=new_Credits_Window->width()*0.7;
    int y=new_Credits_Window->height()*0.7;
    new_Credits_Window->setFixedSize(x,y);

    new_Credits_Window->show();
}
