#ifndef DATASENDER_H
#define DATASENDER_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class DataSender; }
QT_END_NAMESPACE

class QUdpSocket;
class DataSender : public QMainWindow
{
    Q_OBJECT

public:
    DataSender(QWidget *parent = nullptr);
    ~DataSender();
      enum class comboItems { TCP, UDP,};

private slots:
    void on_pushButton_clicked();
    void chooseConnection (comboItems which );

private:
    Ui::DataSender *ui;
     QTcpSocket *tcpsoket;

     QUdpSocket* udpsoket;
};


#endif // DATASENDER_H




