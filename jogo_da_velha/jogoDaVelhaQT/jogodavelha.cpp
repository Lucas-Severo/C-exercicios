#include "jogodavelha.h"
#include "ui_jogodavelha.h"

JogoDaVelha::JogoDaVelha(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JogoDaVelha)
{
    ui->setupUi(this);

    setStatus(false);
}

JogoDaVelha::~JogoDaVelha()
{
    delete ui;
}


void JogoDaVelha::setStatus(bool status)
{
    ui->btn_field1->setEnabled(status);
    ui->btn_field2->setEnabled(status);
    ui->btn_field3->setEnabled(status);
    ui->btn_field4->setEnabled(status);
    ui->btn_field5->setEnabled(status);
    ui->btn_field6->setEnabled(status);
    ui->btn_field7->setEnabled(status);
    ui->btn_field8->setEnabled(status);
    ui->btn_field9->setEnabled(status);
}

void JogoDaVelha::clearFields()
{
    fieldsSelected.clear();
    fieldsSelected.resize(9);
    fieldsSelected.fill(0);
    ui->btn_field1->setText("");
    ui->btn_field2->setText("");
    ui->btn_field3->setText("");
    ui->btn_field4->setText("");
    ui->btn_field5->setText("");
    ui->btn_field6->setText("");
    ui->btn_field7->setText("");
    ui->btn_field8->setText("");
    ui->btn_field9->setText("");

}

void JogoDaVelha::on_btn_start_clicked()
{
    clearFields();
    setStatus(true);
}

void JogoDaVelha::on_btn_field1_clicked()
{
    ui->btn_field1->setText("X");
}

void JogoDaVelha::on_btn_field2_clicked()
{
    ui->btn_field2->setText("X");
}

void JogoDaVelha::on_btn_field3_clicked()
{
    ui->btn_field3->setText("X");
}

void JogoDaVelha::on_btn_field4_clicked()
{
    ui->btn_field4->setText("X");
}

void JogoDaVelha::on_btn_field5_clicked()
{
    ui->btn_field5->setText("X");
}

void JogoDaVelha::on_btn_field6_clicked()
{
    ui->btn_field6->setText("X");
}

void JogoDaVelha::on_btn_field7_clicked()
{
    ui->btn_field7->setText("X");
}

void JogoDaVelha::on_btn_field8_clicked()
{
    ui->btn_field8->setText("X");
}

void JogoDaVelha::on_btn_field9_clicked()
{
    ui->btn_field9->setText("X");
}
