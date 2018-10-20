#include "MainWindow.h"


bool MainWindow::initOptionBar()
{
    bool ret = true;

    QToolBar* ob = new QToolBar("Option Bar");
    addToolBar(Qt::LeftToolBarArea,ob); //然后在对应的方向加入工具条;


    ob->setIconSize(QSize(50,50));

    ret = ret && initOptionBarItem(ob);

    return ret;
}

bool MainWindow::initOptionBarItem(QToolBar *ob)    //initial option bar item;
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && makeAction(action,ob," ",":/new/prefix1/UI_Icon/resources.png") && makeSubWindow("person");
    if(ret)
    {
        ob->addAction(action);
        connect(action,SIGNAL(triggered(bool)),this,SLOT(OptionBar_Person()));
    }

    ret = ret && makeAction(action,ob," ",":/new/prefix1/UI_Icon/tasks.png") && makeSubWindow("meterial");
    if(ret)
    {
        ob->addAction(action);
        connect(action,SIGNAL(triggered(bool)),this,SLOT(OptionBar_material()));
    }

    return ret;
}
bool MainWindow::makeSubWindow(QString name)
{
    bool ret = true;

    if(name != "")
    {
        SubWindow* temp = new SubWindow(this->centralWidget());
        if(temp != NULL)
        {
            SubWinMap.insert(name,temp);
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
