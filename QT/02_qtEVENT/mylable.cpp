#include "mylable.h"
#include <QDebug>
#include "QMouseEvent"
mylable::mylable(QWidget *parent) : QLabel(parent)
{
    //设置鼠标追踪状态
    //setMouseTracking(true);
}
void mylable::enterEvent(QEvent *)
{
    //qDebug() << "鼠标进入了";

}
void mylable::leaveEvent(QEvent *)
{
    //qDebug() << "鼠标离开了";
}
//鼠标移动
void mylable::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton)
    {
        QString str = QString("鼠标移动了 x= %1 y = %2 globalx= %3 globaly= %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }

}
//鼠标按下
void mylable::mousePressEvent(QMouseEvent *ev)
{
    //需求 左键按下 提示信息
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标按下了 x= %1 y = %2 globalx= %3 globaly= %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }



}
//鼠标离开
void mylable::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标释放了 x= %1 y = %2 globalx= %3 globaly= %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}
bool mylable::event(QEvent *e)
{
    //如果是鼠标按下 在event事件中进行拦截
    if(e->type() == QEvent::MouseButtonPress)
    {
        //C++父类转化为子类
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        QString str = QString("event鼠标按下了 x= %1 y = %2 globalx= %3 globaly= %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
        return true;//代表用户自己处理这个事件 不向下分发
    }
    //其他事件交给父类处理
    return QLabel::event(e);

}
