#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QToolBar>
#include <QIcon>
#include <QMap>
#include <QString>
#include <QWidget>
#include "subwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum SubWin_flag{Person = 1,Material};

protected:
    /*** data memory ***/
    QMap<SubWin_flag,SubWindow*>SubWinMap;

    /*** data memory ***/

    MainWindow();
    MainWindow(const MainWindow&);
    MainWindow& operator = (const MainWindow&);

    bool construct();
//these are MenuBar initial;
    bool initMenuBar();
    bool initFileMenu(QMenuBar*);
    bool initViewMenu(QMenuBar*);
    bool initProjectMenu(QMenuBar*);
    bool initHelpMenu(QMenuBar*);
    bool makeAction(QAction*& action,QWidget* parent,QString text,int short_key);
//these are ToolBar initial:
    bool initToolBar();
    bool initPersonToolItem(QToolBar* tb);
    bool makeAction(QAction* &action,QWidget* parent,QString tip,QString icon);
/*** these are MainWindow Option Bar   *****/
    bool initOptionBar();
    bool initOptionBarItem(QToolBar* ob);
    bool makeSubWindow(SubWin_flag flag);

/***  option bar defined  ****/

    QAction* findMenuBarAction(QString text);
public:
    static MainWindow* NewInstance();
    ~MainWindow();
protected slots:
    void onFileMenu_Quit();
/*** these are opation bar slots ***/
    void OptionBar_Person();
    void OptionBar_material();
/***opation bar defined end***/
};

#endif // MAINWINDOW_H
