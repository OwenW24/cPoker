#include "dealer.h"
#include <iostream>

Dealer::Dealer() : dealtHead(nullptr), dealtTail(nullptr) {}

Dealer::~Dealer()
{
    // If there are no cards dealt, nothing to delete.
    if (!dealtHead) return;

    // Since we have a circular list, we continue until we've deleted the tail.
    Card* current = dealtHead;
    while (true) {
        Card* next = current->next;
        delete current;
        if (current == dealtTail) {
            break;
        }
        current = next;
    }
}

void Dealer::burn(Deck deck)
{
    std::cout << "Burning top card..." << std::endl;
    Card* burntCard = deck.drawCard();
    // The dealer discards it, so just delete the card
    delete burntCard;
}

void Dealer::flop(Deck deck)
{
    // Burn the top card first
    std::cout << "Top card burnt*" << std::endl;
    deck.drawCard(); // This is the "burn"

    // Draw the flop (3 cards)
    std::cout << "Dealing the flop*" << std::endl;

    // Draw the first card of the flop
    Card* firstFlopCard = deck.drawCard();
    dealtHead = firstFlopCard;
    Card* prevCard = firstFlopCard;

    std::cout << firstFlopCard->getRank() << " of " << firstFlopCard->getSuit() << std::endl;

    // Draw the remaining two cards of the flop
    for (int i = 0; i < 2; i++) {
        Card* nextCard = deck.drawCard();
        nextCard->prev = prevCard;
        prevCard->next = nextCard;

        std::cout << nextCard->getRank() << " of " << nextCard->getSuit() << std::endl;

        prevCard = nextCard;
    }

    // `prevCard` now points to the last of the three flop cards
    dealtTail = prevCard;

    // Make it circular
    dealtHead->prev = dealtTail;
    dealtTail->next = dealtHead;
}