#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

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

    connect(myUI->addTaskButton,
            &QPushButton::clicked,
            this,
            &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
}

void MainWindow::addTask()
{
    qDebug() << "User clicked on the button!";
}
