#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat()
{
    qDebug() << "学生请吃饭";

}
void Student::treat(QString foodName)
{
    //Qstring ->char* 先转成QByteArray 在转成 char*
    qDebug() << "学生请吃饭,吃:" << foodName.toUtf8().data();

}
