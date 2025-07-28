#include "clientwindow.h"
#include <QTimer>
#include <QApplication>
#include "Client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientWindow w;

    Client client;
    //client.setName("Вася");  // Устанавливаем имя
    //client.connectToServer("127.0.0.1", 1234);  // Подключаемся к серверу


    // Вывод получаемых сообщений
    QObject::connect(&client, &Client::newMessage, [](const QString &msg) {
        qDebug() << "Получено:" << msg;
    });

    w.show();
    return a.exec();
}
