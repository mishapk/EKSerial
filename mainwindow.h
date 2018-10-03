#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "dialogtypes.h"
#include "person.h"
#include "adressbook.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlRelationalTableModel *model;
    QSqlRelationalTableModel *modelStamp;
    QSqlTableModel *TypeModel;
    QSqlTableModel *ChanelModel;
    QSqlTableModel *PersonModel;
    QSqlTableModel *AdressBookModel;
    DialogTypes *m_DialogTypes;
    Person * m_person;
    AdressBook * m_AdressBook;

private slots:
    void on_action_4_triggered();

    void on_action_3_triggered();

    void on_action_triggered();

    void on_action_7_triggered();

    void on_action_6_triggered();

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_toolButton_clicked();

    void on_toolButton_3_clicked();
    void change_table_serial();

private:
    Ui::MainWindow *ui;
    void showError(const QSqlError &err);
};

#endif // MAINWINDOW_H
