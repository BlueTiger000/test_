#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "Client.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ClientWindow;
}
QT_END_NAMESPACE

class ClientWindow : public QMainWindow
{
    //Client *client = new Client(this);
    Q_OBJECT
    QString id_address;
    QString pushed_message;
    qint16 port;
    QString client_name;
    QTimer *holdTimer;
public:
    ClientWindow(QWidget *parent = nullptr);
    ~ClientWindow();

private slots:
    void on_push_message_clicked();

   // void on_connect_with_server_clicked(bool);

    void on_connect_with_server_pressed();

private:
    Ui::ClientWindow *ui;
};
#endif // CLIENTWINDOW_H
