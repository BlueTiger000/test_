#ifndef CLIENT_H
#define CLIENT_H
#include <QTcpSocket>
#include <QObject>
#include <string>
#include <iostream>

class Client : public QObject
{
    Q_OBJECT

public:
    explicit Client(QObject *parent = nullptr);
    void connectToServer(const QString &ip, quint16 port);  // Подключение к серверу
    void sendMessage(const QString &message);               // Отправка сообщения
    void setName(const QString &name);                      // Установка имени

signals:
    void newMessage(const QString &message);
    void connectionStatusChanged(const QString &message);
    void newMessageReceived(const QString &message);    // Сигнал о новом сообщении

private slots:
    void onReadyRead();    // Чтение данных от сервера
    void onConnected();    // Успешное подключение
    void onDisconnected(); // Отключение от сервера

private:
    QTcpSocket *_socket;   // Сокет для соединения
    QString _name;         // Имя клиента
};
#endif // CLIENT_H
