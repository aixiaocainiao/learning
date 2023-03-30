#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPushButton>
#include <QDebug>
//Teacher 类 老师类
//Student 类 学生类
//下课后 老师会触发一个信号 饿了 学生相应这个信号 请客吃饭
myWidget::myWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myWidget)
{
    ui->setupUi(this);

    //创建一个老师的对象
    this->zt = new Teacher(this);

    //创建一个学生的对象
    this->st = new Student(this);

    //老师饿了 学生请吃饭

    //connect(zt,&Teacher::hungry,st,&Student::treat);
    //调用下课函数(先连接在调用才能触发 有先后逻辑顺序)

    //ClassIsOver();

    //链接带参的信号和槽函数
    //指针->地址
    //函数指针->函数地址
        void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
        void(Student:: *studentSignal)(QString) = &Student::treat;
        connect(zt,teacherSignal,st,studentSignal);

    //ClassIsOver();

    //点击一个下课的按钮，再触发下课
    QPushButton *btn = new QPushButton("下课",this);
    //重置 窗口大小
    this->resize(600,400);

    btn->resize(100,20);
    //点击按钮 触发下课
    //connect(btn,&QPushButton::clicked,this,&myWidget::ClassIsOver);

    //无参的信号槽版本
    void(Teacher:: *teacherSignal1)(void) = &Teacher::hungry;
    void(Student:: *studentSignal1)(void) = &Student::treat;
    connect(zt,teacherSignal1,st,studentSignal1);

    //信号链接信号 就不用触发下课函数了就可以直接触发
    //connect(btn,&QPushButton::clicked,zt,teacherSignal1);
    //断开信号
    //disconnect(zt,teacherSignal1,st,studentSignal1);

    //拓展
    //1.信号可以链接信号
    //2.一个信号可以链接多个槽函数
    //3.多个信号可以链接一个槽函数
    //4.信号和槽函数的参数 必须一一对应
    //5.信号和槽函数的参数个数 是不是要一致 信号的参数个数可以多余槽函数的个数 但是类型要一一对应


    //QT4版本以前的信号和槽链接方式
    //利用QT4信号槽 链接无参版本
    //QT4版本 底层SIGNAL("hungry()")  SLOT("treat()")
    connect(zt,SIGNAL(hungry()),st,SLOT(treat()));
    //QT4版本优点 参数直观 缺点:类型不做检测
    //QT5以上支持QT4的版本写法 反之不支持
    //  =/（this）值传递 &引用传递
    [=](){
        btn->setText("AAAA");
    }();
    //btn(值传递) &btn(引用传递)
    QPushButton *btn2 = new QPushButton("第二个按钮",this);
    btn2->move(400,20);
    [btn](){
        btn->setText("AAAA");
        //btn2->setText("BBB"); 错误 btn2 这里面看不到
    }();
    //mutable关键字用于修饰值传递的变量 修改的是拷贝 而不是本体

//    QPushButton *mybtn = new QPushButton(this);
//    mybtn->move(300,10);
//    QPushButton *mybtn2 = new QPushButton(this);
//    mybtn2->move(500,50);
//    int m = 10;
//    connect(mybtn,&QPushButton::clicked,this,[m]()mutable{m = m+100;qDebug() << m;});
//    connect(mybtn,&QPushButton::clicked,this,[=](){qDebug() << m;});
//    qDebug() << m;

    int ret = []()->int{return 1000;}();
    qDebug()<< "ret = " << ret;
    //利用lanbda表达式 实现点击按钮 关闭窗口
    QPushButton *btn3 = new QPushButton("关闭",this);
    btn3->move(200,200);
    //=值传递 &会关闭程序 而且第三个参数可以关闭 this可以省略不写
    connect(btn3,&QPushButton::clicked,this,[=](){
        //可以用来链接多个槽函数
        //this->close();
        btn3->setText("AA");
        emit zt->hungry("宫保鸡丁");

    });
    //lambda表达式 最常用[=](){}


}
//信号链接信号 这个函数就没啥用了
void myWidget::ClassIsOver()
{

    //下课函数 调用后 触发老师饿了的信号
    //emit zt->hungry();
    emit zt->hungry("宫保鸡丁");


}
myWidget::~myWidget()
{
    delete ui;
}
