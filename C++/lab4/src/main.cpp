#include <iostream>
#include <windows.h>
#include <vector>
#include <limits>
#include <ctime>
#include <string>
#include <chrono>
#include <format>
#include <fstream>

#include "constants.h"
#include "screen_utils.h"
#include "file_operations.h"
#include "input_utils.h"
#include "card_generator.h"
#include "card_validation.h"
#include "card_list_operations.h"
#include "menu_handlers.h"

double transaction_fees[4] = {0.07, 0.02, 0.01, 0.03};

double exchange_rate[4] = {84.7, 99.1, 77.3, 90.7};

double cash[3] = {10000.0, 500.0, 300.0};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand(time(0));

    std::vector<Card> cards;
    cards.reserve(MAX_NUMBERS_OF_CARDS);

    bool close_program = false;
    int active_action;

    //load_data(cards);

    do {
        active_action = save_int_input(MAIN_MENU, 0, 5);
        switch(active_action) {
            case 0: 
                close_program = true;
                save_data(cards);
                break;
            case 1:
                if (load_data(cards)) {
                    std::cout << "Чтение данных прошло успешно.\n";
                }
                else {
                    std::cout << "Ошибка. Не удалось открыть файл для чтения данных.\n";
                }
                pause_screen();
                break;
            case 2:
                if (save_data(cards)) {
                    std::cout << "Сохранение данных прошло успешно.\n";
                }
                else {
                    std::cout << "Ошибка. Не удалось открыть файл для сохранения данных.\n";
                }
                pause_screen();
                break;
            case 3:
                if (generate_new_card(cards)) {
                    std::cout << "Карта успешно создана!\n";
                    std::cout << "Номер: " << cards.back().number << "\n";
                    std::cout << "PIN: " << cards.back().pin << "\n";
                    std::cout << "Баланс RUB: " << cards.back().balance[0] << "\n";
                    std::cout << "Баланс USD: " << cards.back().balance[1] << "\n";
                    std::cout << "Баланс EUR: " << cards.back().balance[2] << "\n";
                };
                save_data(cards);
                pause_screen();
                break;
            case 4:
                view_all_cards(cards);
                pause_screen();
                break;
            case 5:
                if (!cards.empty()) {
                    int card_index = search_index_card(cards);
                    if (card_index != -1) {
                        if (entered_pin_is_correct(cards[card_index])) {
                            card_management_menu(cards[card_index], cards);
                        }
                    }
                }
                else {
                    std::cout << "Список карт пуст.\n";
                    pause_screen();
                }
                break;
        }
    } while (!close_program);

    return 0;
}