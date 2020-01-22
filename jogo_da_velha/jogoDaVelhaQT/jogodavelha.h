#ifndef JOGODAVELHA_H
#define JOGODAVELHA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class JogoDaVelha; }
QT_END_NAMESPACE

class JogoDaVelha : public QMainWindow
{
    Q_OBJECT

public:
    JogoDaVelha(QWidget *parent = nullptr);
    ~JogoDaVelha();

private:
    Ui::JogoDaVelha *ui;
};
#endif // JOGODAVELHA_H
