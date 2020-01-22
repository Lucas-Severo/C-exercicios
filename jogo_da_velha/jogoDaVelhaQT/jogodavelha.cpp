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

void JogoDaVelha::AI()
{
    if(!winner)
    {
        QVector<int> nonSelectedFields;
        for(int i = 0; i < 9; i++)
        {
            if(fieldsSelected[i] == 0)
            {
                nonSelectedFields.push_back(i);
            }
        }

        int selected = nonSelectedFields[0];
        fieldsSelected[selected] = 2;
        if(selected == 0)
        {
            ui->btn_field1->setText("O");
        }
        else if(selected == 1)
            ui->btn_field2->setText("O");
        else if(selected == 2)
                ui->btn_field3->setText("O");
        else if(selected == 3)
                ui->btn_field4->setText("O");
        else if(selected == 4)
                ui->btn_field5->setText("O");
        else if(selected == 5)
                ui->btn_field6->setText("O");
        else if(selected == 6)
                ui->btn_field7->setText("O");
        else if(selected == 7)
                ui->btn_field8->setText("O");
        else if(selected == 8)
                ui->btn_field9->setText("O");
        checkWinner(2);
        if(!winner)
            setStatus(true);
    }
}

void JogoDaVelha::checkWinner(int player)
{
    // checking diagonals
    if(fieldsSelected[0] == player && fieldsSelected[4] == player && fieldsSelected[8] == player)
    {
        winner = true;
    }
    else if(fieldsSelected[2] == player && fieldsSelected[4] == player && fieldsSelected[6] == player)
        winner = true;

    // checking rows
    else if(fieldsSelected[0] == player && fieldsSelected[1] == player && fieldsSelected[2] == player)
        winner = true;
    else if(fieldsSelected[3] == player && fieldsSelected[4] == player && fieldsSelected[5] == player)
        winner = true;
    else if(fieldsSelected[6] == player && fieldsSelected[7] == player && fieldsSelected[8] == player)
        winner = true;

    // checking columns
    else if(fieldsSelected[0] == player && fieldsSelected[3] == player && fieldsSelected[6] == player)
        winner = true;
    else if(fieldsSelected[1] == player && fieldsSelected[4] == player && fieldsSelected[7] == player)
        winner = true;
    else if(fieldsSelected[2] == player && fieldsSelected[5] == player && fieldsSelected[8] == player)
        winner = true;

    if(winner)
    {
        if(player == 1)
        {
            ui->lb_result->setText("Player 1 win");
            userScore++;
        } else {
            ui->lb_result->setText("Player 2 win");
            AIScore++;
        }
        updateScore();
    } else if(isTie())
    {
        ui->lb_result->setText("Empate");
        winner = true;
    }
}

bool JogoDaVelha::isTie()
{
    for(int i = 0; i < 9; i++)
    {
        if(fieldsSelected[i] == 0)
            return false;
    }
    return true;
}

void JogoDaVelha::updateScore()
{
    ui->lb_ai_score->setText("Computador: " + QString::number(AIScore));
    ui->lb_user_score->setText("User: " + QString::number(userScore));
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
    ui->lb_result->setText("");

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
    winner = false;
}

void JogoDaVelha::on_btn_field1_clicked()
{
    ui->btn_field1->setText("X");
    ui->btn_field1->setStyleSheet(userClickStyle);
    fieldsSelected[0] = 1;
    setStatus(false);
    checkWinner(1);
    AI();
}

void JogoDaVelha::on_btn_field2_clicked()
{
    ui->btn_field2->setText("X");
    ui->btn_field2->setStyleSheet(userClickStyle);
    fieldsSelected[1] = 1;
    setStatus(false);
    checkWinner(1);
    AI();
}

void JogoDaVelha::on_btn_field3_clicked()
{
    ui->btn_field3->setText("X");
    ui->btn_field3->setStyleSheet(userClickStyle);
    fieldsSelected[2] = 1;
    setStatus(false);
    checkWinner(1);
    AI();
}

void JogoDaVelha::on_btn_field4_clicked()
{
    ui->btn_field4->setText("X");
    ui->btn_field4->setStyleSheet(userClickStyle);
    fieldsSelected[3] = 1;
    setStatus(false);
    checkWinner(1);
    AI();
}

void JogoDaVelha::on_btn_field5_clicked()
{
    ui->btn_field5->setText("X");
    ui->btn_field5->setStyleSheet(userClickStyle);
    fieldsSelected[4] = 1;
    setStatus(false);
    checkWinner(1);
    AI();
}

void JogoDaVelha::on_btn_field6_clicked()
{
    ui->btn_field6->setText("X");
    ui->btn_field6->setStyleSheet(userClickStyle);
    fieldsSelected[5] = 1;
    setStatus(false);
    checkWinner(1);
    AI();
}

void JogoDaVelha::on_btn_field7_clicked()
{
    ui->btn_field7->setText("X");
    ui->btn_field7->setStyleSheet(userClickStyle);
    fieldsSelected[6] = 1;
    setStatus(false);
    checkWinner(1);
    AI();
}

void JogoDaVelha::on_btn_field8_clicked()
{
    ui->btn_field8->setText("X");
    ui->btn_field8->setStyleSheet(userClickStyle);
    fieldsSelected[7] = 1;
    setStatus(false);
    checkWinner(1);
    AI();
}

void JogoDaVelha::on_btn_field9_clicked()
{
    ui->btn_field9->setText("X");
    ui->btn_field9->setStyleSheet(userClickStyle);
    fieldsSelected[8] = 1;
    setStatus(false);
    checkWinner(1);
    AI();
}
