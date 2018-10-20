#include "MainWindow.h"

void MainWindow::OptionBar_Person()
{
    setCentralWidget(SubWinMap["person"]);
    SubWinMap["person"]->Display();
}

void MainWindow::OptionBar_material()
{
//    setCentralWidget();
}
