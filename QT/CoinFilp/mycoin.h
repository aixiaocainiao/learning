#ifndef MYCOIN_H
#define MYCOIN_H
#include <QTimer>
#include <QPushButton>

class Mycoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit Mycoin(QWidget *parent = nullptr);
    //参数代表 传入的金币路径 还是银币路径
    Mycoin(QString btnImg);
    int posX;//x坐标
    int posY;//y坐标
    bool flag;//正反标识
    void changeFlag();//改变标识 执行翻转效果
    QTimer *timer1;//正面反反面
    QTimer *timer2;//反面反正面
    int min = 1;//
    int max = 8;//

    bool isAnimation = false;//执行动画标志 初始值

    //重写 鼠标按下事件  达到在执行动画时点击其他按钮
    void mousePressEvent(QMouseEvent *e);

    //是否胜利的标志 初始值
    bool isWin = false;


signals:

public slots:
};

#endif // MYCOIN_H
