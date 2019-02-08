#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    setWindowTitle("Main Entry Menu:");

    title_prompt = new QLabel("Choose the feature:");
    button_Euler = new QPushButton("Euler's method");
    button_Bisec = new QPushButton("Bisection");
    button_Inter = new QPushButton("Interpolation");

    //QObject::connect(button_Euler, SIGNAL(clicked()), &app, SLOT(quit()));
    centerlayout = new QGridLayout;
    centerlayout -> addWidget(title_prompt,0,0,Qt::AlignCenter);
    centerlayout -> addWidget(button_Euler,1,0);
    centerlayout -> addWidget(button_Bisec,2,0);
    centerlayout -> addWidget(button_Inter,3,0);

    centerpiece = new QWidget;

    centerpiece->setLayout(centerlayout);

    setCentralWidget(centerpiece);
}

MainWindow::~MainWindow()
{
    delete ui;
}
