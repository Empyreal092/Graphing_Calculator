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

#include "FunctionPlotWindows/twoptrwindow/twoptrwindow.h"
#include <cmath>

TwoPtrWindow::TwoPtrWindow(FunctionPlot *parent) :
    FunctionPlot(parent){

    initial_cond1 = 0; // set default left initial condition as 0
    initial_cond2 = 0; // set default right initial condition as 0

    setWindowTitle("Two Point Boundry Value Problem Solver"); // rename the window
    plotbutton->setText("Solve!"); // rename the button
    plotbutton -> setToolTip("Graphically solving the Two Point Boundry Value Problem (Enter)"); // reset the tooltip

    functionstring -> setToolTip("The function to solve (Only use t as your variables)"); // reset the tooltip

    inputf_t -> setText("d2y/dt2 := ");
    inputf_t -> setMaximumWidth(50);

    initial_condition1 = new QDoubleSpinBox; // make double spinbix for left inicond
    initial_condition1 -> setMaximum(1000); // set max and min for initial and final spinbox
    initial_condition1 -> setMinimum(-1000);
    initial_condition1 -> setValue(initial_cond1); // set value as 0
    initial_condition1 -> setToolTip("Input the right initial condition here (y(t_initial))"); // tooltip

    initial_condition2 = new QDoubleSpinBox; // make double spinbix for left inicond
    initial_condition2 -> setMaximum(1000); // set max and min for initial and final spinbox
    initial_condition2 -> setMinimum(-1000);
    initial_condition2 -> setValue(initial_cond2); // set value as 0
    initial_condition2 -> setToolTip("Input the left initial condition here (y(t_final))"); // tooltip

    inicprompt1 = new QLabel("Left Initial Value"); // prompt for the initial values
    inicprompt2 = new QLabel("Right Initial Value");

    input_nsteps_spin_box -> setToolTip("The number of steps to take when numerically solving the function"); // set the tooltip

    // connect the double spinbox to the values
    QObject::connect(initial_condition1, SIGNAL(valueChanged(double)), this, SLOT(changeinicond1(double)));
    QObject::connect(initial_condition2, SIGNAL(valueChanged(double)), this, SLOT(changeinicond2(double)));

    // add the new component to layout
    paralayout->addWidget(initial_condition1, 5, 0);
    paralayout->addWidget(initial_condition2, 5, 1);
    paralayout->addWidget(inicprompt1, 4, 0);
    paralayout->addWidget(inicprompt2, 4, 1);

    // reset max and min of how many set you can take (the methods takes a long time for step size higher than this)
    input_nsteps_spin_box -> setMaximum(100); // set max and min for nsteps spinbox and nsteps slider
    input_nsteps_spin_box -> setMinimum(0);
    input_nsteps_spin_box -> setValue(50); // set default to 50

    //Sets the helpMenuButton for QMenuBar
    menuBar = new QMenuBar();
    helpMenuButton = new QMenu("Help?");
    menuBar->addMenu(helpMenuButton);
    helpMenuButton->addAction("Instructions");
    QObject::connect(helpMenuButton, SIGNAL(triggered(QAction*)), this, SLOT(MakeHelpWindow())); // connect help button to make help window when pressed
    ui->gridLayout->setMenuBar(menuBar);
    menuBar->setStyleSheet("background-color:rgb(240, 240, 240);"); // Sets background color to original grey color

    this->setMinimumSize(1080,880);
    showMaximized();
}

TwoPtrWindow::~TwoPtrWindow(){
}

void TwoPtrWindow::changeinicond1(double i){
    initial_cond1 = i; // change left initial cond
}

void TwoPtrWindow::changeinicond2(double i){
    initial_cond2 = i; // change right initial cond
}

/**
 * @fn	double hsprt2norm(const QVector<QVector<double>>& A, const QVector<double>& u, const QVector<double>& v, double h)
 *
 * @brief	Helper function, H2 norm of (A*u-v)
 *
 * @param	A		The matrix A.
 * @param	u		The vector u.
 * @param	v		The vector v.
 * @param	h	  	The stepsize.
 *
 * @return	A double that is the h,2 norm of (A*u-v).
 */

