#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include "customobject.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for(int i = 0; i < 10; i++)
    {
        label[i] = new QLabel("waiting to start threads",this);
        label[i]->setGeometry(100,100+i*30,200,100);
    }
    for(int i = 0; i < 10; i++)
    {
        cObject[i].setParam(rand());
        cObject[i].setId(i);
        connect(&cObject[i],SIGNAL(finished(int)),this,SLOT(threadFinished(int)));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::threadFinished(int temp)
{
    label[temp]->setText("finished");
}

void MainWindow::on_pushButton_clicked()
{
    for(int i = 0; i < 10; i++)
    {
        cObject[i].doSetup(cThread[i]);
        cObject[i].moveToThread(&cThread[i]);
        label[i]->setText("processing");
        cThread[i].start();
    }

}

