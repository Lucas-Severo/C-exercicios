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
    if(status == true)
    {
        if(fieldsSelected[0] == 0)
            ui->btn_field1->setEnabled(status);
        if(fieldsSelected[1] == 0)
            ui->btn_field2->setEnabled(status);
        if(fieldsSelected[2] == 0)
            ui->btn_field3->setEnabled(status);
        if(fieldsSelected[3] == 0)
            ui->btn_field4->setEnabled(status);
        if(fieldsSelected[4] == 0)
            ui->btn_field5->setEnabled(status);
        if(fieldsSelected[5] == 0)
            ui->btn_field6->setEnabled(status);
        if(fieldsSelected[6] == 0)
            ui->btn_field7->setEnabled(status);
        if(fieldsSelected[7] == 0)
            ui->btn_field8->setEnabled(status);
        if(fieldsSelected[8] == 0)
            ui->btn_field9->setEnabled(status);
    } else {
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
}

void JogoDaVelha::clearFields()
{
    fieldsSelected.clear();
    fieldsSelected.resize(9);
    fieldsSelected.fill(0);
    ui->btn_field1->setText("");
    ui->btn_field1->setStyleSheet(btnStandardStyle);

    ui->btn_field2->setText("");
    ui->btn_field2->setStyleSheet(btnStandardStyle);

    ui->btn_field3->setText("");
    ui->btn_field3->setStyleSheet(btnStandardStyle);

    ui->btn_field4->setText("");
    ui->btn_field4->setStyleSheet(btnStandardStyle);

    ui->btn_field5->setText("");
    ui->btn_field5->setStyleSheet(btnStandardStyle);

    ui->btn_field6->setText("");
    ui->btn_field6->setStyleSheet(btnStandardStyle);

    ui->btn_field7->setText("");
    ui->btn_field7->setStyleSheet(btnStandardStyle);

    ui->btn_field8->setText("");
    ui->btn_field8->setStyleSheet(btnStandardStyle);

    ui->btn_field9->setText("");
    ui->btn_field9->setStyleSheet(btnStandardStyle);
}

void JogoDaVelha::on_btn_start_clicked()
{
    clearFields();
    setStatus(true);
}

void JogoDaVelha::on_btn_field1_clicked()
{
    ui->btn_field1->setText("X");
    ui->btn_field1->setStyleSheet(userClickStyle);
    fieldsSelected[0] = 1;
    setStatus(false);
}

void JogoDaVelha::on_btn_field2_clicked()
{
    ui->btn_field2->setText("X");
    ui->btn_field2->setStyleSheet(userClickStyle);
    fieldsSelected[1] = 1;
    setStatus(false);
}

void JogoDaVelha::on_btn_field3_clicked()
{
    ui->btn_field3->setText("X");
    ui->btn_field3->setStyleSheet(userClickStyle);
    fieldsSelected[2] = 1;
    setStatus(false);
}

void JogoDaVelha::on_btn_field4_clicked()
{
    ui->btn_field4->setText("X");
    ui->btn_field4->setStyleSheet(userClickStyle);
    fieldsSelected[3] = 1;
    setStatus(false);
}

void JogoDaVelha::on_btn_field5_clicked()
{
    ui->btn_field5->setText("X");
    ui->btn_field5->setStyleSheet(userClickStyle);
    fieldsSelected[4] = 1;
    setStatus(false);
}

void JogoDaVelha::on_btn_field6_clicked()
{
    ui->btn_field6->setText("X");
    ui->btn_field6->setStyleSheet(userClickStyle);
    fieldsSelected[5] = 1;
    setStatus(false);
}

void JogoDaVelha::on_btn_field7_clicked()
{
    ui->btn_field7->setText("X");
    ui->btn_field7->setStyleSheet(userClickStyle);
    fieldsSelected[6] = 1;
    setStatus(false);
}

void JogoDaVelha::on_btn_field8_clicked()
{
    ui->btn_field8->setText("X");
    ui->btn_field8->setStyleSheet(userClickStyle);
    fieldsSelected[7] = 1;
    setStatus(false);
}

void JogoDaVelha::on_btn_field9_clicked()
{
    ui->btn_field9->setText("X");
    ui->btn_field9->setStyleSheet(userClickStyle);
    fieldsSelected[8] = 1;
    setStatus(false);
}

void JogoDaVelha::on_pushButton_clicked()
{
    setStatus(true);
}
