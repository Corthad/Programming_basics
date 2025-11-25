#pragma once

#include <string>
#include <vector>

const int MAX_PIN_ATTEMPTS = 3;
const int MAX_NUMBERS_OF_CARDS = 100;

const std::string MAIN_MENU =   "-------------------ГЛАВНОЕ МЕНЮ-------------------\n"
                                "1. Загрузить данные из файла.\n"
                                "2. Сохранить данные в файл.\n"
                                "3. Cоздание новой карты.\n"
                                "4. Просмотр списка всех карт.\n"
                                "5. Переход в режим управления картой.\n"
                                "0. Выход.\n"
                                "Выберите действие: ";

const std::string CARD_MENU =   "--------------МЕНЮ УПРАВЛЕНИЯ КАРТОЙ--------------\n"
                                "1. Изменить пин-код.\n"
                                "2. Посмотреть баланс.\n"
                                "3. Пополнить баланс.\n"
                                "4. Снять наличные.\n"
                                "5. Перевести деньги между своими счетами.\n"
                                "6. Перевести деньги на другую карту.\n"
                                "7. Просмотреть информацию о транзакциях по этой карте.\n"
                                "8. Посмотреть аналитику транзакций по этой карте.\n"
                                "9. Посмотреть количество наличных.\n"
                                "0. Возврат в главное меню.\n"
                                "Выберите действие: ";

const std::string CHANGE_TYPE_OPERATION =   "Введите номер типа операции:\n"
                                            "0 - Все операции\n"
                                            "1 - Конвертация валют (списание)\n"
                                            "2 - Конвертация валют (зачисление)\n"
                                            "3 - Снятие наличных\n"
                                            "4 - Пополнение счета\n"
                                            "5 - Перевод (списание)\n"
                                            "6 - Перевод (зачисление)\n"
                                            "Ваш выбор: ";
                                            
const std::string SEPARATOR = "--------------------------------------------------\n";

const std::string CURRENCY_NAME[3] = {"RUB", "USD", "EUR"}; // 0-RUB, 1-USD, 2-EUR

const std::string PAYMENT_SYSTEM_NAME[3] = {"VISA", "MasterCard", "MIR"}; //0-VISA, 1-MasterCard, 2-MIR

const std::string TYPE_OPERATION[6] = {
    "Конвертация (списание)",
    "Конвертация (зачисление)",
    "Снятие наличных",
    "Пополнение счета",
    "Перевод (списание)",
    "Перевод (зачисление)"
};

extern double transaction_fees[4]; // 0-Снятие со счёта, 1-Пополнение на счёт, 2-Перевод между счетами, 3-Перевод на другую карту

extern double exchange_rate[4]; // // 0-RUB_to_USD, 1-RUB_to_EUR, 2-USD_to_RUB, 3-EUR_to_RUB

extern double cash[3]; // 0-RUB, 1-USD, 2-EUR

struct Transaction {
    std::string date_time;
    std::string type;
    int currency;
    double amount;
    double fee;
};

struct Card {
    std::string number = "";
    std::string pin = "";
    int payment_system;
    bool is_blocked = false;
    int pin_attempts = 0;
    double balance[3]{0};
    std::vector<Transaction> transactions;
};