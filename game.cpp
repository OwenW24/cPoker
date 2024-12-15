#include <iostream>
#include "deck.h"
#include "card.h"

int main(){

    Deck deck;

    std::cout << std::endl;

    deck.printDeck();
    
    std::cout << std::endl;

    deck.drawCard();

    std::cout << std::endl;

    deck.printDeck();
    
    return 0;
}