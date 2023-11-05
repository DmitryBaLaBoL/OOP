#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ����� - �������
class Matrix {
private:
	// ���� ������
	vector<vector<double>> MainMatrix;

	// �������� ������������ ����� � ��������
	bool is_line_col(int line, int col);

	// �������� ��������� ����� � �������� �������
	bool is_line_col_equality(Matrix Matrix2);

	// ��������� ����� ��������
	void new_line_col(int line, int col);

public:

	// ����������� ������ ������� 2:2
	Matrix();

	// ����������� ������ ������� �� �������� ������� � ��������
	Matrix(int line, int col);

	// ��������� ���-�� ����� � ��������
	void Set_line_col(int line, int col);

	// ��������� ���-�� �����
	void Set_line(int line);

	// ��������� ���-�� ��������
	void Set_col(int col);

	// ��������� ������ �������� ������
	void Set_el(int line, int col, double dif);

	// ��������� �������� [k][m] �������
	float get_element(int k, int m);

	// ��������� ���-�� �����
	int get_line();

	// ��������� ���-�� ��������
	int get_col();

	// ����� �������
	void get_matrix() const;

	// ��������� ������� ��������� dif
	void fill_matrix_oneEl(double dif);

	// ��������� ������� ���������� ���������� �� min �� max
	void fill_matrix_random(double min, double max);

	// �������� ������
	Matrix operator+ (Matrix Matrix2);

	// �������� ������� � ������
	Matrix operator+ (double dif);

	// ��������� ������
	Matrix operator- (Matrix Matrix2);

	// ��������� ������� � ������
	Matrix operator- (double dif);

	// ��������� ������� �� ����� dif
	Matrix operator* (double dif) const;

	// ��������� ������� �� �������
	Matrix operator* (Matrix Matrix2);

	// ����������� ��������� ������� �� �������
	void operator*= (Matrix Matrix2);

	// ����������� ��������� ������� �� ����� dif
	void operator*= (double dif);

	// ����������� ��������� ������
	void operator-= (Matrix Matrix2);

	// ����������� ��������� ����� dif �� �������
	void operator-= (double dif);

	// ����������� �������� ������
	void operator+= (Matrix Matrix2);

	// ����������� �������� ����� dif � ��������
	void operator+= (double dif);

	// ���������������� �������
	Matrix Trans_matrix();

	// ������������ �������
	void Diagonal_matrix();

	// ������������ �������
	float determinant(int rang);

	/*// �������� �������
	Matrix Back_matrix();*/

	// ���������� ������
	~Matrix();



};