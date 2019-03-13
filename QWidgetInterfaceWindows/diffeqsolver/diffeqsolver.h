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

 * @file helpwindow.h
 * @brief The header file for the help window.
 *
 * This is the help window for the project.
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
#include "qcustomplot/qcustomplot.h"
#include "exprtk/exprtk.hpp"
#include <QDialog>
#include <QString>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QActionGroup>
#include "FunctionPlotWindows/functionplot/functionplot.h"
#include "FunctionPlotWindows/ODESolvingMethods/eulermethod/eulermethod.h"
#include "FunctionPlotWindows/ODESolvingMethods/Backeulermethod/Backeulermethod.h"
#include "FunctionPlotWindows/ODESolvingMethods/RK2method/RK2method.h"
#include "FunctionPlotWindows/ODESolvingMethods/rk4method/rk4method.h"
#include "FunctionPlotWindows/ODESolvingMethods/trapezoidalmethod/trapezoidalmethod.h"
#include "QWidgetInterfaceWindows/helpwindow/helpwindow.h"

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
   * @fn	void diffeqsolver::goToMethod0();
   *
   * @brief  Go to method 0
   */
   void goToMethod0();
   /**
   * @fn	void diffeqsolver::goToMethod1();
   *
   * @brief  Go to method 1
   */
   void goToMethod1();
   /**
   * @fn	void diffeqsolver::goToMethod2();
   *
   * @brief  Go to method 2
   */
   void goToMethod2();
   /**
   * @fn	void diffeqsolver::goToMethod3();
   *
   * @brief  Go to method 3
   */
   void goToMethod3();
   /**
   * @fn	void diffeqsolver::goToMethod4();
   *
   * @brief  Go to method 4
   */
   void goToMethod4();
   /**
   * @fn	void diffeqsolver::getMenuBar();
   *
   * @brief Returns the odeMenuBar.
   */
   QMenuBar* getodeMenuBar();
   /**
   * @fn	void diffeqsolver::MakeHelpWindow();
   *
   * @brief Create the help window.
   */
   void MakeHelpWindow();

private:
    /** @brief	The solver stacked widget */
    QStackedWidget * solverStackedWidget;
    /** @brief  The ode solver menu */
    QMenu * odeSolver;
    /** @brief	The user interface */
    Ui::diffeqsolver *ui;
    /** @brief  The differential equation solver drop-down menu bar */
    QMenuBar* odeMenuBar;
    /** @brief  Controls error sound*/
    QMenu* soundMenuButtonODE;
    /** @brief  Mutes error sound after ODE sound menu button is pressed */
    QAction* mute;
    /** @brief Creates Euler method window */
    EulerMethod* myEulerMethod;
    /** @brief Creates back Euler method window */
    BackEulerMethod* myBackEulerMethod;
    /** @brief Creates rk2 method window */
    RK2method* myRK2Method;
    /** @brief Creates rk4 method window */
    RK4method* myRK4Method;
    /** @brief Creates trapezoid method window */
    TrapezoidalMethod* myTrapezoidalMethod;
    /** @brief The grid layout containing the QStackedWidget*/
    QGridLayout* menuLayout;
    /** @brief the help button for the ODE solver */
    QMenu* helpButtonODE;
    /** @brief the button to switch to Euler's method window */
    QAction* eul;
    /** @brief the button to switch to back Euler method window */
    QAction* backEul;
    /** @brief the button to switch to rk2 method window */
    QAction* rk2;
    /** @brief the button to switch to rk4 method window */
    QAction* rk4;
    /** @brief the button to switch to trapezoid method window */
    QAction* trap;
    /** @brief the QActionGroup for the solver so only one method shows */
    QActionGroup* methodsGroup;

};

#endif // DIFFEQSOLVER_H
