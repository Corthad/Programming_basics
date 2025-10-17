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
    
    std::cout << "Введите количество монет (сначала золотые, потом серебрянные): ";
    std::cin >> gold_money;
    std::cin >> silver_money;
    std::cout << "Введите номер товара (0 - бутылка, 1 - хлеб, 2 - яблоко):";
    std::cin >> number;
    std::cout << "Введите количество приобретаемого товара: ";
    std::cin >> count;

    int all_money = gold_money * 100 + silver_money;

    if ((number > 2) || (number < 0)) {
        std::cout << "Введен неверный номер товара.\n" ;
        return 0;
    }
    else if (count < 1) {
        std::cout << "Введено неверное количество товара\n";
        return 0;

    }
    else {
        switch (number){
            case 0: if (count > bottle_value) {
                        std::cout << "Товара в таком количестве нет.\n" ;
                    }
                    else if (all_money < (count * bottle_cost)) {
                        std::cout << "Денег на покупку такого колличества товара не хватит.\n" ;
                    }
                    else {
                        all_money -= (count * bottle_cost);
                        bottle_value -= count;
                            std::cout << "Колличество купленного товара: " << count << "\n";
                            std::cout << "Осталось товара в магазине: " << bottle_value << "\n";
                    }
                    break;
            case 1: if (count > bread_value) {
                        std::cout << "Товара в таком количестве нет.\n" ;
                    }
                    else if (all_money < (count * bread_cost)) {
                        std::cout << "Денег на покупку такого колличества товара не хватит.\n" ;
                    }
                    else {
                        all_money -= (count * bread_cost);
                        bread_value -= count;
                            std::cout << "Колличество купленного товара: " << count << "\n";
                            std::cout << "Осталось товара в магазине: " << bread_value << "\n";
                    }
                    break;
            case 2: if (count > apple_value) {
                        std::cout << "Товара в таком количестве нет.\n" ;
                    }
                    else if (all_money < (count * apple_cost)) {
                        std::cout << "Денег на покупку такого колличества товара не хватит.\n" ;
                    }
                    else {
                        all_money -= (count * apple_cost);
                        apple_value -= count;
                            std::cout << "Колличество купленного товара: " << count << "\n";
                            std::cout << "Осталось товара в магазине: " << apple_value << "\n";
                    }
                    break;
            }

    }
    gold_money = all_money / 100;
    silver_money = all_money - (gold_money * 100);
    std::cout << "Осталось золотых монет:" << gold_money << "\n";
    std::cout << "Осталось серебряных монет: " << silver_money << "\n";

    std::cout << "Налог на богатых... ";
    if (all_money > 1000) {
        std::cout << "Вы облагаетесь налогом в 10%. После удержания налога остается:\n";
        all_money *= 0.9;
        gold_money = all_money / 100;
        silver_money = all_money - (gold_money * 100);
        std::cout << "Золотых монет - " << gold_money << "\n";
        std::cout << "Серебряных монет - " << silver_money << "\n";
    }
    else {
        std::cout << "Вы не облагаетесь налогом.\n";
    }
    return 0;

}
