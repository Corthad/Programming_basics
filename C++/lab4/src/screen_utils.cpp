#include <iostream>

#include "screen_utils.h"

void clear_screen() {
    std::cout << "\033c";
}

void pause_screen() {
    system("pause");
    clear_screen();
}