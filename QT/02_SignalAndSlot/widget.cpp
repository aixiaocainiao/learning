#include "widget.h"
#include "ui_widget.h"
#include "QPushButton"
#include <QDebug>
//Teacher 类 老师类
//Student 类 学生类
//下课后，老师会触发一个信号 ，饿了，学生响应信号，请客吃饭
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->zt = new Teacher(this);//第二个this放到对象树上了 不用自己释放堆栈数据了

    //创建一个学生对象
    this->st = new Student(this);//第二个this放到对象树上了 不用自己释放堆栈数据了
    //老师饿了 学生请客吃饭
    //connect(zt,&Teacher::hungry,st,&Student::treat);

    //链接带参数的信号和槽
    //指针—>地址
    //函数指针->函数地址
    //函数指针的写法和使用

    //C++中的匿名函数
    void (Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void (Student:: *studentSlot)(QString) = &Student::treat;

    connect(zt,teacherSignal,st,studentSlot);
    //先连接在调用才会打印输出  有逻辑顺序的
    //调用下课函数
    classIsOver();


//有参:
    //需求: 点击一个 下课的按钮 ，再触发下课
    QPushButton *bn = new QPushButton("下课",this);
    //重置窗口大小
    bn->move(100,0);
    resize(600,400);
    //设置窗口固定大小
    setFixedSize(600,400);
    //设置窗口名称
    setWindowTitle("第一个窗口");
    //执行:点击按钮 触发下课
        //connect(bn,&QPushButton::clicked,this,&Widget::classIsOver);


//无参:
    //无参信号和槽链接
    void (Teacher:: *teacherSignal1)(void) = &Teacher::hungry;
    void (Student:: *studentSlot1)(void) = &Student::treat;
    connect(zt,teacherSignal1,st,studentSlot1);

    //QT4版本以前的信号和槽链接方式

    //利用QT4版本信号槽 链接无参版本 改写了55行
    //connect(zt,SIGNAL(hungry()),st,SLOT(treat()));


    //信号链接信号
    connect(bn,&QPushButton::clicked,zt,teacherSignal1);
    //断开信号 connect里面的数据直接拿来用就行
    //disconnect(zt,teacherSignal1,st,studentSlot1);

    //拓展
    //1.信号是可以链接信号的
    //2.一个信号可以链接多个信号槽
    //3.多个信号 可以 链接同一个槽函数
    //4.信号和槽函数的参数 必须类型一一对应
    //5.信号和槽的参数个数 是不是要一致？ 信号的参数个数可以多于槽函数的参数个数

    //qt4以前的信号和槽链接方式
    //利用QT4信号槽 链接无参版本
    //QRT4版本 底层SIGAL("HUNGRY") SLOT("treat")

    //connect(zt,SIGNAL(hungry()),st,SLOT(treat()))
//    [=](){
//        bn->setText("aaaa");
//    }();

//    QPushButton *btn2 = new QPushButton;
//    [bn](){
//        bn->setText("aaaa");
//        btn2->setText("aaaa");//btn2看不到
//    }();

//    int ret =[]()->int{return 1000;}();
//    qDebug() << "ret = " << ret;
    //利用lambda表达式 实现点击按钮  关闭窗口
    QPushButton *btn = new QPushButton("关闭",this);
    btn->move(200,100);
    connect(btn,&QPushButton::clicked,this,[=](){
//        this->close();
//        emit zt->hungry("宫保鸡丁");
        btn->setText("aaaa");
    });
    //lambda表达式 最常用 [=](){}

}
void Widget::classIsOver()
{
    //下课后，调用后 触发老师饿了的信号
    emit zt->hungry();
    emit zt->hungry("宫保鸡丁");

}
Widget::~Widget()
{
    delete ui;
}

