#include <cstring>
#include <iostream>
#include <limits>

#include "validation.h"
#include "ui.h"

bool is_valid_full_name(const char* full_name) {
    int length = strlen(full_name);
    return (length >= 5 && length <= 60);
}

bool is_valid_date(const char* date) {
    
    if (strlen(date) != 10) {
        return false;
    }

    if (date[2] != '.' || date[5] != '.') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue;
        }
        if (date[i] < '0' || date[i] > '9') {
            return false;
        }
    }

    int day = atoi(date);
    int month = atoi(date + 3);
    int year = atoi(date + 6);

    if (year < 2020 || year > 2030) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    short days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        days_in_month[1] = 29;
    }

    if (day < 1 || day > days_in_month[month - 1]) {
        return false;
    }

    return true;
}

bool is_valid_allowance(double allowance) {
    return (allowance >= 0.0 && allowance <= 100000.0);
}

char* get_string(const char* prompt, bool (*validator)(const char*)) {
    char buffer[256];
    char* result = nullptr;
    clean_screen();

    while(true) {
        std::cout << prompt << "\n";
        std::cin.getline(buffer, 256);

        if (strlen(buffer) == 0) {
            std::cout << "Ошибка: строка не может быть пустой.\n";
            pause_screen();
            continue;
        }

        if (validator && !validator(buffer)) {
            std::cout << "Ошибка: некорректный формат!\n";
            pause_screen();
            continue;
        }

        result = new char[strlen(buffer) + 1];
        strcpy(result, buffer);
        break;
    }

    return result;    
}

double get_valid_allowance() {
    double allowance;
    clean_screen();
    while (true) {
        std::cout << "Введите суточные (0.0 - 100000.0): ";
        if (!(std::cin >> allowance)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            clean_screen();
            std::cout << "Ошибка: введите число!\n";
            pause_screen();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (is_valid_allowance(allowance)) {
            break;
        }

        clean_screen();
        std::cout << "Ошибка: суточные должны быть от 0.0 до 100000.0!\n";
        pause_screen();
    }
    return allowance;
}