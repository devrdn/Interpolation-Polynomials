#include "include/header.h"

double f(double x) {
    return sqrt(3 - 2 * x);
}

int main()
{
    // Начальная инициализация
    double a = -3.0; // Левая граница
    double b = 1.0; // Правая граница
    int n; // количество разбиений
    vector<double> x{ -3.0, -1.0 / 2.0, 1.0 , 0.0 , -4.0 }; // точки, в которых будет вычислены многочлены

    // Считываем количество разбиений
    cout << "Count of Fragments: ";
    cin >> n;
    double h = double(b - a) / n; // приращение на каждом шаге по оси Ox

    // Инициализируем массивы значений по x и в точке x
    // с разбиением n
    vector<double> xv(n);
    vector<double> yv(n);
    double xi = a;
    for (size_t i = 0; i < n; i++) {
        xv[i] = xi; 
        yv[i] = f(xv[i]);
        xi += h;
    }

    // Полином Лагранжа
    // Вывод в форме таблицы
    cout << endl << setw(30) << "Lagrange Polynom" << endl;
    cout << "+-----+----------+----------+-----------+------------+" << endl;
    cout << setw(7) << "NR |" << setw(11) << "xi |"
        << setw(11) << "yi  |" << setw(13) << "L(xi) | "
        << setw(11) << "abs(L - f) |" << endl;
    for (size_t i = 0; i < x.size(); i++) {
        cout << "+-----+----------+----------+-----------+------------+" << endl;
        double L = LagrangePolynomial(x[i], xv, yv);
        double fx = f(x[i]);
        cout << setw(4) << right << "x" << i << " |"
            << setw(9) << setprecision(4) << x[i] << " |"
            << setw(9) << setprecision(4) << f(x[i]) << " |"
            << setw(10) << setprecision(4) << L << " |"
            << setw(11) << setprecision(4) << abs(L - fx) << " |" << endl;
    }
    cout << "+-----+----------+----------+-----------+------------+" << endl;

    // Полином Лагранжа
    // Вывод в форме таблицы
    cout << endl << setw(30) << "Newton Polynom" << endl;
    cout << "+-----+----------+----------+-----------+------------+" << endl;
    cout << setw(7) << "NR |" << setw(11) << "xi |"
        << setw(11) << "yi  |" << setw(13) << "L(xi) | "
        << setw(11) << "abs(L - f) |" << endl;
    for (size_t i = 0; i < x.size(); i++) {
        cout << "+-----+----------+----------+-----------+------------+" << endl;
        double L = NewtonPolynomial(x[i], xv, yv);
        double fx = f(x[i]);
        cout << setw(4) << right << "x" << i << " |"
            << setw(9) << setprecision(4) << x[i] << " |"
            << setw(9) << setprecision(4) << f(x[i]) << " |"
            << setw(10) << setprecision(4) << L << " |"
            << setw(11) << setprecision(4) << abs(L - fx) << " |" << endl;
    }
    cout << "+-----+----------+----------+-----------+------------+" << endl;
    
}
