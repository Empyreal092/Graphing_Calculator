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

 * @file odesolverbase.h
 * @brief The header file for the base of all ode solver.
 *
 * This is the base of all function plot window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */


#ifndef ODESOLVERBASE_H
#define ODESOLVERBASE_H

#include <QWidget>
#include <QLabel>
#include "FunctionPlotWindows/functionplot/functionplot.h"

namespace Ui {
class ODESolverBase;
}

/**
 * @class	ODESolverBase
 *
 * @brief	An ode solver base class, abstract class.
 */

class ODESolverBase : public FunctionPlot{
    Q_OBJECT

 public:

    /**
     * @fn	explicit TwoPtrWindow::TwoPtrWindow(FunctionPlot *parent = nullptr);
     *
     * @brief	Constructor
     *
     * @param [in,out]	parent	(Optional) If non-null, the parent.
     */

    explicit ODESolverBase(FunctionPlot *parent = nullptr);

    /**
     * @fn	TwoPtrWindow::~TwoPtrWindow();
     *
     * @brief	Destructor
     */

    ~ODESolverBase() override;

 public slots:

     /**
      * @fn	void ODESolverBase::changeinicond(double);
      *
      * @brief	Change the initial conditions
      *
      * @param	parameter1	The number to change to.
      */

     void changeinicond(double);

     /**
      * @fn	void ODESolverBase::muteErrorSound();
      *
      * @brief	Mutes the error sound
      */

     void muteErrorSound();

 protected:
     /** @brief	The initial condition input double spinbox */
     QDoubleSpinBox * initial_condition;
     /** @brief	Tell user to input initial condition */
     QLabel * inicprompt;
     /** @brief	The initial condition number */
     double initial_cond;
     /** @brief Indicates if the mute button is pressed */
     bool muteIsPressed = false;
 };
#endif // ODESOLVERBASE_H
