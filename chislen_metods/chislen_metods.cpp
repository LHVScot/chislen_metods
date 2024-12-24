#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Объявление функции, которую нужно интегрировать.
double f(double x) {
    return x * x; 
}

int main() {
    setlocale(LC_ALL, "ru");
    double a, b, e;

    cout << "Введите начало интервала (a): ";
    cin >> a;
    cout << "Введите конец интервала (b): ";
    cin >> b;
    cout << "Введите погрешность (e): ";
    cin >> e;

    double I0 = 0.0;
    double I1 = INFINITY; 
    int n = 5;
    double h, x;

    while (abs(I1 - I0) > e) {
        n = 2 * n;
        I0 = I1;
        h = (b - a) / n;
        I1 = 0.0;

        for (int i = 0; i <= n - 1; ++i) {
            x = a + i * h;
            I1 += f(x);
        }

        I1 = I1 * h;
    }

    cout << fixed << setprecision(10) << "Значение интеграла: " << I1 << endl;

    return 0;
}