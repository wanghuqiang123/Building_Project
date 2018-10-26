
#include "subwin_person.h"

SubWin_person::SubWin_person(QWidget* parent):SubWindow(parent)
{
    HeadTableList.append("名字");
    HeadTableList.append("工作天数");
    HeadTableList.append("手机号");
    HeadTableList.append("工资（记录总共）");

    initUI();       //初始化界面
    initview();     //初始化视图
    initModel();    //初始化模型
}

void SubWin_person::Disply()
{
    this->show();   //当调用此函数时  显示子窗口；
}

bool SubWin_person::initUI()
{
    bool ret = true;

    initToolBar(&TB);

    VLayout.addWidget(&TB);
    VLayout.addSpacing(5);       //这里使工具栏挨着QWidget顶部；下面的Spcing距离为5；
    VLayout.addWidget(&m_view);

    setLayout(&VLayout);

    return ret;
}

bool SubWin_person::initToolBar(QToolBar* toolbar)
{
    bool ret = true;
    toolbar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* action = NULL;

    ret = ret && makeAction(action,toolbar,"删除项",":/new/prefix1/UI_Icon/24_remove_task.png");
    if(ret)
    {
        toolbar->addAction(action);
    }

    return ret;
}


bool SubWin_person::initModel()
{
    bool ret = true;

    QStandardItem* root = m_model.invisibleRootItem();

    if(m_model.rowCount() == 0)
    {
        m_model.setHorizontalHeaderLabels(HeadTableList);
    }

    if(root != NULL)
    {
        //从对空间中分配出每一项，然后设置这些想的数据，再把这些数据项加入到标准模型中，加入到对应的位置
        QStandardItem* name = new QStandardItem();
        QStandardItem* Work_days = new QStandardItem();
        QStandardItem* PhontNumber = new QStandardItem();
        QStandardItem* Wages = new QStandardItem();

        name->setData("张三",Qt::DisplayRole);
        Work_days->setData(5,Qt::DisplayRole);
        PhontNumber->setData(123456789,Qt::DisplayRole);
        Wages->setData(900,Qt::DisplayRole);

        int newRow = m_model.rowCount();

        root->setChild(newRow,0,name);
        root->setChild(newRow,1,Work_days);
        root->setChild(newRow,2,PhontNumber);
        root->setChild(newRow,3,Wages);
    }
    else
    {
        ret = false;
    }

    return ret;
}

bool SubWin_person::initview()
{
    bool ret = true;

    m_view.setModel(&m_model);      //视图类显示的数据模型
    m_view.setParent(this);         //设置视图类所在的父类
    m_view.setMinimumSize(800,500); //设置视图的最小尺寸

    return ret;
}


bool SubWin_person::makeAction(QAction* &action,QWidget* parent,QString tip,QString icon)
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


SubWin_person::~SubWin_person()
{

}
