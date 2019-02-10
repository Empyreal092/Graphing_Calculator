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

 * @file mainwindow.cpp
 * @brief The implimentation file for the entry main window.
 *
 * This is the entry window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functionplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    setWindowTitle("Main Entry Menu:"); // set window title

    title_prompt = new QLabel("Choose the features:"); // the prompt
    button_Plot = new QPushButton("Plot Function"); // the plot function button
    button_Euler = new QPushButton("Euler's method"); // the Euler's method button
    button_Bisec = new QPushButton("Bisection"); // the Bisection window button

    centerlayout = new QGridLayout; // layout
    centerlayout -> addWidget(title_prompt,0,0,Qt::AlignCenter); // put objects in the layout
    centerlayout -> addWidget(button_Plot,1,0);
    centerlayout -> addWidget(button_Euler,2,0);
    centerlayout -> addWidget(button_Bisec,3,0);

    centerpiece = new QWidget; // set the central widget
    centerpiece->setLayout(centerlayout);
    setCentralWidget(centerpiece);

    QObject::connect(button_Plot, SIGNAL(clicked()), this, SLOT(MakePlotWindow())); // connect plot window bottom pressed to make the plot function window
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MakePlotWindow(){
    FunctionPlot *p_window = new FunctionPlot(); // make the function plot window
    p_window->show(); // show the window
}
