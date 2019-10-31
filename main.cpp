#include "rfidmain.h"
#include "adminpanel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    RFIDMain rfid;
    rfid.show();
    
    return a.exec();
}
