#include <iostream>
#include <format>

#include "transaction_operations.h"
#include "card_operations.h"
#include "input_utils.h"
#include "screen_utils.h"
#include "constants.h"

void view_transaction_history(Card& card, int type_operation) {
    clear_screen();
    std::cout << "История транзакций карты " << card.number << ":\n";
    
    if (card.transactions.empty()) {
        std::cout << "История транзакций пуста.\n";
    } else {
        std::cout << SEPARATOR;
        int count_operation = 0;
        for (const Transaction& temp_transaction : card.transactions) {
            bool should_show = false;
            
            if (type_operation == 0) {
                should_show = true;
            } else {
                std::string target_type = TYPE_OPERATION[type_operation - 1];
                if (target_type.substr(0, 15) == temp_transaction.type.substr(0, 15)) {
                    should_show = true;
                }
            }

            if (should_show) {
                std::cout << "Дата/Время: " << temp_transaction.date_time << "\n";
                std::cout << "Тип операции: " << temp_transaction.type << "\n";
                std::string currency_name = CURRENCY_NAME[temp_transaction.currency];

                if (temp_transaction.amount >= 0) {
                    std::cout << "Зачисление: +" << temp_transaction.amount << " " << currency_name << "\n";
                } else {
                    std::cout << "Списание: " << temp_transaction.amount << " " << currency_name << "\n";
                }
                std::cout << "Комиссия: " << temp_transaction.fee << " " << currency_name << "\n";
                std::cout << SEPARATOR;
                count_operation++;
            }
        }
        if (count_operation == 0) {
            std::cout << "Операций с таким типом на этой карте нет.\n";
        }
    }
    pause_screen();
}

void transfer_money_with_conversion(Card& from_card, std::vector<Card>& all_cards) {
    clear_screen();

    if (all_cards.size() <= 1) {
        std::cout << "Нет других карт для перевода!\n";
        pause_screen();
        return;
    }

    std::cout << "---------------МЕЖВАЛЮТНЫЙ  ПЕРЕВОД---------------\n";
    std::cout << "Доступные карты для перевода:\n";
    
    std::string cards_available_for_transfers = "";
    for (int i = 0; i < all_cards.size(); i++) {
        if (all_cards[i].number != from_card.number) {
            cards_available_for_transfers += std::to_string(i + 1) + ". " + all_cards[i].number + " (" + PAYMENT_SYSTEM_NAME[all_cards[i].payment_system] + ")\n";
        }
        else {
            cards_available_for_transfers += std::to_string(i + 1) + ". " + all_cards[i].number + " (" + PAYMENT_SYSTEM_NAME[all_cards[i].payment_system] + ") - Наша карта.\n";
        }
    }
    
    int target_index = save_int_input(cards_available_for_transfers + "Выберите карту для перевода: ", 1, all_cards.size()) - 1;
    
    if (all_cards[target_index].number == from_card.number) {
        std::cout << "Нельзя переводить на ту же карту!\n";
        pause_screen();
        return;
    }
    
    Card& to_card = all_cards[target_index];
    
    int currency_from = save_int_input(view_balance(from_card) + "Выберите валюту для списания (0-RUB, 1-USD, 2-EUR):", 0, 2);
    int currency_to = save_int_input("Выберите валюту для зачисления (0-RUB, 1-USD, 2-EUR):", 0, 2);
    double amount = save_double_input("Введите сумму для перевода (в валюте списания): ", 0.001, from_card.balance[currency_from]);
    
    double commission = amount * transaction_fees[3];
    double total_amount = amount + commission;
    
    if (from_card.balance[currency_from] < total_amount) {
        std::cout << "Недостаточно средств! Нужно: " << total_amount << " (включая комиссию " << commission << ")\n";
        pause_screen();
        return;
    }
    
    double converted_amount = convert_currency_amount(amount, currency_from, currency_to);
    
    from_card.balance[currency_from] -= total_amount;
    to_card.balance[currency_to] += converted_amount;

    add_transaction(from_card, "Перевод (списание): " + CURRENCY_NAME[currency_from] + "->" + CURRENCY_NAME[currency_to], currency_from, -total_amount, commission);
    add_transaction(to_card, "Перевод (зачисление): " + CURRENCY_NAME[currency_from] + "->" + CURRENCY_NAME[currency_to], currency_to, converted_amount, 0);
    
    std::cout << "Межвалютный перевод выполнен успешно!\n";
    std::cout << "Списано: " << total_amount << " " << CURRENCY_NAME[currency_from];
    std::cout << " (включая комиссию " << commission << " " << CURRENCY_NAME[currency_from] << ")\n";
    std::cout << "Зачислено: " << converted_amount << " " << CURRENCY_NAME[currency_to] << "\n";
    std::cout << "Курс конвертации: " << amount << " " << CURRENCY_NAME[currency_from];
    std::cout << " = " << converted_amount << " " << CURRENCY_NAME[currency_to] << "\n";
    pause_screen();
}

