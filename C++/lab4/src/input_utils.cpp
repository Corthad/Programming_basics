#include <iostream>
#include <limits>

#include "input_utils.h"
#include "screen_utils.h"

int save_int_input(const std::string& message, int min_value, int max_value) {
    int value;
    while (true) {
        clear_screen();
        std::cout << message;
        if (std::cin >> value) {
            if (value >= min_value && value <= max_value) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                clear_screen();
                return value;
            }
            else {
                std::cout << "Введенное значение находится вне диапазона выбора. Введите значение из диапазона от " << min_value << " до " << max_value << ".\n";
                pause_screen();
            }
        }
        else {
            std::cout << "Введен некорректный тип данных или введенное значение находится вне диапазона этого типа.\n";
            pause_screen();
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }    
}

double save_double_input(const std::string& message, double min_value, double max_value) {
    double value;
    while (true) {
        clear_screen();
        std::cout << message;
        if (std::cin >> value) {
            if (value >= min_value && value <= max_value) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                clear_screen();
                return value;
            }
            else {
                std::cout << "Введенное значение находится вне диапазона выбора. Введите значение из диапазона от " << min_value << " до " << max_value << ".\n";
                pause_screen();
            }
        }
        else {
            std::cout << "Введен некорректный тип данных или введенное значение находится вне диапазона этого типа.\n";
            pause_screen();
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }    
}