#include "mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug>
//回头看一下列表 C++知识
//命名规范
//类名 首字母大写 ，单词和单词之间首字母大写
//函数名 变量名称 首字母小写  单词和单词之间首字母大写

//快捷键
//注释 ctrl + /
//运行 ctrl + r
//编译 ctrl + b

//字体缩放 ctrl + 鼠标滚轮
//查找 ctrl + f
//整行移动 ctrl + shift + ↑/↓
//帮助文档 F1
//自动对齐 ctrl + i
//同名之间的.h 和.cpp之间切换 F4
//帮助文档 第一种方式 F1 第二种方式 左侧按钮 第三种 桌面那个快捷键
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮、
    QPushButton *btn = new QPushButton;
    //btn->show();//show以顶层的方式弹出窗口
    //让btn对象依赖在myWidget窗口中
    //设置一个父亲这样才能在父亲窗口中显示出来
    btn->setParent(this);
    //显示文本
    btn->setText("第一个按钮");

    //设置第二个按钮
    //创建一个按钮、
    QPushButton *btn2 = new QPushButton("第二个按钮",this);

    //移动btn2按钮
    btn2->move(100,100);
    //按钮可不可以 按照控件的大小创建窗口
    btn2->resize(50,50);//可以的


    //重置窗口大小
    resize(600,400);

    //设置固定窗口大小
    setFixedSize(600,400);

    //设置窗口标题

    setWindowTitle("第一个窗口");



    //创建一个自己的按钮对象
    MyPushButton *mybtn = new MyPushButton;//这里报错看一下头文件的析构 其实是两个
    mybtn->setParent(this);//设置到对象树上 会自动释放堆栈
    mybtn->setText("我自己的按钮");
    mybtn->move(200,0);

    //需求 点击我的按钮 关闭窗口
    //参数一 信号的发送者 参数二 发送的信号（函数的地址） 参数三 信号的接受者 参数四 处理的槽函数
    //connect(mybtn,&MyPushButton::clicked,this,&myWidget::close);
    //继承的父类 可以用子类 也可以直接用父类
    connect(mybtn,&QPushButton::clicked,this,&QWidget::close);


}

myWidget::~myWidget()
{
    qDebug() << "myWidget的析构";
}

