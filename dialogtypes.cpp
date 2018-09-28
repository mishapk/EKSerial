#include "dialogtypes.h"
#include "ui_dialogtypes.h"
DialogTypes::DialogTypes(QSqlTableModel *TypeModel, QSqlTableModel *ChanelModel, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTypes)
{
    ui->setupUi(this);
    modelTypes=TypeModel;
    modelChanels=ChanelModel;

    ui->tableViewTypes->setModel(TypeModel);
    TypeModel->setHeaderData(1, Qt::Horizontal, QObject::tr("Наименование"));

    ui->tableViewChanels->setModel(ChanelModel);
    ChanelModel->setHeaderData(2, Qt::Horizontal, QObject::tr("Наименование"));
    modelTypes->submitAll();
    modelChanels->submitAll();
    ui->tableViewTypes->resizeColumnsToContents();
   // ui->tableViewTypes->hideColumn(0);
    //ui->tableViewTypes->verticalHeader()->setVisible(false);


}

DialogTypes::~DialogTypes()
{
    delete ui;
}

void DialogTypes::on_pushButton_2_clicked()
{
   modelTypes->insertRow(modelTypes->rowCount());
}

void DialogTypes::on_pushButton_8_clicked()
{
    modelTypes->submitAll();
}

void DialogTypes::on_pushButtonAddChanels_clicked()
{
    modelChanels->insertRow(modelChanels->rowCount());
}

void DialogTypes::on_pushButton_7_clicked()
{
  modelChanels->submitAll();
}

void DialogTypes::on_tableViewTypes_clicked(const QModelIndex &index)
{
    QModelIndex index2 = modelTypes->index(index.row(), 0);
    qDebug()<<index2.data().toString();
    modelChanels->setFilter("ID = '" + index2.data().toString() + '\'') ;
    qDebug()<<ui->tableViewTypes->currentIndex().model()->index()
}


