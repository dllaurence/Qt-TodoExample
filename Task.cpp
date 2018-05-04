#include "Task.h"
#include "ui_Task.h"

#include <QInputDialog>

Task::Task(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);

    setName(name);

    connect(ui->editButton,
            &QPushButton::clicked,
            this,
            &Task::rename);

    connect(ui->removeButton,
            &QPushButton::clicked,
            [this] {
                // Macro relays to the
                // removed signal.
                emit removed(this);
            });
}

Task::~Task()
{
    delete ui;
    ui = nullptr;
}

void Task::setName(const QString& name)
{
    ui->checkbox->setText(name);
}

QString Task::name() const
{
    return ui->checkbox->text();
}

bool Task::isCompleted() const
{
    return ui->checkbox->isChecked();
}

void Task::rename()
{
    bool ok;

    QString value = QInputDialog::getText(
                this,
                tr("Edit task"),
                tr("Task name"),
                QLineEdit::Normal,
                this->name(),
                &ok);

    if (!ok || value.isEmpty()) {
        return;
    }

    // Everything is automatically updated
    setName(value);
}
