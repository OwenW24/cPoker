#include "dealer.h"
#include <iostream>


Dealer::Dealer(): dealtHead(nullptr), dealtTail(nullptr){};


Dealer::~Dealer(){

    while (dealtHead != dealtTail){
        Card* next = dealtHead->next;
        delete dealtHead;
        dealtHead = next;
    }

}


void Dealer::burn(Deck deck){
    deck.drawCard(); // burner
}


void Dealer::flop(Deck deck){
    
    
    burn(deck);

    std::cout << "da flop*" << std::endl;

    Card* card1 = deck.drawCard();
    dealtHead = card1;
    Card* prevCard = card1;
    
    std::cout << card1->getRank() << " of " << card1->getSuit() << std::endl;

    for (int i = 0; i < 2; i++){
        
        card1 = deck.drawCard();
        card1->prev = prevCard;
        prevCard->next = card1;
        std::cout << card1->getRank() << " of " << card1->getSuit() << std::endl;
    }

    dealtTail = card1;
    dealtHead->prev = dealtTail;
    dealtTail->next = dealtHead;
}

