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

    QWidget * solverMenu = new QWidget;
    QVBoxLayout * menuLayout = new QVBoxLayout;

    QWidget * eulerMethod = new QWidget;
    QVBoxLayout * page1Layout = new QVBoxLayout;
    QPushButton * page1Back = new QPushButton("Go Back");
    page1Layout->addWidget(page1Back);
    eulerMethod->setLayout(page1Layout);

    QWidget * backwardEuler = new QWidget;
    QVBoxLayout * page2Layout = new QVBoxLayout;
    QPushButton * page2Back = new QPushButton("Go Back");
    page2Layout->addWidget(page2Back);
    backwardEuler->setLayout(page2Layout);

    QWidget * rk2 = new QWidget;
    QVBoxLayout * page3Layout = new QVBoxLayout;
    QPushButton * page3Back = new QPushButton("Go Back");
    page3Layout->addWidget(page3Back);
    rk2->setLayout(page3Layout);

    QWidget * rk4 = new QWidget;
    QVBoxLayout * page4Layout = new QVBoxLayout;
    QPushButton * page4Back = new QPushButton("Go Back");
    page4Layout->addWidget(page4Back);
    rk4->setLayout(page4Layout);

    QWidget * trapezoidalMethod = new QWidget;
    QVBoxLayout * page5Layout = new QVBoxLayout;
    QPushButton * page5Back = new QPushButton("Go Back");
    page5Layout->addWidget(page5Back);
    trapezoidalMethod->setLayout(page5Layout);

    QPushButton * eulerMethodButton = new QPushButton("Euler Method");
    QPushButton * backwardEulerButton = new QPushButton("Backwards Euler Method");
    QPushButton * rk2Button = new QPushButton("RK2");
    QPushButton * rk4Button = new QPushButton("RK4");
    QPushButton * trapezoidalMethodButton = new QPushButton("Trapezoidal Method");


    menuLayout->addWidget(eulerMethodButton);
    menuLayout->addWidget(backwardEulerButton);
    menuLayout->addWidget(rk2Button);
    menuLayout->addWidget(rk4Button);
    menuLayout->addWidget(trapezoidalMethodButton);
    solverMenu->setLayout(menuLayout);

    solverStackedWidget = new QStackedWidget;
    solverStackedWidget->addWidget(solverMenu); // Page 0
    solverStackedWidget->addWidget(eulerMethod); // Page 1
    solverStackedWidget->addWidget(backwardEuler); // Page 2
    solverStackedWidget->addWidget(rk2); // Page 3
    solverStackedWidget->addWidget(rk4); // Page 4
    solverStackedWidget->addWidget(trapezoidalMethod); // Page 5

    connect(eulerMethodButton, SIGNAL(clicked()), this, SLOT(goToEulerMethod()));
    connect(backwardEulerButton, SIGNAL(clicked()), this, SLOT(goToBackwardEuler()));
    connect(rk2Button, SIGNAL(clicked()), this, SLOT(goToRk2()));
    connect(rk4Button, SIGNAL(clicked()), this, SLOT(goToRk4()));
    connect(trapezoidalMethodButton, SIGNAL(clicked()), this, SLOT(goToTrapezoidalMethod()));
    connect(page1Back, SIGNAL(clicked()), this, SLOT(goToSolverMenu()));
    connect(page2Back, SIGNAL(clicked()), this, SLOT(goToSolverMenu()));
    connect(page3Back, SIGNAL(clicked()), this, SLOT(goToSolverMenu()));
    connect(page4Back, SIGNAL(clicked()), this, SLOT(goToSolverMenu()));
    connect(page5Back, SIGNAL(clicked()), this, SLOT(goToSolverMenu()));

    QVBoxLayout* centrallayout = new QVBoxLayout;
    centrallayout->addWidget(solverStackedWidget);
    setLayout(centrallayout);
}

void diffeqsolver::goToEulerMethod()
{
    solverStackedWidget->setCurrentIndex(1);
}
void diffeqsolver::goToBackwardEuler()
{
    solverStackedWidget->setCurrentIndex(2);
}
void diffeqsolver::goToRk2()
{
    solverStackedWidget->setCurrentIndex(3);
}
void diffeqsolver::goToRk4()
{
    solverStackedWidget->setCurrentIndex(4);
}
void diffeqsolver::goToTrapezoidalMethod()
{
    solverStackedWidget->setCurrentIndex(5);
}
void diffeqsolver::goToSolverMenu()
{
    solverStackedWidget->setCurrentIndex(0);
}

diffeqsolver::~diffeqsolver()
{
    delete ui;
}

