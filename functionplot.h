#ifndef FUNCTIONPLOT_H
#define FUNCTIONPLOT_H

#include <QWidget>
#include "qcustomplot.h"
#include "ui_functionplot.h"

namespace Ui {
class FunctionPlot;
}

class FunctionPlot : public QWidget{
    Q_OBJECT

public:
    explicit FunctionPlot(QWidget *parent = 0);
    ~FunctionPlot();
    void makeplot();

private:
  Ui::FunctionPlot *ui;
};

#endif // FUNCTIONPLOT_H
