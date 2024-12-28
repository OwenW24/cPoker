# ifndef _DEALER_H
# define _DEALER_H

#include<string>
#include<vector>
#include "deck.h"


class Dealer{
    private:
        Card* dealtHead;
        Card* dealtTail;
    public:
        Dealer();
        ~Dealer();

        void burn(Deck deck);
        void deal(Deck deck);
        void flop(Deck deck);
        void turn(Deck deck);
        void river(Deck deck);
        

        

    


};


# endif