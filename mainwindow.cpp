#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functionplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    setWindowTitle("Main Entry Menu:");

    title_prompt = new QLabel("Choose the features:");
    button_Plot = new QPushButton("Plot Function");
    button_Euler = new QPushButton("Euler's method");
    button_Bisec = new QPushButton("Bisection");

    //QObject::connect(button_Euler, SIGNAL(clicked()), &app, SLOT(quit()));
    centerlayout = new QGridLayout;
    centerlayout -> addWidget(title_prompt,0,0,Qt::AlignCenter);
    centerlayout -> addWidget(button_Plot,1,0);
    centerlayout -> addWidget(button_Euler,2,0);
    centerlayout -> addWidget(button_Bisec,3,0);

    centerpiece = new QWidget;

    centerpiece->setLayout(centerlayout);

    setCentralWidget(centerpiece);

    QObject::connect(button_Plot, SIGNAL(clicked()), this, SLOT(MakePlotWindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MakePlotWindow(){
    FunctionPlot *p_window = new FunctionPlot(); // make the particle window
    p_window->show(); // show the window
}
