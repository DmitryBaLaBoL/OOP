#include "MatrixStruct.h"

// ��������� ������� ���� �������� i_del ������ � j_del �������
Matrix Matrix::Delete_line_col(const Matrix * MainMatr, int i_del, int j_del) const {
	Matrix result(MainMatr->get_line() - 1, MainMatr->get_col() - 1);
	for (int i = 0; i < MainMatr->get_line(); i++)
	{
		for (int j = 0; j < MainMatr->get_col(); j++)
		{
			if (i < i_del && j < j_del) { result.Set_el(i, j, MainMatr->get_element(i, j)); };
			if (i < i_del && j > j_del) { result.Set_el(i, j - 1, MainMatr->get_element(i, j)); };
			if (i > i_del && j < j_del) { result.Set_el(i - 1, j, MainMatr->get_element(i, j)); };
			if (i > i_del && j > j_del) { result.Set_el(i - 1, j - 1, MainMatr->get_element(i, j)); };
		}
	}
	return result;
}

// �������� ����, ����� ������ � ������� ���� ����������������
bool Matrix::is_line_col(int line, int col) const {
	if (line >= 0 && col >= 0) return true;
	else {
		throw std::runtime_error("������������ �������� ��� ����� �/��� ��������");
		return false;
	}
}

// �������� ����, ����� ���-�� ����� � �������� ������ ���� ��������� ( ��� ���������� )
bool Matrix::is_line_col_equality(const Matrix& Matrix2) const {
	if (MainMatrix.size() == Matrix2.get_line() && MainMatrix[0].size() == Matrix2.get_col()) return true;
	else {
		throw std::runtime_error("���-�� ����� � �������� ������ ������ ���� ���������");
		return false;
	}
}

// ��������� ����� �������� ����� � ��������
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
void Matrix::Set_el(int line, int col, double dif) {
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
float Matrix::get_element(int k, int m) const {
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
int Matrix::get_line() const {
	return MainMatrix.size();
}

// ��������� ���-�� ��������
int Matrix::get_col() const {
	return MainMatrix[0].size();
}

// ����� �������
void Matrix::get_matrix() const {
	cout.precision(4);
	cout << endl;
	for (int i = 0; i < MainMatrix.size(); i++)
	{
		for (int j = 0; j < MainMatrix[0].size(); j++)
		{
			cout << setfill(' ') << setw(12) << fixed << MainMatrix[i][j];
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
			MainMatrix[i][j] = rand() / RAND_MAX * (max - min) + min; // ����� �����
			//MainMatrix[i][j] = 1.0 * rand() / RAND_MAX * (max - min) + min; // ������������ �����
		}
	}
}

// �������� ������
Matrix Matrix::operator+ (const Matrix& Matrix2) const {
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
Matrix Matrix::operator+ (double dif) const {
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
Matrix Matrix::operator- (const Matrix& Matrix2) const {
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
Matrix Matrix::operator- (double dif) const {
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
Matrix Matrix::operator* (const Matrix& Matrix2) const {
	Matrix result(MainMatrix.size(), Matrix2.get_col());

	if (MainMatrix[0].size() == Matrix2.get_line()) {
		double sum;
		for (int i = 0; i < MainMatrix.size(); i++)
		{
			for (int j = 0; j < Matrix2.get_col(); j++)
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
	else {
		cout << "���-�� �������� ������ �������, ������ ���� ����� ������� ������ �������" << endl;
		return result;
	}
}

// ����������� ��������� ������� �� �������
void Matrix::operator*= (const Matrix& Matrix2) {
	Matrix between(MainMatrix.size(), MainMatrix[0].size());
	Matrix result(MainMatrix.size(), Matrix2.get_col());
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
void Matrix::operator-= (const Matrix& Matrix2) {
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
void Matrix::operator+= (const Matrix& Matrix2) {
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
			result.Set_el(i, j, MainMatrix[j][i]);
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

// ����� ������������ �������, ����� rang
double Matrix::determinant(int rang) const {
	
	if (!(this->get_line() == this->get_col())) cout << "��� ������ ������������ ������� ������ ���� ����������";
	else {
		if (rang == 1) return this->get_element(0,0);
		else if (rang == 2) return this->get_element(0, 0) * this->get_element(1, 1) - this->get_element(0, 1) * this->get_element(1, 0);
		else {
			double Det = 0;
			for (int i = 0; i < rang; i++)
			{
				Matrix Between = Delete_line_col(this, 0, i);
				Det = Det + pow(-1, i + 1 + 1) * this->get_element(0, i) * Between.determinant(rang - 1);
				Between.~Matrix();
			}
			return Det;
		}

	}
}

// �������� �������
Matrix Matrix::Back_matrix() const {
	if (!(MainMatrix.size() == MainMatrix[0].size())) cout << "��� ������ �������� �������, ������� ������ ���� ����������";
	else if (determinant(this->get_line()) == 0) cout << "������� �� ����� ��������, ������������ = 0";
	else {
		Matrix Minor(this->get_line(), this->get_line());
		for (int i = 0; i < this->get_line(); i++)
		{
			for (int j = 0; j < this->get_col(); j++)
			{
				Matrix Between = Delete_line_col(this, i, j);
				Minor.Set_el(i, j, Between.determinant(Between.get_col()) * pow(-1,i+j+2));
				Between.~Matrix();
			}
		}
		Minor = Minor.Trans_matrix();
		return Minor * (1 / determinant(this->get_line()));
	}
}

// ���������� ������
Matrix::~Matrix() {
	MainMatrix.clear();
}