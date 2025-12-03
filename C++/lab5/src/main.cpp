#include <iostream>
#include <limits>
#include <windows.h>

#include "ui.h"
#include "trip.h"

int main() {
    SetConsoleCP(1251);    
    SetConsoleOutputCP(1251);

    
    Trip* head = nullptr;
    int choice;

    do {
        display_menu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода! Введите число от 0 до 6.\n";
            pause_screen();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                head = add_trip(head);
                break;
            case 2:
                print_trips(head);
                break;
            case 3:
                search_by_full_name(head);
                break;
            case 4:
                head = bubble_sort_by_full_name(head);
                break;
            case 5:
                head = reverse_list(head);
                break;
            case 6:
                print_destination_stats(head);
                break;
            case 0:
                clean_screen();
                std::cout << "Завершение программы...\n";
                std::cout << "Очистка памяти...\n";
                delete_list(head);
                std::cout << "Программа завершена.\n";
                break;
            default:
                std::cout << "Неверный выбор! Попробуйте снова.\n";
                pause_screen();
        }
    } while (choice != 0);
    
    return 0;
}