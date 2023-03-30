#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置单选按钮 男默认选中
    ui->rbtMan->setChecked(true);
    //选中女后打印信息
    connect(ui->rbtmen,&QRadioButton::clicked,this,[=](){

        qDebug() << "选中了女";


    });
    //多选按钮
    connect(ui->checkBox_4,&QCheckBox::stateChanged,this,[=](int state){

        qDebug() << state;

    });
    //利用listwidget写诗
    QListWidgetItem *item = new QListWidgetItem("锄禾日当午");
    //将一行诗歌放入到listWidget控件中
    ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignCenter);

    //QStringList Qlist<QString> 容器 链表
    QStringList list;
    list << "锄禾日当午" << "汗滴禾下土" << "谁知盘中餐" <<"粒粒皆辛苦";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}

