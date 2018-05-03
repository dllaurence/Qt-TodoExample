#ifndef TASK_H
#define TASK_H

#include <memory>

#include <QWidget>

#include <QString>


namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString& name,
                  QWidget *parent = 0);
    ~Task();

    void setName(const QString& name);
    QString name() const;
    bool isCompleted() const;

private:
    std::unique_ptr<Ui::Task> myUI;
};

#endif // TASK_H
