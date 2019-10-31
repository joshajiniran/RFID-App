#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include "ui_adminpanel.h"
#include "loginpanel.h"

#include <QtSql>

class AdminPanel;

class AdminPanel : public QWidget, private Ui::AdminPanel
{
    Q_OBJECT
    
public:
    explicit AdminPanel(QWidget *parent = 0);
    
    
private slots:
    void on_searchEdit_textChanged(const QString &arg1);
    
private:
    QSqlTableModel *empModel;
    QSqlTableModel *custModel;
    QSqlDatabase db;
    
};

#endif // ADMINPANEL_H
