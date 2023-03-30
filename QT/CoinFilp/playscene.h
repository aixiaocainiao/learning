#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mycoin.h"
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    PlayScene(int levelNum);
    int levelIndex;//内部成员属性 记录所选的关卡
    //重写painevent事件
    void paintEvent(QPaintEvent *event);

    int gameArray[4][4];//二位数组，维护每个关卡的每个数据

    Mycoin *coinBtn[4][4];
    bool isWin = true;

signals:
    void chooseSceneBack();


public slots:
};

#endif // PLAYSCENE_H
