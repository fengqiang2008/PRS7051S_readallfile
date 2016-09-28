#ifndef READALLFILE_H
#define READALLFILE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

class ReadAllFile:public QWidget
{
    Q_OBJECT
public:
    ReadAllFile(QWidget *parent = 0 , Qt::WindowFlags flags = 0) ;
    ~ReadAllFile();
private slots:
    //Net file slot
    void showFileConnect();
    void clearFile();
    //v1.1 file slot
    void showFileConnect1();
    void clearFile1();
private:
    //v1.1 file
    QLabel *inputlabel1;
    QLineEdit *inputlineEdit11;
    QLineEdit *inputlineEdit12;
    QLineEdit *inputlineEdit13;
    QLineEdit *inputlineEdit14;
    QLabel *outputlabel1;
    QTextEdit *outputEdit1;
    QPushButton *pushbutton1;
    QPushButton *pushbuttonClear1;
    //Net file
    QLabel *inputlabel;
    QLineEdit *inputlineEdit1;
    QLineEdit *inputlineEdit2;
    QLineEdit *inputlineEdit3;
    QLineEdit *inputlineEdit4;
    QLineEdit *inputlineEdit5;
    QLabel *outputlabel;
    QTextEdit *outputEdit;
    QPushButton *pushbutton;
    QPushButton *pushbuttonClear;
};

#endif // READALLFILE_H

