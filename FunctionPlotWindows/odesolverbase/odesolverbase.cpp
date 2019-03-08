#include "FunctionPlotWindows/odesolverbase/odesolverbase.h"

ODESolverBase::ODESolverBase(FunctionPlot *parent) :
    FunctionPlot(parent){

    setWindowTitle("ODE Solver Base");
    plotbutton->setText("Solve!");
    plotbutton -> setToolTip("Graphically solving the ODE (Enter)");

    initial_cond = 0.1; // default value

    functionstring -> setToolTip("The function to solve (Only use y as your variables)");

    promp_function -> setText("Input function you want to solve here \n(Only use y as your variables):"); // some prompt to tell the user what to do

    initial_condition = new QDoubleSpinBox;
    initial_condition -> setMaximum(1000); // set max and min for initial and final spinbox
    initial_condition -> setMinimum(-1000);
    initial_condition -> setValue(initial_cond); // set default value
    initial_condition -> setToolTip("Input the initial condition here (y(t initial))");

    inputf_t -> setText("dy/dt := ");
    inputf_t -> setMaximumWidth(50);

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
}
