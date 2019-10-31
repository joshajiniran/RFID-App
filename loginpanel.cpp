#include "loginpanel.h"
#include "adminpanel.h"

#include <QtWidgets>

LoginPanel::LoginPanel(QWidget *parent) : QWidget(parent)
{
    userLbl = new QLabel(tr("Admin name: "));
    userEdit = new QLineEdit;
    userEdit->setFocus();
    userLbl->setBuddy(userEdit);
    
    qDebug() << QApplication::focusWidget();
    
    passwordLbl = new QLabel(tr("Password: "));
    passwordEdit = new QLineEdit;
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordLbl->setBuddy(passwordEdit);
    
    loginBtn = new QPushButton(tr("&Login"), this);
    cancelBtn = new QPushButton(tr("&Cancel"), this);
    
    connect(loginBtn, SIGNAL(clicked()), this, SLOT(showAdmin()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));
    
    // attempts to login when users press enter key
    connect(userEdit, SIGNAL(returnPressed()), loginBtn, SLOT(click()));
    connect(passwordEdit, SIGNAL(returnPressed()), loginBtn, SLOT(click()));
    
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(userLbl, 0, 0);
    mainLayout->addWidget(userEdit, 0, 1);
    mainLayout->addWidget(passwordLbl, 1, 0);
    mainLayout->addWidget(passwordEdit, 1, 1);
    mainLayout->addWidget(loginBtn, 2, 0);
    mainLayout->addWidget(cancelBtn, 2, 1);
    
    setLayout(mainLayout);
    
    userText = userEdit->text();
    pswdText = passwordEdit->text();
}

void LoginPanel::showAdmin()
{
    userText = userEdit->text();
    pswdText = passwordEdit->text();
    
    if (userText == "Admin" && pswdText == "admin1234") {
        this->close();
        admin = new AdminPanel;
        admin->show();
    } else {
        passwordEdit->text().clear();
    }
    
}
