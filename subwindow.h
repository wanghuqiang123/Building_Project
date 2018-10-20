#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
#include <QPushButton>
class SubWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SubWindow(QWidget *parent = nullptr);

    void Display();
private:
    QPushButton btn;

};

#endif // SUBWINDOW_H
