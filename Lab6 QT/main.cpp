#include "widget.h"
#include "hashtable.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HashTableWidget w;
    w.resize(500, 500);
    w.show();
    return a.exec();
}
