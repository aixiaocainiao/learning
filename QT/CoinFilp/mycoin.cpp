#include "mycoin.h"
#include <QPixmap>
#include <QDebug>
#include <QTimer>
#include <QPixmap>
//Mycoin::Mycoin(QWidget *parent)
//{

//}
Mycoin::Mycoin(QString btnImg)
{

    QPixmap pix;
    bool ret = pix.load(btnImg);
    if (!ret)
    {
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug() << str;
        return;

    }
    //设置图片的固定尺寸
    this->setFixedSize(pix.width(),pix.height());
    //设置图标
    this->setIcon(pix);
    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));

    //初始化定时器对象
    this->timer1 = new QTimer;
    this->timer2 = new QTimer;
    //监听 正面翻转反面
    connect(timer1,&QTimer::timeout,this,[=](){

        QPixmap pix;
        QString str = QString(":/Image/Coin000%1.png").arg(this->min++);
        pix.load(str);

        //设置图片的固定尺寸
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片的样式表
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断如果翻完了 将min重置
        if(this->min > this->max)
        {
            this->min = 1;
            //动画执行结束
            this->isAnimation = false;
            this->timer1->stop();

        }



    });
    //监听 反面翻转正面
    connect(timer2,&QTimer::timeout,this,[=](){

        QPixmap pix;
        QString str = QString(":/Image/Coin000%1.png").arg(this->max--);
        pix.load(str);

        //设置图片的固定尺寸
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片的样式表
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
        //判断如果翻完了 将max重置
        if(this->max < this->min)
        {
            this->max = 8;
            //动画执行结束
            this->isAnimation = false;
            this->timer2->stop();

        }



    });

}
void Mycoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin == true)
    {
        return;

    }
    else
    {
         return QPushButton::mousePressEvent(e);
    }


}
//改变正反面标志的方法
void Mycoin::changeFlag()
{
    //如果是正面 反成 反面


    if(this->flag)
    {
        //正面 反成 反面的定时器
        this->timer1->start(30);
         //开始执行动画了
        this->isAnimation = true;
        this->flag = false;


    }
    else
    {

        this->timer2->start(30);
        //开始执行动画了
        this->isAnimation = true;
        this->flag = true;


    }


}
