#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QList>

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //设置背景颜色
    setground();

    QIcon icon;
    icon.addFile(tr("res/images/win.ico"));
    setWindowIcon(icon);

    ui->setupUi(this);
    serial =new QSerialPort;

    QString description;
    QString manufacturer;
    QString serialNumber;
    QList<QSerialPortInfo> serialPortInfos=QSerialPortInfo::availablePorts();
    //将所有可使用的串口添加到ComboBox中
    for(const QSerialPortInfo &serialPortInfo : serialPortInfos){
        description=serialPortInfo.description();
        manufacturer = serialPortInfo.manufacturer();
        serialNumber=serialPortInfo.serialNumber();
        QStringList list;
        list << serialPortInfo.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << serialPortInfo.systemLocation()
             << (serialPortInfo.vendorIdentifier() ? QString::number(serialPortInfo.vendorIdentifier(), 16) : blankString)
             << (serialPortInfo.productIdentifier() ? QString::number(serialPortInfo.productIdentifier(), 16) : blankString);
        ui->comboBox_serialPort->addItem(list.first(),list);
    }
    ui->comboBox_serialPort->addItem(tr("custom"));

    //设置波特率
    ui->comboBox_baudRate->addItem(QStringLiteral("9600"),QSerialPort::Baud1200);
    ui->comboBox_baudRate->addItem(QStringLiteral("2400"),QSerialPort::Baud2400);
    ui->comboBox_baudRate->addItem(QStringLiteral("4800"),QSerialPort::Baud4800);
    ui->comboBox_baudRate->addItem(QStringLiteral("9600"),QSerialPort::Baud9600);
    ui->comboBox_baudRate->addItem(QStringLiteral("19200"),QSerialPort::Baud19200);
    ui->comboBox_baudRate->addItem(QStringLiteral("38400"),QSerialPort::Baud38400);
    ui->comboBox_baudRate->addItem(QStringLiteral("57600"),QSerialPort::Baud57600);
    ui->comboBox_baudRate->addItem(QStringLiteral("115200"),QSerialPort::Baud115200);
    ui->comboBox_baudRate->addItem(tr("custom"));
    //设置数据位
    ui->comboBox_dataBit->addItem(QStringLiteral("5"), QSerialPort::Data5);
    ui->comboBox_dataBit->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->comboBox_dataBit->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->comboBox_dataBit->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->comboBox_dataBit->setCurrentIndex(3);
    //设置奇偶校验位
    ui->comboBox_parity->addItem(tr("None"), QSerialPort::NoParity);
    ui->comboBox_parity->addItem(tr("Even"), QSerialPort::EvenParity);
    ui->comboBox_parity->addItem(tr("Odd"), QSerialPort::OddParity);
    ui->comboBox_parity->addItem(tr("Mark"), QSerialPort::MarkParity);
    ui->comboBox_parity->addItem(tr("Space"), QSerialPort::SpaceParity);

    //设置停止位
    ui->comboBox_stopBit->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    ui->comboBox_stopBit->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    //添加流控
    ui->comboBox_flowBit->addItem(tr("None"), QSerialPort::NoFlowControl);
    ui->comboBox_flowBit->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    ui->comboBox_flowBit->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);

    //禁用发送按钮
    ui->btn_Send->setEnabled(false);

    //设置发送编码格式
    ui->radioButton_hex->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete serial;
    delete ui;
}

