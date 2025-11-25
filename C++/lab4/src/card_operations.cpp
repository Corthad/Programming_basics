#include <iostream>
#include <string>

#include "card_operations.h"
#include "card_validation.h"
#include "date_time_utils.h"
#include "input_utils.h"
#include "screen_utils.h"

bool change_pin(Card& card) {
    if (entered_pin_is_correct(card)) {
        std::string new_pin = "";
        std::string confirm_new_pin = "";
        do {
            if (new_pin == "") {
                clear_screen();
                std::cout << "Введите новый пин-код, состоящий из 4 цифр: ";
                std::cin >> new_pin;
                if (!is_valid_pin(new_pin)) {
                    new_pin = ""; 
                    std::cout << "Введено неверное количество символов и/или использованы символы, отличный от цифр.\n";
                    pause_screen();
                    continue;
                }
                else if (new_pin == card.pin) {
                    new_pin = ""; 
                    std::cout << "Новый пин-код совпадает со старым. Введите другой пин-код.\n";
                    pause_screen();
                    continue;
                }
            }
            else if (confirm_new_pin == "") {
                clear_screen();
                std::cout << "Подтвердите новый пин-код, состоящий из 4 цифр: ";
                std::cin >> confirm_new_pin;
                if (!is_valid_pin(confirm_new_pin)) {
                    std::cout << "Введено неверное количество символов и/или использованы символы, отличный от цифр.\n";
                    confirm_new_pin = "";
                    pause_screen();
                    continue;
                }
                else if (new_pin != confirm_new_pin) {
                    new_pin = "";
                    confirm_new_pin = "";
                    std::cout << "Пин код не совпадает. Повторите ввод сначала.\n";
                    pause_screen();
                    continue;
                }
                else {
                    card.pin = new_pin;
                    std::cout << "Смена пин-кода прошла успешно.\n";
                    pause_screen(); 
                    return true;
                }
            }
        } while (true);
    }
    else {
        return false;
    }
}

std::string view_balance(Card& card, int currency_type_number) {
    std::string message = "Баланс карты " + card.number + ":\n";
    if (currency_type_number == -1) {
        message +=  CURRENCY_NAME[0] + " - " + std::to_string (card.balance[0]) + "\n" +
                    CURRENCY_NAME[1] + " - " + std::to_string (card.balance[1]) + "\n" +
                    CURRENCY_NAME[2] + " - " + std::to_string (card.balance[2]) + "\n";
    }
    else {
        if (currency_type_number == 0) {
            message += CURRENCY_NAME[0] + " - " + std::to_string (card.balance[0]) + "\n";
        }
        if (currency_type_number == 1) {
            message += CURRENCY_NAME[1] + " - " + std::to_string (card.balance[1]) + "\n";
        }
        if (currency_type_number == 2) {
            message += CURRENCY_NAME[2] + " - " + std::to_string (card.balance[2]) + "\n";
        }
    }
    return message;
}

std::string view_cash() {
    return "Наличные деньги:\n" +
           CURRENCY_NAME[0] + " - " + std::to_string(cash[0]) + "\n" +
           CURRENCY_NAME[1] + " - " + std::to_string(cash[1]) + "\n" +
           CURRENCY_NAME[2] + " - " + std::to_string(cash[2]) + "\n";
}

double convert_currency_amount(double amount, int from_currency, int to_currency) {
    if (from_currency == to_currency) {
        return amount;
    }
    
    double converted_amount = 0.0;
    
    if (from_currency == 0) {
        if (to_currency == 1) {
            converted_amount = amount / exchange_rate[0];
        } else if (to_currency == 2) {
            converted_amount = amount / exchange_rate[1];
        }
    }
    else if (from_currency == 1) {
        if (to_currency == 0) {
            converted_amount = amount * exchange_rate[2];
        } else if (to_currency == 2) {
            double in_rub = amount * exchange_rate[2];
            converted_amount = in_rub / exchange_rate[1];
        }
    }
    else if (from_currency == 2) {
        if (to_currency == 0) {
            converted_amount = amount * exchange_rate[3];
        } else if (to_currency == 1) {
            double in_rub = amount * exchange_rate[3];
            converted_amount = in_rub / exchange_rate[0];
        }
    }
    
    return converted_amount;
}

