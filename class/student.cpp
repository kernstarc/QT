#include "student.h"
#include <QDebug>


Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::say()
{
    qDebug() << "Go Away!";

}

void Student::say(QString foodName)
{
    // QString先转QByteArray，然后转Char *
    qDebug() << "eat " << foodName.toUtf8().data();
}

