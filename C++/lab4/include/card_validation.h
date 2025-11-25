#pragma once

#include <string>

#include "constants.h"

// Базовая проверка номера карты
bool is_valid_card_number(const std::string& number);

// Базовая проверка пин-кода карты
bool is_valid_pin(const std::string& pin);

// Ввод пин-кода и проверка на соответствие
bool entered_pin_is_correct(Card& card);