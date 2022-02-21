#ifndef HAND_H
#define HAND_H

#include "card.h"

using namespace std;

class Hand 
{
	private:
		Card * cards;
		int num_cards;

	public:
		Hand();
		Hand(Card* & str_cards, int str_num_cards);
		~Hand();

		Card*& get_cards();

		void set_cards(const Card*& new_cards),
			 set_num_cards(int new_num_cards),
			 add_card(Card& new_card),
			 remove_card(int rank, int suit),
			 print_hand();

		int get_suit(int index),
			get_rank(int index),
			get_num_cards();
};

#endif