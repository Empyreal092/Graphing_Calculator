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

 * @file rk4method.h
 * @brief The header file for the RK4 Method window.
 *
 * This is the RK4 Method window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs
 */

#ifndef RK4METHOD_H
#define RK4METHOD_H

#include <QWidget>
#include "FunctionPlotWindows/odesolverbase/odesolverbase.h"

namespace Ui {
class RK4method;
}

/**
 * @class	RK4method
 *
 * @brief	The RK4 Method window.
 */

class RK4method : public ODESolverBase{
    Q_OBJECT

public:

    /**
     * @fn	explicit RK4method::RK4method(ODESolverBase *parent = nullptr);
     *
     * @brief	Constructor
     *
     * @param [in,out]	parent	(Optional) If non-null, the parent.
     */

    explicit RK4method(ODESolverBase *parent = nullptr);

    /**
     * @fn	RK4method::~RK4method() override;
     *
     * @brief	Destructor
     */

    ~RK4method() override;

    /**
     * @fn	void RK4method::makepoints() override;
     *
     * @brief	Make the points for the graph
     */

    void makepoints() override;
};

#endif // RK4METHOD_H
