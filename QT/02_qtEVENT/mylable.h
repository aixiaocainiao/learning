#ifndef MYLABLE_H
#define MYLABLE_H

#include <QLabel>

class mylable : public QLabel
{
    Q_OBJECT
public:
    explicit mylable(QWidget *parent = nullptr);
    virtual void enterEvent(QEvent *);
    virtual void leaveEvent(QEvent *);
    //鼠标移动
    virtual void mouseMoveEvent(QMouseEvent *ev);
    //鼠标按下
    virtual void mousePressEvent(QMouseEvent *ev);
    //鼠标释放
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    //通过event事件分发器 拦截 鼠标按下事件
    bool event(QEvent *e);


signals:

public slots:
};

#endif // MYLABLE_H
