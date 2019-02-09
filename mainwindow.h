#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel *title_prompt;

    QPushButton* button_Plot;
    QPushButton* button_Euler;
    QPushButton* button_Bisec;

    QGridLayout *centerlayout;
    QWidget *centerpiece;

public slots:
    void MakePlotWindow();

};

#endif // MAINWINDOW_H
