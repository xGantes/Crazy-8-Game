#include "card.h"
#include "hand.h"

#define DECK_SIZE 52

using namespace std;

class Deck 
{
	private:
		Card cards[DECK_SIZE];
		int num_cards;

	public:
		Deck();
		Deck(const Card(&str_cards)[DECK_SIZE]);
		~Deck();

		Card* get_cards();
		int get_num_cards();

		void set_cards(const Card* & new_cards),
			 set_num_cards(int num_cards),
			 print_cards(),
			 deal_card(Hand & hand, int num_cards),
			 fill_cards(),
			 shuffle_cards(),
			 swap_cards(Card* a, Card* b);
};
