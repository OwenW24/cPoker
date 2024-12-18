# ifndef _CARD_H
# define _CARD_H

#include<string>
#include<vector>

class Card{
    private:
        std::string rank; 
        std::string suit;

        Card* prev;
        Card* next;

        int timesPlayed;
    public:
        Card(const std::string &rank, const std::string &suit);
        std::string getRank();
        std::string getSuit();

    friend class Deck;  //this will allow access to Card's private members from the Deck class
    friend class Dealer;
};
# endif