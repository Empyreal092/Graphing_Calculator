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
 * @brief The header file for the ODE solver window.
 *
 * This is the ODE solver window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */
#include "diffeqsolver.h"
#include "ui_diffeqsolver.h"

diffeqsolver::diffeqsolver(QWidget *parent) :
    QWidget(parent), ui(new Ui::diffeqsolver)
{
    ui->setupUi(this);

    setWindowTitle("Differential Equations Solver");

    // Creates pages for each method
    EulerMethod* myEulerMethod = new EulerMethod;
    BackEulerMethod* myBackEulerMethod = new BackEulerMethod;
    RK2method* myRK2Method = new RK2method;
    RK4method* myRK4Method = new RK4method;
    TrapezoidalMethod* myTrapezoidalMethod = new TrapezoidalMethod;

    // Adds the method pages to the solverStackedWidget
    solverStackedWidget = new QStackedWidget;
    solverStackedWidget->addWidget(myEulerMethod); // Page 1
    solverStackedWidget->addWidget(myBackEulerMethod); // Page 2
    solverStackedWidget->addWidget(myRK2Method); // Page 3
    solverStackedWidget->addWidget(myRK4Method); // Page 4
    solverStackedWidget->addWidget(myTrapezoidalMethod); // Page 5

    // Adds options to dropDownMenu
    dropDownMenu = new QComboBox;
    dropDownMenu->insertItem(0, "Euler's Method"); // Item 0
    dropDownMenu->insertItem(1, "Backwards Euler Method"); // Item 1
    dropDownMenu->insertItem(2, "2nd order Runge-Kutta Method"); // Item 2
    dropDownMenu->insertItem(3, "4th order Runge-Kutta Method"); // Item 3
    dropDownMenu->insertItem(4, "Trapezoidal Method"); // Item 4
    dropDownMenu->setCurrentIndex(0); // Sets default method to Euler's Method
    connect(dropDownMenu, SIGNAL(currentIndexChanged(int)), this, SLOT(goToMethod()));

    // Adds the solverStackedWidget and dropDownMenu to the layout
    QGridLayout* menuLayout = new QGridLayout;
    QLabel* methodPrompt = new QLabel("Choose a method:");
    menuLayout->addWidget(methodPrompt, 0, 0, 1, 2);
    menuLayout->addWidget(dropDownMenu, 0, 2, 1, 5);
    menuLayout->addWidget(solverStackedWidget, 2, 0, 11, 16);
    setMinimumSize(800, 600);
    setLayout(menuLayout);
}

void diffeqsolver::goToMethod()
{
    int index = dropDownMenu->currentIndex();
    solverStackedWidget->setCurrentIndex(index); // Sets to current page
    setWindowTitle(dropDownMenu->currentText()); // Sets the page title to the current text
}

diffeqsolver::~diffeqsolver()
{
    delete ui;
}
