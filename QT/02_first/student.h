#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    //早期版本 必须写到public slots，高级版本可以 写到public或者全局下
    //可以 有返回值 需要声明 也需要实现
    //可以有参数 可以发生重载
    void treat();
    void treat(QString foodName);

};

#endif // STUDENT_H
