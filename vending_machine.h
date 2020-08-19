#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class vending_machine; }
QT_END_NAMESPACE

class vending_machine : public QWidget
{
    Q_OBJECT

public:
    vending_machine(QWidget *parent = nullptr);
    ~vending_machine();
    int money { 0 };
    void ChangeMoney(int change);
    void SetDisplay();
private slots:
    void on_push10_clicked();

    void on_push50_clicked();

    void on_push100_clicked();

    void on_push500_clicked();

    void on_pushCoffee_clicked();

    void on_pushTea_clicked();

    void on_pushMilk_clicked();

    void on_Reset_clicked();

private:
    Ui::vending_machine *ui;
};
#endif // VENDING_MACHINE_H
