#ifndef TASK_H
#define TASK_H


#include <QWidget>

#include <QString>

// Allows the alternate, more verbose signal
// relay with an extra slot rather than a
// closure.
#define USE_SLOT 1


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

public slots:

    void rename();

#if USE_SLOT
    void onClick();
#endif

signals:

    void removed(Task* task);

private:
    Ui::Task* ui;
};

#endif // TASK_H
