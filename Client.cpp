#include "Client.h"
#include <QDebug>

Client::Client(QObject *parent) : QObject(parent), _socket(new QTcpSocket(this))
{
    connect(_socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
    connect(_socket, &QTcpSocket::connected, this, &Client::onConnected);
}

void Client::connectToServer(const QString &ip, quint16 port) {
    _socket->connectToHost(ip, port);  // Подключение к серверу
}

void Client::setName(const QString &name) {
    _name = name;
    // Отправляем серверу имя при подключении
    if (_socket->state() == QTcpSocket::ConnectedState) {
        _socket->write(QString("NAME:%1").arg(_name).toUtf8());
    }
}

void Client::sendMessage(const QString &message) {
    if (_socket->state() == QTcpSocket::ConnectedState) {
        _socket->write(message.toUtf8());  // Отправляем сообщение
        std::cout <<"сообщение отправлено";
    }
}

void Client::onReadyRead() {
    QString message = QString::fromUtf8(_socket->readAll());
    emit newMessage(message);  // Передаем сообщение в интерфейс
}

void Client::onConnected() {
    qDebug() << "Успешно подключились к серверу!";
    emit connectionStatusChanged("Подключено к серверу");
    _socket->write(QString("NAME:%1").arg(_name).toUtf8());  // Отправляем имя
}

void Client::onDisconnected() {
    qDebug() << "Отключились от сервера.";
}
