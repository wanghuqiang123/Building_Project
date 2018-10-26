#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>

class SubWindow:public QWidget
{
public:
    SubWindow(QWidget* parent):QWidget(parent)
    {

    }
    virtual ~SubWindow() = default;

    virtual void Disply() = 0;

};

#endif // SUBWINDOW_H
