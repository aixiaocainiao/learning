#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置水平头
    //QStringList() 匿名对象
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄" << "英雄介绍");
    QTreeWidgetItem *item = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<< "战斗力");
    //加载顶层的节点
    ui->treeWidget->addTopLevelItem(item);
    ui->treeWidget->addTopLevelItem(item1);
    //追加子节点
    QStringList hear;
    hear << "孙悟空" << "战士  血量999 战斗力无敌";
    QTreeWidgetItem *ll = new QTreeWidgetItem(hear);
    item->addChild(ll);
    //追加子节点
    QStringList widk;
    widk <<"猪八戒" << "战士 血量920 战斗力第二";
    QTreeWidgetItem *ll1 = new QTreeWidgetItem(widk);
    item1->addChild(ll1);
}

Widget::~Widget()
{
    delete ui;
}

