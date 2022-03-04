#include "../include/header.h"

/**
* Вычисление полинома Ньютона в точке
* @param x - точка в которое многочлен будет вычислен
* @param xv - массив значений точек на оси Ox
* @param yv - значение в точке xv[i]
* @return (double) полином Ньютона в точке x
*/
double NewtonPolynomial(double x, vector<double> xv, vector<double> yv) {
	int size = xv.size();
	double N = yv[0];
	for (size_t i = 0; i < xv.size(); i++) {
		double divd = 0;
		// Считаем слагаемое полинома
		for (size_t j = 0; j <= i; j++) {
			double div = 1;
			// Вычислячем знаменатель разделенной разности
			for (size_t k = 0; k <= i; k++) {
				if (k == j) continue;
				div *= xv[j] - xv[k];
			}
			// Считаем разделительную разность
			divd += yv[j] / div;
		}
		// Умножаем разделительную разность на 
		// (x - x0) ... (x-x[k-1])
		// Прибавляем к Полиному
		for (size_t k = 0; k < i; k++) {
			divd *= (x - xv[k]);
			N += divd;
		}
	}
	return N;
}