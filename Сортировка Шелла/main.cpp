#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>
using namespace std;
typedef chrono::high_resolution_clock Clock;

const int indent = 20;

int random(int a, int b)
{
	int r = rand();
	if (a > 0) {
		return a + r % (b - a);
	}
	else
		return a + r % (abs(a) + b);
}
void swap(int& a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void sort(int* a, int n) {
    for (int k = n / 2; k > 0; k /= 2) {
        for (int i = 0; i < n; i++) {
            for (int j = i + k; j < n; j += k) {
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                }
            }
        }
    }
}
bool checkSort(int *a, int n){
    for (int i = 0; i < n-1; i++)
    {
        if (a[i] > a[i+1]){
            return false;
        }
    }
    return true;
}

void generateArray(int*a, int n, int min, int max){
    for (int i = 0; i < n; i++)
    {
        int r = random(min, max);
		a[i] = r;
    }
    
}
void outputResult(int n, int minValGen, int maxValGen, int time, bool correct, int countTest){
    if (correct){
	    cout << setw(indent) << n << setw(indent)<<  time << setw(indent+11) << "[\x1b[32;1mOK\x1b[0m]" << setw(indent) << minValGen << setw(indent) << maxValGen << endl;
    }
    else {
	    cout << setw(indent) << n << setw(indent)<<  time << setw(indent+11) << "[\x1b[31;1mWA\x1b[0m]" << setw(indent) << minValGen << setw(indent) << maxValGen << endl;
    }
}
void startTest(){
    int countArrays, countTest;
    cin >> countArrays >> countTest;
    int* arrays = new int[countArrays];
    int* minVal = new int[countArrays];
    int* maxVal = new int[countArrays];

    for (int i = 0; i < countArrays; i++)
    {
        cin >> arrays[i] >> minVal[i] >> maxVal[i];
    }
    cout << setprecision(1) << fixed;
    cout << endl << endl << "Test №" << countTest << ": " << endl;
	cout << setw(indent) << "Count Elements" << setw(indent)<<  "Time Sorting" << setw(indent) << "Correct" << setw(indent) << "Min Value" << setw(indent) << "Max Value" << endl;

    for (int i = 0; i < countArrays; i++)
    {
        int* a = new int[arrays[i]];
        for(int j=0; j < countTest; j++){
            generateArray(a, arrays[i], minVal[i], maxVal[i]);
            auto t1 = Clock::now();
            sort(a,arrays[i]);
            auto t2 = Clock::now();
	        double result = (double)chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() / 1000000;
            outputResult(arrays[i], minVal[i], maxVal[i], result, checkSort(a,arrays[i]), i*countArrays + j);
        }
    }
}

void checkWork(){
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, n);
    cout << "correct: " << checkSort(a,n) << endl;
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
}

int main() {
    srand(time(NULL));
    startTest();
}