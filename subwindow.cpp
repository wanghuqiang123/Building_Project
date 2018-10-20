#include "subwindow.h"

SubWindow::SubWindow(QWidget *parent) : QWidget(parent)
{

}
void SubWindow::Display()
{
    btn.setParent(this);
    btn.setText("wanghuqiang");
}


