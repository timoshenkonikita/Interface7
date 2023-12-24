#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();

    ui->result->setText("result.....");

    // 0. Положить проект в git, дописать код в form.cpp,
    //       оформить в виде отдельного коммита
    bool found = str.contains(sub_str, Qt::CaseInsensitive);

    if (found) {
        ui->result->setText("yes");
    } else {
        ui->result->setText("no");
    }
}
