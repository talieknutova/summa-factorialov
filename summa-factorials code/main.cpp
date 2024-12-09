#include "func.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string vvod;
    cout << "Введите целое неотрицательное число n: ";
    cin >> vvod;

    string oshibka = proverka_vvod(vvod);
    if (oshibka.length() > 0) { 
        cerr << "Ошибка: " << oshibka << endl; 
        return 1; 
    }

    int n = stoi(vvod); 

    string sum = "0";
    if (n >= 0) { 
        for (int i = 1; i <= n; i++) {
            sum = slozhenie(sum, factorial(i));
        }
        if (n > 1) {
            cout << "Сумма факториалов от 1 до " << n << ": " << sum << endl;
        } else if (n == 0) {
            cout << endl; 
        } else if (n == 1) {
            cout << "Факториал 1 равен: 1" << endl; 
        }
    } else {
        cout << "Ошибка: Введено отрицательное число." << endl;
        return 1;
    }

    return 0;
}



