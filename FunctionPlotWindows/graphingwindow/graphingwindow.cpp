#include "FunctionPlotWindows/graphingwindow/graphingwindow.h"

GraphingWindow::GraphingWindow(FunctionPlot *parent) : FunctionPlot(parent)
{
    //Sets the helpMenuButton for QMenuBar
    menuBar = new QMenuBar();
    helpMenuButton = new QMenu("Help?");
    menuBar->addMenu(helpMenuButton);
    helpMenuButton->addAction("Instructions");
    QObject::connect(helpMenuButton, SIGNAL(triggered(QAction*)), this, SLOT(MakeHelpWindow())); // connect help button to make help window when pressed
    ui->gridLayout->setMenuBar(menuBar);
    menuBar->setStyleSheet("background-color:rgb(240, 240, 240);"); // Sets background color to original grey color

    this->setMinimumSize(1080,880);
    showMaximized();
}

GraphingWindow::~GraphingWindow(){
}
