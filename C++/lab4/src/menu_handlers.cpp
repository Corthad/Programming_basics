#include <iostream>

#include "menu_handlers.h"
#include "card_operations.h"
#include "transaction_operations.h"
#include "input_utils.h"
#include "screen_utils.h"
#include "file_operations.h"

void card_management_menu(Card& card, std::vector<Card>& all_cards) {
    int activity_action;
    int type_operation;    
    bool exit_to_main_menu = false;
    do {
        activity_action = save_int_input(CARD_MENU, 0, 9);
        switch (activity_action) {
            case 0:
                exit_to_main_menu = true;
                break;
            case 1:
                change_pin(card);                
                break;
            case 2:
                clear_screen();
                std::cout << view_balance(card);
                pause_screen();
                break;
            case 3:
                edit_balance(card, 1);
                break;
            case 4:
                edit_balance(card, 0);
                break;
            case 5:
                convert_money(card);
                break;
            case 6:
                transfer_money_with_conversion(card, all_cards);
                break;
            case 7:
                type_operation = save_int_input(CHANGE_TYPE_OPERATION, 0, 5);
                view_transaction_history(card, type_operation);
                break;
            case 8:
                show_complete_analytics(card);
                break;
            case 9:
                clear_screen();
                std::cout << view_cash();
                pause_screen();
                break;
        }
        save_data(all_cards);
    } while (!exit_to_main_menu);                        
}