#include "adminpanel.h"
#include <QtSql>

AdminPanel::AdminPanel(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    
    setMinimumSize(800, 640);
    
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("a.josh10");
    db.setDatabaseName("StoreDB");
    db.open();

    empModel = new QSqlTableModel(this, db);
    empModel->setTable("employee");
    empModel->select();
    custModel = new QSqlTableModel(this, db);
    custModel->setTable("customer");
    custModel->select();
    
    employeeTable->setModel(empModel);
    employeeTable->resizeColumnsToContents();
    employeeTable->verticalHeader()->setStretchLastSection(true);
    customerTable->setModel(custModel);
    customerTable->resizeColumnsToContents();
    customerTable->verticalHeader()->setStretchLastSection(true);
}

void AdminPanel::on_searchEdit_textChanged(const QString &arg1)
{
    if (arg1.length() > 0)
        searchBtn->setEnabled(true);
    else
        searchBtn->setDisabled(true);
}
