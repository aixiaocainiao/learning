#ifndef MAINSENSE_H
#define MAINSENSE_H

#include <QMainWindow>
#include "chooselevelscene.h"
namespace Ui {
class MainSense;
}

class MainSense : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSense(QWidget *parent = 0);
    ~MainSense();
    //重新paintEvent事件 画背景图
    void paintEvent(QPaintEvent *event);
    ChooseLevelScene *chooseScene = NULL;
    //

private:
    Ui::MainSense *ui;
};

#endif // MAINSENSE_H
