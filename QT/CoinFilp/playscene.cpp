#include "playscene.h"
#include "mypushbutton.h"
#include "chooselevelscene.h"
#include <QDebug>
#include <QPainter>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTimer>
#include <QLabel>
#include <QPixmap>
#include "mycoin.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}
PlayScene::PlayScene(int levelNum)
{


    QString str = QString("进入了 %1 关").arg(levelNum);
    qDebug() << str;
    this->levelIndex = levelNum;



    //设置固定大小
    this->setFixedSize(320,588);
    //设置图标
    this->setWindowIcon(QIcon(":/Image/Coin0001.png"));
    //设置标题
    this->setWindowTitle("游戏场景");
    //退出按钮实现

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
        qDebug() << "点击了返回按钮";
        //告诉主场景 我返回了 主场景监听chooseSceneBack的返回按钮
        //延时返回
        QTimer::singleShot(500,this,[=](){

            emit this->chooseSceneBack();
        });

    });
    //显示当前的关卡数
    QLabel *lable1 = new QLabel;
    lable1->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    lable1->setFont(font);
    QString str1 = QString("Leavel: %1").arg(levelIndex);
    lable1->setText(str1);
    lable1->setGeometry(QRect(30, this->height() - 50,120, 50));

    //初始化每个关卡的二维数组
    dataConfig config;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];

        }


    }
    //胜利照片实现
    QLabel *lable2 = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/Image/LevelCompletedDialogBg.png");
    lable2->setParent(this);
    lable2->setPixmap(tmpPix);
    lable2->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    lable2->move(this->width()*0.5-tmpPix.width()*0.5,-tmpPix.height());



    //显示金币的背景图案
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
           //绘制背景图片
            QPixmap pix = QPixmap(":/Image/BoardNode(1).png");
            QLabel* label = new QLabel;
            label->setParent(this);
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->move(57 + i*50,200+j*50);

            //创建金币
            QString str;
            if(gameArray[i][j] == 1)
            {

                str = ":/Image/Coin0001.png";
            }else {
               str = ":/Image/Coin0008.png";
            }


            Mycoin *coin = new Mycoin(str);
            //给金币属性复制
            coin->posX = i;
            coin->posY = j;
            coin->flag = gameArray[i][j];//1 正面 2反面

            //将金币放入到 金币的二维数组中 方便后期维护
            this->coinBtn[i][j] = coin;

            coin->setParent(this);
            coin->move(59 + i*50,204+j*50);

            //点击金币进行翻转
            connect(coin,&Mycoin::clicked,[=](){

                //点击按钮 将所以的按钮都先禁用
                for(int i = 0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        this->coinBtn[i][j]->isWin = true;
                    }
                }


                coin->changeFlag();
                //更新维护的数组 因为最后都是金币才是胜利 所以都得是1
                this->gameArray[i][j] = this->gameArray[i][j] == 0 ? 1 : 0;

                //延时
                QTimer::singleShot(300,this,[=](){

                    //翻转周围金币
                    if(coin->posX+1 <= 3)//周围的右侧金币翻转的条件
                    {

                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY] = this->gameArray[coin->posX+1][coin->posY] == 0 ? 1 : 0;

                    }
                    if(coin->posX-1 >= 0)//左侧翻转条件
                    {

                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY] = this->gameArray[coin->posX-1][coin->posY] == 0 ? 1 : 0;
                    }
                    if(coin->posY+1 <= 3)//上侧
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1] = this->gameArray[coin->posX][coin->posY+1] == 0 ? 1 : 0;

                    }
                    if(coin->posY-1 >= 0)//下册
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1] = this->gameArray[coin->posX][coin->posY-1] == 0 ? 1 : 0;

                    }

                    //翻完所有的金币 解开禁用
                    for(int i = 0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            this->coinBtn[i][j]->isWin = false;
                        }
                    }

                    //判断是否胜利
                    this->isWin = true;
                    for(int i = 0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            if(coinBtn[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;

                            }
                        }
                    }
                    if(this->isWin == true)
                    {

                         qDebug() << "胜利了";

                         //将所有的按钮的胜利标志都改为true 如果再次点击按钮 直接return,不做相应
                         for(int i = 0;i<4;i++)
                         {
                             for(int j=0;j<4;j++)
                             {
                                coinBtn[i][j]->isWin = true;
                             }
                         }

                         QPropertyAnimation *animation = new QPropertyAnimation(lable2,"geometry");
                         //设置时间间隔
                         animation->setDuration(1000);
                         //设置起始位置
                         animation->setStartValue(QRect(lable2->x(),lable2->y(),lable2->width(),lable2->height()));
                         //设置结束位置
                         animation->setEndValue(QRect(lable2->x(),lable2->y()+114,lable2->width(),lable2->height()));
                         //设置缓和曲线
                         animation->setEasingCurve(QEasingCurve::OutBounce);
                         //设置动画
                         animation->start();

                    }



                });


            });
        }
    }



}
void PlayScene::paintEvent(QPaintEvent *event)
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
