#pragma once

#include <vector>

#include "constants.h"

// Просмотр истории транзакций
void view_transaction_history(Card& card, int type_operation);

// Функция межвалютного перевода с автоматической конвертацией
void transfer_money_with_conversion(Card& from_card, std::vector<Card>& all_cards);

// Аналитика по всем транзакциям
void show_complete_analytics(const Card& card);