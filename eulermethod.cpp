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

 * @file eulermethod.cpp
 * @brief The implementation file for the Euler Method window.
 *
 * This is the Euler Method window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */

#include "eulermethod.h"

EulerMethod::EulerMethod(FunctionPlot *parent) :
    FunctionPlot(parent){

    setWindowTitle("Euler's Method");
    plotbutton->setText("Solve!");
    plotbutton -> setToolTip("Solve the ODE");

    functionstring -> setToolTip("The function to solve");


    initial_condition = new QDoubleSpinBox;
    initial_condition -> setMaximum(1000); // set max and min for initial and final spinbox
    initial_condition -> setMinimum(-1000);
    initial_condition -> setToolTip("Input the initial condition here");

    inicprompt = new QLabel("Initial Condition");

    QObject::connect(initial_condition, SIGNAL(valueChanged(double)), this, SLOT(changeinicond(double)));

    paralayout->addWidget(initial_condition, 3, 1);
    paralayout->addWidget(inicprompt, 2, 1);
}

EulerMethod::~EulerMethod(){

}

void EulerMethod::changeinicond(double i){
    initial_cond = i; // change final
}


void EulerMethod::makepoints(){
    // exprtk commands
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double>     expression_t;
    typedef exprtk::parser<double>             parser_t;

    QString expr_string = function_str; // the function string

    double x = initial; // initialize x

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x); // add x as a variable

    // exprtk commands to parse the function
    expression_t expression;
    expression.register_symbol_table(symbol_table);
    parser_t parser;
    parser.compile(expr_string.toStdString(),expression);

    const double delta = (final-initial)/nsteps; // the step size

    //plot functions
    QVector<std::pair <double,double>> points; // the variable and value vector

    double result = initial_cond;

    for (double t = initial; t <= final; t += delta) // for all value points
    {
       x = result;
       double deri = expression.value();
       result = result+deri*delta; // evaluate the result of the function string
       std::pair <double,double> data_point = std::make_pair(t,result);
       points.push_back(data_point); // add the data point
    }

    vec_points_to_plot.push_back(points);
}
