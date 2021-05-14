#include "customobject.h"

CustomObject::CustomObject(QObject *parent) : QObject(parent)
{

}

void CustomObject::setParam(int temp)
{
    param = temp;
}

void CustomObject::doSetup(QThread &cThread)
{
    connect(&cThread,SIGNAL(started()),this,SLOT(doMath()));
    connect(this,SIGNAL(finished(int)),&cThread,SLOT(quit()));
}
void CustomObject::setId(int temp)
{
    id = temp;
}

void CustomObject::doMath()
{
    for(int i = 0; i <param;i++)
    {
        qDebug()<<i;
    }
    emit finished(id);
}
