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
    ui->tableViewChanels->resizeColumnsToContents();
    ui->tableViewTypes->selectRow(0);
    modelChanels->setFilter("TYPE_ID = 1") ;
   // ui->tableViewTypes->hideColumn(0);
    //ui->tableViewTypes->verticalHeader()->setVisible(false);
    ui->tableViewChanels->hideColumn(0);
    //ui->tableViewChanels->hideColumn(1);
  //master-detail
    connect(ui->tableViewTypes->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(change_tabletypes()));

}

DialogTypes::~DialogTypes()
{
    delete ui;
}





void DialogTypes::on_pushButtonAddChanels_clicked()
{

    int row=ui->tableViewTypes->selectionModel()->currentIndex().row();   //Получаем номер выбранной строки таблицы типов
    int id=modelTypes->record(row).value(0).toInt();                      //Получаем значение ID таблицы типов
    int nrow=modelChanels->rowCount();
    modelChanels->insertRow(nrow);                                        //Вставляем новую строку в конец таблицы
    modelChanels->setData(modelTypes->index(nrow, 1), id);               //Подсталяем ID типа в соответсвующие поле
}


void DialogTypes::on_tableViewTypes_clicked(const QModelIndex &index)
{
    //Master-Dertail
 //   QString id= modelTypes->record(index.row()).value(0).toString();
  //  modelChanels->setFilter("TYPE_ID = '" + id + '\'') ;

}



void DialogTypes::on_pushButtonSubmitChanels_clicked()
{
   modelChanels->submitAll();
}

void DialogTypes::on_pushButtonSubmitTypes_clicked()
{
  modelTypes->submitAll();

}

void DialogTypes::on_pushButtonADDTypes_clicked()
{
    int row=modelTypes->rowCount();
    modelTypes->insertRow(row);

}

void DialogTypes::change_tabletypes()
{
    //Master-Dertail
    int row=ui->tableViewTypes->selectionModel()->currentIndex().row();   //Получаем номер выбранной строки таблицы типов
    QString id=modelTypes->record(row).value(0).toString();
    modelChanels->setFilter("TYPE_ID = '" + id + '\'') ;

}

