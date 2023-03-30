#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //使用添加QT资源 “+前缀名 + 文件名”
    ui->actionnew->setIcon(QIcon(":/Image/02.png"));
    ui->actionopen->setIcon(QIcon(":/Image/03.jpg"));
}


MainWindow::~MainWindow()
{
    delete ui;
}
