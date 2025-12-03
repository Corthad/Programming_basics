#include <iostream>
#include <cstring>
#include <iomanip>

#include "trip.h"
#include "validation.h"
#include "ui.h"

Trip* add_trip(Trip* head) {
    Trip* new_trip = new Trip;
    new_trip->full_name = get_string("ФИО (5-60 символов): ", is_valid_full_name);
    new_trip->departure_date = get_string("Дата выезда (ДД.ММ.ГГГГ): ", is_valid_date);
    new_trip->return_date = get_string("Дата возвращения (ДД.ММ.ГГГГ): ", is_valid_date);
    
    if (!(compare_dates(new_trip->departure_date, new_trip->return_date))) {
        clean_screen();
        std::cout << "Ошибка: дата возвращения не может быть раньше даты выезда или совпадать c ней!\n";
        pause_screen();
        delete[] new_trip->full_name;
        delete[] new_trip->departure_date;
        delete[] new_trip->return_date;
        delete[] new_trip->destination;
        delete[] new_trip->purpose;
        delete new_trip;
        return head;
    }

    new_trip->destination = get_string("Место назначения: ");
    new_trip->purpose = get_string("Цель поездки: ");
    new_trip->daily_allowance = get_valid_allowance();

    new_trip->next = head;
    head = new_trip;

    clean_screen();
    std::cout << "Командировка успешно добавлена!\n";
    pause_screen();
    return head;
}

void print_trips(Trip* head) {
    clean_screen();
    std::cout << "Список всех командировок\n";

    if (!head) {
        clean_screen();
        std::cout << "Список пуст.\n";
        pause_screen();
        return;
    }

    const short col0 = 5;
    const short col1 = 60;
    const short col2 = 20;
    const short col3 = 20;
    const short col4 = 20; // Уточнить размер
    const short col5 = 20; // Уточнить размер
    const short col6 = 10;


    std::cout   << std::left 
                << std::setw(col0) << "№"
                << std::setw(col1) << "Фамилия Имя Отчество"
                << std::setw(col2) << "Дата выезда"
                << std::setw(col3) << "Дата возвращения"
                << std::setw(col4) << "Место назначения"
                << std::setw(col5) << "Цель поездки"
                << std::setw(col6) << "Суточные"
                << '\n';
    std::cout << std::string(col0 + col1 + col2 + col3 + col4 + col5, '-') << '\n';
    
    Trip* current = head;
    int counter = 0;
    while (current) {
            counter++;
            std::cout   << std::left 
                        << std::setw(col0) << counter
                        << std::setw(col1) << current->full_name
                        << std::setw(col2) << current->departure_date
                        << std::setw(col3) << current->return_date
                        << std::setw(col4) << current->destination
                        << std::setw(col5) << current->purpose
                        << std::setw(col6) << current->daily_allowance
                        << '\n';
            current = current->next;
    }
    std::cout << std::string(col0 + col1 + col2 + col3 + col4 + col5, '-') << '\n';
    std::cout << "Всего записей в списке: " << counter << '\n';
    pause_screen();
}

void search_by_full_name(Trip* head) {
    clean_screen();
    if (!head) {
        std::cout << "Список пуст!\n";
        pause_screen();
        return;
    }

    char* full_name = get_string("Введите ФИО для поиска (5-60 символов): ", is_valid_full_name);
    
    Trip* current = head;
    int comparisons = 0;
    int found_count = 0;

    std::cout << "Поиск по следующему ФИО: " << full_name << '\n';

    const short col0 = 5;
    const short col1 = 70;
    const short col2 = 20;
    const short col3 = 20;
    const short col4 = 30; // Уточнить размер
    const short col5 = 30; // Уточнить размер
    const short col6 = 10;

    std::cout << std::string(col0 + col1 + col2 + col3 + col4 + col5, '-') << '\n';
    
    while (current) {
            comparisons++;
            if (strcmp(current->full_name, full_name) == 0) {
                if (found_count == 0) {
                        std::cout   << std::left 
                                    << std::setw(col0) << "№"
                                    << std::setw(col1) << "Фамилия Имя Отчество"
                                    << std::setw(col2) << "Дата выезда"
                                    << std::setw(col3) << "Дата возвращения"
                                    << std::setw(col4) << "Место назначения"
                                    << std::setw(col5) << "Цель поездки"
                                    << std::setw(col6) << "Суточные"
                                    << '\n';
                }
            
                std::cout   << std::left 
                            << std::setw(col0) << ++found_count
                            << std::setw(col1) << current->full_name
                            << std::setw(col2) << current->departure_date
                            << std::setw(col3) << current->return_date
                            << std::setw(col4) << current->destination
                            << std::setw(col5) << current->purpose
                            << std::setw(col6) << current->daily_allowance
                            << '\n';
            }

            current = current->next;
    }

    std::cout << std::string(col0 + col1 + col2 + col3 + col4 + col5, '-') << '\n';
    if (found_count > 0) {
        std::cout << "Найдено записей: " << found_count << '\n';
    }
    else {
        std::cout << "Записи с данным ФИО в списке не найдены.\n";
    }

    std::cout << "Выполнено сравнений: " << comparisons << '\n';
    pause_screen();

    delete[] full_name;
}

