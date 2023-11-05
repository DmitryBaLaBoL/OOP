#include "MatrixStruct.h"

// �������� ������������ ����� � ��������
bool Matrix::is_line_col(int line, int col) {
	if (line >= 0 && col >= 0) return true;
	else {
		throw std::runtime_error("������������ �������� ��� ����� �/��� ��������");
		return false;
	}
}

// �������� ��������� ����� � �������� �������
bool Matrix::is_line_col_equality(Matrix Matrix2) {
	if (MainMatrix.size() == Matrix2.get_line() && MainMatrix[0].size() == Matrix2.get_col()) return true;
	else {
		throw std::runtime_error("���-�� ����� � �������� ������ ������ ���� ���������");
		return false;
	}
}

// ��������� ����� ��������
void Matrix::new_line_col(int line, int col) {
	MainMatrix.resize(line);
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		MainMatrix[i].resize(col);
	}
}

// ����������� ������ ������� 2:2
Matrix::Matrix() {
	new_line_col(2, 2);
}

// ����������� ������ ������� �� �������� ������� � ��������
Matrix::Matrix(int line, int col) {
	try {
		if (is_line_col(line, col)) {
			new_line_col(line, col);
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		new_line_col(2, 2);
	}
}

// ��������� ���-�� ����� � ��������
void Matrix::Set_line_col(int line, int col) {
	try {
		if (is_line_col(line, col)) {
			new_line_col(line, col);
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		//new_line_col(2, 2);
	}
}

// ��������� ���-�� �����
void Matrix::Set_line(int line) {
	MainMatrix.resize(line);
}

// ��������� ���-�� ��������
void Matrix::Set_col(int col) {
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		MainMatrix[i].resize(col);
	}
}

// ��������� ������ �������� ������
void Matrix::Set_el(int line, int col,double dif) {
	try {
		if (is_line_col(line, col)) {
			MainMatrix[line][col] = dif;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// ��������� �������� [k][m] �������
float Matrix::get_element(int k, int m) {
	try {
		if (is_line_col(k, m)) {
			return MainMatrix[k][m];
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
	
}

// ��������� ���-�� �����
int Matrix::get_line() {
	return MainMatrix.size();
}

// ��������� ���-�� ��������
int Matrix::get_col() {
	return MainMatrix[0].size();
}

// ����� �������
void Matrix::get_matrix() const {
	cout << endl;
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			cout << MainMatrix[i][j] << "  ";
		}
		cout << endl;
	}
}

// ��������� ������� ��������� dif
void Matrix::fill_matrix_oneEl(double dif) {
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			MainMatrix[i][j] = dif;
		}
	}
}

// ��������� ������� ���������� ���������� �� min �� max
void Matrix::fill_matrix_random(double min, double max) {
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			MainMatrix[i][j] = 1.0 * (rand() % 10) * (max - min) + min;//1.0 * rand() / RAND_MAX * (max - min) + min;
		}
	}
}

// �������� ������
Matrix Matrix::operator+ (Matrix Matrix2) {
	Matrix result(MainMatrix.size(), MainMatrix[0].size());
	try {
		if (is_line_col_equality(Matrix2)) {
			for (int i = 0; i < MainMatrix.size(); i++)
			{
				for (int j = 0; j < MainMatrix[0].size(); j++)
				{
					result.Set_el(i, j, MainMatrix[i][j] + Matrix2.get_element(i, j));
				}
			}
			return result;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		return result;
	}
}

// �������� ������� � ������
Matrix Matrix::operator+ (double dif) {
	Matrix result(MainMatrix.size(), MainMatrix[0].size());
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			result.Set_el(i, j, MainMatrix[i][j] + dif);
		}
	}
	return result;
}

// ��������� ������
Matrix Matrix::operator- (Matrix Matrix2) {
	Matrix result(MainMatrix.size(), MainMatrix[0].size());
	try {
		if (is_line_col_equality(Matrix2)) {
			for (int i = 0; i < MainMatrix.size(); i++)
			{
				for (int j = 0; j < MainMatrix[0].size(); j++)
				{
					result.Set_el(i, j, MainMatrix[i][j] - Matrix2.get_element(i, j));
				}
			}
			return result;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		return result;
	}
}

// ��������� ������� � ������
Matrix Matrix::operator- (double dif) {
	Matrix result(MainMatrix.size(), MainMatrix[0].size());
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			result.Set_el(i, j, MainMatrix[i][j] - dif);
		}
	}
	return result;
}

// ��������� ������� �� ����� dif
Matrix Matrix::operator* (double dif) const {
	Matrix result(MainMatrix.size(), MainMatrix[0].size());
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			result.Set_el(i, j, MainMatrix[i][j] * dif);
		}
	}
	return result;
}

