#include "Task.h"
#include "ui_Task.h"

Task::Task(const QString &name, QWidget *parent) :
    QWidget(parent),
    myUI(new Ui::Task)
{
    myUI->setupUi(this);

    setName(name);
}

Task::~Task()
{
}

void Task::setName(const QString& name)
{
    myUI->checkbox->setText(name);
}

QString Task::name() const
{
    return myUI->checkbox->text();
}

bool Task::isCompleted() const
{
    return myUI->checkbox->isChecked();
}
