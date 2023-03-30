#include "mainsense.h"
#include "ui_mainsense.h"
#include <QPainter>
#include <QPixmap>
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QTimer>
//#include <QSound>//多媒体模块下的音效头文件
MainSense::MainSense(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSense)
{
    ui->setupUi(this);
    //设置固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QIcon(":/Image/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币主场景");
    //退出按钮实现
    connect(ui->actionQuit,&QAction::triggered,this,[=](){
        this->close();

    });
    //准备开始按钮的音效
    //QSound *startSound = new QSound(":/Image/TapButtonSound.wav",this);

    //开始按钮
    MyPushButton *startBtn = new MyPushButton(":/Image/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5,this->height()*0.7);

    chooseScene = new ChooseLevelScene;

    //监听选择关卡返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){

        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();


    });

    //监听
    connect(startBtn,&MyPushButton::clicked,this,[=](){
        //播放开始音效资源
        //startSound->play(); //开始音效


        //做弹起效果
        startBtn->zoom1(true);
        startBtn->zoom1(false);

        //延时进入选择关卡
        QTimer::singleShot(500,this,[=](){

            //设置一下chooseScene场景的位置
            chooseScene->setGeometry(this->geometry());
            //自身隐藏
            this->hide();


            //进入到选择关卡场景中
            chooseScene->show();

        });

        //////用这个 监听机制会出现问题//////////////////
//        QTimer *timer = new QTimer(this);
//        timer->start(500);
//        connect(timer,&QTimer::timeout,this,[=](){
//            //进入到选择关卡场景中
//            //自身隐藏
//            this->hide();
//            chooseScene->show();

//        });


    });

}

MainSense::~MainSense()
{
    delete ui;
}
void MainSense::paintEvent(QPaintEvent *event)
{
    //加载画家 指定绘画设备
     QPainter painter(this);
     //创建QPixmap对象
     QPixmap pix;
     //加载图片
     pix.load(":/Image/PlayLevelSceneBg.png");
     //绘制背景图
     painter.drawPixmap(0,0,this->width(),this->height(),pix);

     //加载标题照片
     pix.load(":/Image/Title.png");

     //缩放照片
     pix = pix.scaled(pix.width() * 0.5,pix.height()*0.5);
     //绘制标题
     painter.drawPixmap(10,30,pix.width(),pix.height(),pix);


}
