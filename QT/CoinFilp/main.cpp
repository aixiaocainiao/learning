#include "mainsense.h"
#include <QApplication>
#include "dataconfig.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainSense w;
    w.show();
    //测试关卡数据
//    dataConfig date;
//    for(int i=0;i<4;i++)
//    {
//        for(int j= 0;j<4;j++)
//        {
//            qDebug() << date.mData[1][i][j];

//        }
//        qDebug() << "";

//    }

    return a.exec();
}
