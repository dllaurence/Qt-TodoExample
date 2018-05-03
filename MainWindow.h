#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QVector>

#include "Task.h"


// namespace Ui is reserved for objects generated
// from .ui files.
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addTask();

private:
    // Each object has a parallel UI object
    Ui::MainWindow* ui;
    // Don't want unique_ptrs, not the owner
    QVector<Task*> mTasks;
};

#endif // MAINWINDOW_H
