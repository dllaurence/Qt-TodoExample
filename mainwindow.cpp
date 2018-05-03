#include "mainwindow.h"
#include "ui_mainwindow.h"

/*
 * MainWindow's purpose in life seems to
 * be to wrap a corresponding moc(?)-generated
 * Ui::* file.
 * */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    myUI(new Ui::MainWindow)
{
    myUI->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete myUI;
}
