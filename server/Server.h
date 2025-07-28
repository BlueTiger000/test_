#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QList>
#include <QMap>
#include <windows.h.>
#include <fstream>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = nullptr);
    bool StartServer(QHostAddress addr, qint16 port);
    void SendMessageToUsers(const QString &message, const QString &sender);
    void SendServerMessageToUsers(const QString &message);
    void sendToClient(QTcpSocket* clientSocket, const QString& message);

protected:
    void incomingConnection(qintptr handle);

private:
    //std::ofstream out;

    QMap<QTcpSocket*, QString> m_clients;
    QWidget *_widget;
    void processClientAuth(QTcpSocket *client, const QString &data);
private slots:
    void onReadyRead();

};

#endif // SERVER_H
