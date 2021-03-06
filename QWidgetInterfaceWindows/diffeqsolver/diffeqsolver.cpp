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

 * @file diffeqsolver.cpp
 * @brief The implimentation file for the ODE solver window.
 *
 * This is the ODE solver window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */

#include "QWidgetInterfaceWindows/diffeqsolver/diffeqsolver.h"

diffeqsolver::diffeqsolver(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("Euler's Method");

    // Creates the widgets for each method
    myEulerMethod = new EulerMethod;
    myBackEulerMethod = new BackEulerMethod;
    myRK2Method = new RK2method;
    myRK4Method = new RK4method;
    myTrapezoidalMethod = new TrapezoidalMethod;

    // Adds the method pages to the solverStackedWidget
    solverStackedWidget = new QStackedWidget;
    solverStackedWidget->addWidget(myEulerMethod); // Page 0
    solverStackedWidget->addWidget(myBackEulerMethod); // Page 1
    solverStackedWidget->addWidget(myRK2Method); // Page 2
    solverStackedWidget->addWidget(myRK4Method); // Page 3
    solverStackedWidget->addWidget(myTrapezoidalMethod); // Page 4

    // Adds the solverStackedWidget to the layout
    menuLayout = new QGridLayout;
    menuLayout->addWidget(solverStackedWidget,0,0);

    // Creates new menus odeSolver and helpButtonODE in new menu bar odeMenuBar
    odeMenuBar = new QMenuBar;
    helpButtonODE = new QMenu("Help?");
    odeSolver = new QMenu("Method Selection");
    odeMenuBar->addMenu(odeSolver);
    odeMenuBar->addMenu(helpButtonODE);
    odeMenuBar->setStyleSheet("background-color:rgb(240, 240, 240);");

    //Sets the sound menu button
    soundMenuButtonODE = new QMenu("Sound");

    mute = new QAction("Mute");
    mute->setCheckable(true);
    mute->setChecked(false);
    odeMenuBar->addMenu(soundMenuButtonODE);
    soundMenuButtonODE->addAction(mute);

    QObject::connect(mute, SIGNAL(triggered()), myEulerMethod, SLOT(muteErrorSound())); // connects mute button to mute the error sound
    QObject::connect(mute, SIGNAL(triggered()), myBackEulerMethod, SLOT(muteErrorSound())); // connects mute button to mute the error sound
    QObject::connect(mute, SIGNAL(triggered()), myRK2Method, SLOT(muteErrorSound())); // connects mute button to mute the error sound
    QObject::connect(mute, SIGNAL(triggered()), myRK4Method, SLOT(muteErrorSound())); // connects mute button to mute the error sound
    QObject::connect(mute, SIGNAL(triggered()), myTrapezoidalMethod, SLOT(muteErrorSound())); // connects mute button to mute the error sound

    // Creates the actions for each solving method and sets the checkmark
    eul = new QAction("Euler's Method");
    eul->setCheckable(true);
    backEul = new QAction("Backward Euler Method");
    backEul->setCheckable(true);
    rk2 = new QAction("2nd Order Runge-Kutta Method");
    rk2->setCheckable(true);
    rk4 = new QAction("4th Order Runge-Kutta Method");
    rk4->setCheckable(true);
    trap = new QAction("Trapezoidal Method");
    trap->setCheckable(true);

    // Adds the actions to a methodsGroup so only one method is checked at a time
    methodsGroup = new QActionGroup(this);
    methodsGroup->addAction(eul);
    methodsGroup->addAction(backEul);
    methodsGroup->addAction(rk2);
    methodsGroup->addAction(rk4);
    methodsGroup->addAction(trap);
    eul->setChecked(true);

    // Adds the actions to the odeSolver menu
    odeSolver->addAction(eul);
    odeSolver->addAction(backEul);
    odeSolver->addAction(rk2);
    odeSolver->addAction(rk4);
    odeSolver->addAction(trap);

    helpButtonODE->addAction("Instructions");

    // Connects each action to its method page
    QObject::connect(eul, SIGNAL(triggered()), this, SLOT(goToMethod0()));
    QObject::connect(backEul, SIGNAL(triggered()), this, SLOT(goToMethod1()));
    QObject::connect(rk2, SIGNAL(triggered()), this, SLOT(goToMethod2()));
    QObject::connect(rk4, SIGNAL(triggered()), this, SLOT(goToMethod3()));
    QObject::connect(trap, SIGNAL(triggered()), this, SLOT(goToMethod4()));

    QObject::connect(helpButtonODE, SIGNAL(triggered(QAction*)), this, SLOT(MakeHelpWindow()));

    // Sets the menu bar to odeMenuBar
    menuLayout->setMenuBar(odeMenuBar);

    setLayout(menuLayout);
    menuLayout->setMargin(0);

    // set minimum size but show maximized
    this->setMinimumSize(1080,900);
    showMaximized();
}

void diffeqsolver::goToMethod0()
{
    // go to Euler Method window
    solverStackedWidget->setCurrentIndex(0);
    setWindowTitle("Euler's Method");
}


void diffeqsolver::goToMethod1()
{
    // go to Backward Euler Method window
    solverStackedWidget->setCurrentIndex(1);
    setWindowTitle("Backward Euler Method");
}


void diffeqsolver::goToMethod2()
{
    // go to RK2 Method window
    solverStackedWidget->setCurrentIndex(2);
    setWindowTitle("2nd Order Runge-Kutta Method");
}


void diffeqsolver::goToMethod3()
{
    // go to Rk4 Method window
    solverStackedWidget->setCurrentIndex(3);
    setWindowTitle("4th Order Runge-Kutta Method");
}


void diffeqsolver::goToMethod4()
{
    // go to Trapezoidal Method window
    solverStackedWidget->setCurrentIndex(4);
    setWindowTitle("Trapezoidal Method");
}

QMenuBar* diffeqsolver::getodeMenuBar()
{
    // show method selection menu bar
    return odeMenuBar;
}

void diffeqsolver::MakeHelpWindow()
{
    // show help window
    QWidget* h_window = new helpWindow();
}

diffeqsolver::~diffeqsolver(){
}
