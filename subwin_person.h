#ifndef SUBWIN_PERSON_H
#define SUBWIN_PERSON_H

#include "subwindow.h"
#include <QPushButton>

class SubWin_person : public SubWindow
{
public:
    SubWin_person(QWidget* parent = nullptr);

    void Disply();
private:
    QPushButton* btn;
};


#endif // SUBWIN_PERSON_H
