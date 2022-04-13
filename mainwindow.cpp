#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("QtPALSandCDB");
    QString s;
    s=GIT_VERSION;
    QString date;
    date=__DATE__;
    QString time;
    time =__TIME__;
    msgBox.setInformativeText("(c) Martin Petriska <br><a href='mailto:petriska@gmail.com'>petriska@gmail.com</a><br> Compiled: "+date+" "+time+"<br>Git Version: "+s);
    msgBox.exec();
}

