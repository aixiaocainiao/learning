#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
//槽函数
class Student : public QObject
{
    Q_OBJECT
public:
    //返回值void ,需要声明，也需要实现
    //可以有参数 ，可以发生重载
    void treat();
    //重载
    void treat(QString foodName);
    explicit Student(QObject *parent = nullptr);//相当于析构函数  就是析构函数

signals:

//public slots:
    //早期QT版本必须要写到public slots，高级版本可以写到public 或者全局下

};

#endif // STUDENT_H
