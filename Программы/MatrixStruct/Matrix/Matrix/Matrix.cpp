#include "MatrixStruct.h"
#include <cassert>


int main()
{
    setlocale(LC_ALL, "Russian");
    // Проверка assert

    

    // Проверка assert
    Matrix Test(3, 3);
    // Проверка получения кол-ва строк и столбцов
    assert(Test.get_line() == 3 && Test.get_col() == 3);

    Test.fill_matrix_oneEl(5);
    // Проверка получения конкретного элемента
    assert(Test.get_element(2, 2) == 5.0);
    Test.fill_matrix_random(20, 30);
    // Проверка рандомного заполнения матрицы в промежутке
    for (int i = 0; i < Test.get_line(); i++)
    {
        assert(Test.get_element(0, i) >= 20 && Test.get_element(0, i) <= 30);
    }
    // Проверка операторов
    Matrix Test1(3, 3), Test2(3, 3);
    Test.fill_matrix_oneEl(1); Test1.fill_matrix_oneEl(2);////
    // +
    Test2 = Test + Test1;
    // for
    for (int i = 0; i < Test.get_line(); i++) {
        for (int j = 0; j < Test.get_col(); j++)
        {
            assert(Test2.get_element(i, j) == 3.0);
        }
    }
    // -
    Test2 = Test - Test1;
    for (int i = 0; i < Test.get_line(); i++) {
        for (int j = 0; j < Test.get_col(); j++)
        {
            assert(Test2.get_element(i, j) == -1.0);
        }
    }
    // Проверка транспонирования
    Test.fill_matrix_random(10, 20);
    Test1 = Test * 1;
    Test = Test.Trans_matrix();
    for (int i = 0; i < Test.get_line(); i++) {
        for (int j = 0; j < Test.get_col(); j++)
        {
            assert(Test.get_element(i, j) == Test1.get_element(j, i));
        }
    }
    // проверка диагональной матрицы
    Test.Diagonal_matrix();
    for (int i = 0; i < Test.get_line(); i++)
    {
        for (int j = 0; j < Test.get_col(); j++)
        {
            if (i != j) assert(Test.get_element(i, j) == 0);
            else assert(Test.get_element(i, j) != 0);
        }
    }

    // Проверка определителя
    Test.Set_el(0, 0, 1); Test.Set_el(0, 1, 2); Test.Set_el(0, 2, 3);
    Test.Set_el(1, 0, 4); Test.Set_el(1, 1, 5); Test.Set_el(1, 2, 6);
    Test.Set_el(2, 0, 7); Test.Set_el(2, 1, 8); Test.Set_el(2, 2, 10);
    Test.get_matrix();
    assert(Test.determinant(3) == -3);
    // Проверка обратной матрицы
    Test1.fill_matrix_oneEl(1);
    Test2 = Test;
    Test.Back_matrix();
    Matrix Test3 = Test2 * Test;
    Test.get_matrix(); Test3.get_matrix();
    /*for (int i = 0; i < Test.get_line(); i++)
    {
        for (int j = 0; j < Test.get_line(); j++)
        {
            assert(Test1.get_element(i,j) == Test3.get_element(i, j));
        }
    }*/




    // Проверка кматрицы строки и столбца
    Matrix TestLine(1, 5);
    TestLine.fill_matrix_random(10, 20);
    Matrix TestCol(5, 1);
    TestCol.fill_matrix_random(10, 20);
    TestLine.get_matrix();
    TestCol.get_matrix();
    TestLine = TestLine * TestCol;
    TestLine.get_matrix();
}

