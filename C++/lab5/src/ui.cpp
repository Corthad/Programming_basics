#include <iostream>
#include <windows.h>

#include "ui.h"

void clean_screen() {
    std::cout << "\033c";
}

void pause_screen() {
    system("pause");
    clean_screen();
}

void display_menu() {
    clean_screen();
    std::cout << "------РЕЕСТР КОМАНДИРОВОК------\n";
    std::cout << "1. Добавить командировку\n";
    std::cout << "2. Просмотреть все\n";
    std::cout << "3. Найти по ФИО\n";
    std::cout << "4. Сортировка по ФИО (А-Я)\n";
    std::cout << "5. Инвертировать список\n";
    std::cout << "6. Статистика по местам назначения\n";
    std::cout << "0. Выход\n";
    std::cout << "Выберите действие: ";
}