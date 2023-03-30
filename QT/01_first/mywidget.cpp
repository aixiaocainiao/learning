#include "mywidget.h"
#include <QPushButton>
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn = new QPushButton;
    btn->setParent(this);
    btn->setText("第一个按钮");

    //按钮可不可以 重新制定大小
    btn->resize(100,20);



    //创建第二个按钮 按照控件的大小创建窗口
    QPushButton *btn2 = new QPushButton("第二个按钮",this);
    //重置窗口大小
    this->resize(600,400);
    //设置固定窗口大小

    this->setFixedSize(600,400);
    //按钮移动
    btn2->move(100,100);

    setWindowTitle("第一个窗口");

    //需求 点击我的按钮 关闭窗口
    //参数1 信号的发送者  参数2 发送的信号
    connect(btn,&QPushButton::clicked,this,&myWidget::close);



}

myWidget::~myWidget()
{

}
