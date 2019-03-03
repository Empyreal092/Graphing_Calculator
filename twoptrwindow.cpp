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

 * @file twoptrwindow.cpp
 * @brief The implementation file for the Two Point problem solver window.
 *
 * This is the Two Point problem solver window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */

#include "twoptrwindow.h"
#include <cmath>

TwoPtrWindow::TwoPtrWindow(FunctionPlot *parent) :
    FunctionPlot(parent){

    initial_cond1 = 0;
    initial_cond2 = 0;

    setWindowTitle("Two Point Boundry Value Problem Solver");
    plotbutton->setText("Solve!");
    plotbutton -> setToolTip("Solve the Two Point Boundry Value Problem");

    functionstring -> setToolTip("The function to solve");

    initial_condition1 = new QDoubleSpinBox;
    initial_condition1 -> setMaximum(1000); // set max and min for initial and final spinbox
    initial_condition1 -> setMinimum(-1000);
    initial_condition1 -> setValue(initial_cond1);
    initial_condition1 -> setToolTip("Input the right initial condition here");

    initial_condition2 = new QDoubleSpinBox;
    initial_condition2 -> setMaximum(1000); // set max and min for initial and final spinbox
    initial_condition2 -> setMinimum(-1000);
    initial_condition2 -> setValue(initial_cond2);
    initial_condition2 -> setToolTip("Input the left initial condition here");

    inicprompt1 = new QLabel("Left Initial Value");
    inicprompt2 = new QLabel("Right Initial Value");

    QObject::connect(initial_condition1, SIGNAL(valueChanged(double)), this, SLOT(changeinicond1(double)));
    QObject::connect(initial_condition2, SIGNAL(valueChanged(double)), this, SLOT(changeinicond2(double)));

    paralayout->addWidget(initial_condition1, 5, 0);
    paralayout->addWidget(initial_condition2, 5, 1);
    paralayout->addWidget(inicprompt1, 4, 0);
    paralayout->addWidget(inicprompt2, 4, 1);

    input_nsteps_spin_box -> setMaximum(100); // set max and min for nsteps spinbox and nsteps slider
    input_nsteps_spin_box -> setMinimum(0);
    input_nsteps_spin_box -> setValue(50);
}

TwoPtrWindow::~TwoPtrWindow(){

}

void TwoPtrWindow::changeinicond1(double i){
    initial_cond1 = i; // change final
}

void TwoPtrWindow::changeinicond2(double i){
    initial_cond2 = i; // change final
}

//////////////////////
double hsprt2norm(QVector<QVector<double>>A, QVector<double>u, QVector<double>v, double h){
    int size = u.size();
    QVector<double> mult(size);

    for (int j = 0; j < size; ++j)
        for(int k = 0; k < size; ++k)
        {
            mult[j] += u[k] * A[k][j];
        }
    QVector<double> result(size);
    for (int i = 0; i < size; ++i){
        result[i] = mult[i] - v[i];
    }
    double normsquar = 0;
    for (int i = 0; i < size; ++i){
        normsquar += pow(abs(result[i]),2);
    }
    double norm = sqrt(normsquar);
    norm = norm*sqrt(h);
    return norm;
}
/////////////////////////
/// \brief TwoPtrWindow::makepoints
///
void TwoPtrWindow::makepoints(){
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

    QVector<QVector<double>> MatrixA(nsteps-1, QVector<double>(nsteps-1));
    double fac = 1/(delta*delta);

    MatrixA[0][0] = -2*fac;
    MatrixA[0][1] = 1*fac;
    MatrixA[nsteps-2][nsteps-2] = -2*fac;
    MatrixA[nsteps-2][nsteps-3] = 1*fac;

    for (int i = 1; i < nsteps-2; ++i){
        MatrixA[i][i] = -2*fac;
        MatrixA[i][i-1] = 1*fac;
        MatrixA[i][i+1] = 1*fac;
    }

    QVector<double> vec_x;
    for (int i = 0; i<nsteps-1; ++i){
        vec_x.push_back(initial+(i+1)*delta);
    }

    QVector<double> vec_f;
    for (int i = 0; i<nsteps-1; ++i){
        x = vec_x[i];
        vec_f.push_back(expression.value());
    }

    vec_f[0] -= initial_cond1*fac;
    vec_f[nsteps-2] -= initial_cond2*fac;

    QVector<double> results = QVector<double>(nsteps-1,0);
    int count = 0;

    while (hsprt2norm(MatrixA, results, vec_f, delta)>0.05 && count <1000){
        QVector<double> results_prev = results;
        for (int i = 0; i < nsteps-1; ++i){
            results[i] = vec_f[i];
            for (int j = 0; j < i; ++j){
                results[i] -= MatrixA[i][j]*results[j];
            }
            for (int j = i+1; j < nsteps-1; ++j){
                results[i] -= MatrixA[i][j]*results_prev[j];
            }
            results[i] = results[i]/MatrixA[i][i];
        }
        ++count;
    }

    //plot functions
    QVector<std::pair <double,double>> points; // the variable and value vector

    std::pair <double,double> data_point;
    data_point = std::make_pair(initial,initial_cond1);
    points.push_back(data_point); // add the data point
    for (int i = 0; i < nsteps-1; ++i){
        data_point = std::make_pair(vec_x[i],results[i]);
        points.push_back(data_point); // add the data point
    }
    data_point = std::make_pair(final,initial_cond2);
    points.push_back(data_point); // add the data point

    vec_points_to_plot.push_back(points);
}




