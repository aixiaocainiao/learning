#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //点击新建按钮 弹出一个对话框
    connect(ui->actionnew,&QAction::triggered,this,[=](){
        //对话框 分类
        //模态对话框(不可以对其他窗口操作)非模态对话框(可以对其他对话框弹出)
        //模态创建
//       QDialog dlg(this);
//       dlg.exec();

//       qDebug() << "模态对话框弹出了";



        //非模态对话框 必须用这个 不然堆上的数据执行完会被释放 看不到效果 一闪而过
//        QDialog * dlg2 = new QDialog(this);
//        dlg2->resize(200,100);
//        dlg2->show();
//        //这个非模态关闭之后 这条指令会将其释放 否则一致点 内存会崩溃
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);// 55号 属性
//        qDebug() << "非模态对话框弹出了";



       //消息对话框
//       QMessageBox::critical(this,"critical","错误");
//        //信息对话框
//       QMessageBox::information(this,"info","信息");

       //提问对话框
       //参数1 父亲 参数二 标题
//       if(QMessageBox::Save == QMessageBox::question(this,"ques","提问",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
//       {
//           qDebug() << "选择的是保存";

//       }
//       else{

//                   qDebug() << "选择的是取消";
//       }
        //警告的对话框
        QMessageBox::warning(this,"warn","警告");


    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
