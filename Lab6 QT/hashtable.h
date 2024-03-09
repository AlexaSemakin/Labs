#pragma once

#include <iostream>
#include <vector>

struct HashTableItem
{
    int m_key;
    int m_value;
    HashTableItem* nextItem = nullptr;
    ~HashTableItem(){
        delete nextItem;
    }
};

class HashTable
{
public:
    HashTable(int tableSize);
    HashTable(const HashTable& other);

    ~HashTable();

    int Insert(int key, int value);
    int Remove(int key);
    HashTableItem* Check(int key);

    HashTableItem** get_m_items();

    HashTable& operator=(const HashTable& hashTable);
    int& operator[](int key);

    bool Resize(int newSize);
    int GetSize();
    int Function(int k);


private:

    int size_table = 0;
    HashTableItem** m_items = nullptr;
    int m_count = 0;

    int InsertRoutine(int key, int value);
    int RemoveRoutine(int key);
    HashTableItem* CheckRoutine(int key);
};
