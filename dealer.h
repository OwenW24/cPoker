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
        void flop(Deck deck);
        

    


};


# endif