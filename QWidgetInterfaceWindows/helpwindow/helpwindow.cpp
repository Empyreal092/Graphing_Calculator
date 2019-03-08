#include "QWidgetInterfaceWindows/helpwindow/helpwindow.h"
#include <QGridLayout>
#include <QTextStream>
#include <QScrollArea>
#include <QScrollBar>

helpWindow::helpWindow()
{
    //Reads the instructions text file

    QFile instructionsTextFile("../PIC10C_Final_Project-Graphic_Calc/Graphing_Calculator_Instructions_Text_File.txt");
    //instructionsTextFile->open("Graphing Calculator Instructions Text File.txt")

    instructionsText = new QLabel;
    instructionsReadLine = new QString;

    auto i = instructionsTextFile.exists();

    if (!instructionsTextFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream stream(&instructionsTextFile);
    while (!stream.atEnd()){

        instructionsReadLine->append(stream.readLine()+"\n");
    }
    instructionsText->setText(*instructionsReadLine);

    instructionsTextFile.close();

    //Creates the help window and the names seen on the help window

    QWidget* new_Help_Window = new QWidget;

    QGridLayout* centerLayout = new QGridLayout; // layout

    new_Help_Window->setStyleSheet("background-color:rgb(200, 220, 250);"); // Menu background is light blue

    //Adds the text file contents to centerLayout;

    centerLayout->addWidget(instructionsText);

    //Sets the centerlayout as the layout for the help window

    new_Help_Window->setWindowTitle("Help Window");

    new_Help_Window->setLayout(centerLayout);

    //Adds a scrollbar to the help window

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(instructionsText);
    scrollArea->verticalScrollBar()->setSingleStep(new_Help_Window->width() / 24);

    centerLayout->addWidget(scrollArea);

    //Sets the size of the help window

   new_Help_Window->setMinimumSize(700,900);

    new_Help_Window->show();
}
