#include "mainwindow.h"
#include "ui_mainwindow.h"

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
