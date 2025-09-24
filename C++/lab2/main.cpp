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
    std::cout << "Введите количество золотых монет: ";
    std::cin >> a;
    std::cout << "Введите количество серебряных монет: ";
    std::cin >> b;
    std::cout << "Введите количество приобретаемого товара: ";
    std::cin >> c;

    int money = a * 100 + b;

    int max_bottle = (money / bottle_cost);
    int basket = (c <= max_bottle) * c + (c > max_bottle) * max_bottle;
    int res = (bottle_value >= basket) * basket + (bottle_value < basket) * bottle_value;
    bottle_value -= res;

    money -= (res * bottle_cost);
    a = money / 100;
    b = money - (a * 100);

    std::cout << "Колличество купленного товара: " << res << std::endl;
    std::cout << "Осталось золотых монет:" << a << std::endl;
    std::cout << "Осталось серебряных монет: " << b << std::endl;
    std::cout << "Осталось бутылок в магазине: " << bottle_value << std::endl;
    long double p = pow(money, res);
    std::cout << money << "^" << res << " = " << p << std::endl;

    return 0;
}