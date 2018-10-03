#include "person.h"
#include "ui_person.h"
#include <QDebug>
Person::Person(QSqlTableModel * model,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Person)
{
    ui->setupUi(this);
    personModel = model;
    ui->tableView->setModel(personModel);
    personModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Фамилия И.О."));
    personModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Должность"));
    personModel->select();
    personModel->submitAll();
    ui->tableView->resizeColumnsToContents();
}

Person::~Person()
{
    delete ui;
}

void Person::on_pushButton_clicked()
{
    int row=personModel->rowCount();
    personModel->insertRow(row);
}

void Person::on_pushButton_3_clicked()
{
   personModel->submitAll();

}

void Person::on_pushButton_2_clicked()
{
     int row=ui->tableView->selectionModel()->currentIndex().row();
     personModel->removeRow(row);
}
