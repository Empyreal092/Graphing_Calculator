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

 * @file functionplot.h
 * @brief The header file for the function plot window.
 *
 * This is the function plot window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */

#ifndef FUNCTIONPLOT_H
#define FUNCTIONPLOT_H

#include <QWidget>
#include "qcustomplot.h"
#include "ui_functionplot.h"
#include "exprtk.hpp"
#include <QDialog>
#include <QString>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <utility>
#include <QKeyEvent>

namespace Ui {
class FunctionPlot;
}

/**
 * @class	FunctionPlot
 *
 * @brief	A function plot window.
 */

class FunctionPlot : public QWidget{
    Q_OBJECT

public:

    /**
     * @fn	explicit FunctionPlot::FunctionPlot(QWidget *parent = nullptr);
     *
     * @brief	Constructor
     *
     * @param [in,out]	parent	(Optional) If non-null, the parent.
     */

    explicit FunctionPlot(QWidget *parent = nullptr);

    /**
     * @fn	FunctionPlot::~FunctionPlot();
     *
     * @brief	Destructor
     */

    virtual ~FunctionPlot();


    virtual void makepoints();
    void makeplot();

protected:
    QVector<QVector<std::pair <double,double>>> vec_points_to_plot;

    /** @brief	The user interface */
    Ui::FunctionPlot *ui;
    /** @brief	The function string */
    QString function_str;
    /** @brief	The initial value */
    double initial;
    /** @brief	The final value */
    double final;
    /** @brief	The nsteps value */
    int nsteps;

    /** @brief	The input widget */
    QWidget * input;
   /** @brief	The layout for input */
    QVBoxLayout * inputlayout;
    /** @brief	The layout for parameters */
    QGridLayout * paralayout;
    /** @brief	The the function str input box */
    QLineEdit * functionstring;
    /** @brief	The plot button */
    QPushButton * plotbutton;
    /** @brief	The clear button */
    QPushButton * clearbutton;
    /** @brief	The initial double spinbox */
    QDoubleSpinBox * input_initial;
    /** @brief	The final double spinbox */
    QDoubleSpinBox * input_final;
    /** @brief	The nsteps double spin box */

    QSpinBox * input_nsteps_spin_box;
    /** @brief	Tell user to input function str */

    QLabel * promp_function;
    /** @brief	Tell user to input initial value */
    QLabel * promp_ini;
    /** @brief	Tell user to input final value */
    QLabel * promp_final;

    /** @brief	Tell user to input nsteps value */
    QLabel * promp_nsteps;
    /** @brief	Tell user to move slider to change nsteps value */
    QLabel * promp_nsteps_slider;
    /** @brief	Changes nsteps value */
    QSlider * nsteps_slider;

public slots:

   /**
    * @fn	FunctionPlot::changefstring();
    *
    * @brief	Change the function string
    */

   void changefstring();

   void clearstring();

   /**
    * @fn	FunctionPlot::changeini();
    *
    * @brief	Change the initial value
    */

   void changeini(double);

   /**
    * @fn	FunctionPlot::changefinal();
    *
    * @brief	Change the final value
    */

   void changefinal(double);

   /**
    * @fn	FunctionPlot::changensteps();
    *
    * @brief	Change the nsteps value
    */

   void changensteps(int);

};

#endif // FUNCTIONPLOT_H
