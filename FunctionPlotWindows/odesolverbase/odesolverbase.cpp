#include "FunctionPlotWindows/odesolverbase/odesolverbase.h"

ODESolverBase::ODESolverBase(FunctionPlot *parent) :
    FunctionPlot(parent){


    setWindowTitle("ODE Solver Base"); // set window title
    plotbutton->setText("Solve!"); // set the button name
    plotbutton -> setToolTip("Graphically solving the ODE (Enter)"); // change tooltip

    initial_cond = 0.1; // default value

    functionstring -> setToolTip("The function to solve (Only use y as your variables)"); // change tooltip

    promp_function -> setText("Input function you want to solve here \n(Only use y as your variables):"); // some prompt to tell the user what to do

    initial_condition = new QDoubleSpinBox;
    initial_condition -> setMaximum(1000); // set max and min for initial and final spinbox
    initial_condition -> setMinimum(-1000);
    initial_condition -> setValue(initial_cond); // set default value
    initial_condition -> setToolTip("Input the initial condition here (y(t_initial))");

    input_nsteps_spin_box -> setToolTip("The number of steps to take when numerically solving the function"); // set the tooltip

    inputf_t -> setText("dy/dt := "); // the text in front of function string input
    inputf_t -> setMaximumWidth(50); // set size

    inicprompt = new QLabel("Initial Condition"); // tell user to input ini condition

    QObject::connect(initial_condition, SIGNAL(valueChanged(double)), this, SLOT(changeinicond(double)));
    // connect the double spinbox to the value of initial condition

    paralayout->addWidget(initial_condition, 3, 1);
    paralayout->addWidget(inicprompt, 2, 1);
}

ODESolverBase::~ODESolverBase(){
}

void ODESolverBase::changeinicond(double i){
    initial_cond = i; // change final
}
