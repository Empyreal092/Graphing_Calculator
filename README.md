# Graphic Calculator

This application is a graphic calculator. It can solve Ordinary Differential Equations and Two Point Boundary Value Problems.

## Motivation

It has three main functionalities:
 - Plotting Function
 - Graphically solving (Autonomous) Ordinary Differential Equation (ODE)
 - Graphically solving Two Point Boundary Value Problem
 
## Screenshots

### Plotting Function
![GraphingWindow.png](https://github.com/Empyreal092/PIC10C_Final_Project-Graphic_Calc/blob/master/Screenshot/GraphingWindow.png)
### Euler's Method
![EulerMethod.png](https://github.com/Empyreal092/PIC10C_Final_Project-Graphic_Calc/blob/master/Screenshot/EulerMethod.png)
### Two Point Boundary Value Problem
![TwoPtrWindow.png](https://github.com/Empyreal092/PIC10C_Final_Project-Graphic_Calc/blob/master/Screenshot/TwoPtrWindow.png)

## Features

- Plotting Function
- Graphically solving (Autonomous) Ordinary Differential Equation (ODE) with the folloing methods
  - Euler’s Method
  - Backward Euler Method
  - 2nd Order Runge-Kutta Method
  - 4th Order Runge-Kutta Method
  - Trapezoidal Method
- Graphically solving Two Point Boundary Value Problem (with  Dirichlet boundary conditions)

## Prerequisites

Built and Tested using Qt-5.12.0 MSVC-2017 (64-bits)

## Potentian Compiling error

This section is about possible reasons for the code fail to compile in other Environment and possible directions to solve them.

### FLAG: /bigobj

If the error message mentions `bigobj` in some way, then these lines in `"PIC10C_Final_Project-Graphic_Calc.pro"` might be the source of trouble. 
```prolog
# Prevents "fatal error C1128: number of sections exceeded object file format limit".
win32-msvc : QMAKE_CXXFLAGS += /bigobj # for MSVC compilers
win32-g++ : QMAKE_CXXFLAGS += -Wa,-mbig-obj # for MinGW compilers
# but the project still does not complie for MinGW because some files exceed the hard limit for the compiler. To be solved if you want to compile using MinGW
```
Unfortunatly these lines must be there because `Exprtk.hpp` exceed the default build limit of certain compiler and these lines allow us to exceed that limit. Make sure to use the setting stated in **Prerequisites** avoid the error. If you are using other compilers and the error appear, try to find ways to allow the build to exceed the build limit. You could also try commenting out those lines but I am pretty confident that those commands are restricted so that they only apply to the correct situation. 

Here are some links that I found useful when I was trying to solve this problem:
- [/bigobj Flag for MSVC](https://docs.microsoft.com/en-us/cpp/build/reference/bigobj-increase-number-of-sections-in-dot-obj-file?view=vs-2017)
- [How to refer to certain compiler](https://doc.qt.io/qt-5/qmake-environment-reference.html)
- [Qt Documentation about QtProject file, specifically: `QMAKE_CXXFLAGS`](https://doc.qt.io/qt-5/qmake-variable-reference.html)
- [A thread on how to add the bigobj flag for WinGW](https://stackoverflow.com/questions/16596876/object-file-has-too-many-sections)

### Cannot find file

You might see an error like `:-1: error: dependent '..\PIC10C_Final_Project-Graphic_Calc\FunctionPlotWindows\...\...\...' does not exist.` This error is because there is a certain limit on how long a file path could be. Our folder names plus file names might exceed that limit. The easiest way to solve this problem is by reducing the lenghth of the outmost folder name, e.g.: change `PIC10C_Final_Project-Graphic_Calc` to `Calc`. 

## Packages used
 
- [Exprtk](https://github.com/ArashPartow/exprtk)
- [QCustomPlot](https://www.qcustomplot.com/)

## Authors

- Ryan Du ([Empyreal092](https://github.com/Empyreal092))
- Firat Taxpulat ([FT-1984](https://github.com/FT-1984))
- Anita Chen ([achen1105](https://github.com/achen1105))

## Acknowledgments

This project is the Final Project for PIC 10C. Advanced Programming in UCLA. 

We declare that this work is our own. We did this work honestly and can fully stand behind everything that we have written. We did not copy code from anyone, student or otherwise, expect files we downloaded and have the permission to use. We pledge that we have neither given nor received unauthorized assistance on making this project.


## License

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.
