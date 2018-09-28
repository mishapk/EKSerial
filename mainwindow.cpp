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
    model = new QSqlTableModel(this);
    model->setTable("gauges_res");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::EditKeyPressed);
    TypeModel= new QSqlTableModel(this);
    TypeModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    TypeModel->setTable("types");
    ChanelModel= new QSqlTableModel(this);
    ChanelModel->setTable("chanels");
    ChanelModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

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

}

void MainWindow::showError(const QSqlError &err)
{
   QMessageBox::critical(this, "Unable to initialize Database",
                    "Error initializing database: " + err.text());
  //qDebug()<< err.text();
}
