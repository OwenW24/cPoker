#include "card.h"
using std::string;

Card::Card(const std::string &rank,const std::string &suit): rank(rank), suit(suit), prev(nullptr), next(nullptr){
}
        
std::string Card::getRank(){
    return rank;
}
std::string Card::getSuit(){
    return suit;
}
