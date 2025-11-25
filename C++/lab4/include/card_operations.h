#pragma once

#include <vector>

#include "constants.h"

// Изменение пин кода
bool change_pin(Card& card);

// Функция возвращает строку с балансом карты
std::string view_balance(Card& card, int currency_type_number = -1);

// Функция возвращает строку с "балансом" кошелька
std::string view_cash();

// Конвертация числа из одной валюты в другую
double convert_currency_amount(double amount, int from_currency, int to_currency);

// Конвертация валюты с последующим изменением баланса карты
void convert_money(Card& card);

// Редактирование баланса счёта. 0-для снятия, 1-для пополнения
void edit_balance(Card& card, int type_operation);

// Добавление информации о транзакции
void add_transaction(Card& card, const std::string& type, int currency, double amount, double fee = 0.0);