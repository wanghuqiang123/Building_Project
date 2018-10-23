#ifndef SUBWIN_MATERIAL_H
#define SUBWIN_MATERIAL_H

#include "subwindow.h"
#include <QPushButton>

class subwin_material:public SubWindow
{
public:
    subwin_material(QWidget* parent = nullptr);

    void Disply();

private:
    QPushButton* btn;
};

#endif // SUBWIN_MATERIAL_H
