#ifndef MYWIDGET_H
#define MYWIDGET_H
//防止头文件包含
#include <QWidget>//包含头文件 QWidget窗口宏

class myWidget : public QWidget
{
    Q_OBJECT//Q_OBJECT宏，允许类中使用信号和槽的机制

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
};
#endif // MYWIDGET_H
