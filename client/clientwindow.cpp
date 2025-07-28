#include "clientwindow.h"
#include "ui_clientwindow.h"
Client client2;


ClientWindow::ClientWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ClientWindow)
{
    ui->setupUi(this);
    Client *client = new Client(this);
   connect(client, &Client::connectionStatusChanged, this, [this](const QString &msg) {
    ui->Message_box->append("[STATUS] " + msg);
    });
    connect(client, &Client::newMessageReceived, this, [this](const QString &msg) {
        ui->Message_box->append("[ДАННЫЕ] " + msg);
    });
}

ClientWindow::~ClientWindow()
{
    delete ui;

}

void ClientWindow::on_push_message_clicked()
{
    pushed_message = ui->enter_text->text();
    client2.sendMessage(pushed_message);
    ui->enter_text->clear();
}




/*void ClientWindow::on_connect_with_server_clicked(bool)
{
    id_address = ui->ip_adress->text();
    QString port_qstd = ui->port_name->text();
    bool ok;
    port = port_qstd.toShort(&ok); // ok будет true, если преобразование успешно
    if(!ok) {
        qDebug() << "Ошибка преобразования строки в число";
    }
    client_name = ui->client_name->text();
    client.setName(client_name);
    client.connectToServer(id_address, port);
     ui-> Message_box->append("Ожидаем подключения");

    QObject::connect(&client, &Client::newMessage, [this](const QString &msg) {
       // qDebug() << "Получено:" << msg;
        ui-> Message_box->append(msg);
    });

}*/

/*QObject::connect(&client, &Client::newMessage, [](const QString &msg) {

    this-> Message_box->append("Новый текст");
    qDebug() << "Получено:" << msg;
});*/

void ClientWindow::on_connect_with_server_pressed()
{
    holdTimer = new QTimer(this); // 1. Создаем таймер
    holdTimer->setInterval(500);  // 2. Устанавливаем интервал


    id_address = ui->ip_adress->text();
    QHostAddress address(id_address);
    if (address.isNull()) {
        qDebug() << "Неверный IP-адрес";
    }
    QString port_qstd = ui->port_name->text();
    bool ok;
    port = port_qstd.toShort(&ok); // ok будет true, если преобразование успешно
    if(!ok) {
        qDebug() << "Ошибка преобразования строки в число";
    }
    client_name = ui->client_name->text();
    client2.setName(client_name);
    client2.connectToServer(id_address, port);
    ui-> Message_box->append("Ожидаем подключения");
   // connect(ui->connect_with_server, &QPushButton::pressed, this, [this](){
       // holdTimer->start();
       // ui-> Message_box->append("Кнопка зажата");
        QObject::connect(&client2, &Client::newMessage, [this](const QString &msg) {
            // qDebug() << "Получено:" << msg;
            ui-> Message_box->append(msg);
        });
     //   qDebug() << "Кнопка зажата";
   // });

    /*QObject::connect(&client, &Client::newMessage, [this](const QString &msg) {
        // qDebug() << "Получено:" << msg;
        ui-> Message_box->append(msg);
    });*/
}

