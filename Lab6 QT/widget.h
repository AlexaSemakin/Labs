#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTableWidget>
#include <QGraphicsEllipseItem>
#include <hashtable.h>
#include <vector>
#include <hashtable.h>
#include <iostream>

class HashTableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HashTableWidget ();

private slots:
    void addValue();
    void delValue();

private:
    QLineEdit *inputLineAddKey;
    QLineEdit *inputLineAddValue;
    QPushButton *addButton;
    QLineEdit *inputLineDeleteKey;
    QPushButton *deleteButton;

    QTableWidget *hashTableElement;

    QVBoxLayout *layout;
    QHBoxLayout *subLayout;

    HashTable *hashTable;

    // void displayTable(HashTable *hashTable);
};

#endif // WIDGET_H
