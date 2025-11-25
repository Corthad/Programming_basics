#include <iostream>
#include <string>

#include "card_list_operations.h"
#include "card_validation.h"
#include "input_utils.h"
#include "screen_utils.h"

void view_all_cards(const std::vector<Card>& cards) {
    std::cout << "СПИСОК ВСЕХ КАРТ\n";
    if (cards.empty()) {
        std::cout << "Пусто.\n";
    }
    else {
        std::cout << SEPARATOR;
        for (int i = 0; i < cards.size(); i++) {
            std::cout << "Карта #" << i + 1 << ":\n";
            std::cout << "  Номер: " << cards[i].number << "\n";
            std::cout << "  Платежная система: " << PAYMENT_SYSTEM_NAME[cards[i].payment_system] << "\n";
            std::cout << "  PIN: " << cards[i].pin << "\n";
            std::cout << "  Статус: " << (cards[i].is_blocked ? "Заблокирована" : "Активна") << "\n";
            std::cout << "  Баланс RUB: " << cards[i].balance[0] << "\n";
            std::cout << "  Баланс USD: " << cards[i].balance[1] << "\n";
            std::cout << "  Баланс EUR: " << cards[i].balance[2] << "\n";
            std::cout << SEPARATOR;
        }
    }
}

int search_card_in_list(std::vector<Card>& cards) {
    std::string number_of_card;
    do{
        number_of_card = "";
        std::cout << "Введите номер карты (без пробелов и посторонних знаков, только 16 цифр): ";
        std::cin >> number_of_card;
        if (is_valid_card_number(number_of_card)) {
            clear_screen();
            break;
        }
        else {
            std::cout << "Номер карты введен некорректно. Повторите ввод...\n";
            pause_screen();
        }
    } while(true);
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i].number == number_of_card) {
            std::cout << "Отлично. Карта с таким номером найдена.\n";
            pause_screen();
            return i;
        }
    }
    std::cout << "Карты с таким номером в этом списке нет.\n";
    pause_screen();
    return -1;
}

int search_index_card(std::vector<Card>& cards) {
    int method_of_choosing_a_card = save_int_input("Выбор карты из списка или поиск по номеру (0-выбрать из списка, 1-поиск карты по номеру): ", 0, 1);
    if (method_of_choosing_a_card == 0) {
        bool flag_exit = false;
        std::string card_index = "";
        int card_index_int;
        while (!flag_exit) {
            view_all_cards(cards);
            std::cout << "Введите индекс карты: ";
            std::cin >> card_index;
            for (char c : card_index) {
                if (c > '9' || c < '0') {
                    card_index = "";
                    std::cout << "Некорректный индекс. Для ввода индекса используйте только цифры.\n";
                    pause_screen();
                    break;
                }
            }
            if (card_index != "") {
                card_index_int = std::stoi(card_index);
                if (card_index_int < 1 || card_index_int > cards.size()) {
                    std::cout << "Некорректный индекс. Выход за диапазон списка.\n";
                    pause_screen();
                }
                else {
                    card_index_int--;
                    return card_index_int;
                }
            }
        }
    }
    else {
        int card_index = search_card_in_list(cards);
        if (card_index != -1) {
                return card_index;
        }
    }
    return -1;
}