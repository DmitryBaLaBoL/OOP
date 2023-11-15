#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Класс - Матрица
class Matrix {
private:
	// Поля класса
	vector<vector<double>> MainMatrix;

	// Получение матрицы путём удаление i_del строки и j_del столбца
	Matrix Delete_line_col(Matrix MainMatr, int i_del, int j_del) const;

	// Проверка того, чтобы строки и столбцы были неотрицательными
	bool is_line_col(int line, int col) const;

	// Проверка того, чтобы кол-во строк и столбцов матриц было одинаково ( для операторов )
	bool is_line_col_equality(const Matrix& Matrix2) const;

	// Установка новых размеров строк и столбцов
	void new_line_col(int line, int col);

public:

	// Конструктор создаёт матрицу 2:2
	Matrix();

	// Конструктор создаёт матрицу по заданным строкам и столбцам
	Matrix(int line, int col);

	// Установка кол-ва строк и столбцов
	void Set_line_col(int line, int col);

	// Установка кол-ва строк
	void Set_line(int line);

	// Установка кол-ва столбцов
	void Set_col(int col);

	// Установка нового значения ячейки
	void Set_el(int line, int col, double dif);

	// Получение элемента [k][m] матрицы
	float get_element(int k, int m) const;

	// Получение кол-ва строк
	int get_line() const;

	// Получение кол-ва столбцов
	int get_col() const;

	// Вывод матрицы
	void get_matrix() const;

	// Заполнить матрицу элементом dif
	void fill_matrix_oneEl(double dif);

	// Заполнить матрицу случайными значениями от min до max
	void fill_matrix_random(double min, double max);

	// Сложение матриц
	Matrix operator+ (const Matrix& Matrix2) const;

	// Сложение матрицы с числом
	Matrix operator+ (double dif) const;

	// Вычитание матриц
	Matrix operator- (const Matrix& Matrix2) const;

	// Вычитание матрицы с числом
	Matrix operator- (double dif) const;

	// Умножение матрицы на число dif
	Matrix operator* (double dif) const;

	// Умножение матрицы на матрицу
	Matrix operator* (const Matrix& Matrix2)const;

	// Собственное умножение матрицы на матрицу
	void operator*= (const Matrix& Matrix2);

	// Собственное умножение матрицы на число dif
	void operator*= (double dif);

	// Собственное вычитание матриц
	void operator-= (const Matrix& Matrix2);

	// Собственное вычитание числа dif из матрицы
	void operator-= (double dif);

	// Собственное сложение матриц
	void operator+= (Matrix Matrix2);

	// Собственное сложение числа dif с матрицей
	void operator+= (double dif);

	// Транспонирование матрицы
	Matrix Trans_matrix();

	// Диагональная матрица
	void Diagonal_matrix();

	// Поиск определителя матрицы, ранга rang
	double determinant(Matrix Matr,int rang) const;

	// Обратная матрица
	Matrix Back_matrix(Matrix Matr) const ;

	// Деструктор класса
	~Matrix();



};