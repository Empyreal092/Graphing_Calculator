/**
 * This file is part of PIC 10C Final Project - A Graphic Calculator.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.

 * We declare that this work is our own.
 * We did this work honestly and can fully stand behind everything that we have written.
 * We did not copy code from anyone, student or otherwise, expect files we downloaded and have the permission to use.
 * We pledge that we have neither given nor received unauthorized assistance on making this project.

 * @file helpwindow.cpp
 * @brief The implimentation file for the Two Point problem solver window.
 *
 * This is the Two Point problem solver window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs
 */

#include "QWidgetInterfaceWindows/helpwindow/helpwindow.h"
#include <QGridLayout>
#include <QTextStream>
#include <QScrollArea>
#include <QScrollBar>

helpWindow::helpWindow()
{
    // Reads the instructions text file
    QFile instructionsTextFile(":/Instructions/FinalGraphingCalculatorInstructions.txt");

    instructionsText = new QLabel;
    instructionsReadLine = new QString;

    if (!instructionsTextFile.open(QIODevice::ReadOnly | QIODevice::Text)) // if cannot readfile, end
        return;

    QTextStream stream(&instructionsTextFile); // read the file onw line at a time
    while (!stream.atEnd()){

        instructionsReadLine->append(stream.readLine()+"\n");
    }
    instructionsText->setText(*instructionsReadLine);

    instructionsTextFile.close(); // close the file

    // Creates the help window and the names seen on the help window
    QWidget* new_Help_Window = new QWidget;

    QGridLayout* centerLayout = new QGridLayout; // layout

    new_Help_Window->setStyleSheet("background-color:rgb(200, 220, 250);"); // Menu background is light blue

    // Adds the text file contents to centerLayout;
    centerLayout->addWidget(instructionsText);
    // Set title
    new_Help_Window->setWindowTitle("Help Window");
    // Sets the centerlayout as the layout for the help window
    new_Help_Window->setLayout(centerLayout);

    // Adds a scrollbar to the help window
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(instructionsText);
    scrollArea->verticalScrollBar()->setSingleStep(new_Help_Window->width() / 24);

    centerLayout->addWidget(scrollArea);

    // Sets the size of the help window
    new_Help_Window->setMinimumSize(700,900);

    new_Help_Window->show();
}
