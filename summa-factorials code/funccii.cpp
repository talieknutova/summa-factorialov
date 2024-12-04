#include "func.h"

using namespace std;


// функция сложения в столбик
string slozhenie(string chislo1, string chislo2) {
    int dlina1 = chislo1.length(); 
    int dlina2 = chislo2.length(); 
    int maximum = max(dlina1, dlina2); 
    string resultat = ""; 
    int ostatok = 0; 

 
    while (chislo1.length() < maximum) chislo1 = "0" + chislo1;
    while (chislo2.length() < maximum) chislo2 = "0" + chislo2;

    for (int i = maximum - 1; i >= 0; i--) { 
        int sum = (chislo1[i] - '0') + (chislo2[i] - '0') + ostatok;
        ostatok = sum / 10;
        resultat = to_string(sum % 10) + resultat; 
    }
    if (ostatok > 0) { 
        resultat = to_string(ostatok) + resultat;
    }
    
    return resultat;
}

// Вычисление факториала числа
string factorial(int n) {
    if (n == 0) return "1"; 
    if (n == 1) return "1"; 
    string resultat = "1"; 
    for (int i = 2; i <= n; i++) { 
        string chislo = to_string(i); 
        string umnozhenie = ""; 
        int perenos = 0; 
        for (int j = resultat.length() - 1; j >= 0; --j){ 
            int odno_chislo = (resultat[j] - '0') * i + perenos;
            perenos = odno_chislo  / 10;
            umnozhenie = to_string(odno_chislo  % 10) + umnozhenie;
        }
        if (perenos > 0) {
            umnozhenie = to_string(perenos) + umnozhenie;
        }
        resultat = umnozhenie;

    }
    return resultat;
}


//обработка ошибки
string proverka_vvod(string vvod) {
    if (vvod.length() == 0) {
        return "Ввод пуст.";
    }

    for (int i = 0; i < vvod.length(); ++i) {
        char c = vvod[i];
        if (c < '0' || c > '9') {
            return "Недопустимый символ: " + string(1, c); 
        }
    }

    return ""; 
}




