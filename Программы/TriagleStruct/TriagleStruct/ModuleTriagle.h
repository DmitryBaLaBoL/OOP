#pragma once

using namespace std;

//Класс - треугольник
class Triangle {
private:
	// Поля
	double Ax, Ay, Bx, By, Cx, Cy;

public: // Методы
	// Конструктор
	Triangle();

	// Сеттер вершины A
	void Set_CoordinateA(double NewCoorginateX, double NewCoorginateY);

	// Сеттер вершины B
	void Set_CoordinateB(double NewCoorginateX, double NewCoorginateY);

	// Сеттер вершины C
	void Set_CoordinateC(double NewCoorginateX, double NewCoorginateY);

	// Геттер координаты x вершины A
	double Get_X_A();

	// Геттер координаты x вершины B
	double Get_X_B();

	// Геттер координаты x вершины C
	double Get_X_C();

	// Геттер координаты y вершины A
	double Get_Y_A();

	// Геттер координаты y вершины B
	double Get_Y_B();

	// Геттер координаты y вершины C
	double Get_Y_C();

	// Получение длины стороны напротив вершины A
	double Length_A();

	// Получение длины стороны напротив вершины B
	double Length_B();

	// Получение длины стороны напротив вершины C
	double Length_C();

	// Площадь треугольника
	double Square();

	//Периметр треугольника
	double Perimetr();

	// Угол у вершины A
	double Angle_A();

	// Угол у вершины B
	double Angle_B();

	// Угол у вершины C
	double Angle_C();
};

