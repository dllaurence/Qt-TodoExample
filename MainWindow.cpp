#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>
#include <QInputDialog>

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
    bool ok;
    QString name = QInputDialog::getText(
                this,
                tr("Add task"),
                tr("Task name"),
                QLineEdit::Normal,
                tr("Untitled task"),
                   &ok);

    if (!ok || name.isEmpty()) {
        return;
    }

    qDebug() << "Adding new task";

    Task* task = new Task(name);
    mTasks.append(task);
    // tasksLayout assumes ownership
    ui->tasksLayout->addWidget(task);
}
