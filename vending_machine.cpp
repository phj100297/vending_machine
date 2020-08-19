#include "vending_machine.h"
#include "ui_vending_machine.h"
#include <QMessageBox>
vending_machine::vending_machine(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::vending_machine)
{
    ui->setupUi(this);
    ui->pushMilk->setEnabled(false);
    ui->pushCoffee->setEnabled(false);
    ui->pushTea->setEnabled(false);
}
vending_machine::~vending_machine()
{
    delete ui;
}
void vending_machine::SetDisplay()
{
    if (money<0)
    {
        money=0;
    }
    if (money>=200)
    {
        ui->pushMilk->setEnabled(true);
    }
    else
    {
        ui->pushMilk->setEnabled(false);
    }
    if (money>=150)
    {
        ui->pushTea->setEnabled(true);
    }
    else
    {
        ui->pushTea->setEnabled(false);
    }
    if (money>=100)
    {
        ui->pushCoffee->setEnabled(true);
    }
    else
    {
        ui->pushCoffee->setEnabled(false);
    }
}
void vending_machine::ChangeMoney(int change)
{
    money += change;
    SetDisplay();
    ui->lcdNumber->display(money);

}

void vending_machine::on_push10_clicked()
{

    ChangeMoney(10);
}

void vending_machine::on_push50_clicked()
{
    ChangeMoney(50);
}

void vending_machine::on_push100_clicked()
{
    ChangeMoney(100);
}

void vending_machine::on_push500_clicked()
{
    ChangeMoney(500);
}

void vending_machine::on_pushCoffee_clicked()
{
    ChangeMoney(-100);
}

void vending_machine::on_pushTea_clicked()
{
    ChangeMoney(-150);
}

void vending_machine::on_pushMilk_clicked()
{
    ChangeMoney(-200);
}

void vending_machine::on_Reset_clicked()
{
    QMessageBox m;
    int coin500=0;
    int coin100=0;
    int coin50=0;
    int coin10=0;
    if (money>=500)
    {
        coin500=money/500;
        money=money-(coin500*500);
    }
    if (money>=100)
    {
        coin100=money/100;
        money=money-(coin100*100);
    }
    if (money >=50)
    {
        coin50=money/50;
        money=money-(coin50*50);
    }
    if (money>=10)
    {
        coin10=money/10;
    }
    money=0;
    m.information(nullptr, "Return","500 :"+ QString::number(coin500)+"\n100 :"+QString::number(coin100)+"\n50 :"+QString::number(coin50)+"\n10 :"+QString::number(coin10));
    ui->lcdNumber->display(money);
    SetDisplay();
}
