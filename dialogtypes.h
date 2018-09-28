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
    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();

    void on_pushButtonAddChanels_clicked();

    void on_pushButton_7_clicked();

    void on_tableViewTypes_clicked(const QModelIndex &index);


private:
    Ui::DialogTypes *ui;
};

#endif // DIALOGTYPES_H
