#include <iostream>
#include <limits>

#include "card_validation.h"
#include "screen_utils.h"

bool is_valid_card_number(const std::string& number) {
    if (number.length() != 16) return false;
    for (char c : number) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

bool is_valid_pin(const std::string& pin) {
    if (pin.length() != 4) return false;
    for (char c : pin) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

bool entered_pin_is_correct(Card& card) {
    std::string entered_pin = "";
    if (!card.is_blocked) {
        do {
            clear_screen();
            std::cout << "Введите пин-код, состоящий из 4 цифр: ";
            std::cin >> entered_pin;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (!is_valid_pin(entered_pin)) {
                entered_pin = "";
                std::cout << "Введено неверное количество символов и/или использованы символы, отличный от цифр.\n";
                pause_screen();
                continue;
            } 
            else if (card.pin != entered_pin) {
                card.pin_attempts += 1;
                entered_pin = "";
                std::cout << "Введен неверный пин-код. Осталось попыток ввода: " << MAX_PIN_ATTEMPTS - card.pin_attempts << ".\n";
                pause_screen();   
                continue;
            }
            else {
                card.pin_attempts = 0;
                return true;
            }
        } while (card.pin_attempts < MAX_PIN_ATTEMPTS);
        card.is_blocked = true;
    }
    clear_screen();
    std::cout << "Ваша карта заблокирована.\n";
    pause_screen();
    return false;
}