#include <iostream>

int main()
{   
    setlocale(LC_ALL, "RU");
    
    int gold_money, silver_money, number, count;
    int bottle_cost = 50;
    int bottle_value = 10;
    int bread_cost = 120;
    int bread_value = 5;
    int apple_cost = 30;
    int apple_value = 20;
    
    std::cout << "������� ���������� ����� (������� �������, ����� �����������): ";
    std::cin >> gold_money;
    std::cin >> silver_money;
    std::cout << "������� ����� ������ (0 - �������, 1 - ����, 2 - ������):";
    std::cin >> number;
    std::cout << "������� ���������� �������������� ������: ";
    std::cin >> count;

    int all_money = gold_money * 100 + silver_money;

    if ((number > 2) || (number < 0)) {
        std::cout << "������ �������� ����� ������.\n" ;
        return 0;
    }
    else if (count < 1) {
        std::cout << "������� �������� ���������� ������\n";
        return 0;

    }
    else {
        switch (number){
            case 0: if (count > bottle_value) {
                        std::cout << "������ � ����� ���������� ���.\n" ;
                    }
                    else if (all_money < (count * bottle_cost)) {
                        std::cout << "����� �� ������� ������ ����������� ������ �� ������.\n" ;
                    }
                    else {
                        all_money -= (count * bottle_cost);
                        bottle_value -= count;
                            std::cout << "����������� ���������� ������: " << count << "\n";
                            std::cout << "�������� ������ � ��������: " << bottle_value << "\n";
                    }
                    break;
            case 1: if (count > bread_value) {
                        std::cout << "������ � ����� ���������� ���.\n" ;
                    }
                    else if (all_money < (count * bread_cost)) {
                        std::cout << "����� �� ������� ������ ����������� ������ �� ������.\n" ;
                    }
                    else {
                        all_money -= (count * bread_cost);
                        bread_value -= count;
                            std::cout << "����������� ���������� ������: " << count << "\n";
                            std::cout << "�������� ������ � ��������: " << bread_value << "\n";
                    }
                    break;
            case 2: if (count > apple_value) {
                        std::cout << "������ � ����� ���������� ���.\n" ;
                    }
                    else if (all_money < (count * apple_cost)) {
                        std::cout << "����� �� ������� ������ ����������� ������ �� ������.\n" ;
                    }
                    else {
                        all_money -= (count * apple_cost);
                        apple_value -= count;
                            std::cout << "����������� ���������� ������: " << count << "\n";
                            std::cout << "�������� ������ � ��������: " << apple_value << "\n";
                    }
                    break;
            }

    }
    gold_money = all_money / 100;
    silver_money = all_money - (gold_money * 100);
    std::cout << "�������� ������� �����:" << gold_money << "\n";
    std::cout << "�������� ���������� �����: " << silver_money << "\n";

    std::cout << "����� �� �������... ";
    if (all_money > 1000) {
        std::cout << "�� ����������� ������� � 10%. ����� ��������� ������ ��������:\n";
        all_money *= 0.9;
        gold_money = all_money / 100;
        silver_money = all_money - (gold_money * 100);
        std::cout << "������� ����� - " << gold_money << "\n";
        std::cout << "���������� ����� - " << silver_money << "\n";
    }
    else {
        std::cout << "�� �� ����������� �������.\n";
    }
    return 0;

}
