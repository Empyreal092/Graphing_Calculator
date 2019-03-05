#include "trapezoidalmethod.h"

TrapezoidalMethod::TrapezoidalMethod(ODESolverBase *parent) :
    ODESolverBase(parent){
    setWindowTitle("Trapezoidal Method"); // rename the window
}

TrapezoidalMethod::~TrapezoidalMethod(){
}

void TrapezoidalMethod::makepoints(){
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
    parser.compile(expr_string.toStdString(),expression);

    const double delta = (final-initial)/nsteps; // the step size

    //plot functions
    QVector<std::pair <double,double>> points; // the variable and value vector

    double result = initial_cond; // initialize the result first as the initial condition
    constexpr int MAX_ITER= 10000; // max iteration the root finder can take
    constexpr double TOLERANCE = 0.00001; // the tolerane of the root finder

    double prev; // the previous result, used in the loop

    std::pair <double,double> data_point = std::make_pair(initial,result); // initial point
    points.push_back(data_point); // add the data point
    for (double t = initial; t <= final; t += delta) // for all value points
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
            x = prev; // set x as prev
            double fprev = expression.value(); // evaluate f(prev)
            x = x0; // set x as x0
            double f0 = x-prev-0.5*delta*(fprev+expression.value()); // evaluate the function that we try to solve for
            x = x1; // set x as x1
            double f1 = x-prev-0.5*delta*(fprev+expression.value()); // evaluate the function that we try to solve for
            x2 = x1 - ((f1 * (x1 - x0)) / (f1 - f0));
            x = x2; // set x as x2
            f2 = x-prev-0.5*delta*(fprev+expression.value()); // evaluate the function that we try to solve for
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

    vec_points_to_plot.push_back(points); // add the points of the graph to the vector of graphs to plot
    funstr_vec.push_back(function_str); // save the function string in a vetor

    int r; int g; int b; // rgb paramaters
    do{ // randomize
        r = QRandomGenerator::global()->bounded(0, 255);
        g = QRandomGenerator::global()->bounded(0, 255);
        b = QRandomGenerator::global()->bounded(0, 255);
    }
    while (r+g+b<300); // if the color is too light do it again

    reds.push_back(r); // save the color int to vectors
    greens.push_back(g);
    blues.push_back(b);
}
