#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

#include <QMainWindow>
#include <QVector>

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

private:
    Ui::JogoDaVelha *ui;
    int AIScore = 0;
    int userScore = 0;
    QVector<int> fieldsSelected;
};
#endif // JOGODAVELHA_H
