#include "MainWindow.h"
#include "subwin_person.h"
#include "subwin_material.h"

bool MainWindow::initOptionBar()
{
    bool ret = true;

    QToolBar* ob = new QToolBar("Option Bar");
    addToolBar(Qt::TopToolBarArea,ob); //然后在对应的方向加入工具条;
    ob->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ob->setIconSize(QSize(50,50));

    ret = ret && initOptionBarItem(ob);

    return ret;
}

bool MainWindow::initOptionBarItem(QToolBar *ob)    //initial option bar item;
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && makeAction(action,ob,"人工",":/new/prefix1/UI_Icon/resources.png") && makeSubWindow(Person);
    if(ret)
    {
        ob->addAction(action);
        connect(action,SIGNAL(triggered(bool)),this,SLOT(OptionBar_Person()));
    }

    ret = ret && makeAction(action,ob,"材料",":/new/prefix1/UI_Icon/tasks.png") && makeSubWindow(Material);
    if(ret)
    {
        ob->addAction(action);
        connect(action,SIGNAL(triggered(bool)),this,SLOT(OptionBar_material()));
    }

    return ret;
}

bool MainWindow::makeSubWindow(SubWin_flag flag)
{
    bool ret = true;

    if(flag != 0)
    {
        SubWindow* temp = NULL;
        switch (flag)
        {
            case Person:
                temp = new SubWin_person(this->centralWidget());
                break;
            case Material:
                temp = new subwin_material(this->centralWidget());
                break;
            default:
                temp = NULL;
                break;
        }

        if(temp != NULL)
        {
            SubWinMap.insert(flag,temp);
        }
        else
        {
            ret = false;
        }
    }
    else
    {
        ret = false;
    }

    return ret;
}


bool MainWindow::makeAction(QAction* &action,QWidget* parent,QString tip,QString icon)
{
    bool ret = true;
    action = new QAction("",parent);

    if(action != NULL)
    {
        action->setIcon(QIcon(icon));
        action->setIconText(tip);
    }
    else
    {
        ret = false;
    }

    return ret;
}

