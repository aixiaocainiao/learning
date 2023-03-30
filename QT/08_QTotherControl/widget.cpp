#include "widget.h"
#include "ui_widget.h"
#include "QMovie"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置 默认页
    ui->stackedWidget->setCurrentIndex(0);
    //栈控件使用
    //scro按钮
    connect(ui->btn_scro,&QPushButton::clicked,[=](){

        ui->stackedWidget->setCurrentIndex(2);

    });
    //tabbox按钮
    connect(ui->btn_tabbox,&QPushButton::clicked,this,[=](){

        ui->stackedWidget->setCurrentIndex(0);

    });
    //tabwidget按钮
    connect(ui->btn_tabwidget,&QPushButton::clicked,this,[=](){

        ui->stackedWidget->setCurrentIndex(1);
    });
    //下拉框
    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("拖拉机");

    connect(ui->btn_tlj,&QPushButton::clicked,this,[=](){

        ui->comboBox->setCurrentIndex(2);
        //ui->comboBox->setCurrentText("拖拉机");

    });
    //利用QLable显示图片
    ui->label_2->setPixmap(QPixmap(":/image/siyun.jpg"));
    //利用QLable可以是指动图
    QMovie *movie = new QMovie(":/image/siyun.jpg");
    ui->label->setMovie(movie);
    //播放动图
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

