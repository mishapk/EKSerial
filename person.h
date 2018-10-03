#ifndef PERSON_H
#define PERSON_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class Person;
}

class Person : public QDialog
{
    Q_OBJECT

public:
    explicit Person(QSqlTableModel * model,QWidget *parent = nullptr);
    ~Person();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Person *ui;
    QSqlTableModel * personModel;

};

#endif // PERSON_H
