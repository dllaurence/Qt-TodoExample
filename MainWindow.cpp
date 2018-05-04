#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

/*
 * MainWindow seems to be the model that
 * corresponds to a parallel, moc(?)-generated
 * Ui::* view.
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
    // Tasks released when ui recursively
    // destructs its children, since we
    // added them to the tasksLayout.
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