void show_complete_analytics(const Card& card) {
    struct Category {
        std::string name;
        double amount = 0;
        double fees = 0;
        int count = 0;
    };
    
    Category expenses[] = {
        {TYPE_OPERATION[0], 0, 0, 0},
        {TYPE_OPERATION[2], 0, 0, 0},
        {TYPE_OPERATION[4], 0, 0, 0}
    };
    
    Category incomes[] = {
        {TYPE_OPERATION[1], 0, 0, 0},
        {TYPE_OPERATION[3], 0, 0, 0},
        {TYPE_OPERATION[5], 0, 0, 0}
    };
    
    const int EXPENSE_COUNT = 3;
    const int INCOME_COUNT = 3;
    
    double total_expenses = 0;
    double total_incomes = 0;
    double total_fees = 0;

    int analitics_currency_number = save_int_input("Введите валюту, в которой хотите видеть аналитику (0-RUB, 1-USD, 2-EUR): ", 0, 2);
    
    for (int i = 0; i < card.transactions.size(); i++) {
        const Transaction& trans = card.transactions[i];
        
        double amount = convert_currency_amount(trans.amount, trans.currency, analitics_currency_number);
        double fee = convert_currency_amount(trans.fee, trans.currency, analitics_currency_number);
        
        if (trans.amount < 0) {
            for (int j = 0; j < EXPENSE_COUNT; j++) {
                if (trans.type.find(expenses[j].name) == 0) {
                    expenses[j].amount += std::abs(amount);
                    expenses[j].fees += fee;
                    expenses[j].count++;
                    total_expenses += std::abs(amount);
                    total_fees += fee;
                    break;
                }
            }
        }
        else {
            for (int j = 0; j < INCOME_COUNT; j++) {
                if (trans.type.find(incomes[j].name) == 0) {
                    incomes[j].amount += amount;
                    incomes[j].fees += fee;
                    incomes[j].count++;
                    total_incomes += amount;
                    total_fees += fee;
                    break;
                }
            }
        }
    }
    
    double percentage;

    clear_screen();
    std::cout << "---------------АНАЛИТИКА ТРАНЗАКЦИЙ---------------\n";
    std::cout << "Карта: " << card.number << "\n";
    std::cout << SEPARATOR;

    std::cout << "ОБЩАЯ СТАТИСТИКА:\n";
    std::cout << std::format("  Доходы: {:.2f} ", total_incomes) << CURRENCY_NAME[analitics_currency_number] << "\n";
    std::cout << std::format("  Расходы: {:.2f} ", total_expenses) << CURRENCY_NAME[analitics_currency_number] << "\n";
    std::cout << std::format("  Комиссии: {:.2f} ", total_fees) << CURRENCY_NAME[analitics_currency_number] << "\n";
    std::cout << std::format("  Чистая прибыль: {:.2f} ", (total_incomes - total_expenses - total_fees)) << CURRENCY_NAME[analitics_currency_number] << "\n";
    std::cout << SEPARATOR;

    std::cout << "РАСХОДЫ:\n";
     for (int i = 0; i < EXPENSE_COUNT; i++) {
        if (expenses[i].count > 0) {
            percentage = (total_expenses > 0) ? (expenses[i].amount / total_expenses) * 100 : 0;
            std::cout << expenses[i].name << ":\n";
            std::cout << "  Операций: " << expenses[i].count << "\n";
            std::cout << std::format("  Сумма: {:.2f} ", expenses[i].amount) << CURRENCY_NAME[analitics_currency_number] << " (" << percentage << "%)\n";
            std::cout << std::format("  Комиссии: {:.2f} ", expenses[i].fees) << CURRENCY_NAME[analitics_currency_number] << "\n";
            std::cout << SEPARATOR;
        }
        else {
            std::cout << "Нет расходов\n";
            std::cout << SEPARATOR;
        }
    }
    
    std::cout << "ДОХОДЫ:\n";
    for (int i = 0; i < INCOME_COUNT; i++) {
        if (incomes[i].count > 0) {
            percentage = (total_incomes > 0) ? (incomes[i].amount / total_incomes) * 100 : 0;
            std::cout << incomes[i].name << ":\n";
            std::cout << "  Операций: " << incomes[i].count << "\n";
            std::cout << std::format("  Сумма: {:.2f} ", incomes[i].amount) << CURRENCY_NAME[analitics_currency_number] << " (" << percentage << "%)\n";
            std::cout << std::format("  Комиссии: {:.2f} ", incomes[i].fees) << CURRENCY_NAME[analitics_currency_number] << "\n";
            std::cout << SEPARATOR;
        }
        else {
            std::cout << "Нет доходов\n";
            std::cout << SEPARATOR;
        }
    }

    pause_screen();
}