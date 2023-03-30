#ifndef MYWIDGET_H
#define MYWIDGET_H
#include "student.h"
#include "teacher.h"
#include <QWidget>

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

private:
    Ui::myWidget *ui;

    Teacher *zt;
    Student *st;
    void ClassIsOver();
};

#endif // MYWIDGET_H
