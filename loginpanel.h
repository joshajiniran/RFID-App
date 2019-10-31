#ifndef LOGINPANEL_H
#define LOGINPANEL_H

#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;
class AdminPanel;
class QGridLayout;

class LoginPanel : public QWidget
{
    Q_OBJECT
public:
    explicit LoginPanel(QWidget *parent = 0);
    
    AdminPanel *admin;
    
private:
    QLabel *userLbl;
    QLabel *passwordLbl;
    QLineEdit *userEdit;
    QLineEdit *passwordEdit;
    QPushButton *loginBtn;
    QPushButton *cancelBtn;
    QGridLayout *mainLayout;
    
    QString userText, pswdText; 
    
private slots:
    void showAdmin();
    
};

#endif // LOGINPANEL_H
