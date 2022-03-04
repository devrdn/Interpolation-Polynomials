#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/**
* Вычисление полинома Лагранжа в точке
* @param x - точка в которое многочлен будет вычислен
* @param xv - массив значений точек на оси Ox
* @param yv - значение в точке xv[i]
* @return (double) полином Лагранжа в точке x
*/
double LagrangePolynomial(double x, vector<double> xv, vector<double> yv);

/**
* Вычисление полинома Ньютона в точке
* @param x - точка в которое многочлен будет вычислен
* @param xv - массив значений точек на оси Ox
* @param yv - значение в точке xv[i]
* @return (double) полином Лагранжа в точке x
*/
double NewtonPolynomial(double x, vector<double> xv, vector<double> yv);