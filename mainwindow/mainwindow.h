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

 * @file mainwindow.h
 * @brief The header file for the entry main window.
 *
 * This is the entry window for the project.
 *
 * @author Ryan Du (Empyreal092)
 * @author Firat Taxpulat (FT-1984)
 * @author Anita Chen (achen1105)
 *
 * @bug No known bugs, but more features to be added
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QToolBar>
#include <QToolButton>
#include <QMediaPlayer>
#include <QUrl>

namespace Ui {
class MainWindow;
}

/**
 * @class	MainWindow
 *
 * @brief	The main window class.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @fn	explicit MainWindow::MainWindow(QWidget *parent = nullptr);
     *
     * @brief	Constructor
     *
     * @param [in,out]	parent	(Optional) If non-null, the parent.
     */

    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @fn	MainWindow::~MainWindow();
     *
     * @brief	Destructor
     */

    ~MainWindow();

private:
    /** @brief	The user interface */
    Ui::MainWindow *ui;

    /** @brief The first part of title */
    QLabel *title1;
    /** @brief The second part of title */
    QLabel *title2;
    /** @brief	The title prompt */
    QLabel *title_prompt;

    /** @brief	The button for plot function */
    QPushButton* button_Plot;
    /** @brief	The button for Euler's method, do nothing rn */
    QPushButton* button_ODE;
    /** @brief	The button for bisection method, do nothing rn */
    QPushButton* button_2ptr;
    /** @brief  The menubar for the main window */
    QMenuBar* menuBar;
    /** @brief  The button to see the credits */
    QMenu* creditsButton;
    /** @brief  The button to see the instructions */
    QMenu* helpMenu;

    /** @brief	The centerlayout */
    QGridLayout *centerlayout;
    /** @brief	The centerpiece for mainwindow */
    QWidget *centerpiece;

    /** @brief	The source of the sound in main window */
    QMediaPlayer* sound;
    /** @brief	Determines whether or not the sound is on or off */
    bool soundOn = true;

public slots:

    /**
     * @fn	void MainWindow::MakePlotWindow();
     *
     * @brief	Makes the plot window
     */
    void MakePlotWindow();
    /**
     * @fn	void MainWindow::MakeEulerWindow();
     *
     * @brief	Makes the Euler window
     */
    void MakeODEWindow();
    /**
     * @fn	void MainWindow::MakeBisecWindow();
     *
     * @brief	Makes the bisec window
     */
    void Make2ptrcWindow();
    /**
     * @fn	void MainWindow::MakeCreditsWindow();
     *
     * @brief	Makes the credits window
     */
    void MakeCreditsWindow();
    /**
     * @fn	void MainWindow::MakeHelpWindow();
     *
     * @brief	Makes the help window
     */
    void MakeHelpWindow();
    /**
     * @fn	void MainWindow::MakeLicenseWindow();
     *
     * @brief	Makes the license window
     */
    void MakeLicenseWindow();
    /**
     * @fn	void MainWindow::changeSound();
     *
     * @brief	Mutes or unmutes the program's sound
     */
    void changeSound();
};

#endif // MAINWINDOW_H
