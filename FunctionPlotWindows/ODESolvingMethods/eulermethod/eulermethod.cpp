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

#include "FunctionPlotWindows/ODESolvingMethods/eulermethod/eulermethod.h"

EulerMethod::EulerMethod(ODESolverBase *parent) :
    ODESolverBase(parent){
    setWindowTitle("Euler's Method"); // rename the window
}

EulerMethod::~EulerMethod(){
}

void EulerMethod::makepoints(){
    // exprtk commands
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double>     expression_t;
    typedef exprtk::parser<double>             parser_t;

    QString expr_string = function_str; // the function string

    double x = initial; // initialize x

    symbol_table_t symbol_table;
    symbol_table.add_variable("y",x); // add y in string as x, a variable

    // exprtk commands to parse the function
    expression_t expression;
    expression.register_symbol_table(symbol_table);
    parser_t parser;

    bool iffuncvalid = parser.compile(expr_string.toStdString(),expression); // check if the parser failed
    if (iffuncvalid){
        error->setText("Function Parser: No Error");
    }
    if (!iffuncvalid) // if it failed
    {
        errormsg = "Function Parser: "; // save the error messages
        for (std::size_t i = 0; i < parser.error_count(); ++i)
              {
                 typedef exprtk::parser_error::type error_t;

                 error_t error = parser.get_error(i);
                 errormsg.append(error.diagnostic.c_str());
                 errormsg.append("  ");
              }
        error->setText(errormsg); // print the error message
        return; // do not plot the erroruous function
    }

    const double delta = (final-initial)/nsteps; // the step size

    //plot functions
    points.clear(); // clear the points vector

    double result = initial_cond; // initialize the result first as the initial condition

    std::pair <double,double> data_point = std::make_pair(initial,result); // initial point
    points.push_back(data_point); // add the data point
    for (double t = initial; t <= final; t += delta) // for all value points
    {
       x = result; // set x as result
       double deri = expression.value(); // evaluate the derivative at x = result
       result = result+deri*delta; // update the result by marching a step
       std::pair <double,double> data_point = std::make_pair(t,result); // make the data point
       points.push_back(data_point); // add the data point
    }
    ++num_graph;
    makeplot();
}
