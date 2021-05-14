#ifndef CUSTOMOBJECT_H
#define CUSTOMOBJECT_H

#include <QObject>
#include <QDebug>
#include <QThread>

class CustomObject : public QObject
{
    Q_OBJECT
private:
    int param;
    int id;
public:
    explicit CustomObject(QObject *parent = nullptr);
    void doSetup(QThread &cThread);
    void setParam(int);
    void setId(int);
signals:
    void finished(int);

public slots:
    void doMath();

};

#endif // CUSTOMOBJECT_H
