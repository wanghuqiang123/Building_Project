#include "MainWindow.h"

void MainWindow::OptionBar_Person()
{
    takeCentralWidget();
    setCentralWidget(SubWinMap[Person]);
    SubWinMap[Person]->Disply();
}

void MainWindow::OptionBar_material()
{
    takeCentralWidget();
    setCentralWidget(SubWinMap[Material]);
    SubWinMap[Material]->Disply();
}
