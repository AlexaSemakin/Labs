#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class ArrayExeption:public exception{
private:
    string m_error;

public:
    ArrayExeption(string error): m_error(error){}

    const char* what() const noexcept {
        return m_error.c_str();
    }
};

template <class T> 
class Array
{
private:
    int count;
    T *arrayData;
 
public:
    Array()
    {
        count = 0;
        arrayData = nullptr;
    }
 
    Array(int count)
    {
        arrayData = new T[count];
        this.count = count;
    }
 
    ~Array()
    {
        delete[] arrayData;
    }
 
    void EraseArray()
    {
        delete[] m_data;
        // Присваиваем значение nullptr для m_data, чтобы на выходе не получить висячий указатель!
        arrayData = nullptr;
        count = 0;
    }
 
 
    T& operator[](int index)
    {
        if(index >= 0 && index < m_length){
            throw ArrayExeption("Out of bounds of an array");
        }
        return m_data[index];
    }
    T& operator+(T f, T s){

    }
    T& operator+=(T element){
        push_back(element);
    }
    T& operator-=(T element){
        pop_back();
    }
    int size(){
        return count;
    }
    void push_back(T element){
        int *newArray = new int[count+1];
        for(int i=0; i< count; i++){
            newArray[i] = arrayData[i];
        }
        newArray[count] = element;
        delete[] arrayData;
        arrayData = newArray;
        count++;
    }
    void pop_back(){
        if (count < 0)
            throw ArrayExeption("Removing the last element from an empty array");
        else{
            int *newArray = new int[count-1];
            for(int i=0; i< count-1; i++){
                newArray[i] = arrayData[i];
            }
            delete[] arrayData;
            arrayData = newArray;
            count--;
        }
    }
    void reverse(){
        int *newArray = new int[count-1];
        for(int i=0; i< count; i++){
            newArray[i] = arrayData[count-i-1];
        }
        delete[] arrayData;
        arrayData = newArray;
    }
    void resize(int newSize){
        int *newArray = new int[newSize];
        for(int i=0; i< newSize; i++){
            newArray[i] = arrayData[count-i-1];
        }
        if (newSize > count){
            for(int i=count; i<newSize; i++){
                newArray[i]=0;
            }
        }
        delete[] arrayData;
        arrayData = newArray;
        count = newSize;
    }
    int find (T element){
        for(int i=0; i<count; i++){
            if (arrayData[i] == element){
                return i;
            }
        }
        return -1;
    }
    int sort(){
        for(int i=0; i<count; i++){
            for(int j=0; j<count; j++){
                if (arrayData[i] < arrayData[j]){
                    swap(arrayData[i], arrayData[j]);
                }
            }
        }
    }
    void push_to_index(int index, T element){
        if (index >= count){
            throw ArrayExeption("Out of bounds of an array");
        }
        else {
            int *newArray = new int[count+1];
            for(int i=0; i< index; i++){
                newArray[i] = arrayData[i];
            }
            newArray[index] = element;
            for(int i=index; i< count+1; i++){
                newArray[i] = arrayData[i-1];
            }
            delete[] arrayData;
            arrayData = newArray;
            count = newSize;
        }
    }
    void pop_to_index(int index, T element){
        if (index >= count){
            throw ArrayExeption("Out of bounds of an array");
        }
        else {
            int *newArray = new int[count-1];
            for(int i=0; i< index; i++){
                newArray[i] = arrayData[i];
            }
            for(int i=index+1; i< count; i++){
                newArray[i-1] = arrayData[i];
            }
            delete[] arrayData;
            arrayData = newArray;
            count = newSize;
        }
    }
    int pop_to_element(int element){
        int index = find(element);
        if (index == -1){
            return 0;
        }
        pop_to_index(index);
        return 1;
    }
    T getMaxElement(){
        T max = arrayData[0];
        for(int i=0; i<count; i++){
            if (max < arrayData[i]){
                max = arrayData[i];
            }
        }
        return max;
    }
    T getMinElement(){
        T min = arrayData[0];
        for(int i=0; i<count; i++){
            if (min > arrayData[i]){
                min = arrayData[i];
            }
        }
        return min;
    }
    void inputArray(){
        for(int i=0; i<count; i++){
            cin >> arrayData[i];
        }
    }
    void outputArray(){
        for(int i=0; i<count-1; i++){
            cout << arrayData[i] << " ";
        }
        cout << arraydata[count-1];
    }
    void shiftElements(int index, int countRep){
        if (index >= count){
            throw ArrayExeption("Out of bounds of an array");
        }
        else {
            if (countRep < 0){
                countRep += count;
            }
            int *newArray = new int[count-1];
            for(int i=0; i< index; i++){
                newArray[i] = arrayData[i];
            }

            for(int i=0; i< count-index; i++){
                newArray[index + ((i+countRep)%(count-index))] = arrayData[i];
            }
            delete[] arrayData;
            arrayData = newArray;
            count = newSize;
        }
    }
};

int main () {
    

}