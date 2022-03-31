#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //system("conda list");     // 直接用QT调用的bash，调用conda是失败的，没有conda的环境变量信息
    //system("python3 a.py");   // QT的shell解释器，没有python，只有python3，运行脚本，还是没有conda的环境变量
    system("bash a.sh");        // 在shell脚本调用conda，是可以的，详情见脚本
}

Widget::~Widget()
{
    delete ui;
}

