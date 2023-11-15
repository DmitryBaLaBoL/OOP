#include "MatrixStruct.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    // Проверка assert

    

    Matrix Test(3,3), Test1(3, 3), Test2(3, 3);
    float a;
    Test.fill_matrix_random(20, 30);
    Test.get_matrix();
    a = Test.determinant(Test, 3);
    cout << endl << "Определитель = " << a;
    Test1 = Test.Back_matrix(Test);
    cout << endl << "Обр = " << endl;
    Test1.get_matrix();
}

