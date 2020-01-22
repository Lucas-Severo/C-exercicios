#include "jogodavelha.h"
#include "ui_jogodavelha.h"

JogoDaVelha::JogoDaVelha(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JogoDaVelha)
{
    ui->setupUi(this);
}

JogoDaVelha::~JogoDaVelha()
{
    delete ui;
}

