#ifndef INITDB_H
#define INITDB_H
#include <QtSql>

static QSqlError initDb()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
   /*
    db.setDatabaseName("sql7258612");
    db.setUserName("sql7258612");
    db.setHostName("sql7.freemysqlhosting.net");
    db.setPort(3306);
    db.setPassword("QWFy4cFtNv");
    */

    db.setDatabaseName("serials");
    db.setUserName("mishapk");
    db.setHostName("in.iteng.com.ua");
    db.setPort(3306);//1104//6060php//2220ssh
    db.setPassword("1111");
    if (!db.open()) {
    return db.lastError();
    }
   QStringList tables = db.tables();
    if (tables.contains("gauges", Qt::CaseInsensitive)
        && tables.contains("gauges_res", Qt::CaseInsensitive)
        && tables.contains("types", Qt::CaseInsensitive))
        return QSqlError();
  return QSqlError();
}

#endif // INITDB_H
