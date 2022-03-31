#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(200, 100);

    QPushButton * buttonTech = new QPushButton;
    buttonTech->resize(80, 40);
    buttonTech->setText("class over");
    buttonTech->move(100, 10);
    buttonTech->setParent(this);

    this->tea = new Teacher(this);      // C++创建对象方式，h文件声明，C文件指针new
    this->stu = new Student(this);

    // 函数重载，无参，不知道调用哪个地址的同名函数
    //connect(tea, &Teacher::hungry, stu, &Student::say);
    // 函数重载，有参,定义函数指针，指向类内函数的地址
    void(Teacher:: *teaSingal)(QString) = &Teacher::hungry;
    void(Student:: *stuSlot)(QString) = &Student::say;
    connect(tea, teaSingal, stu, stuSlot);    // 老师hungry信号和学生say槽函数连接
    classIsOver();      // 发射老师hungry信号

    // 按钮触发槽函数, 第三个参数，信号的接受者是当前窗口类，并触发窗口的槽函数
    // 按钮触发的信号和这个窗口的classIsOver函数相连接，这个函数发送emit hungry信号
    connect(buttonTech, &QPushButton::clicked, this, &MainWindow::classIsOver);

    // 无参数的信号和槽连接
    void(Teacher:: *teaSingalN)(void) = &Teacher::hungry;
    void(Student:: *stuSlotN)(void) = &Student::say;
    connect(tea, teaSingalN, stu, stuSlotN);
    classIsOver();      // 发射老师hungry信号

    // 信号和信号的连接
    QPushButton * button = new QPushButton("signal", this);
    button->resize(50, 50);
    button->move(0, 0);
    connect(button, &QPushButton::clicked, stu, stuSlotN);

    // 信号断开, 上一行代码的connect，无效了
    disconnect(button, &QPushButton::clicked, stu, stuSlotN);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::classIsOver()
{
    emit tea->hungry("asd");
    emit tea->hungry();
}


// 1.信号可以连接信号
// 2.一个信号可以连接多个槽函数
// 3.多个信号可以连接一个槽函数
// 4.信号和槽函数的参数类型必须一一对应
// 5.信号和槽函数的参数的个数必须一一对应
// ,信号参数个数可以多于槽函数参数个数

/*
Lambda表达式
空：没有参数
= ：值传递，所有局部变量
& ：引用传递，所有局部变量

*/






