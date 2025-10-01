#include <iostream>
#include <cmath>
//#include <windows.h>

int main()
{   
    setlocale(LC_ALL, "RU");
    int a, b, c;
    int bottle_cost = 50;
    int bottle_value = 10;
    //SetConsoleCP(65001);
    //SetConsoleOutputCP(65001);
    std::cout << "������� ���������� ������� �����: ";
    std::cin >> a;
    std::cout << "������� ���������� ���������� �����: ";
    std::cin >> b;
    std::cout << "������� ���������� �������������� ������: ";
    std::cin >> c;

    int money = a * 100 + b;

    int max_bottle = (money / bottle_cost);
    int basket = (c <= max_bottle) * c + (c > max_bottle) * max_bottle;
    int res = (bottle_value >= basket) * basket + (bottle_value < basket) * bottle_value;
    bottle_value -= res;

    money -= (res * bottle_cost);
    a = money / 100;
    b = money - (a * 100);

    std::cout << "����������� ���������� ������: " << res << std::endl;
    std::cout << "�������� ������� �����:" << a << std::endl;
    std::cout << "�������� ���������� �����: " << b << std::endl;
    std::cout << "�������� ������� � ��������: " << bottle_value << std::endl;
    long double p = pow(money, res);
    std::cout << money << "^" << res << " = " << p << std::endl;

    return 0;
}