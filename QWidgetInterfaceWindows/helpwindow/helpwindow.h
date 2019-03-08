#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QFile>

/**
 * @class	helpWindow
 *
 * @brief	A help window.
 */

class helpWindow: public QWidget
{
    Q_OBJECT

public:

    /**
     * @fn	helpWindow();
     *
     * @brief	Default constructor
     *
     */

    helpWindow();


private:

QFile* instructionsTextFile;
QLabel* instructionsText;
QString* instructionsReadLine;
};

#endif // HELPWINDOW_H
