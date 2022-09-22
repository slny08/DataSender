#include "datasender.h"
#include "ui_datasender.h"
#include <QString>
#include "QUdpSocket"
#include "ComboBoxHelper.h"
#include <QMessageBox>

  int secim;
DataSender::DataSender(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DataSender)
{
    ui->setupUi(this);

     int setupMethod = 0;
        if (setupMethod == 0)
            ComboBoxHelper::setup<comboItems>(ui->comboBox, comboItems::TCP,
                                              {{"TCP", comboItems::TCP},
                                               {"UDP", comboItems::UDP}},
                                              this, &DataSender::chooseConnection);

}

DataSender::~DataSender()
{
    delete ui;
}

void DataSender::chooseConnection(DataSender::comboItems which)
{

                                                 switch (which) {
                                                     case comboItems::TCP:
                                                      tcpsoket = new QTcpSocket;
                                                      tcpsoket ->connectToHost("127.0.0.1",1234);
                                                      qDebug() << "tcp secildi";
                                                      secim=0;
                                                         break;
                                                     case comboItems::UDP:
                                                      udpsoket=new QUdpSocket(this);
                                                      qDebug() << "udp secildi";
                                                      secim=1;
                                                         break;
                                                     }
}

void DataSender::on_pushButton_clicked()
{

    QString veri = ui ->lineEdit->text();
    QByteArray gonderilecek;
    gonderilecek=veri.toUtf8();

    switch (secim) {
        case 0:
         tcpsoket->write(gonderilecek);
         qDebug() << "tcp gonderildi";
            break;
        case 1:
         udpsoket->writeDatagram(gonderilecek,QHostAddress::LocalHost, 2323);
         qDebug() << "udp secildi";
            break;
        }
}





