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

 * @file Backeulermethod.cpp
 * @brief The implementation file for the Backward Euler Method window.
 *
 * This is the Backward Euler Method window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs
 */

#include "FunctionPlotWindows/ODESolvingMethods/Backeulermethod/Backeulermethod.h"

BackEulerMethod::BackEulerMethod(ODESolverBase *parent) :
    ODESolverBase(parent){
}

BackEulerMethod::~BackEulerMethod(){
}

void BackEulerMethod::makepoints(){
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
        error->setStyleSheet("color: black;"); // Font is black when no error
    }
    if (!iffuncvalid) // if it failed
    {
        errormsg = "Function Parser: "; // save the error messages
        for (size_t i = 0; i < parser.error_count(); ++i)
              {
                 typedef exprtk::parser_error::type error_t;

                 error_t error = parser.get_error(i);
                 errormsg.append(error.diagnostic.c_str());
                 errormsg.append("  ");
              }

        errorSound = new QMediaPlayer;
        errorSoundFile = new QUrl("qrc:/Music/Sound/Computer Error-SoundBible.com-1655839472.mp3");
        errorSound->setMedia(*errorSoundFile); //Sets the error sound file to be playable
        errorSound->play(); //Plays the error sound when there is an actual error

        error->setText(errormsg); // print the error message
        error->setStyleSheet("color: red;"); // Font is red when there is error
        return; // do not plot the erroruous function
    }

    const double delta = (final-initial)/nsteps; // the step size

    points.clear(); // clear the points vector
    double result = initial_cond; // initialize the result first as the initial condition
    constexpr int MAX_ITER= 10000; // max iteration the root finder can take
    constexpr double TOLERANCE = 0.00001; // the tolerane of the root finder

    double prev; // the previous result, used in the loop

    std::pair <double,double> data_point = std::make_pair(initial,result); // initial point
    points.push_back(data_point); // add the data point
    for (double t = initial+delta; t <= final; t += delta) // for all value points
    {
        int iter_num = 1; // initialize the iteration counter
        prev = result; // copy the previous result
        // then we use Secant method to find the root
        double x0 = prev*0.9; // first guess is a bit below previous value
        double x1 = prev; // second guess is the previous value
        double x2 = 0; // x2 is the value of the root we find, right now initialize to be 0
        double f2 = 1; // f2 is the value of f(x2), right now initialize to be 1
        while (( iter_num <= MAX_ITER) && (abs(f2) >= TOLERANCE)){
            // while there has not been MAX_ITER number of iteration and the absolute value of f(x2) is still larger than TOLERANCE
            x = x0; // set x as x0 because it is needed to evaluate f(x0)
            double f0 = x-prev-delta*expression.value(); // evaluate the function that we try to solve for: x0-xk-delta*f(x0)
            x = x1; // set x as x1 because it is needed to evaluate f(x1)
            double f1 = x-prev-delta*expression.value(); // evaluate the function that we try to solve for: x1-xk-delta*f(x1)
            x2 = x1 - ((f1 * (x1 - x0)) / (f1 - f0)); // calculate x2 via Secant method algorithm
            x = x2; // set x to x2
            f2 = x-prev-delta*expression.value(); // evaluate f2 by x2
            x0 = x1; // take step forward by setting x0 at x1
            x1 = x2; // x1 as x2
            ++iter_num; // add one more iteration number
            if (abs(f0 - f1) < TOLERANCE){ // if the difference between f0 and f1 is small
                break; // then break
            }
            result = x2; // make the result x2
        }
        std::pair <double,double> data_point = std::make_pair(t,result); // make the data point
        points.push_back(data_point); // add the data point
    }
    ++num_graph; // add in number of plot
    makeplot(); // call makeplot
}
