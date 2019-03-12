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
 * @brief The file for the main entry of the program.
 *
 * This is the entry window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */

#include "mainwindow/mainwindow.h"
#include "ui_mainwindow.h"
#include "FunctionPlotWindows/functionplot/functionplot.h"
#include "QWidgetInterfaceWindows/diffeqsolver/diffeqsolver.h"
#include "FunctionPlotWindows/twoptrwindow/twoptrwindow.h"
#include "FunctionPlotWindows/ODESolvingMethods/eulermethod/eulermethod.h"
#include "QWidgetInterfaceWindows/creditswindow/creditswindow.h"
#include "FunctionPlotWindows/ODESolvingMethods/RK2method/RK2method.h"
#include "FunctionPlotWindows/ODESolvingMethods/Backeulermethod/Backeulermethod.h"
#include "FunctionPlotWindows/ODESolvingMethods/rk4method/rk4method.h"
#include "FunctionPlotWindows/ODESolvingMethods/trapezoidalmethod/trapezoidalmethod.h"
#include "QWidgetInterfaceWindows/helpwindow/helpwindow.h"
#include "FunctionPlotWindows/graphingwindow/graphingwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    setWindowTitle("Graphing Calculator Main Window"); // set window title

    title1 = new QLabel("Graphing Calculator"); // the first part of title
    title_prompt = new QLabel("Select one of the following features:"); // the prompt
    button_Plot = new QPushButton("Plot Function"); // the plot function button
    button_ODE = new QPushButton("ODE Solver"); // the Euler's method button
    button_2ptr = new QPushButton("Two Point Boundary Value Problem"); // the Bisection window button

    centerlayout = new QGridLayout; // layout
    centerlayout -> addWidget(title1, 0, 0, Qt::AlignCenter); // put objects in the layout
    centerlayout -> addWidget(title_prompt,2,0, Qt::AlignCenter);
    centerlayout -> addWidget(button_Plot,3,0);
    centerlayout -> addWidget(button_ODE,4,0);
    centerlayout -> addWidget(button_2ptr,5,0);

    centerpiece = new QWidget; // set the central widget
    centerpiece->setLayout(centerlayout);
    setCentralWidget(centerpiece);

    // Changes the font size, colors, or boldness of items in the main window
    QFont arialTitle("Arial", 30, QFont::Bold); // Font size underlined and in Arial format
    arialTitle.setUnderline(true);

    title1->setFont(arialTitle); // Set the font style of titles 1 and 2

    title1->setStyleSheet("QLabel { color : purple; }"); // Set the color of titles 1 and 2

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
    centerpiece->setStyleSheet("background-color:rgb(200, 220, 250);"); // Menu background is light blue

    QObject::connect(button_Plot, SIGNAL(clicked()), this, SLOT(MakePlotWindow())); // connect plot window bottom pressed to make the plot function window
    QObject::connect(button_ODE, SIGNAL(clicked()), this, SLOT(MakeODEWindow())); // connect euler button to make euler window when pressed
    QObject::connect(button_2ptr, SIGNAL(clicked()), this, SLOT(Make2ptrcWindow())); // connect bisec button to make bisec window when pressed

    //Changes the size of the mainwindow
    this->setMinimumSize(600,400);

    //Added instructions button, credits button, and sound button in QMenu
    menuBar = new QMenuBar();
    helpMenu = new QMenu("Help?");
    creditsButton = new QMenu("About");
    QMenu* soundMenu = new QMenu("Sound");
    QMenu* licenseMenuButton = new QMenu("License");

    QAction* mute = new QAction("Mute");
    QAction* license = new QAction("License");
    mute->setCheckable(true);
    mute->setChecked(false);

    menuBar->addMenu(helpMenu);
    menuBar->addMenu(creditsButton);
    menuBar->addMenu(soundMenu);
    menuBar->addMenu(licenseMenuButton);

    helpMenu->addAction("Instructions");
    helpMenu->addAction(license);
    creditsButton->addAction("Credits");
    soundMenu->addAction(mute);
    licenseMenuButton->addAction("License");

    // add sound in the window
    sound = new QMediaPlayer;
    QUrl* q = new QUrl("qrc:/Music/Sound/SoftPianoMusic-RoyaltyFree-Summit.mp3");
    sound->setMedia(*q);
    sound->play();

    QObject::connect(creditsButton, SIGNAL(triggered(QAction*)), this, SLOT(MakeCreditsWindow())); // connect credits button to make credits window when pressed
    QObject::connect(license, SIGNAL(triggered()), this, SLOT(MakeCreditsWindow())); // connect credits button to make credits window when pressed
    QObject::connect(helpMenu, SIGNAL(triggered(QAction*)), this, SLOT(MakeHelpWindow())); // connect help button to make help window when pressed    
    QObject::connect(mute, SIGNAL(triggered()), this, SLOT(changeSound())); // connects mute button to mute the sound
    QObject::connect(licenseMenuButton, SIGNAL(triggered(QAction*)), this, SLOT(MakeLicenseWindow())); // connect license button to make license window when pressed

    this->setMenuBar(menuBar);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::MakePlotWindow(){
    GraphingWindow *p_window = new GraphingWindow(); // make the function plot window
    p_window->show(); // show the window
}

void MainWindow::MakeODEWindow()
{
    diffeqsolver* e_window = new diffeqsolver(); // make the euler window
    menuBar = e_window->getodeMenuBar();
    e_window->show(); // show the window
}

void MainWindow::Make2ptrcWindow()
{
    TwoPtrWindow* b_window = new TwoPtrWindow(); // make the bisec window
    menuBar = b_window->getfplotMenuBar();
    b_window->show(); // show the window
}

void MainWindow::MakeCreditsWindow()
{
    QWidget* c_window = new creditsWindow();
    //c_window->show();
}

void MainWindow::MakeHelpWindow()
{
    QWidget* h_window = new helpWindow();
    //h_window->show();
}

void MainWindow::changeSound()
{
    if(soundOn == false) // play sound
    {
        sound->play();
        soundOn = true; // change button
    }
    else // mute sound
    {
        sound->stop();
        soundOn = false; // change button
    }
}
