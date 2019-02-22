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
    // default graph
    initial = -5.0; // default initial value
    final = 5.0; // default final value
    nsteps = 1000;
    ui->setupUi(this);

    setWindowTitle("Plotting Function"); // set the window title

    input = new QWidget(); // widget of inputs on the left of the window
    inputlayout = new QVBoxLayout(); // the layout of the input
    paralayout = new QGridLayout(); // layout for the initial and final
    functionstring = new QLineEdit(); // where the user input the function
    input_initial = new QDoubleSpinBox(); // a double spinbox for the initial
    input_final = new QDoubleSpinBox(); // a double spinbox for the final

    input_nsteps_spin_box = new QSpinBox(); // a double spinbox for the nsteps value
    nsteps_slider = new QSlider(Qt::Horizontal); // a double slider for the nsteps value

    input_initial -> setMaximum(1000); // set max and min for initial and final spinbox
    input_initial -> setMinimum(-1000);
    input_final -> setMaximum(1000);
    input_final -> setMinimum(-1000);

    input_nsteps_spin_box -> setMaximum(100); // set max and min for nsteps spinbox and nsteps slider
    input_nsteps_spin_box -> setMinimum(0);
    nsteps_slider -> setRange(0, 100);

    plotbutton = new QPushButton("Plot!"); // plot button

    QObject::connect(plotbutton, SIGNAL(clicked()), this, SLOT(changefstring()));
        // when plot pressed, change the function string
    QObject::connect(input_initial, SIGNAL(valueChanged(double)), this, SLOT(changeini(double)));
        // when user input new initial, change the initial value
    QObject::connect(input_final, SIGNAL(valueChanged(double)), this, SLOT(changefinal(double)));
        // when user input new final, change the final value

    QObject::connect(input_nsteps_spin_box, SIGNAL(valueChanged(int)), this, SLOT(changensteps(int)));
        // when user input new number of steps, change the nsteps value
    QObject::connect(nsteps_slider, SIGNAL(valueChanged(int)), this, SLOT(changensteps(int)));
        // when user moves slider, change the nsteps value
    QObject::connect(nsteps_slider, SIGNAL(valueChanged(int)), input_nsteps_spin_box, SLOT(setValue(int)));
        // when user moves slider, change the nsteps spin box value*/
    QObject::connect(input_nsteps_spin_box, SIGNAL(valueChanged(int)), nsteps_slider, SLOT(setValue(int)));
        // when user changes nsteps spin box, changes the nsteps slider

    promp_function = new QLabel ("Input function here:"); // some prompt to tell the user what to do
    promp_ini = new QLabel  ("T initial");
    promp_final = new QLabel  ("T final");
    promp_nsteps = new QLabel ("Num of steps");
    promp_nsteps_slider = new QLabel ("Num of steps slider");

    // set the formats into the layout
    inputlayout->addWidget(promp_function);
    inputlayout->addWidget(functionstring);
    paralayout->addWidget(promp_ini,0,0);
    paralayout->addWidget(promp_final,0,1);

    paralayout->addWidget(promp_nsteps,2,0);
    paralayout->addWidget(promp_nsteps_slider, 2, 1);

    paralayout->addWidget(input_initial,1,0);
    paralayout->addWidget(input_final,1,1);

    paralayout->addWidget(input_nsteps_spin_box,3,0);
    paralayout->addWidget(nsteps_slider, 3, 1);

    inputlayout->addLayout(paralayout);
    inputlayout->addWidget(plotbutton);

    input->setLayout(inputlayout);
    input->setMaximumWidth(250); // so that the input is not too big when the window is big

    FunctionPlot::makeplot<double>(); // call the make pot to plot the default graph

    ui->gridLayout->addWidget(input,0,0); // add input in the left of the window
}

void FunctionPlot::changefstring(){
    if (initial >= final){ // if initial is larger than final, do nothing
        return; // here should be error handeling
    }
    else{
        function_str = functionstring->text(); // change the function_str according to the input
        FunctionPlot::makeplot<double>(); // call make plot
    }
}

void FunctionPlot::changeini(double i){
    initial = i; // change initial
}

void FunctionPlot::changefinal(double i){
    final = i; // change final
}

void FunctionPlot::changensteps(int i){
    nsteps = i; // change nsteps
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

    QString expr_string = function_str; // the function string

    T x = T(initial); // initialize x

    symbol_table_t symbol_table;
    symbol_table.add_variable("x",x); // add x as a variable

	// exprtk commands to parse the function
    expression_t expression;  
    expression.register_symbol_table(symbol_table);
	parser_t parser;
    parser.compile(expr_string.toStdString(),expression);

    const T delta = T((final-initial)/nsteps); // the step size

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
    ui->customPlot->xAxis->setLabel("t");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data
    T max = *std::max_element(value.begin(), value.end());
    T min = *std::min_element(value.begin(), value.end());
    ui->customPlot->xAxis->setRange(T(initial)-0.1*abs(T(final)-T(initial)), T(final)+0.1*abs(T(final)-T(initial)));
    ui->customPlot->yAxis->setRange(min-0.1*abs(max-min), max+0.1*abs(max-min));
    ui->customPlot->replot(); // replot
}
