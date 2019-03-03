#include "trapezoidalmethod.h"

TrapezoidalMethod::TrapezoidalMethod(EulerMethod *parent) :
    EulerMethod(parent){

    setWindowTitle("Trapezoidal Method");
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
    symbol_table.add_variable("x",x); // add x as a variable

    // exprtk commands to parse the function
    expression_t expression;
    expression.register_symbol_table(symbol_table);
    parser_t parser;
    parser.compile(expr_string.toStdString(),expression);

    const double delta = (final-initial)/nsteps; // the step size

    //plot functions
    QVector<std::pair <double,double>> points; // the variable and value vector

    double result = initial_cond;
    constexpr int max_iter= 10000;
    constexpr double tolerance = 0.00001;

    double prev;

    for (double t = initial; t <= final; t += delta) // for all value points
    {
        int iter_num = 1;
        prev = result;
        double x0 = result*0.9;
        double x1 = result;
        double x2 = 0;
        double f2 = 1;
        while (( iter_num <= max_iter) && (abs(f2) >= tolerance)){
            x = prev;
            double fprev = expression.value();
            x = x0;
            double f0 = x-prev-0.5*delta*(fprev+expression.value());
            x = x1;
            double f1 = x-prev-0.5*delta*(fprev+expression.value());
            x2 = x1 - ((f1 * (x1 - x0)) / (f1 - f0));
            x = x2;
            f2 = x-prev-0.5*delta*(fprev+expression.value());
            x0 = x1;
            x1 = x2;
            ++iter_num;
            if (abs(f0 - f1) < tolerance){
                break;
            }
            result = x2; // evaluate the result of the function string
        }
        std::pair <double,double> data_point = std::make_pair(t,result);
        points.push_back(data_point); // add the data point
    }

    vec_points_to_plot.push_back(points);
}
