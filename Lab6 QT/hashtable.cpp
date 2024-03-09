#include "HashTable.h"

int HashTable::Function(int k)
{
    return (k + 28) % size_table;
}

HashTable::HashTable(int tableSize)
{
    size_table = tableSize;
    m_count = 0;
    if(!tableSize){
        return;
    }
    m_items = new HashTableItem * [size_table];

    for (int i = 0; i < size_table; i++)
    {
        m_items[i] = nullptr;
    }
}

HashTable::HashTable(const HashTable& hashTable)
{
    size_table = hashTable.size_table;
    m_count = hashTable.m_count;
    m_items = new HashTableItem * [size_table];

    for (int i = 0; i < size_table; i++)
    {
        if (hashTable.m_items[i] == nullptr)
        {
            m_items[i] = nullptr;
        }
        else
        {
            m_items[i] = new HashTableItem;
            m_items[i]->m_key = hashTable.m_items[i]->m_key;
            m_items[i]->m_value = hashTable.m_items[i]->m_value;

            HashTableItem* el = hashTable.m_items[i]->nextItem;

            if (el->nextItem){
                m_items[i]->nextItem = new HashTableItem;
            }

            HashTableItem* el_this = m_items[i]->nextItem;

            while(el){
                el_this->nextItem = new HashTableItem;
                el_this->m_key = el->m_key;
                el_this->m_value = el->m_value;

                el_this = el_this->nextItem;
                el = el->nextItem;
            }
        }
    }
}

HashTable::~HashTable()
{
    for (int i = 0; i < size_table; i++)
    {
        HashTableItem* item = m_items[i];

        if (item != nullptr)
        {
            delete item;
        }
    }

    delete[] m_items;
}

HashTableItem** HashTable::get_m_items(){
    return m_items;
}

int HashTable::InsertRoutine(int key, int value)
{
    int k = Function(key);
    HashTableItem* el = m_items[k];
    if (!m_items[k]){
        HashTableItem* item = new HashTableItem;
        item->m_key = key;
        item->m_value = value;
        item->nextItem = nullptr;
        m_items[k] = item;
        return k;
    }
    if (m_items[k]->m_key == key){
        m_items[k]->m_value = value;
        return k;
    }
    while(el->nextItem){
        if(el->nextItem->m_key == key){
            el->nextItem->m_value = value;
            return k;
        }
        el = el->nextItem;
    }
    HashTableItem* item = new HashTableItem;
    item->m_key = key;
    item->m_value = value;
    item->nextItem = nullptr;
    el->nextItem = item;
    m_count++;
    return k;
}

int HashTable::RemoveRoutine(int key)
{
    int k = HashTable::Function(key);
    HashTableItem* el = m_items[k];
    if (el->m_key == key){

        HashTableItem* temp = el->nextItem;
        m_items[k] = temp;
        el->nextItem = nullptr;
        delete el;
        el = nullptr;
        return k;
    }
    while(el->nextItem){
        if(el->nextItem->m_key == key){
            HashTableItem* del = el->nextItem;
            el->nextItem = el->nextItem->nextItem;
            delete del;
            del = nullptr;
            return k;
        }
        el = el->nextItem;
    }
    return k;

}


HashTableItem* HashTable::CheckRoutine(int key)
{
    int k = Function(key);
    HashTableItem* el = m_items[k];
    while(el){
        if(el->m_key == key){
            return el;
        }
        el = el->nextItem;
    }

    return nullptr;
}

int HashTable::Insert(int key, int value)
{
    return InsertRoutine(key, value);
}

int HashTable::Remove(int key)
{
    return RemoveRoutine(key);
}

HashTableItem* HashTable::Check(int key)
{
    return CheckRoutine(key);
}


HashTable& HashTable::operator=(const HashTable& hashTable)
{
    if (this == &hashTable)
    {
        return *this;
    }

    for (int i = 0; i < size_table; i++)
    {
        HashTableItem* item = m_items[i];

        if (item != nullptr)
        {
            delete item;
        }
    }
    delete[] m_items;

    size_table = hashTable.size_table;
    m_count = hashTable.m_count;
    m_items = new HashTableItem * [size_table];

    for (int i = 0; i < size_table; i++)
    {
        if (hashTable.m_items[i] == nullptr)
        {
            m_items[i] = nullptr;
        }
        else
        {
            m_items[i] = new HashTableItem;
            m_items[i]->m_key = hashTable.m_items[i]->m_key;
            m_items[i]->m_value = hashTable.m_items[i]->m_value;
            HashTableItem* el_this = m_items[i]->nextItem;
            HashTableItem* el = hashTable.m_items[i]->nextItem;
            while(el){
                el_this->nextItem = new HashTableItem;
                el_this->m_key = el->m_key;
                el_this->m_value = el->m_value;

                el_this = el_this->nextItem;
                el = el->nextItem;
            }
        }
    }

    return *this;
}

int& HashTable::operator[](int key)
{
    HashTableItem* el = Check(key);
    if(!el)
    {
        throw "Key no found!\n";
    }
    return el->m_value;
}



int HashTable::GetSize()
{
    return size_table;
}
