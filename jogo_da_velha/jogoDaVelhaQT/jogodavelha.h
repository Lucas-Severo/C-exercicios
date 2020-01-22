#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

#include <QMainWindow>
#include <QVector>
#include <random>

QT_BEGIN_NAMESPACE
namespace Ui { class JogoDaVelha; }
QT_END_NAMESPACE

class JogoDaVelha : public QMainWindow
{
    Q_OBJECT

public:
    JogoDaVelha(QWidget *parent = nullptr);
    ~JogoDaVelha();

    void setStatus(bool status);
    void clearFields();
    void checkWinner(int player);
    void updateScore();
    void AI();
    bool isTie();

private slots:
    void on_btn_start_clicked();

    void on_btn_field1_clicked();

    void on_btn_field2_clicked();

    void on_btn_field3_clicked();

    void on_btn_field4_clicked();

    void on_btn_field5_clicked();

    void on_btn_field6_clicked();

    void on_btn_field7_clicked();

    void on_btn_field8_clicked();

    void on_btn_field9_clicked();

    void on_btn_reset_clicked();

private:
    Ui::JogoDaVelha *ui;
    int AIScore = 0;
    int userScore = 0;
    bool winner = false;
    QVector<int> fieldsSelected;
    QString userClickStyle = "QPushButton{border: 1px solid green; background-color: white; color: green;}";
    QString aiClickStyle = "QPushButton{border: 1px solid red; background-color: white; color: red;}";
    QString btnStandardStyle = "QPushButton{border: 1px solid darkgray; background-color: lightgray;}";
};
#endif // JOGODAVELHA_H
