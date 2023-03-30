//单个set 多个add
#include "mainwindow.h"
#include <QMenuBar>
#include <QPushButton>
#include <QToolBar>
#include <QDebug>
#include <QWidget>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //重置窗口大小
    resize(600,400);
    //菜单栏只能有一个
    //菜单栏创建
    QMenuBar *bar = menuBar();
    //将菜单栏放入窗口中
    setMenuBar(bar);
    //创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    //创建菜单项
    QAction *newAction = fileMenu->addAction("新建");
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");

    //工具栏 可以有多个 //枚举值  一会自己看一下  不会的Qt::LeftToolBarArea
    QToolBar *toolbar = new QToolBar(this);
    //枚举值限制了工具栏的位置
    addToolBar(Qt::LeftToolBarArea,toolbar);

    //后期设置 只允许左右停靠
    toolbar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    //设置浮动
    toolbar->setFloatable(false);
    //设置移动(总开关)这个设置了没法移动了 上面的设置也就没有意义了
    toolbar->setMovable(false);

    //工具栏也可以设置内容
    toolbar->addAction(newAction);
    //添加分割线
    toolbar->addSeparator();
    toolbar->addAction(openAction);
    //工具栏中添加控件 例如按钮
    QPushButton *btn = new QPushButton("aa",this);
    toolbar->addWidget(btn);

    //状态栏最多有一个
    QStatusBar *stBar = statusBar();
    //设置到窗口中
    setStatusBar(stBar);
    //放一些标签控件
    QLabel *lable = new QLabel("提示信息",this);
    stBar->addWidget(lable);

    QLabel *lable1 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(lable1);
    //铆接部件 (浮动窗口)
    QDockWidget * doctWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,doctWidget);
    doctWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    //设置中心部件 只能有一个
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);
    //

}

MainWindow::~MainWindow()
{
}

