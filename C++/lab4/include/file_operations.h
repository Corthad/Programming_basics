#pragma once

#include <vector>

#include "constants.h"

// Загрузка данных из файла
bool load_data(std::vector<Card>& cards);

// Сохранение всех данных в файл
bool save_data(const std::vector<Card>& cards);