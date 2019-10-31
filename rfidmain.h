#ifndef RFIDMAIN_H
#define RFIDMAIN_H

#include "ui_rfidmain.h"
#include "adminpanel.h"
#include <QtSql>

class LoginPanel;

class RFIDMain : public QWidget, private Ui::RFIDMain
{
   Q_OBJECT
    
public:
    explicit RFIDMain(QWidget *parent = 0);
    
protected slots:
    void keyPressEvent(QKeyEvent *event);

    
private slots:
    void on_searchEdit_textChanged(const QString &arg1);
    
    void on_pushButton_3_toggled(bool checked);
    
private:
    QString caption;
    AdminPanel *admin;
    LoginPanel *login;
};

#endif // RFIDMAIN_H
