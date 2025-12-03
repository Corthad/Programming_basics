#pragma once

struct Trip {
    char* full_name;
    char* departure_date;
    char* return_date;
    char* destination;
    char* purpose;
    double daily_allowance;
    Trip* next;
};

struct Destination_stat {
    char* destination;
    int count;
    Destination_stat* next;
};

Trip* add_trip(Trip* head);

void print_trips(Trip* head);

void search_by_full_name(Trip* head);

Trip* bubble_sort_by_full_name(Trip* head);

Trip* reverse_list(Trip* head);

void print_destination_stats(Trip* head);

void delete_list(Trip* head);

bool compare_dates(const char* date1, const char* date2);

int russian_strcmp_1251(const char* s1, const char* s2);