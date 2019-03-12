#-------------------------------------------------
#
# Project created by QtCreator 2019-01-22T10:20:10
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = PIC10C_Final_Project-Graphic_Calc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

INCLUDEPATH += main
INCLUDEPATH += QWidgetInterfaceWindows
INCLUDEPATH += FunctionPlotWindows
INCLUDEPATH += mainwindow
INCLUDEPATH += qcustomplot
INCLUDEPATH += exprtk

SOURCES += \
    QWidgetInterfaceWindows/creditswindow/creditswindow.cpp \
    FunctionPlotWindows/ODESolvingMethods/Backeulermethod/Backeulermethod.cpp \
    QWidgetInterfaceWindows/diffeqsolver/diffeqsolver.cpp \
    FunctionPlotWindows/ODESolvingMethods/eulermethod/eulermethod.cpp \
    FunctionPlotWindows/functionplot/functionplot.cpp \
    mainwindow/mainwindow.cpp \
    FunctionPlotWindows/ODESolvingMethods/rk4method/rk4method.cpp \
    FunctionPlotWindows/ODESolvingMethods/trapezoidalmethod/trapezoidalmethod.cpp \
    FunctionPlotWindows/twoptrwindow/twoptrwindow.cpp \
    FunctionPlotWindows/graphingwindow/graphingwindow.cpp \
    QWidgetInterfaceWindows/helpwindow/helpwindow.cpp \
    main/main.cpp \
    FunctionPlotWindows/odesolverbase/odesolverbase.cpp \
    qcustomplot/qcustomplot.cpp \
    FunctionPlotWindows/ODESolvingMethods/RK2method/RK2method.cpp

HEADERS += \
    FunctionPlotWindows/ODESolvingMethods/Backeulermethod/Backeulermethod.h \
    QWidgetInterfaceWindows/creditswindow/creditswindow.h \
    QWidgetInterfaceWindows/diffeqsolver/diffeqsolver.h \
    FunctionPlotWindows/ODESolvingMethods/eulermethod/eulermethod.h \
    exprtk/exprtk.hpp \
    FunctionPlotWindows/functionplot/functionplot.h \
    FunctionPlotWindows/graphingwindow/graphingwindow.h \
    QWidgetInterfaceWindows/helpwindow/helpwindow.h \
    mainwindow/mainwindow.h \
    FunctionPlotWindows/odesolverbase/odesolverbase.h \
    FunctionPlotWindows/ODESolvingMethods/RK2method/RK2method.h \
    FunctionPlotWindows/ODESolvingMethods/rk4method/rk4method.h \
    FunctionPlotWindows/ODESolvingMethods/trapezoidalmethod/trapezoidalmethod.h \
    FunctionPlotWindows/twoptrwindow/twoptrwindow.h \
    qcustomplot/qcustomplot.h

FORMS += \
    FunctionPlotWindows/functionplot/functionplot.ui \
    mainwindow/mainwindow.ui

# Prevents "fatal error C1128: number of sections exceeded object file format limit".
win32-msvc : QMAKE_CXXFLAGS += /bigobj # for MSVC compilers
win32-g++ : QMAKE_CXXFLAGS += -Wa,-mbig-obj # for MinGW compilers
# but the project still does not complie for MinGW because some files exceed the hard limit for the compiler. To be solved if you want to compile using MinGW


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    LICENSE.md \
    README.md \
    Screenshot/GraphingWindow.png \
    Screenshot/TwoPtrWindow.png \
    Screenshot/CreditWindow.png \
    Screenshot/HelpWindow.png \
    Screenshot/MainWindow.png \
    Screenshot/GraphingFunction.png \
    Screenshot/Twoptr.png \
    Screenshot/EulerMethod.png \
    Screenshot/TrapMethod.png

SUBDIRS += \
    PIC10C_Final_Project-Graphic_Calc.pro

RESOURCES += \
    resources.qrc