void MainWindow::on_btn_openConsole_clicked()
{
    qDebug()<<ui->btn_openConsole->text()<<endl;
    if(ui->btn_openConsole->text()==tr("打开串口")){
        //设置串口名称
        serial->setPortName(ui->comboBox_serialPort->currentText());
        //设置波特率
        serial->setBaudRate(ui->comboBox_baudRate->currentText().toInt());
        //设置数据位
        serial->setDataBits(QSerialPort::Data8);
        //设置奇偶校位
        serial->setParity(QSerialPort::NoParity);
        //设置停止位
        serial->setStopBits(QSerialPort::OneStop);
        //设置流控
        serial->setFlowControl(QSerialPort::NoFlowControl);

        //打开串口
        if(serial->open(QIODevice::ReadWrite)){
            ui->comboBox_baudRate->setEnabled(false);
            ui->comboBox_dataBit->setEnabled(false);
            ui->comboBox_flowBit->setEnabled(false);
            ui->comboBox_parity->setEnabled(false);
            ui->comboBox_serialPort->setEnabled(false);
            ui->comboBox_stopBit->setEnabled(false);

            ui->btn_Send->setEnabled(true);

            ui->btn_openConsole->setText(tr("关闭串口"));

            //连接到槽
            connect(serial,&QSerialPort::readyRead,this,&MainWindow::readData);
        }
    }else{
        serial->close();
        ui->comboBox_baudRate->setEnabled(true);
        ui->comboBox_dataBit->setEnabled(true);
        ui->comboBox_flowBit->setEnabled(true);
        ui->comboBox_parity->setEnabled(true);
        ui->comboBox_serialPort->setEnabled(true);
        ui->comboBox_stopBit->setEnabled(true);

        ui->btn_openConsole->setText(tr("打开串口"));
        ui->btn_Send->setEnabled(false);
    }
}

void MainWindow::on_btn_Send_clicked()
{
    QString sendData = ui->textEdit_send->toPlainText();
    qDebug()<<sendData<<endl;

    if(ui->radioButton_ascii->isChecked()){
        //displaysend(sendData);
        //Unicode转GBK
        QTextCodec *codec = QTextCodec::codecForName("GBK"); //建立一个unicode与GBK之间的转换器
        QByteArray bytesForGBK = codec->fromUnicode(sendData); //unicode转换成gbk
        //发送数据
        serial->write(bytesForGBK);
    } else if(ui->radioButton_hex->isChecked()) {
        //是否显示发送消息
        //displaysend(sendData);
        // HexToString
        QByteArray sendbuff("");
        //方法一
        QStringtoHex(sendbuff,sendData);
        //方法二
        //sendbuff = QByteArray::fromHex(sendData.toLatin1().data());
        serial->write(sendbuff);
    }
}

void MainWindow::on_btn_clearSend_clicked()
{
    ui->textEdit_send->clear();
}

void MainWindow::on_btn_clearRecv_clicked()
{
    ui->textEdit_recv->clear();
}

void MainWindow::readData()
{
    QByteArray buf;//QByteArray为16进制字符
    buf = serial->readAll();
    //qDebug() << "readData: " <<buf<< endl;
    if (!buf.isEmpty())
    {
        QString str = ui->textEdit_recv->toPlainText();
        if(ui->radioButton_ascii->isChecked()){
            str +=tr(buf);
            str +="\r\n";
            ui->textEdit_recv->clear();
            ui->textEdit_recv->append(str);
        }else if(ui->radioButton_hex->isChecked()){
            str +=QString(buf.toInt());//转化为int
            str +="\r\n";
            ui->textEdit_recv->clear();
            ui->textEdit_recv->append(str);
        }
    }
}

char MainWindow::ConvertHexChar(char c)
{
    if(c>='a'&&c<='f')
    {
        return c-'a'+10;
    }
    else if(c>='A'&&c<='F')
    {
        return c-'A'+10;
    }
    else if(c>='0'&&c<='9')
    {
        return c-'0';
    }
    else{
        return -1;
    }
}

void MainWindow::setground()
{
    palette.setColor(QPalette::Background,QColor(85, 85, 125));
    this->setPalette(palette);
}

void MainWindow::QStringtoHex(QByteArray& sendData,QString str)
{
    char hstr,lstr,hdata,ldata;
    int len = str.length();
    int sendnum = 0;
    QByteArray temp;
    temp.resize(len);//设置大小，len/2会大于实际16进制字符
    //sendData.resize(len/2);
    for(int i=0;i<len;)
    {
        //hstr = str[i].toAscii();
        hstr = str[i].toLatin1();
        if(hstr == ' ')
        {
            ++i;
            continue;
        }
        ++i;
        if(i >= len)
        {
            break;
        }
        lstr = str[i].toLatin1();
        hdata = ConvertHexChar(hstr);
        ldata = ConvertHexChar(lstr);
        if(-1 == hdata || -1 == ldata)
        {
            break;
        }
        ++i;
        temp[sendnum] = hdata<<4 | ldata;
        sendnum++;
    }
    sendData.reserve(sendnum);
    //sendData = temp.left(sendnum);//去掉多余字符
    qDebug()<<sendData<<endl;
}

