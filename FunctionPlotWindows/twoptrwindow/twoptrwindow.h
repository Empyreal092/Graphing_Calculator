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

 * @file twoptrwindow.h
 * @brief The header file for the Two Point problem solver window.
 *
 * This is the Two Point problem solver window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs
 */


#ifndef TWOPTRWINDOW_H
#define TWOPTRWINDOW_H

#include <QWidget>
#include "FunctionPlotWindows/functionplot/functionplot.h"

namespace Ui {
class TwoPtrWindow;
}

/**
 * @class	TwoPtrWindow
 *
 * @brief	Two Point Value Problem window.
 */

class TwoPtrWindow : public FunctionPlot{
    Q_OBJECT

public:

    /**
     * @fn	explicit TwoPtrWindow::TwoPtrWindow(FunctionPlot *parent = nullptr);
     *
     * @brief	Constructor
     *
     * @param [in,out]	parent	(Optional) If non-null, the parent.
     */

    explicit TwoPtrWindow(FunctionPlot *parent = nullptr);

    /**
     * @fn	TwoPtrWindow::~TwoPtrWindow();
     *
     * @brief	Destructor
     */

    ~TwoPtrWindow() override;

    /**
     * @fn	void TwoPtrWindow::makepoints() override;
     *
     * @brief	Make the points for the graph
     */

    void makepoints() override;

public slots:

    /**
     * @fn	void TwoPtrWindow::changeinicond1(double);
     *
     * @brief	Change left initial condition
     *
     * @param	parameter1	The double user inputted.
     */

    void changeinicond1(double);

    /**
     * @fn	void TwoPtrWindow::changeinicond2(double);
     *
     * @brief	Change right initial condition
     *
     * @param	parameter1	The double user inputted.
     */

    void changeinicond2(double);

protected:
    /** @brief	The left initial condition DoubleSpinBox */
    QDoubleSpinBox * initial_condition1;
    /** @brief	The right initial condition DoubleSpinBox */
    QDoubleSpinBox * initial_condition2;
    /** @brief	The left initial condition prompt */
    QLabel * inicprompt1;
	/** @brief	The right initial condition prompt */
    QLabel * inicprompt2;
    /** @brief	The left initial condition value */
    double initial_cond1;
    /** @brief	The right initial condition value */
    double initial_cond2;
};

#endif // TWOPTRWINDOW_H
