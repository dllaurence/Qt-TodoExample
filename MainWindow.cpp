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
    ui(new Ui::MainWindow),
    mTasks()
{
    ui->setupUi(this);

    connect(ui->addTaskButton,
            &QPushButton::clicked,
            this,
            &MainWindow::addTask);
}


MainWindow::~MainWindow()
{
    // Tasks released when UI object recursively
    // destructs its children, since we added
    // them to the tasksLayout.
    delete ui;
    ui = nullptr;
}


void MainWindow::addTask()
{
    qDebug() << "Adding new task";

    Task* task = new Task("Untitled task");
    mTasks.append(task);
    // tasksLayout assumes ownership
    ui->tasksLayout->addWidget(task);
}
