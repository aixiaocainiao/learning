#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("文件读写");
    this->resize(600,400);
    //点击选取文件按钮 弹出文件对话框
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){

        QString path = QFileDialog::getOpenFileName(this,"打开文件","/home/yunfang/文档");
        //将路径放入到lineEdit中
        ui->lineEdit->setText(path);

        //编码格式类
        //QTextCodec *codec = QTextCodec::codecForName("gbk");

        //读取内容放入到textEdit QFile 默认支持的格式为utf-8
        QFile file(path);//参数就是读取文件的路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);

        //QByteArray array = file.readAll();

        QByteArray array01;

        while (!file.atEnd())   //file.atEnd()文件尾
        {
           array01 += file.readLine();
        }


        //将读取的数据 放入到TEXTedit中
        //ui->textEdit->setText(array);

        ui->textEdit->setText(array01);
        //ui->textEdit->setText(codec->toUnicode(array));

        //对文件对象进行关闭
        file.close();

//        //对文件进行写入
//        file.open(QIODevice::Append);
//        file.write("啊啊啊啊");
//        file.close();

        //文件信息类QFileInfo

        QFileInfo info(path);
        qDebug() << "大小: " << info.size() << "后缀名:"
                 << info.suffix() << "文件名称：" << info.fileName()
                 << "文件路径: " << info.filePath();
        qDebug() << "创建日期: " << info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug() << "修改日期: " << info.lastModified().toString("yyyy-MM-dd hh:mm:ss");




    });
}

Widget::~Widget()
{
    delete ui;
}
