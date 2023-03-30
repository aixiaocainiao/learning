#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat()
{
    qDebug() << "请老师吃饭";

}
void Student::treat(QString footName)
{
    //这一步的 目的是 将  QString 指向的宫保鸡丁 的双引号去电
    //QString ->char* 先转成QByteArray(.toUtf8),在转char*()
    qDebug() << "请老师吃饭:老师要吃 " << footName.toUtf8().data();
}