// ��������� ������� �� �������
Matrix Matrix::operator* (Matrix Matrix2) {
	Matrix result(MainMatrix.size(), MainMatrix[0].size());
	try {
		if (is_line_col_equality(Matrix2)) {
			double sum;
			for (int i = 0; i < MainMatrix.size(); i++)
			{
				for (int j = 0; j < MainMatrix[0].size(); j++)
				{
					sum = 0;
					for (int k = 0; k < MainMatrix[0].size(); k++)
					{
						sum = sum + MainMatrix[i][k] * Matrix2.get_element(k, j);
					}
					result.Set_el(i, j, sum);
				}
			}
			return result;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		return result;
	}
}

// ����������� ��������� ������� �� �������
void Matrix::operator*= (Matrix Matrix2) {
	Matrix between(MainMatrix.size(), MainMatrix[0].size());
	Matrix result(MainMatrix.size(), MainMatrix[0].size());
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			between.Set_el(i, j, MainMatrix[i][j]);
		}
	}
	result = between * Matrix2;
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			MainMatrix[i][j] = result.get_element(i, j);
		}
	}
	between.~Matrix();
	result.~Matrix();
}

// ����������� ��������� ������� �� ����� dif
void Matrix::operator*= (double dif) {
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			MainMatrix[i][j] = MainMatrix[i][j] * dif;
		}
	}
}

// ����������� ��������� ������
void Matrix::operator-= (Matrix Matrix2) {
	try {
		if (is_line_col_equality(Matrix2)) {
			for (int i = 0; i < MainMatrix.size(); i++)
			{
				for (int j = 0; j < MainMatrix[0].size(); j++)
				{
					MainMatrix[i][j] = MainMatrix[i][j] - Matrix2.get_element(i, j);
				}
			}
		}

	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// ����������� ��������� ����� dif �� �������
void Matrix::operator-= (double dif) {
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			MainMatrix[i][j] = MainMatrix[i][j] - dif;
		}
	}
}

// ����������� �������� ������
void Matrix::operator+= (Matrix Matrix2) {
	try {
		if (is_line_col_equality(Matrix2)) {
			for (int i = 0; i < MainMatrix.size(); i++)
			{
				for (int j = 0; j < MainMatrix[0].size(); j++)
				{
					MainMatrix[i][j] = MainMatrix[i][j] + Matrix2.get_element(i, j);
				}
			}
		}

	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// ����������� �������� ����� dif � ��������
void Matrix::operator+= (double dif) {
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			MainMatrix[i][j] = MainMatrix[i][j] + dif;
		}
	}
}

// ���������������� �������
Matrix Matrix::Trans_matrix() {
	Matrix result(MainMatrix[0].size(), MainMatrix.size());
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			result.Set_el(i,j, MainMatrix[j][i]);
		}
	}
	return result;
}

// ������������ �������
void Matrix::Diagonal_matrix() {
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			if (!(i == j)) MainMatrix[i][j] = 0;
		}
	}
}

// �� �������� ��� 3+
// ������������ �������
float Matrix::determinant(int rang) {
	if (!(MainMatrix.size() == MainMatrix[0].size())) cout << "��� ������ ������������ ������� ������ ���� ����������";
	else {
		if (rang == 1) return MainMatrix[0][0];
		else if (rang == 2) return MainMatrix[0][0] * MainMatrix[1][1] - MainMatrix[0][1] * MainMatrix[1][0];
		else if (rang == 3)return MainMatrix[0][0] * MainMatrix[1][1] * MainMatrix[2][2] +
			MainMatrix[1][0] * MainMatrix[2][1] * MainMatrix[0][2] +
			MainMatrix[0][1] * MainMatrix[1][2] * MainMatrix[2][0] -
			MainMatrix[0][2] * MainMatrix[1][1] * MainMatrix[2][0] -
			MainMatrix[0][1] * MainMatrix[1][0] * MainMatrix[2][2] -
			MainMatrix[0][0] * MainMatrix[2][1] * MainMatrix[1][2];
		else cout << "������������ ��������� ������ 1,2 � 3 �������";
	}
}

/*// �������� �������
Matrix Matrix::Back_matrix() {
	if (!(MainMatrix.size() == MainMatrix[0].size())) cout << "��� ������ �������� �������, ������� ������ ���� ����������";
	else if (MainMatrix.size() > 3 ) cout << "�������� ������� ������ �� 3 �������";
	else if (determinant(MainMatrix.size()) == 0) cout << "������� �� ����� ��������, ������������ = 0";
	else if 
}*/

// ���������� ������
Matrix::~Matrix() {
	MainMatrix.clear();
}