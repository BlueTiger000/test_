#include "serverwindow.h"
#include "Server.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWindow w;
    Server server;
    if (!server.StartServer(QHostAddress::Any,1234)) {
        return -1;
    }
   // w.show();
    return a.exec();
}
