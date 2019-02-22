#ifndef TWOPTRWINDOW_H
#define TWOPTRWINDOW_H

#include <QWidget>
#include "functionplot.h"

namespace Ui {
class TwoPtrWindow;
}

class TwoPtrWindow : public FunctionPlot{
    Q_OBJECT

public:
    explicit TwoPtrWindow(FunctionPlot *parent = nullptr);
    ~TwoPtrWindow();
};



#endif // TWOPTRWINDOW_H
