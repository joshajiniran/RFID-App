#include "rfidmain.h"
#include "loginpanel.h"

#include <QtWidgets>
#include <QSound>

RFIDMain::RFIDMain(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    
    stackedWidget->setCurrentWidget(loginPage);
    
    QSound::play(":/sounds/voice-welcome.wav");
    QTimer *timer = new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(1500);
    timer->start();
    connect(timer, &QTimer::timeout, []() { QSound::play(":/sounds/voice-piy.wav"); });
    
    // some customization
    searchEdit->setClearButtonEnabled(true);
    QIcon ico(":/images/search.png");
    searchEdit->addAction(ico, QLineEdit::LeadingPosition);
    searchEdit->setPlaceholderText("Search for an item...");
}

void RFIDMain::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_A:
        caption.append("a");
        break;
    case Qt::Key_D:
        caption.append("d");
        break;
    case Qt::Key_M:
        caption.append("m");
        break;
    case Qt::Key_I:
        caption.append("i");
        break;
    case Qt::Key_N:
        caption.append("n");
        break;
    default:
        break;
    }
    
    if (!caption.isEmpty() && caption.at(0) == 'a') {
        if (caption == "admin") {
            login = new LoginPanel();
            login->show();
            QSound::play(":/sounds/voice-welcome.wav");
            caption.clear();
        } else if (caption.count() > 5)
            caption.clear();
    } else 
        caption.clear();
}

void RFIDMain::on_searchEdit_textChanged(const QString &arg1)
{
    if (arg1.length() > 0) 
        searchButton->setEnabled(true);
    else
        searchButton->setEnabled(false);
    
    QStringList completions;
    completions << "Rfid Machine" << "Magic wand tool" << "Break Plier"; 
    QCompleter *completer = new QCompleter(completions, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    searchEdit->setCompleter(completer);
}

void RFIDMain::on_pushButton_3_toggled(bool checked)
{
    if (checked) {
        if (!login) {
            login = new LoginPanel();
            login->show();
        } else {
            login->show();
            login->raise();
            login->activateWindow();
        } 
    }
}
