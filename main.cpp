#include <QApplication>
#include <QTextCodec>
#include "readallfile.h"
#include <QtGui>


int main(int argc ,char *argv[])
{
    QApplication app(argc ,argv);
    ReadAllFile a;
    a.show();
    return app.exec();
}


