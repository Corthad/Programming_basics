
#include <iostream>
#include <string>
#include <ctime>

#include "card_generator.h"
#include "screen_utils.h"
#include "input_utils.h"

std::string generate_card_number(int number_of_payment_system) {
    std::string number = "";
    switch(number_of_payment_system) {
        case 0:
            number = "4";
            break;
        case 1:
            number = "5";
            number += std::to_string((rand() % 5) + 1);
            break;
        case 2:
            number = "220";
            number += std::to_string(rand() % 5);
            break;
    }
    
    while (number.length() < 15) {
        number += std::to_string(rand() % 10);
    }

    // Алгоритм Луна
    int sum = 0;
    bool alternate = false;
    for (int i = number.length() - 1; i >= 0; i--) {
        int digit = number[i] - '0';
        if (alternate) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }
        sum += digit;
        alternate = !alternate;
    }
    int check_digit = (10 - (sum % 10)) % 10;
    number += std::to_string(check_digit);

    return number;
}

std::string generate_card_pin() {
    std::string pin = "";
    while (pin.length() < 4) {
        pin += std::to_string(rand() % 10);
    }
    return pin;
}

bool generate_new_card(std::vector<Card>& cards) {
    if (cards.size() >= MAX_NUMBERS_OF_CARDS) {
        std::cout << "Достигнуто максимальное количество карт!\n";
        pause_screen();
        return false;
    }

    Card new_card;
    int number_of_payment_system = save_int_input("Выберете платежную систему (0-VISA, 1-MasterCard, 2-MIR): ", 0, 2);
    new_card.number = generate_card_number(number_of_payment_system);
    new_card.pin = generate_card_pin();
    new_card.payment_system = number_of_payment_system;
    new_card.balance[0] = rand() % 100000;
    new_card.balance[1] = rand() % 100000;
    new_card.balance[2] = rand() % 100000;
    cards.push_back(new_card);
    return true;
}