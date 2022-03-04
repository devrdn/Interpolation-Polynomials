#include "../include/header.h"

/**
* ���������� �������� ������� � �����
* @param x - ����� � ������� ��������� ����� ��������
* @param xv - ������ �������� ����� �� ��� Ox
* @param yv - �������� � ����� xv[i]
* @return (double) ������� ������� � ����� x
*/
double NewtonPolynomial(double x, vector<double> xv, vector<double> yv) {
	int size = xv.size();
	double N = yv[0];
	for (size_t i = 0; i < xv.size(); i++) {
		double divd = 0;
		// ������� ��������� ��������
		for (size_t j = 0; j <= i; j++) {
			double div = 1;
			// ���������� ����������� ����������� ��������
			for (size_t k = 0; k <= i; k++) {
				if (k == j) continue;
				div *= xv[j] - xv[k];
			}
			// ������� �������������� ��������
			divd += yv[j] / div;
		}
		// �������� �������������� �������� �� 
		// (x - x0) ... (x-x[k-1])
		// ���������� � ��������
		for (size_t k = 0; k < i; k++) {
			divd *= (x - xv[k]);
			N += divd;
		}
	}
	return N;
}