double hsprt2norm(const QVector<QVector<double>>& A, const QVector<double>& u, const QVector<double>& v, double h){
    int size = u.size(); // The size of all the matrix and vector
    double temp = 0; // temp for the loop
    QVector<double> result(size); // create a result vector for A*u-v
    for (int j = 0; j < size; ++j){ // calculate A*u
        for(int k = 0; k < size; ++k)
        {
            temp += u[k] * A[k][j];
        }
        result[j] = temp - v[j];
    }
    double normsquar = 0; // initialize norm^2
    for (int i = 0; i < size; ++i){ // calculate norm^2
        normsquar += pow(abs(result[i]),2);
    }
    double norm = sqrt(normsquar); // calculate norm
    norm = norm*sqrt(h); // calculate h norm
    return norm; // return the vale
}

void TwoPtrWindow::makepoints(){
    // exprtk commands
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double>     expression_t;
    typedef exprtk::parser<double>             parser_t;

    QString expr_string = function_str; // the function string

    double x = initial; // initialize x

    symbol_table_t symbol_table;
    symbol_table.add_variable("t",x); // add x as a variable

    // exprtk commands to parse the function
    expression_t expression;
    expression.register_symbol_table(symbol_table);
    parser_t parser;

    bool iffuncvalid = parser.compile(expr_string.toStdString(),expression); // check if the parser failed
    if (iffuncvalid){
        error->setText("Function Parser: No Error");
        error->setStyleSheet("color: black;"); // Font is black when there is no error
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

        errorSound = new QMediaPlayer;
        errorSoundFile = new QUrl("qrc:/Music/Computer Error-SoundBible.com-1655839472.mp3");
        errorSound->setMedia(*errorSoundFile); //Sets the error sound file to be playable
        errorSound->play(); //Plays the error sound when there is an actual error

        error->setText(errormsg); // print the error message
        error->setStyleSheet("color: red;"); // Font is red when there is error
        return; // do not plot the erroruous function
    }

    const double delta = (final-initial)/nsteps; // the step size

    QVector<QVector<double>> MatrixA(nsteps-1, QVector<double>(nsteps-1));
    // matrix A in the algorithm
    double fac = 1/(delta*delta); // fac = 1/delta^2

    // set the value of matrix A
    MatrixA[0][0] = -2*fac;
    MatrixA[0][1] = 1*fac;
    MatrixA[nsteps-2][nsteps-2] = -2*fac;
    MatrixA[nsteps-2][nsteps-3] = 1*fac;
    for (int i = 1; i < nsteps-2; ++i){
        MatrixA[i][i] = -2*fac;
        MatrixA[i][i-1] = 1*fac;
        MatrixA[i][i+1] = 1*fac;
    }

    QVector<double> vec_x; // vector of value of x
    for (int i = 0; i<nsteps-1; ++i){ // set the value of vec_x
        vec_x.push_back(initial+(i+1)*delta);
    }

    QVector<double> vec_f; // vector of value of f
    for (int i = 0; i<nsteps-1; ++i){ // set the value of vec_f
        x = vec_x[i];
        vec_f.push_back(expression.value()); // evaluated at x in the right position
    }

    vec_f[0] -= initial_cond1*fac; // minus the initial conditions as the alg goes
    vec_f[nsteps-2] -= initial_cond2*fac;

    QVector<double> results = QVector<double>(nsteps-1,0); // initialize the reulst to solve the matrix
    int count = 0; // the interation counter

    // Gauss–Seidel method
    constexpr int MAX_ITER= 1000; // max iteration the root finder can take
    constexpr double TOLERANCE = 0.01; // the tolerane of the root finder
    while (hsprt2norm(MatrixA, results, vec_f, delta)>TOLERANCE && count <MAX_ITER){
        // if the hnorn is large the the interation number is not exceeding the max
        QVector<double> results_prev = results; // save the previous result
        for (int i = 0; i < nsteps-1; ++i){ // do the Gauss–Seidel iteration
            results[i] = vec_f[i];
            for (int j = 0; j < i; ++j){
                results[i] -= MatrixA[i][j]*results[j];
            }
            for (int j = i+1; j < nsteps-1; ++j){
                results[i] -= MatrixA[i][j]*results_prev[j];
            }
            results[i] = results[i]/MatrixA[i][i];
        }
        ++count; // add to the counter
    }

    points.clear(); // clear the points vector

    std::pair <double,double> data_point;
    data_point = std::make_pair(initial,initial_cond1); // make the initial point
    points.push_back(data_point); // add the data point
    for (int i = 0; i < nsteps-1; ++i){
        data_point = std::make_pair(vec_x[i],results[i]); // make the points in the middle
        points.push_back(data_point); // add the data point
    }
    data_point = std::make_pair(final,initial_cond2); // make the final point
    points.push_back(data_point); // add the data point

    ++num_graph;
    makeplot();
}




