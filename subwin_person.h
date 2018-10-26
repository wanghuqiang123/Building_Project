#ifndef SUBWIN_PERSON_H
#define SUBWIN_PERSON_H

#include "subwindow.h"
#include <QPushButton>
#include <QObject>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QVBoxLayout>
#include <QToolBar>
#include <QAction>
#include <QList>
#include <QStringList>

class SubWin_person : public SubWindow
{
    enum{Name,Work_Days,PhoneNumber,Wages};
public:
    SubWin_person(QWidget* parent = nullptr);
    ~SubWin_person();

    void Disply();
protected:
    bool initUI();    //初始化界面
    bool initModel();   //初始化数据模型
    bool initview();        //初始化视图
    bool initToolBar(QToolBar* toolbar);  //初始化工具栏
    bool makeAction(QAction* &action,QWidget* parent,QString tip,QString icon);  //动作制造

private:
    struct DataItem
    {
        QStandardItem* name;             //工资
        QStandardItem* Work_days;        //总工作天数
        QStandardItem* PhontNumber;     //手机号
        QStandardItem* Wages;           //总工资
    };

    QStandardItemModel m_model;
    QTableView m_view;
    QPushButton Edit_Btn;
    QPushButton Clear_Btn;
    QToolBar TB;
    QVBoxLayout VLayout;
    QStringList HeadTableList;
};


#endif // SUBWIN_PERSON_H
