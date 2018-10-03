#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDataWidgetMapper>

namespace Ui {
class AdressBook;
}

class AdressBook : public QDialog
{
    Q_OBJECT

public:
    explicit AdressBook(QSqlTableModel *model,QWidget *parent = nullptr);
    ~AdressBook();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AdressBook *ui;
    QSqlTableModel *modelAdresBook;
    QDataWidgetMapper *mapper;
};

#endif // ADRESSBOOK_H
