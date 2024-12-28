#include "deck.h"
// #include "card.h" if problem occurs, uncomment 12/14

#include <iostream>
#include <random>

using std::string;



Deck::Deck(): suits{"Spades", "Clubs", "Hearts", "Diamonds"}, ranks{"A","2","3","4","5","6","7","8","9","10","J","Q","K"}, headCard(nullptr), tailCard(nullptr) {

    Card* currCard = nullptr;
    
    Card* prevCard = nullptr;
    
    for (const std::string &suit : suits){
        for(const std::string &rank: ranks){
            
            currCard = new Card(rank, suit); 

            if (prevCard == nullptr){
                headCard = currCard;
            }
            else{
                currCard->prev = prevCard;
                prevCard->next = currCard;
            }

            prevCard = currCard;

        }
    }

    tailCard = currCard;
    
    
    prevCard->next = headCard;
    headCard->prev = currCard;

    numCardsDeck = 52;


}


Deck::~Deck(){


    while (headCard != tailCard){
        Card* next = headCard->next;
        delete headCard;
        headCard = next;
    }

    numCardsDeck = 0;


}

void Deck::printDeck(){

    Card* currCard = headCard;

    while (currCard != tailCard){
        std::cout << currCard->getRank() << " of " << currCard->getSuit() << std::endl;
        currCard = currCard->next;
    }

}

// should probably move draw card to the dealer class
Card* Deck::drawCard(){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(1,numCardsDeck); // range from 1 to 52
    int randomCard = dist(gen);

    std::cout << randomCard << std::endl;

    Card* currCard = headCard;

    for (int i = 1; i < randomCard; i++){  // double check indexing
        currCard = currCard->next;
    }

    currCard->prev->next = currCard->next;

    currCard->next->prev = currCard->prev;

    currCard->prev = nullptr;
    currCard->next = nullptr;  // prevent poining to the deck

    std::cout << currCard->getRank() << " of " << currCard->getSuit() << std::endl;
    
    return currCard;
}