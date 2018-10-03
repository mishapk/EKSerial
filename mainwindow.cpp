#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <dialogtypes.h>
#include "initdb.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Initialize the database:
     QSqlError err = initDb();
     if (err.type() != QSqlError::NoError) {
            showError(err);
            return;
        }
    ui->splitter->setSizes(QList<int>() <<ui->splitter->width()<<0);

    model = new  QSqlRelationalTableModel(this);
    model->setTable("device");
    model->setRelation(1, QSqlRelation("types", "id", "name_dev"));
    model->setRelation(4, QSqlRelation("ZK", "id", "ename"));
    model->setRelation(5, QSqlRelation("MN", "id", "ename"));
    model->setRelation(6, QSqlRelation("TH", "id", "ename"));
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));


    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::EditKeyPressed);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setColumnWidth(3,80);
    ui->tableView->setColumnWidth(4,120);
    ui->tableView->setColumnWidth(5,120);
    ui->tableView->setColumnWidth(6,120);

    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Наименование\n изделия"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Дата\n создания"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Заводской\n номер"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Заказчик"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Монтажник"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Обслуживание"));
    //-----------------------------------------------------------------
    modelStamp =new  QSqlRelationalTableModel(this);
    modelStamp->setTable("stamp");
    modelStamp->setRelation(4, QSqlRelation("person", "id", "PName"));
    modelStamp->setEditStrategy(QSqlTableModel::OnManualSubmit);
    modelStamp->select();
    modelStamp->setHeaderData(4, Qt::Horizontal, QObject::tr("ФИО\nполучателя"));
    ui->tableViewStamp->setModel(modelStamp);
    ui->tableViewStamp->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewStamp));
    ui->tableViewStamp->setEditTriggers(QAbstractItemView::EditKeyPressed);
    ui->tableView->resizeColumnsToContents();
    ui->tableViewStamp->hideColumn(3);



    //master-detail
      connect(ui->tableView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(change_table_serial()));
    //-----------------------------------------------------------------
    TypeModel= new QSqlTableModel(this);
    TypeModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    TypeModel->setTable("types");

    ChanelModel= new QSqlTableModel(this);
    ChanelModel->setTable("chanels");
    ChanelModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_DialogTypes = new DialogTypes(TypeModel,ChanelModel,this);
    //-------------------------------------------------------------------
    PersonModel= new QSqlTableModel(this);
    PersonModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
     PersonModel->setTable("person");
    m_person = new Person(PersonModel,this);
    //------------------------------------------------------------------
    AdressBookModel= new QSqlTableModel(this);
    AdressBookModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    AdressBookModel->setTable("adressbook");
    m_AdressBook = new AdressBook(AdressBookModel,this);


}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_4_triggered()
{
    m_DialogTypes = new DialogTypes(TypeModel,ChanelModel,this);
    m_DialogTypes->exec();
}

void MainWindow::on_action_3_triggered()
{
    QMessageBox::question(this,"Удаление","Вы действительно хотите удалить запись?");
}

void MainWindow::on_action_triggered()
{
    int row=model->rowCount();
    model->insertRow(row);
}

void MainWindow::showError(const QSqlError &err)
{
   QMessageBox::critical(this, "Unable to initialize Database",
                    "Error initializing database: " + err.text());
  //qDebug()<< err.text();
}

void MainWindow::on_action_7_triggered()
{

    m_person->exec();
}

void MainWindow::on_action_6_triggered()
{
   m_AdressBook->exec();
}

void MainWindow::on_action_8_triggered()
{
    model->submitAll();
     ui->tableView->resizeColumnsToContents();
}

void MainWindow::on_action_9_triggered()
{
    QList<int> pos;
    if(!ui->action_9->isChecked())
        pos<<ui->splitter->width()<<0;
    else
        pos<<ui->splitter->width()/2<< ui->splitter->width()/3;
   ui->splitter->setSizes(pos);
}






void MainWindow::on_toolButton_clicked()
{

    int row=ui->tableView->selectionModel()->currentIndex().row();   //Получаем номер выбранной строки таблицы типов
    int id=model->record(row).value(0).toInt();                      //Получаем значение ID таблицы типов
    int nrow=modelStamp->rowCount();
    modelStamp->insertRow(nrow);                                        //Вставляем новую строку в конец таблицы
    modelStamp->setData(model->index(nrow, 3), id);               //Подсталяем ID типа в соответсвующие поле
}

void MainWindow::on_toolButton_3_clicked()
{
    modelStamp->submitAll();
}

void MainWindow::change_table_serial()
{
    //Master-Dertail
    int row=ui->tableView->selectionModel()->currentIndex().row();   //Получаем номер выбранной строки таблицы типов
    QString id=model->record(row).value(0).toString();
    modelStamp->setFilter("ids = '" + id + '\'') ;
}
