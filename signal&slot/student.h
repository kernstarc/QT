#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    // void 返回值类型，需要声明和实现
    // 可以有参数，可以发生重载
    void say();
    void say(QString foodName);

};

#endif // STUDENT_H
