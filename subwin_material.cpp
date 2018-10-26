#include "subwin_material.h"

subwin_material::subwin_material(QWidget* parent):SubWindow(parent)
{
    btn = new QPushButton();
}

void subwin_material::Disply()
{
    btn->setParent(this);
    btn->setText("material");
}

 subwin_material::~subwin_material()
 {
    delete this->btn;
 }
