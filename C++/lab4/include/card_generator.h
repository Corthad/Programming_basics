#pragma once

#include <vector>

#include "constants.h"

// Генерация номера карты
std::string generate_card_number(int number_of_payment_system);

// Генерация пин-клжа
std::string generate_card_pin();

// Создание новой карты
bool generate_new_card(std::vector<Card>& cards);