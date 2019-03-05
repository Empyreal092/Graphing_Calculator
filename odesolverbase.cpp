#include "odesolverbase.h"

ODESolverBase::ODESolverBase(FunctionPlot *parent) :
    FunctionPlot(parent){

    setWindowTitle("ODE Solver Base");
    plotbutton->setText("Solve!");
    plotbutton -> setToolTip("Solve the ODE");

    functionstring -> setToolTip("The function to solve");

    promp_function -> setText("Input function you want to solve here \n(Only use y as your variables):"); // some prompt to tell the user what to do

    initial_condition = new QDoubleSpinBox;
    initial_condition -> setMaximum(1000); // set max and min for initial and final spinbox
    initial_condition -> setMinimum(-1000);
    initial_condition -> setToolTip("Input the initial condition here");

    inicprompt = new QLabel("Initial Condition");

    QObject::connect(initial_condition, SIGNAL(valueChanged(double)), this, SLOT(changeinicond(double)));

    paralayout->addWidget(initial_condition, 3, 1);
    paralayout->addWidget(inicprompt, 2, 1);
}

ODESolverBase::~ODESolverBase(){

}

void ODESolverBase::changeinicond(double i){
    initial_cond = i; // change final
}


void ODESolverBase::makepoints(){
    // exprtk commands
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double>     expression_t;
    typedef exprtk::parser<double>             parser_t;

    QString expr_string = function_str; // the function string

    double x = initial; // initialize x

    symbol_table_t symbol_table;
    symbol_table.add_variable("y",x); // add x as a variable

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
