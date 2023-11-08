// Chess_Figure.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "ChessFigureStruct.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    Chessmen Test;
    Test.Set_Coordinate(1, 1);
    cout << Test.ToString();
    Rook Test1(0, 3);
    
}

