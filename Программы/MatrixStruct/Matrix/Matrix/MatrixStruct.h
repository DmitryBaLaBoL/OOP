#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Класс - Матрица
class Matrix {
private:
	// Поля класса
	vector<vector<double>> MainMatrix;

	// Проверка допустимости строк и столбцов
	bool is_line_col(int line, int col);

	// Проверка равенства строк и столбцов матрицы
	bool is_line_col_equality(Matrix Matrix2);

	// Установка новых размеров
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
	float get_element(int k, int m);

	// Получение кол-ва строк
	int get_line();

	// Получение кол-ва столбцов
	int get_col();

	// Вывод матрицы
	void get_matrix() const;

	// Заполнить матрицу элементом dif
	void fill_matrix_oneEl(double dif);

	// Заполнить матрицу случайными значениями от min до max
	void fill_matrix_random(double min, double max);

	// Сложение матриц
	Matrix operator+ (Matrix Matrix2);

	// Сложение матрицы с числом
	Matrix operator+ (double dif);

	// Вычитание матриц
	Matrix operator- (Matrix Matrix2);

	// Вычитание матрицы с числом
	Matrix operator- (double dif);

	// Умножение матрицы на число dif
	Matrix operator* (double dif) const;

	// Умножение матрицы на матрицу
	Matrix operator* (Matrix Matrix2);

	// Собственное умножение матрицы на матрицу
	void operator*= (Matrix Matrix2);

	// Собственное умножение матрицы на число dif
	void operator*= (double dif);

	// Собственное вычитание матриц
	void operator-= (Matrix Matrix2);

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

	// Определитель матрицы
	float determinant(int rang);

	/*// Обратная матрица
	Matrix Back_matrix();*/

	// Деструктор класса
	~Matrix();



};