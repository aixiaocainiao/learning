#include "widget.h"
#include "ui_widget.h"
#include <QTimer>//定时器的类
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动定时器
    id1 = startTimer(1000);

    id2 = startTimer(2000);
    //定时器的第二种方式
    QTimer *timer = new QTimer(this);
    //启动定时器
    timer->start(500);

    connect(timer,&QTimer::timeout,this,[=](){
        static int num3 = 1;
        //lable4 每隔0.5秒+1
        ui->label_4->setText(QString::number(num3++));

    });
    //点击按钮 实现暂停功能
    connect(ui->pushButton,&QPushButton::clicked,timer,[=](){
        timer->stop();

    });

}

Widget::~Widget()
{
    delete ui;
}
void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1)
    {
        //分配一次
        static int num = 1;
        //lable2 每隔1秒+1
        ui->label_2->setText(QString::number(num++));

    }

    if(event->timerId() == id2)
    {
        //lable3 每隔2秒+1
        static int num2 = 1;
        ui->label_3->setText(QString::number(num2++));

    }


}
