#include "include/header.h"

double f(double x) {
    return sqrt(2 - 3 * x);
}

int main()
{
    // Начальная инициализация
    vector<double> xv{ -7. / 3, -2. / 3, 1. / 3}; // Значения по оси Ox
    vector<double> yv{ f(xv[0]), f(xv[1]), f(xv[2]) }; // Значения по оси Oy
    vector<double> xi{ -7. / 3, -2. / 3, 1. / 3, 0.0, -3 }; // Точки, в которых надо посчитать значения многочлена

    // Полином Лагранжа
    // Вывод в форме таблицы
    cout << setw(20) << "Lagrange Polynom" << endl;
    cout << setw(7) << "NR |" << setw(11) << "xi |"
        << setw(11) << "yi  |" << setw(11) << "L(xi) | "
        << setw(11) << "abs(L - f) |" << endl;
    for (size_t i = 0; i < xi.size(); i++) {
        cout << "+-----+----------+----------+---------+------------+" << endl;
        double L = LagrangePolynom(xi[i], xv, yv);
        double fx = f(xi[i]);
        cout << setw(4) << right << "x" << i << " |"
            << setw(9) << setprecision(4) << xi[i] << " |"
            << setw(9) << setprecision(4) << f(xi[i]) << " |"
            << setw(8) << setprecision(4) << L << " |"
            << setw(11) << setprecision(4) << abs(L - fx) << " |" << endl;
    }
    cout << "+-----+----------+----------+---------+------------+" << endl;
    
}
