#ifndef ODESOLVERBASE_H
#define ODESOLVERBASE_H

#include <QWidget>
#include <QLabel>
#include "FunctionPlotWindows/functionplot/functionplot.h"

namespace Ui {
class ODESolverBase;
}

class ODESolverBase : public FunctionPlot{
    Q_OBJECT

 public:

    /**
     * @fn	explicit TwoPtrWindow::TwoPtrWindow(FunctionPlot *parent = nullptr);
     *
     * @brief	Constructor
     *
     * @param [in,out]	parent	(Optional) If non-null, the parent.
     */

    explicit ODESolverBase(FunctionPlot *parent = nullptr);

    /**
     * @fn	TwoPtrWindow::~TwoPtrWindow();
     *
     * @brief	Destructor
     */

    ~ODESolverBase() override;

     void makepoints() override;

 public slots:
     void changeinicond(double);

 protected:
     QDoubleSpinBox * initial_condition;
     QLabel * inicprompt;
     double initial_cond;

 };
#endif // ODESOLVERBASE_H
