#include "adressbook.h"
#include "ui_adressbook.h"

AdressBook::AdressBook(QSqlTableModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdressBook)
{
    ui->setupUi(this);
    modelAdresBook=model;
    ui->tableView->setModel(modelAdresBook);
    modelAdresBook->setHeaderData(1, Qt::Horizontal, QObject::tr("Наименование"));
  //  modelAdresBook->setHeaderData(2, Qt::Horizontal, QObject::tr("Должность"));
    modelAdresBook->select();
    modelAdresBook->submitAll();
    ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(3);
    ui->tableView->hideColumn(4);
    ui->tableView->hideColumn(5);
    ui->tableView->hideColumn(6);
    ui->tableView->resizeColumnsToContents();

    //--------------------------------------
    mapper = new QDataWidgetMapper();
    mapper->setModel(modelAdresBook);
    mapper->addMapping(ui->textEdit, 2);
    mapper->addMapping(ui->checkBoxZK3, 3);
    mapper->addMapping(ui->checkBoxTh4, 4);
    mapper->addMapping(ui->checkBoxMn5, 5);
    mapper->addMapping(ui->checkBoxRp6, 6);
    mapper->toFirst();
    connect (ui->tableView->selectionModel (), SIGNAL (currentRowChanged (QModelIndex, QModelIndex)),
             mapper, SLOT (setCurrentModelIndex (QModelIndex)));
}

AdressBook::~AdressBook()
{
    delete ui;
}

void AdressBook::on_pushButton_3_clicked()
{
    modelAdresBook->submitAll();
    mapper->submit();
}

void AdressBook::on_pushButton_clicked()
{
    int row=modelAdresBook->rowCount();
    modelAdresBook->insertRow(row);
}

void AdressBook::on_pushButton_2_clicked()
{
    int row=ui->tableView->selectionModel()->currentIndex().row();
     modelAdresBook->removeRow(row);
}
