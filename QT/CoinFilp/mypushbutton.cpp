#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
#include "playscene.h"
//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}
MyPushButton::MyPushButton(QString normalmg,QString PressImg)
{
    this->normalImgPath = normalmg;
    this->pressImgPath = PressImg;
    QPixmap pix;
    bool ret = pix.load(normalImgPath);
    if(!ret)
    {
        qDebug() << "图片加载错误";
        return;

    }
    //设置图片的固定尺寸
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));


}
void MyPushButton::zoom1(bool flag)
{
   QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");

   //创建动画事件间隔
   animation->setDuration(200);
   if(flag)
   {

       //起始位置
       animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
       //结束位置'
       animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));


   }
   else
   {
       //起始位置
       animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
       //结束位置'
       animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
   }


   //设置弹跳曲线
   animation->setEasingCurve(QEasingCurve::OutInCubic);

   //动画启动
   animation->start();

}
void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImgPath != "")
    {

        QPixmap pix;
        bool ret = pix.load(this->pressImgPath);
        if(!ret)
        {
            qDebug() << "图片加载错误";
            return;

        }
        //设置图片的固定尺寸
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片的样式表
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));


    }
    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);

}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{

    if(this->pressImgPath != "")
    {

        QPixmap pix;
        bool ret = pix.load(this->normalImgPath);
        if(!ret)
        {
            qDebug() << "图片加载错误";
            return;

        }
        //设置图片的固定尺寸
        this->setFixedSize(pix.width(),pix.height());
        //设置不规则图片的样式表
        this->setStyleSheet("QPushButton{border:0px;}");
        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));


    }
    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);

}
