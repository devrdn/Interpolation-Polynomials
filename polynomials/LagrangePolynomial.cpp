#include "../include/header.h"

/**
* Вычисление полинома Лагранжа в точке
* @param x - точка в которое многочлен будет вычислен
* @param xv - массив значений точек на оси Ox
* @param yv - значение в точке xv[i]
* @return (double) значения полинома Лагранжа в точке x
*/
double LagrangePolynomial(double x, vector<double> xv, vector<double> yv) {
	int size = xv.size(); // Количество точек, по которым строим многочлен
	double L = 0.0; 
	for (size_t i = 0; i < size; i++) {
		double basisPol = 1.0;
		for (size_t j = 0; j < size; j++) {
			// Вычисляем базисные полиномы
			if (i == j) continue;
			basisPol *= (x - xv[j])/(xv[i] - xv[j]);
		}
		// Вычисляем полином Лагранжа
		L += basisPol*yv[i];
	}
	return L;
}