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
#include "diffeqsolver.h"
#include "twoptrwindow.h"
#include "eulermethod.h"
#include "creditswindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    setWindowTitle("Main Entry Menu:"); // set window title

    title1 = new QLabel("Differential Equations"); // the first part of title
    title2 = new QLabel("Solver"); // the second part of title
    title_prompt = new QLabel("Select one of the following features:"); // the prompt
    button_Plot = new QPushButton("Plot Function"); // the plot function button
    button_ODE = new QPushButton("ODE Solver"); // the Euler's method button
    button_2ptr = new QPushButton("Two Point Boundary Value Problem"); // the Bisection window button
    credits_button = new QPushButton("Credits"); // the credits button

    centerlayout = new QGridLayout; // layout
    centerlayout -> addWidget(title1, 0, 0, Qt::AlignCenter); // put objects in the layout
    centerlayout -> addWidget(title2, 1, 0, Qt::AlignCenter);
    centerlayout -> addWidget(title_prompt,2,0, Qt::AlignCenter);
    centerlayout -> addWidget(button_Plot,3,0);
    centerlayout -> addWidget(button_ODE,4,0);
    centerlayout -> addWidget(button_2ptr,5,0);
    centerlayout -> addWidget(credits_button, 6, 0);

    centerpiece = new QWidget; // set the central widget
    centerpiece->setLayout(centerlayout);
    setCentralWidget(centerpiece);

    // Changes the font size, colors, or boldness of items in the main window

    QFont arialTitle( "Arial", 30, QFont::Bold); // Font size underlined and in Arial format
    arialTitle.setUnderline(true);

    title1->setFont(arialTitle); // Set the font style of titles 1 and 2
    title2->setFont(arialTitle);

    title1->setStyleSheet("QLabel { color : purple; }"); // Set the color of titles 1 and 2
    title2->setStyleSheet("QLabel { color : purple; }");

    title_prompt->setStyleSheet("font:bold"); // Prompt bold font
    button_Plot->setStyleSheet("background-color:rgb(45, 75, 190); " // Plot button is blue
                               "color: white; " // Font is white
                               "border-style: outset; " // Outer border
                               "border-width: 2 px; " // Border is 2 px
                               "border-color: beige; " // Border color is beige
                               "padding: 6 px;"); // Padding is 6 px
    button_ODE->setStyleSheet("background-color:rgb(20, 90, 15); " // Euler button is green
                                "color: white; " // Font is white
                                "border-style: outset; " // Outer border
                                "border-width: 2 px; " // Border is 2 px
                                "border-color: beige; " // Border color is beige
                                "padding: 6 px"); // Padding is 6 px
    button_2ptr->setStyleSheet("background-color:rgb(60, 70, 100); " // Bisec button is navy
                                "color: white; " // Font is white
                                "border-style: outset; " // Outer border
                                "border-width: 2 px; " // Border is 2 px
                                "border-color: beige; " // Border color is beige
                                "padding: 6 px;"); // Padding is 6 px
    credits_button->setStyleSheet("background-color:rgb(90, 40, 20); " // Credits button is dark red
                                  "color: white; " // Font is white
                                  "border-style: outset; " // Outer border
                                  "border-width: 2 px; " // Border is 2 px
                                  "border-color: beige; " // Border color is beige
                                  "padding: 6 px"); // Padding is 6 px
    centerpiece->setStyleSheet("background-color:rgb(200, 220, 250);"); // Menu background is light blue

    QObject::connect(button_Plot, SIGNAL(clicked()), this, SLOT(MakePlotWindow())); // connect plot window bottom pressed to make the plot function window
    QObject::connect(button_ODE, SIGNAL(clicked()), this, SLOT(MakeODEWindow())); // connect euler button to make euler window when pressed
    QObject::connect(button_2ptr, SIGNAL(clicked()), this, SLOT(Make2ptrcWindow())); // connect bisec button to make bisec window when pressed
    QObject::connect(credits_button, SIGNAL(clicked()), this, SLOT(MakeCreditsWindow())); // connect credits button to make credits window when pressed

    //Changes the size of the mainwindow

    int x=centerpiece->width()*1.1;
    int y=centerpiece->height()*1.1;
    centerpiece->setFixedSize(x,y);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MakePlotWindow(){
    FunctionPlot *p_window = new FunctionPlot(); // make the function plot window
    p_window->show(); // show the window
}

void MainWindow::MakeODEWindow()
{
    QWidget* e_window = new EulerMethod(); // make the euler window
    e_window->show(); // show the window
}

void MainWindow::Make2ptrcWindow()
{
    QWidget* b_window = new TwoPtrWindow(); // make the bisec window
    b_window->show(); // show the window
}

void MainWindow::MakeCreditsWindow()
{
    QWidget* c_window = new creditsWindow();
    //c_window->show();
}
