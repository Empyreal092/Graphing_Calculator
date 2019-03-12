/**
 * This file is part of PIC 10C Final Project - A Graphic Calculator.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.

 * We declare that this work is our own.
 * We did this work honestly and can fully stand behind everything that we have written.
 * We did not copy code from anyone, student or otherwise, expect files we downloaded and have the permission to use.
 * We pledge that we have neither given nor received unauthorized assistance on making this project.

 * @file graphingwindow.cpp
 * @brief The implimentation file for the function plot window.
 *
 * This is the function plot window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */

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

    //Sets the sound menu button
    soundMenuButton = new QMenu("Sound");

    mute = new QAction("Mute");
    mute->setCheckable(true);
    mute->setChecked(false);
    menuBar->addMenu(soundMenuButton);
    soundMenuButton->addAction(mute);

    QObject::connect(mute, SIGNAL(triggered()), this, SLOT(muteErrorSound())); // connects mute button to mute the error sound

    // set minimum size of the window but when open default maximized
    this->setMinimumSize(1080,880);
    showMaximized();

}

GraphingWindow::~GraphingWindow(){
}

void GraphingWindow::makepoints(){
    // exprtk commands
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double>     expression_t;
    typedef exprtk::parser<double>             parser_t;

    QString expr_string = function_str; // the function string

    double x = initial; // initialize x

    symbol_table_t symbol_table;
    symbol_table.add_variable("t",x); // add x as a variable

    // exprtk commands to parse the function
    expression_t expression;
    expression.register_symbol_table(symbol_table);
    parser_t parser;

    bool iffuncvalid = parser.compile(expr_string.toStdString(),expression); // check if the parser failed
    if (iffuncvalid){
        error->setText("Function Parser: No Error");
        error->setStyleSheet("color: black;"); // Font is black when there is no error
    }
    if (!iffuncvalid) // if it failed
    {
        errormsg = "Function Parser: "; // save the error messages
        for (std::size_t i = 0; i < parser.error_count(); ++i)
              {
                 typedef exprtk::parser_error::type error_t;

                 error_t error = parser.get_error(i);
                 errormsg.append(error.diagnostic.c_str());
              }

        errorSound = new QMediaPlayer;
        errorSoundFile = new QUrl("qrc:/Music/Sound/Computer Error-SoundBible.com-1655839472.mp3");
        errorSound->setMedia(*errorSoundFile); //Sets the error sound file to be playable
        if(mutePressed == false) //If the error sound was muted
        {
            errorSound->play(); //Plays the error sound when there is an actual error
        }


        error->setText(errormsg); // print the error message
        error->setStyleSheet("color: red;"); // Font is red when there is error
        return; // do not plot the erroruous function
    }

    const double delta = (final-initial)/nsteps; // the step size

    points.clear(); // clear the points vector
    for (x = initial; x <= final; x += delta) // for all value points
    {
       double result = expression.value(); // evaluate the result of the function string
       std::pair <double,double> data_point = std::make_pair(x,result);
       points.push_back(data_point); // add the data point
    }
    ++num_graph; // add in number of plot
    makeplot(); // call makeplot
}

