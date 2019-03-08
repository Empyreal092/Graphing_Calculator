#include "helpwindow.h"
#include <QGridLayout>
#include <QTextStream>

helpWindow::helpWindow()
{
    //Reads the instructions text file

    instructionsTextFile = new QFile("C:/Users/fax21/Desktop/UCLA_Classes/PIC_10C/Final_Project/PIC10C_Final_Project-Graphic_Calc/Graphing Calculator Instructions Text File.txt");
    //instructionsTextFile->open("Graphing Calculator Instructions Text File.txt")
    instructionsText = new QLabel;
    instructionsReadLine = new QString;

    if (instructionsTextFile->open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(instructionsTextFile);
        while (!stream.atEnd())
        {
            instructionsReadLine->append(stream.readLine()+"\n");
        }
        instructionsText->setText(*instructionsReadLine);
    }
    instructionsTextFile->close();

    //Creates the help window and the names seen on the help window

    QWidget* new_Help_Window = new QWidget;

    QGridLayout* centerLayout = new QGridLayout; // layout

    new_Help_Window->setStyleSheet("background-color:rgb(200, 220, 250);"); // Menu background is light blue

    //Adds the text file contents to centerLayout;

    centerLayout->addWidget(instructionsText);

    //Sets the centerlayout as the layout for the help window

    new_Help_Window->setWindowTitle("Help Window");

    new_Help_Window->setLayout(centerLayout);

    //Sets the size of the help window

    int x=new_Help_Window->width()*0.7;
    int y=new_Help_Window->height()*0.7;
    new_Help_Window->setMinimumSize(x,y);

    new_Help_Window->show();
}
