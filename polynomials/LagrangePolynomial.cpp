#include "../include/header.h"

/**
* ���������� �������� �������� � �����
* @param x - ����� � ������� ��������� ����� ��������
* @param xv - ������ �������� ����� �� ��� Ox
* @param yv - �������� � ����� xv[i]
* @return (double) ������� �������� � ����� x
*/
double LagrangePolynomial(double x, vector<double> xv, vector<double> yv) {
	int size = xv.size(); // ���������� �����, �� ������� ������ ���������
	double L = 0.0; 
	for (size_t i = 0; i < size; i++) {
		double basisPol = 1.0;
		for (size_t j = 0; j < size; j++) {
			// ��������� �������� ��������
			if (i == j) continue;
			basisPol *= (x - xv[j])/(xv[i] - xv[j]);
		}
		// ��������� ������� ��������
		L += basisPol*yv[i];
	}
	return L;
}