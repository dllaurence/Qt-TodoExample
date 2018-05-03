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
    myUI(new Ui::MainWindow),
    myTasks()
{
    myUI->setupUi(this);

    connect(myUI->addTaskButton,
            &QPushButton::clicked,
            this,
            &MainWindow::addTask);
}


MainWindow::~MainWindow()
{
    // Tasks released when UI object recursively
    // destructs its children, since we added
    // them to the tasksLayout.
    delete myUI;
    myUI = nullptr;
}


void MainWindow::addTask()
{
    qDebug() << "Adding new task";

    Task* task = new Task("Untitled task");
    myTasks.append(task);
    // tasksLayout assumes ownership
    myUI->tasksLayout->addWidget(task);
}
