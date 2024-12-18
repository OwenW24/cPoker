#include <iostream>
#include "deck.h"
#include "card.h"
#include "dealer.h"

int main(){

    Deck deck;
    Dealer Owen;

    std::cout << std::endl;

    Owen.flop(deck); //testing da flop

    std::cout << std::endl;

    std::cout << std::endl;

    deck.printDeck();
    
    return 0;
}