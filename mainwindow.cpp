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
    QString bvers="";
#if releaseExec
    bvers="Release Version";
#else
    bvers="Debug Version";
#endif
    msgBox.setText("QtPALSandCDB <br>"+bvers);
    msgBox.setInformativeText("(c) Martin Petriska <br><a href='mailto:petriska@gmail.com'>petriska@gmail.com</a><br> Compiled: "+date+" "+time+"<br>Git Version: "+s);
    msgBox.exec();
}

bool MainWindow::maybeSave()
{

    const QMessageBox::StandardButton ret
        = QMessageBox::warning(this, tr("Application"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}
