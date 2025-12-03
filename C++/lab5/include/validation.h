#pragma once

bool is_valid_full_name(const char* full_name);

bool is_valid_date(const char* date);

bool is_valid_allowance(double allowance);

char* get_string(const char* prompt, bool (*validator)(const char*) = nullptr);

double get_valid_allowance();