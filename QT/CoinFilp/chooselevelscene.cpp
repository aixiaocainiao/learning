#include "chooselevelscene.h"
#include <QPainter>
#include <QMenuBar>
#include "mypushbutton.h"
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include "playscene.h"
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{


    //设置大小
    this->setFixedSize(320,588);
    //设置标题
    this->setWindowTitle("选择关卡");
    //配置选择关卡场景
    this->setWindowIcon(QPixmap(":/Image/Coin0001.png"));
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");
    QAction *quitAction = startMenu->addAction("退出");

    connect(quitAction,&QAction::triggered,this,[=](){

        this->close();
    });

    //返回按钮
    MyPushButton *backbtn = new MyPushButton(":/Image/BackButton.png",":/Image/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());

    connect(backbtn,&MyPushButton::clicked,[=](){
        //qDebug() << "点击了返回按钮";
        //告诉主场景 我返回了 主场景监听chooseSceneBack的返回按钮
        //延时返回
        QTimer::singleShot(500,this,[=](){

            emit this->chooseSceneBack();
        });

    });
    //创建选择关卡的按钮
    for(int i =0;i < 20;i++)
    {
        MyPushButton *menuBtn = new MyPushButton(":/Image/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4 *70,130+i/4*70);
        //监听每个按钮的点击事件

        //lable会将按钮挡住 如果一起 不会点击到按钮

        connect(menuBtn,&MyPushButton::clicked,[=](){

            QString str = QString("您选择的是第 %1 关").arg(i+1);
            qDebug() << str;
            //进入到游戏场景
            play = new PlayScene(i+1);//创建游戏场景

            play->setGeometry(this->geometry());

            this->hide();//将所选场景隐藏掉 
            play->show();//显示游戏场景

            //监听
            connect(play,&PlayScene::chooseSceneBack,this,[=](){
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = NULL;

            });

        });

        //按钮设置数字
        QLabel *label = new QLabel();
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25+i%4 *70,130+i/4*70);

        //设置lable的文字对齐方式 水平对齐和 垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置让鼠标进行穿透 51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);

    }


}
void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    //加载画家 指定绘画设备
     QPainter painter(this);
     //创建QPixmap对象
     QPixmap pix;
     //加载图片
     pix.load(":/Image/OtherSceneBg.png");
     //绘制背景图
     painter.drawPixmap(0,0,this->width(),this->height(),pix);

     //加载标题照片
     pix.load(":/Image/Title.png");

     //缩放照片
     pix = pix.scaled(pix.width() * 0.5,pix.height()*0.5);
     //绘制标题
     painter.drawPixmap(10,30,pix.width(),pix.height(),pix);




}
