#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/**
* ���������� �������� �������� � �����
* @param x - ����� � ������� ��������� ����� ��������
* @param xv - ������ �������� ����� �� ��� Ox
* @param yv - �������� � ����� xv[i]
* @return (double) ������� �������� � ����� x
*/
double LagrangePolynomial(double x, vector<double> xv, vector<double> yv);

