#include "widget.h"
#include "ui_widget.h"
#include <QPainter>//画家类
#include <QPen>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
//        //如果要手动调用绘图事件,用update更新
//        posX += 20;
//        if(posX > this->width())//this->height()
//        {
//            posX = 0;
//        }

//        update();


//    });

    QTimer *timer = new QTimer(this);
    timer->start(500);
    connect(timer,&QTimer::timeout,this,[=](){

        posX += 20;
        if(posX > this->width())//this->height()
        {
            posX = 0;
        }

        update();
    });

}

Widget::~Widget()
{
    delete ui;
}
void Widget::paintEvent(QPaintEvent *)
{
//    //实例化画家对象 this指定的是绘图设备
//    QPainter painter(this);
//    //设置画笔颜色
//    QPen pen(QColor(255,0,0));
//    //设置画笔风格
//    pen.setStyle(Qt::DashLine);
//    //设置画笔宽度
//    pen.setWidth(3);
//    //让画家使用这个笔
//    painter.setPen(pen);


//    //利用画刷
//    //QBrush brush(QColor(0,255,0));
//    QBrush brush(Qt::green);
//    brush.setStyle(Qt::Dense7Pattern);
//    //让画家使用画刷
//    painter.setBrush(brush);


//    //画线
//    painter.drawLine(QPoint(0,0),QPoint(100,100));
//    //画圆
//    painter.drawEllipse(QPoint(100,100),50,50);
//    //画椭圆
//    painter.drawEllipse(QPoint(100,100),100,50);
//    //画矩形
//    painter.drawRect(20,20,50,50);
//    //画文字
//    painter.drawText(QRect(10,200,150,50),"好好学习,天天向上");

    //QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置 抗锯齿能力 效率较低
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);



//    //画矩形
//    painter.drawRect(QRect(20,20,50,50));
//    //移动画家
//    painter.translate(100,0);

//    //保存画家状态
//    painter.save();

//    painter.drawRect(QRect(20,20,50,50));


//    //移动画家
//    painter.translate(100,0);
//    //还原画家状态
//    painter.restore();

//    painter.drawRect(QRect(20,20,50,50));


    //利用画家画资源文件
    QPainter painter(this);

    painter.drawPixmap(posX,0,QPixmap(":/Image/33.png"));



}
