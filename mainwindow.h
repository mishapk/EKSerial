#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <dialogtypes.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QSqlTableModel *model;
    QSqlTableModel *TypeModel;
    QSqlTableModel *ChanelModel;
    DialogTypes *m_DialogTypes;


private slots:
    void on_action_4_triggered();

    void on_action_3_triggered();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
    void showError(const QSqlError &err);
};

#endif // MAINWINDOW_H
