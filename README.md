# Graphing Calculator

This application is a graphic calculator. It can solve Ordinary Differential Equations and Two Point Boundary Value Problems. 

This project is on Github at [Graphing_Calculator](https://github.com/Empyreal092/Graphing_Calculator). 

<!---
This README file uses Markdown and read it on Github will give you a better exprience. Link: https://github.com/Empyreal092/Graphing_Calculator/blob/master/README.md
-->

## Motivation

It has three main functionalities:
 - Plotting Function
 - Graphically solving (Autonomous) Ordinary Differential Equation (ODE)
 - Graphically solving Two Point Boundary Value Problem
 
## Features

- Plotting Function
- Graphically solving (Autonomous) Ordinary Differential Equation (ODE) with the folloing methods
  - Euler’s Method
  - Backward Euler Method
  - 2nd Order Runge-Kutta Method
  - 4th Order Runge-Kutta Method
  - Trapezoidal Method
- Graphically solving Two Point Boundary Value Problem (with  Dirichlet boundary conditions)
 
## Screenshots

### Main Window
![MainWindow.png](https://github.com/Empyreal092/Graphing_Calculator/blob/master/Screenshot/MainWindow.png)
### Plotting Function
![GraphingFunction.png](https://github.com/Empyreal092/Graphing_Calculator/blob/master/Screenshot/GraphingFunction.png)
### Solving ODE (Euler's Method)
![EulerMethod.png](https://github.com/Empyreal092/Graphing_Calculator/blob/master/Screenshot/EulerMethod.png)
### Solving ODE (Trapezoidal Method)
![TrapMethod.png](https://github.com/Empyreal092/Graphing_Calculator/blob/master/Screenshot/TrapMethod.png)
### Two Point Boundary Value Problem
![Twoptr.png](https://github.com/Empyreal092/Graphing_Calculator/blob/master/Screenshot/Twoptr.png)

## Prerequisites

Developed using Qt Creator 4.8.0 (Community). Building using compiler Qt 5.12.0 MSVC2017 (64bit) and Qt 5.12.0 clang (64bit)

## Potential Compiling Error

This section is about possible reasons for the code fail to compile in other Environment and possible directions to solve them.

### FLAG: /bigobj

If the error message mentions `exceed limit`, `file too big` or `bigobj` in some way, then these lines in `"Graphing_Calculator.pro"` might be the source of trouble. 
```prolog
# Prevents "fatal error C1128: number of sections exceeded object file format limit".
win32-msvc : QMAKE_CXXFLAGS += /bigobj
win32-g++ : QMAKE_CXXFLAGS += -Wa,-mbig-obj
```
Unfortunatly these lines must be there because `Exprtk.hpp` exceed the default build limit of certain compiler and these lines allow us to exceed that limit. Make sure to use the setting stated in **Prerequisites** to avoid the error. If you are using other compilers and the error appear, try to find ways to allow the build to exceed the build limit. You could also try commenting out those lines but we are pretty confident that those commands are restricted so that they only apply to the correct situation. 

Here are some links that I found useful when I was trying to solve this problem:
- [/bigobj Flag for MSVC](https://docs.microsoft.com/en-us/cpp/build/reference/bigobj-increase-number-of-sections-in-dot-obj-file?view=vs-2017)
- [How to refer to certain compiler (the section about QMAKESPEC)](https://doc.qt.io/qt-5/qmake-environment-reference.html)
- [Qt Documentation about QtProject file, specifically: `QMAKE_CXXFLAGS`](https://doc.qt.io/qt-5/qmake-variable-reference.html)
- [A thread on how to add the bigobj flag for WinGW](https://stackoverflow.com/questions/16596876/object-file-has-too-many-sections)
- [But program still cannot compile using WinGW, ran into problem similar to this post](http://mingw-users.1079350.n2.nabble.com/File-too-big-too-many-sections-td7579168.html)

### Cannot find file

You might see an error like `:-1: error: dependent '..\Graphing_Calculator-master\FunctionPlotWindows\...\...\...' does not exist.` This error is because there is a certain limit on how long a file path (DOS notation) could be. Our folder names plus file names might exceed that limit. The easiest way to solve this problem is by reducing the lenghth of the outmost folder name, e.g.: change `Graphing_Calculator-master` to `GC_m`. 

## Packages used
 
- [Exprtk](https://github.com/ArashPartow/exprtk)
  - Exprtk enables us to read the function (e.g.: y = sin(t) ) user entered (as a string). When given a value (e.g.: t=2), it evaluates the value of the function at that point (e.g.: gives us sin(2) ).
- [QCustomPlot](https://www.qcustomplot.com/)
  - Qt class for plotting function. 
  
## Numerical Methods

The Numerical Methods used in the program is based on the Math 151B course (Winder 2019), taught by Professor [Chris Anderson](http://www.math.ucla.edu/~anderson/). The textbook used in the course is *Numerical Analysis* by Burden and Faires (10th edition).

## Future Planned Features

- Be able to solve system of first order ODE.
- Be able to solve non-automonous ODE.
- Give user more options for parameters. (E.g.: change tolerence for in Secant methods and Gauss-Seidel methods).
- Represent error bounds on the graph.

## Authors

- Ryan Du ([Empyreal092](https://github.com/Empyreal092))
- Firat Taxpulat ([FT-1984](https://github.com/FT-1984))
- Anita Chen ([achen1105](https://github.com/achen1105))

## Acknowledgments

This project is the Final Project for PIC 10C. Advanced Programming at UCLA (Winter 2019) taught by [Claudia Falcon](http://www.math.ucla.edu/~cfalcon/) and TA by [Michael Puthawala](http://math.ucla.edu/~mputhawala/). We appreciate their help in the process of making this program.

We declare that this work is our own. We did this work honestly and can fully stand behind everything that we have written. We did not copy code from anyone, student or otherwise, except files we downloaded and have the permission to use. We pledge that we have neither given nor received unauthorized assistance on making this project.


## License

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.
