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

 * @file functionplot.cpp
 * @brief The implimentation file for the function plot window.
 *
 * This is the function plot window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */

#include "functionplot.h"
#include "qcustomplot.h"
#include "ui_functionplot.h"

FunctionPlot::FunctionPlot(QWidget *parent) :
    QWidget(parent), ui(new Ui::FunctionPlot), function_str(){

    function_str = "10*(4/3.1415)*"
                   "((1 /1)*sin( 2*3.1415^2*x/10)+(1 /3)*sin( 6*3.1415^2*x/10)+"
                   " (1 /5)*sin(10*3.1415^2*x/10)+(1 /7)*sin(14*3.1415^2*x/10)+"
                   " (1 /9)*sin(18*3.1415^2*x/10)+(1/11)*sin(22*3.1415^2*x/10))";
	// this the an example, that the function parser works, now it is possible to take input from user and plot the function
    initial = -5.0; // initial value
    final = 5.0; // final value
    ui->setupUi(this);
    FunctionPlot::makeplot<double>(); // call the make plot function

    setWindowTitle("Plotting Function");
}

FunctionPlot::~FunctionPlot()
{
    delete ui;
}

template <typename T>
void FunctionPlot::makeplot(){

	// exprtk commands
    typedef exprtk::symbol_table<T> symbol_table_t; 
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;

    std::string expr_string = function_str; // the function string

    T x = T(initial); // initialize x

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x); // add x as a variable

	// exprtk commands to parse the function
    expression_t expression;  
    expression.register_symbol_table(symbol_table);
	parser_t parser;
    parser.compile(expr_string,expression);

    const T delta = T(1/1000.0); // the step size

    //plot functions
    QVector<T> var, value; // the variable and value vector

    for (x = T(initial); x <= T(final); x += delta) // for all value points
    {
       T result = expression.value(); // evaluate the result of the function string
       var.push_back(x); // add the variable
       value.push_back(result); // add the result 
    }
    // create graph and assign data to it
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(var, value);
    // give the axes some labels
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data
    T max = *std::max_element(value.begin(), value.end());
    T min = *std::min_element(value.begin(), value.end());
    ui->customPlot->xAxis->setRange(T(initial)-0.1*abs(T(initial)), T(final)+0.1*abs(T(final)));
    ui->customPlot->yAxis->setRange(min-0.1*abs(min), max+0.1*abs(max));
}
