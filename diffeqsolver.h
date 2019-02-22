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

 * @file diffeqsolver.h
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


#ifndef DIFFEQSOLVER_H
#define DIFFEQSOLVER_H

#include <QWidget>
#include "qcustomplot.h"
#include "exprtk.hpp"
#include <QDialog>
#include <QString>
#include <QPushButton>
#include <QDoubleSpinBox>
#include "functionplot.h"

namespace Ui {
class diffeqsolver;
}

/**
 * @class	diffeqsolver
 *
 * @brief	A diffeqsolver window.
 */

class diffeqsolver : public QWidget
{
    Q_OBJECT

public:

    /**
     * @fn	explicit diffeqsolver::diffeqsolver(QWidget *parent = nullptr);
     *
     * @brief	Constructor
     *
     * @param [in,out]	parent	(Optional) If non-null, the parent.
     */

    explicit diffeqsolver(QWidget *parent = nullptr);

    /**
     * @fn	diffeqsolver::~diffeqsolver();
     *
     * @brief	Destructor
     */

    ~diffeqsolver();

public slots:

   /**
    * @fn	void diffeqsolver::goToEulerMethod();
    *
    * @brief	Go to euler method
    */

   void goToEulerMethod();

   /**
    * @fn	void diffeqsolver::goToBackwardEuler();
    *
    * @brief	Go to backward euler
    */

   void goToBackwardEuler();

   /**
    * @fn	void diffeqsolver::goToRk2();
    *
    * @brief	Go to rk 2
    */

   void goToRk2();

   /**
    * @fn	void diffeqsolver::goToRk4();
    *
    * @brief	Go to rk 4
    */

   void goToRk4();

   /**
    * @fn	void diffeqsolver::goToTrapezoidalMethod();
    *
    * @brief	Go to trapezoidal method
    */

   void goToTrapezoidalMethod();

   /**
    * @fn	void diffeqsolver::goToSolverMenu();
    *
    * @brief	Go to solver menu
    */

   void goToSolverMenu();

private:
    /** @brief	The solver stacked widget */
    QStackedWidget * solverStackedWidget;
    /** @brief	The user interface */
    Ui::diffeqsolver *ui;
};

#endif // DIFFEQSOLVER_H
