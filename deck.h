# ifndef _DECK_H
# define _DECK_H

#include<string>
#include "card.h"

class Deck{
    private:
        std::string suits[4];
        std::string ranks[13];
        int numCardsDeck;
        Card* headCard;
        Card* tailCard;
    public:
        Deck();

        ~Deck();

        void printDeck();

        Card* drawCard();
    
    friend class Dealer;
};
# endif