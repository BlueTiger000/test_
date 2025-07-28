#include "Server.h"
Server::Server(QObject *parent) : QTcpServer(parent)
{
    // инициализация
}

bool Server::StartServer(QHostAddress addr,qint16 port)

{
    //out.open("logs.txt");
    /*if (out.is_open())
    {
        qDebug() << "File is open!";
    }*/
    if (!this->listen(QHostAddress::Any, port)) {
        qDebug() << "Server could not start!";

        return false;
    }
    qDebug() << "Server started on port" << port;

    return true;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketDescriptor);

    connect(client, &QTcpSocket::readyRead, this, &Server::onReadyRead);

    m_clients.insert(client, ""); // Временное пустое имя
    qDebug() << "New client connected";

}

void Server::onReadyRead()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (!client) return;

    QString data = QString::fromUtf8(client->readAll());
    qDebug() << "Получено от клиента:" << data;
    if (m_clients[client].isEmpty()) {
        processClientAuth(client, data);
    } else {
        SendMessageToUsers(data, m_clients[client]);
        sendToClient(client, data);
    }
}

void Server::processClientAuth(QTcpSocket *client, const QString &data)
{
    QString name = data.section(':', 1, 1).trimmed();
    if (name.isEmpty()) {
        client->disconnectFromHost();
        return;
    }

    m_clients[client] = name;
    client->write("AUTH_OK");
    SendServerMessageToUsers(QString("User '%1' joined the chat").arg(name));
}


void Server::SendMessageToUsers(const QString &message, const QString &sender)
{
    QString formatted = QString("[%1] %2").arg(sender, message);
    for (QTcpSocket *client : m_clients.keys()) {
        if (m_clients[client] != sender) { // Не отправляем отправителю
            client->write(QString("MSG:%1").arg(formatted).toUtf8());
        }
    }
}

void Server::SendServerMessageToUsers(const QString &message)
{
    for (QTcpSocket *client : m_clients.keys()) {
        client->write(QString("SERVER:%1").arg(message).toUtf8());
    }
}
void Server::sendToClient(QTcpSocket* clientSocket, const QString& message) {
    QByteArray data = message.toUtf8();
    clientSocket->write(data);

    if(clientSocket->waitForBytesWritten(3000)) { // Таймаут 3 секунды
        qDebug() << "Данные отправлены клиенту:" << message;
    } else {
        qDebug() << "Ошибка отправки:" << clientSocket->errorString();
    }
}
