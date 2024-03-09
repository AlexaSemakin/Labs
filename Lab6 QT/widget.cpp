#include "widget.h"

#include <QDebug>

HashTableWidget::HashTableWidget()
{

    inputLineAddKey = new QLineEdit(this);
    inputLineAddValue = new QLineEdit(this);
    addButton = new QPushButton("addValue ", this);

    connect(addButton, &QPushButton::clicked, this, &HashTableWidget::addValue);


    inputLineDeleteKey = new QLineEdit(this);
    deleteButton = new QPushButton("deleteKey", this);
    connect(deleteButton, &QPushButton::clicked, this, &HashTableWidget::delValue);


    layout = new QVBoxLayout(this);

    subLayout = new QHBoxLayout();
    subLayout->addWidget(inputLineAddKey);
    subLayout->addWidget(inputLineAddValue);
    subLayout->addWidget(addButton);
    layout->addLayout(subLayout);

    subLayout = new QHBoxLayout();
    subLayout->addWidget(inputLineDeleteKey);
    subLayout->addWidget(deleteButton);
   layout->addLayout(subLayout);

    hashTableElement = new QTableWidget(this);
    layout->addWidget(hashTableElement);

    hashTable = new HashTable(10);

    hashTableElement->setColumnCount(1);

    hashTableElement->setRowCount(hashTable->GetSize());
    hashTableElement->setHorizontalHeaderLabels(QStringList() << "[Key, Value]");
 }
HashTableWidget::~HashTableWidget(){
    delete hashTable;
}


void HashTableWidget::addValue(){
    const int key = inputLineAddKey->text().toInt();
    const int value = inputLineAddValue->text().toInt();
    int hash = hashTable->Insert(key, value);
    QTableWidgetItem* qtwi = hashTableElement->item(hash, 0);
    QString ceilData = "";
    HashTableItem* el = hashTable->get_m_items()[hash];
    while(el){
        ceilData += QString(" [%1, %2]").arg(QString::number(el->m_key), QString::number(el->m_value));
        el = el->nextItem;
    }
    if (qtwi){
        qtwi->setText(ceilData);
        return;
    }
    hashTableElement->setItem(hash, 0, new QTableWidgetItem(ceilData));
}

void HashTableWidget::delValue(){
    const int key = inputLineDeleteKey->text().toInt();
    int hash = hashTable->Remove(key);
    QTableWidgetItem* qtwi = hashTableElement->item(hash, 0);
    QString ceilData = "";
    HashTableItem* el = hashTable->get_m_items()[hash];
    while(el){
        ceilData += QString(" [%1, %2]").arg(QString::number(el->m_key), QString::number(el->m_value));
        el = el->nextItem;
    }
    if (qtwi){
        qtwi->setText(ceilData);
        return;
    }
    hashTableElement->setItem(hash, 0, new QTableWidgetItem(ceilData));
}


