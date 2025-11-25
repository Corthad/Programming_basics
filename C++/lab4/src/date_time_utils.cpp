#include "date_time_utils.h"

#include <chrono>
#include <format>

std::string get_current_date_time() {
    auto now = std::chrono::system_clock::now();
    std::string time_str = std::format("{:%Y-%m-%d %H:%M:%S}", now);
    return time_str;
}