Trip* bubble_sort_by_full_name(Trip* head) {
    if (!head || !head->next) {
        return head;
    }

    bool swapped;
    Trip* newHead = nullptr;
    Trip* last = nullptr;
    
    do {
        swapped = false;
        Trip* current = head;
        Trip* prev = nullptr;
        
        while (current && current->next) {
            //if (strcmp(current->full_name, current->next->full_name) > 0) {
            if (russian_strcmp_1251(current->full_name, current->next->full_name) > 0) {
                
                // Меняем current и current->next местами
                Trip* nextNode = current->next;
                current->next = nextNode->next;
                nextNode->next = current;
                
                if (prev) {
                    prev->next = nextNode;
                } else {
                    head = nextNode;
                }
                
                prev = nextNode;
                swapped = true;
            } 
            else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
    
    return head;
}

Trip* reverse_list(Trip* head) {
    clean_screen();
    // Проверка условия "элементов больше 2-х"
    if (!head || !head->next) {
        return head;
    }

    Trip* prev = nullptr;
    Trip* current = head;
    Trip* next = nullptr;

    while (current) {
        next = current->next; // Запоминаем следующий элемент
        current->next = prev; // Разворачиваем указатель
        prev = current;
        current = next;
    }
    
    std::cout << "Список инвертирован.\n";
    pause_screen();
    return prev;
}

void print_destination_stats(Trip* head) {
    clean_screen();
    if(!head) {
        std::cout << "Список пуст!\n";
        pause_screen();
        return;
    }

    std::cout << "Статистика по местам назначения\n";
    
    Destination_stat* stats_head = nullptr;
    Trip* current = head;

    while (current) {
        Destination_stat* stat = stats_head;
        Destination_stat* prev = nullptr;

        while (stat) {
            if (strcmp(stat->destination, current->destination) == 0) {
                stat->count++;
                break;
            }
            prev = stat;
            stat = stat->next;
        }

        if (!stat) {
            Destination_stat* new_stat = new Destination_stat;
            new_stat->destination = new char[strlen(current->destination) + 1];
            strcpy(new_stat->destination, current->destination);
            new_stat->count = 1;
            new_stat->next = stats_head;
            stats_head = new_stat;
        }

        current = current->next;
    }

    const short col0 = 5;
    const short col1 = 20;
    const short col2 = 5;

    std::cout   << std::left 
                << std::setw(col0) << "№"
                << std::setw(col1) << "Место назначения"
                << std::setw(col2) << "Кол-во"
                << '\n';

    std::cout << std::string(col0 + col1 + col2, '-') << '\n';
    
    Destination_stat* stat = stats_head;
    short count = 0;
    while (stat) {
        count++;
        std::cout   << std::left 
                    << std::setw(col0) << count
                    << std::setw(col1) << stat->destination
                    << std::setw(col2) << stat->count
                    << '\n';
        stat = stat->next;
    }
    pause_screen();

    while (stats_head) {
        Destination_stat* temp = stats_head;
        stats_head = stats_head->next;
        delete[] temp->destination;
        delete temp;
    }
}

void delete_list(Trip* head) {
    Trip* current = head;
    while (current) {
        Trip* next = current->next;
        delete[] current->full_name;
        delete[] current->departure_date;
        delete[] current->return_date;
        delete[] current->destination;
        delete[] current->purpose;
        delete current;
        current = next;
    }
}

bool compare_dates(const char* date1, const char* date2) {
    
    short year1 = atoi(date1 + 6);
    short year2 = atoi(date2 + 6);
    if (year1 != year2) {
        return (year1 < year2); 
    }

    short month1 = atoi(date1 + 3);
    short month2 = atoi(date2 + 3);
    if (month1 != month2) {
        return (month1 < month2);
    }

    short day1 = atoi(date1);
    short day2 = atoi(date2);
    return (day1 < day2);
}

int russian_strcmp_1251(const char* s1, const char* s2) {
    
    while (*s1 && *s2) {
        unsigned char c1 = (unsigned char)*s1;
        unsigned char c2 = (unsigned char)*s2;
        
        if (c1 == 'ё') c1 = 'е';
        if (c2 == 'ё') c2 = 'е';
        
        if (c1 == 'Ё') c1 = 'Е';
        if (c2 == 'Ё') c2 = 'Е';
        
        if (c1 != c2) {
            return c1 - c2;
        }
        
        s1++;
        s2++;
    }
    
    return (unsigned char)*s1 - (unsigned char)*s2;
}