#ifndef DIALOGTYPES_H
#define DIALOGTYPES_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class DialogTypes;
}

class DialogTypes : public QDialog
{
    Q_OBJECT

public:
    explicit DialogTypes(QSqlTableModel *TypeModel,QSqlTableModel *ChanelModel,QWidget *parent = nullptr);
    ~DialogTypes();
    QSqlTableModel *modelTypes;
    QSqlTableModel *modelChanels;
private slots:


    void on_pushButtonAddChanels_clicked();


    void on_tableViewTypes_clicked(const QModelIndex &index);


    void on_pushButtonSubmitChanels_clicked();

    void on_pushButtonSubmitTypes_clicked();

    void on_pushButtonADDTypes_clicked();

    void change_tabletypes();

private:
    Ui::DialogTypes *ui;

};

#endif // DIALOGTYPES_H
