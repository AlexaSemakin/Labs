#include <iostream>
using namespace std;
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

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    sort(a, n);
}