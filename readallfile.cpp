#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include "readallfile.h"
#include <QMessageBox>

const QString filestr1 = "/etc/sysconfig/network-scripts/ifcfg-eno1";
const QString filestr2 = "/etc/sysconfig/network-scripts/ifcfg-enp1s0f0";
const QString filestr3 = "/etc/sysconfig/network-scripts/ifcfg-enp1s0f1";
const QString filestr4 = "/etc/sysconfig/network-scripts/ifcfg-enp5s0f0";
const QString filestr5 = "/etc/sysconfig/network-scripts/ifcfg-enp5s0f1";
const QString filestr11 = "/etc/profile.d/custom.sh";
const QString filestr12 = "/home/v1.1/bin/FileVersion.ini";
const QString filestr13 = "/home/v1.1/bin/SysConfig/WeatherConfig.xml";
const QString filestr14 = "/home/v1.1/bin/SysConfig/UpConfig.xml";

ReadAllFile::ReadAllFile(QWidget *parent  , Qt::WindowFlags flags )
    :QWidget(parent , flags)
{
    //Net file layout
    inputlabel = new QLabel("NetFileName");
    inputlineEdit1 = new QLineEdit(filestr1);
    inputlineEdit2 = new QLineEdit(filestr2);
    inputlineEdit3 = new QLineEdit(filestr3);
    inputlineEdit4 = new QLineEdit(filestr4);
    inputlineEdit5 = new QLineEdit(filestr5);
    pushbutton = new QPushButton("OpenNetFile");
    pushbuttonClear = new QPushButton("ClearFile");
    outputlabel = new QLabel("NetFileContent");
    outputEdit = new QTextEdit;
    outputEdit->setReadOnly(true);
    QHBoxLayout *hboxlayout0 = new QHBoxLayout;
    hboxlayout0->addWidget(inputlabel);
    hboxlayout0->addStretch();
    hboxlayout0->addWidget(pushbutton);
    hboxlayout0->addWidget(pushbuttonClear);
    QHBoxLayout *hboxlayout1 = new QHBoxLayout;
    hboxlayout1->addWidget(inputlineEdit1);
    hboxlayout1->addWidget(inputlineEdit2);
    QHBoxLayout *hboxlayout2 = new QHBoxLayout;
    hboxlayout2->addWidget(inputlineEdit3);
    hboxlayout2->addWidget(inputlineEdit4);
    QVBoxLayout *vboxlayout = new QVBoxLayout;
    vboxlayout->addLayout(hboxlayout0);
    vboxlayout->addLayout(hboxlayout1);
    vboxlayout->addLayout(hboxlayout2);
    vboxlayout->addWidget(inputlineEdit5);
    vboxlayout->addWidget(outputlabel);
    //v1.1 file layout
    inputlabel1 = new QLabel("FileName");
    inputlineEdit11 = new QLineEdit(filestr11);
    inputlineEdit12 = new QLineEdit(filestr12);
    inputlineEdit13 = new QLineEdit(filestr13);
    inputlineEdit14 = new QLineEdit(filestr14);
    pushbutton1 = new QPushButton("OpenFile");
    pushbuttonClear1 = new QPushButton("ClearFile");
    outputlabel1 = new QLabel("FileContent");
    outputEdit1 = new QTextEdit;
    outputEdit1->setReadOnly(true);
    QHBoxLayout *hboxlayout10 = new QHBoxLayout;
    hboxlayout10->addWidget(inputlabel1);
    hboxlayout10->addStretch();
    hboxlayout10->addWidget(pushbutton1);
    hboxlayout10->addWidget(pushbuttonClear1);
    QHBoxLayout *hboxlayout11 = new QHBoxLayout;
    hboxlayout11->addWidget(inputlineEdit11);
    hboxlayout11->addWidget(inputlineEdit12);
    QHBoxLayout *hboxlayout12 = new QHBoxLayout;
    hboxlayout12->addWidget(inputlineEdit13);
    hboxlayout12->addWidget(inputlineEdit14);
    QVBoxLayout *vboxlayout1 = new QVBoxLayout;
    vboxlayout1->addLayout(hboxlayout10);
    vboxlayout1->addLayout(hboxlayout11);
    vboxlayout1->addLayout(hboxlayout12);
    vboxlayout1->addWidget(outputlabel1);
    vboxlayout1->addWidget(outputEdit1);
    //layout
    QVBoxLayout *vboxlayout2 = new QVBoxLayout;
    vboxlayout2->addLayout(vboxlayout1);
    vboxlayout2->addLayout(vboxlayout);
    vboxlayout2->addWidget(outputEdit);
    //show layout
    setLayout(vboxlayout2);
    //信号连接
    connect(pushbutton1,SIGNAL(clicked(bool)),this,SLOT(showFileConnect1()));
    connect(pushbuttonClear1,SIGNAL(clicked(bool)),this,SLOT(clearFile1()));
    connect(pushbutton,SIGNAL(clicked(bool)),this,SLOT(showFileConnect()));
    connect(pushbuttonClear,SIGNAL(clicked(bool)),this,SLOT(clearFile()));
    setFixedSize(700,800);
    setWindowTitle("Opne_PRS7051S_AllFile");
}
ReadAllFile::~ReadAllFile()
{

}
//NetFile 连接函数
void ReadAllFile::showFileConnect()
{
    for(int i = 1;i<6;i++)
    {
        QString filestr;
        switch (i){
        case 1:
            filestr = filestr1;
            break;
        case 2:
            filestr = filestr2;
            break;
        case 3:
            filestr = filestr3;
            break;
        case 4:
            filestr = filestr4;
            break;
        case 5:
            filestr = filestr5;
            break;
        default:
            break;
        }
        QFile file(filestr);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            in.setCodec("uft-8");
            outputEdit->append("************************************************************************");
            outputEdit->append("************************************************************************");
            while(!in.atEnd())
            {
                outputEdit->append(in.readLine());
            }
        }
        file.close();
    }
}
//AllFile 连接函数
void ReadAllFile::showFileConnect1()
{
    for(int i = 1;i<5;i++)
    {
        QString filestr;
        switch (i){
        case 1:
            filestr = filestr11;
            break;
        case 2:
            filestr = filestr12;
            break;
        case 3:
            filestr = filestr13;
            break;
        case 4:
            filestr = filestr14;
            break;
        default:
            break;
        }
        QFile file(filestr);
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file);
            in.setCodec("uft-8");
            outputEdit1->append("************************************************************************");
            outputEdit1->append("************************************************************************");
            while(!in.atEnd())
            {
                outputEdit1->append(in.readLine());
            }
        }
        file.close();
    }
}
//clear Net file
void ReadAllFile::clearFile()
{
    outputEdit->clear();
}
//clear All file
void ReadAllFile::clearFile1()
{
        outputEdit1->clear();
}
