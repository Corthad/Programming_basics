#include <fstream>
#include <vector>

#include "file_operations.h"

bool load_data(std::vector<Card>& cards) {
    std::ifstream file("../data/bank_data.txt");
    if (!file.is_open()) {
        return false;
    }
    
    cards.clear();
    int card_count;
    file >> card_count;
    file.ignore();
    
    for (int i = 0; i < card_count; i++) {
        Card card;
        
        std::getline(file, card.number);
        std::getline(file, card.pin);
        file >> card.payment_system;
        file >> card.is_blocked;
        file >> card.pin_attempts;
        file >> card.balance[0] >> card.balance[1] >> card.balance[2];
        file.ignore();
        
        int trans_count;
        file >> trans_count;
        file.ignore();
        for (int j = 0; j < trans_count; j++) {
            Transaction temp_transaction;
            std::getline(file, temp_transaction.date_time);
            std::getline(file, temp_transaction.type);
            file >> temp_transaction.currency;
            file >> temp_transaction.amount;
            file >> temp_transaction.fee;
            file.ignore();
            card.transactions.push_back(temp_transaction);
        }
        
        cards.push_back(card);
    }
    
    file.close();
    return true;
}

bool save_data(const std::vector<Card>& cards) {
    std::ofstream file("../data/bank_data.txt");
    if (!file.is_open()) {
        return false;
    }
    
    const Card* card_ptr = cards.data();
    const Card* end_ptr = card_ptr + cards.size();
    
    file << cards.size() << "\n";
    
    while (card_ptr < end_ptr) {
        file << (*card_ptr).number << "\n";
        file << (*card_ptr).pin << "\n";
        file << (*card_ptr).payment_system << "\n";
        file << (*card_ptr).is_blocked << "\n";
        file << (*card_ptr).pin_attempts << "\n";
        file << (*card_ptr).balance[0] << " " << (*card_ptr).balance[1] << " " << (*card_ptr).balance[2] << "\n";
        
        const Transaction* trans_ptr = (*card_ptr).transactions.data();
        const Transaction* trans_end_ptr = trans_ptr + (*card_ptr).transactions.size();
        
        file << (*card_ptr).transactions.size() << "\n";
        while (trans_ptr < trans_end_ptr) {
            file << (*trans_ptr).date_time << "\n";
            file << (*trans_ptr).type << "\n";
            file << (*trans_ptr).currency << "\n";
            file << (*trans_ptr).amount << "\n";
            file << (*trans_ptr).fee << "\n";
            ++trans_ptr;
        }
        
        ++card_ptr;
    }
    
    file.close();
    return true;
}