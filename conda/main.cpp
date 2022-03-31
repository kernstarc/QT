#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //w.show();     // 方便测试，主要看打印信息
    return a.exec();
}