void convert_money(Card& card) {
    int source_currency;
    int target_currency;
    do {
        source_currency = save_int_input(view_balance(card) + "Выберете валюту, из которой будете конвертировать (0-RUB, 1-USD, 2-EUR): ", 0, 2);
        target_currency = save_int_input(view_balance(card) + "Выберете валюту, в которую будете конвертировать (0-RUB, 1-USD, 2-EUR): ", 0, 2);
        if (source_currency == target_currency) {
            clear_screen();
            std::cout << "Валюты не могут совпадать. Повторите свой выбор сначала.\n";
            pause_screen();
        }
    } while (source_currency == target_currency);

    double epsilon = 0.001;
    if (card.balance[source_currency] - 0.f <= epsilon) {
        std::cout << "Недостаточно средств на счете!\n";
        pause_screen();
        return;
    }
    
    double convertible_amount = save_double_input(view_balance(card, source_currency) + "Введите желаемое значение для конвертирования: ", 0.f, card.balance[source_currency]);
    
    double commission = convertible_amount * transaction_fees[2];
    double amount_after_fee = convertible_amount - commission;

    double converted_amount = convert_currency_amount(amount_after_fee, source_currency, target_currency);

    card.balance[source_currency] -= convertible_amount;
    card.balance[target_currency] += converted_amount;

    add_transaction(card, "Конвертация (списание)", source_currency, -convertible_amount, commission);
    add_transaction(card, "Конвертация (зачисление)", target_currency, converted_amount, 0.f);
    
    std::cout << view_balance(card);
    std::cout << "Конвертация выполнена успешно!\n";
    std::cout << "Комиссия за операцию: " << commission << " ";
    std::cout << CURRENCY_NAME[source_currency];
    std::cout << "\n";
    pause_screen();
}

void edit_balance(Card& card, int type_operation) {
    int type_currency = save_int_input(SEPARATOR + view_cash() + SEPARATOR + view_balance(card) + SEPARATOR 
    + "Введите тип валюты, над которой будет производится операция (0-RUB, 1-USD, 2-EUR): ", 0, 2);  
    double value;
    double value_after_fee = 0.f;
    double commission = 0.f;
    
    if (type_operation == 0) {
        double max_withdrawal = card.balance[type_currency] / (1 + transaction_fees[0]);
        do {
            value = save_double_input(SEPARATOR + view_cash() + SEPARATOR + view_balance(card, type_currency) + SEPARATOR 
             + "Введите сумму наличных, которую хотите получить: ", 0.01, max_withdrawal);
            commission = value * transaction_fees[0];
            value_after_fee = value + commission;
            if ((card.balance[type_currency] - value_after_fee) < 0) {
                std::cout << "У Вас недостаточно средств для совершения данной операции.\n";
                pause_screen();
                continue;
            }
            else {
                card.balance[type_currency] -= value_after_fee;
                cash[type_currency] += value;
                add_transaction(card, "Снятие наличных", type_currency, -value_after_fee, commission);
                std::cout << view_balance(card, type_currency) << "Списание средств прошло успешно.\n";
                std::cout << view_cash();
                pause_screen();
                break;
            }
        } while (true);
    }
    else if (type_operation == 1) {
        if (cash[type_currency] >= 1) {    
            value = save_double_input(SEPARATOR + view_cash() + SEPARATOR + view_balance(card, type_currency) + SEPARATOR
                 + "Введите сумму наличных, которую хотите внести: ", 0.01, cash[type_currency]);
            commission = value * transaction_fees[1];
            value_after_fee = value - commission;

            cash[type_currency] -= value;
            card.balance[type_currency] += value_after_fee;
            add_transaction(card, "Пополнение счета", type_currency, value_after_fee, commission);
            clear_screen();
            std::cout << view_balance(card, type_currency) << "Пополнение баланса прошло успешно.\n";
            std::cout << view_cash();
            pause_screen();
        }
        else {
            std::cout << "У Вас недостаточно средств для совершения данной операции.\n";
            pause_screen();
        }
    }
}

void add_transaction(Card& card, const std::string& type, int currency, double amount, double fee) {
    Transaction temp_transaction;
    temp_transaction.date_time = get_current_date_time();
    temp_transaction.type = type;
    temp_transaction.currency = currency;
    temp_transaction.amount = amount;
    temp_transaction.fee = fee;
    card.transactions.push_back(temp_transaction);
}