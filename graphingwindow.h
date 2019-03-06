#ifndef GRAPHINGWINDOW_H
#define GRAPHINGWINDOW_H

#include <QWidget>
#include "functionplot.h"

namespace Ui {
class GraphingWindow;
}

class GraphingWindow : public FunctionPlot
{
    Q_OBJECT

public:

    explicit GraphingWindow(FunctionPlot *parent = nullptr);
    ~GraphingWindow() override;

};

#endif // GRAPHINGWINDOW_H
