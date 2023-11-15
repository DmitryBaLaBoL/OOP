#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ����� - �������
class Matrix {
private:
	// ���� ������
	vector<vector<double>> MainMatrix;

	// ��������� ������� ���� �������� i_del ������ � j_del �������
	Matrix Delete_line_col(Matrix MainMatr, int i_del, int j_del) const;

	// �������� ����, ����� ������ � ������� ���� ����������������
	bool is_line_col(int line, int col) const;

	// �������� ����, ����� ���-�� ����� � �������� ������ ���� ��������� ( ��� ���������� )
	bool is_line_col_equality(const Matrix& Matrix2) const;

	// ��������� ����� �������� ����� � ��������
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
	float get_element(int k, int m) const;

	// ��������� ���-�� �����
	int get_line() const;

	// ��������� ���-�� ��������
	int get_col() const;

	// ����� �������
	void get_matrix() const;

	// ��������� ������� ��������� dif
	void fill_matrix_oneEl(double dif);

	// ��������� ������� ���������� ���������� �� min �� max
	void fill_matrix_random(double min, double max);

	// �������� ������
	Matrix operator+ (const Matrix& Matrix2) const;

	// �������� ������� � ������
	Matrix operator+ (double dif) const;

	// ��������� ������
	Matrix operator- (const Matrix& Matrix2) const;

	// ��������� ������� � ������
	Matrix operator- (double dif) const;

	// ��������� ������� �� ����� dif
	Matrix operator* (double dif) const;

	// ��������� ������� �� �������
	Matrix operator* (const Matrix& Matrix2)const;

	// ����������� ��������� ������� �� �������
	void operator*= (const Matrix& Matrix2);

	// ����������� ��������� ������� �� ����� dif
	void operator*= (double dif);

	// ����������� ��������� ������
	void operator-= (const Matrix& Matrix2);

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

	// ����� ������������ �������, ����� rang
	double determinant(Matrix Matr,int rang) const;

	// �������� �������
	Matrix Back_matrix(Matrix Matr) const ;

	// ���������� ������
	~Matrix();



};