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

 * @file trapezoidalmethod.h
 * @brief The header file for the Trapezoidal Method window.
 *
 * This is the Trapezoidal Method window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs
 */

#ifndef TRAPEZOIDALMETHOD_H
#define TRAPEZOIDALMETHOD_H

#include <QWidget>
#include "FunctionPlotWindows/odesolverbase/odesolverbase.h"

namespace Ui {
class TrapezoidalMethod;
}

/**
 * @class	TrapezoidalMethod
 *
 * @brief	The Trapezoidal Method window.
 */

class TrapezoidalMethod : public ODESolverBase{
   Q_OBJECT

public:

   /**
    * @fn	explicit TrapezoidalMethod::TrapezoidalMethod(ODESolverBase *parent = nullptr);
    *
    * @brief	Constructor
    *
    * @param [in,out]	parent	(Optional) If non-null, the parent.
    */

   explicit TrapezoidalMethod(ODESolverBase *parent = nullptr);

   /**
    * @fn	TrapezoidalMethod::~TrapezoidalMethod () override;
    *
    * @brief	Destructor
    */

   ~TrapezoidalMethod () override;

   /**
    * @fn	void TrapezoidalMethod::makepoints() override;
    *
    * @brief	Make the points for the graph
    */

   void makepoints() override;
};

#endif // TRAPEZOIDALMETHOD_H
