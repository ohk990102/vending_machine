#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <climits>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->display(money);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb10_clicked()
{
    addMoney(10);
    updateView();
}

void Widget::on_pb50_clicked()
{
    addMoney(50);
    updateView();
}

void Widget::on_pb100_clicked()
{
    addMoney(100);
    updateView();
}

void Widget::on_pb500_clicked()
{
    addMoney(500);
    updateView();
}

void Widget::on_pbCoffee_clicked()
{
    buyDrink(100);
    updateView();
}

void Widget::on_pbTea_clicked()
{
    buyDrink(150);
    updateView();
}

void Widget::on_pbCoke_clicked()
{
    buyDrink(200);
    updateView();
}

void Widget::on_pbReset_clicked()
{
    QString ret = "";
    if(money > 0) {
        int coin[4] = {500, 100, 50, 10};
        for(int i = 0; i < 4; i++) {
            if(money >= coin[i]) {
                ret.append(QString::number(coin[i]));
                ret.append("원: ");
                ret.append(QString::number(money / coin[i]));
                ret.append("개\n");
                money %= coin[i];
            }
        }
    }
    else
        ret = "No money. ";
    QMessageBox msg;
    msg.information(nullptr, "Vending Machine", ret);
    msg.show();
    updateView();
}

void Widget::addMoney(int amount) {
    if(money + amount < 0)
        return;
    money += amount;
    ui->lcdNumber->display(money);
}

void Widget::buyDrink(int amount)
{
    if(money < amount)
    {
        QMessageBox msg;
        msg.warning(nullptr, "Vending Machine", "Not enough money. ");
        msg.show();
        return;
    }
    money -= amount;

}
void Widget::updateView() {
    if(money >= 100)
        ui->pbCoffee->setDisabled(false);
    else
        ui->pbCoffee->setDisabled(true);
    if(money >= 150)
        ui->pbTea->setDisabled(false);
    else
        ui->pbTea->setDisabled(true);
    if(money >= 200)
        ui->pbCoke->setDisabled(false);
    else
        ui->pbCoke->setDisabled(true);
    ui->lcdNumber->display(money);
}


