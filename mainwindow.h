#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    // This is the generated class we wrap
    Ui::MainWindow *myUI;
};

#endif // MAINWINDOW_H
