#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    //normalImg 代表正常显示的照片
    //pressImg 代表按下后显示的图片 默认为空
    MyPushButton(QString normalmg,QString pressImg = "");
    QString normalImgPath;//默认显示的照片路径
    QString pressImgPath;//按下后显示的图片路径

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void zoom1(bool flag);

signals:

public slots:
};

#endif // MYPUSHBUTTON_H
