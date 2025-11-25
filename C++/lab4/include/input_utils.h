#pragma once

#include <string>

// Безопасный ввод целого числового значения
int save_int_input(const std::string& message, int min_value = INT_MIN, int max_value = INT_MAX);

// Безопасный ввод числового значения с плавающей запятой
double save_double_input(const std::string& message, double min_value = __DBL_MIN__, double max_value = __DBL_MAX__);