#pragma once

#include <vector>

#include "constants.h"

// Просмотр списка карт
void view_all_cards(const std::vector<Card>& cards);

//Поиск индекса карты по её номеру
int search_card_in_list(std::vector<Card>& cards);

//Выбор карты по индексу или поиск по номеру
int search_index_card(std::vector<Card>& cards);