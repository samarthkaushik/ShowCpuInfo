/*
  MBRDNA Assignment
  The below application displays the Model/View architecture concepts in relation to the assignment provided by MBRDNA.
  Main.cpp
  @author Samarth Kaushik
  @version 1.0  09/14/2015
*/
#include "cpuinfodialogview.h"
#include <QApplication>

/* Main Application
 * Creates a new Dialog for viewing Cpu information
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CpuInfoDialogView w;
    w.show();

    return a.exec();
}
