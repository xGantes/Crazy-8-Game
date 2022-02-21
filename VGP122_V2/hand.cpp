#include <iostream>
#include "card.h"
#include "hand.h"

Hand::Hand() 
{
	cards = NULL;
	num_cards = 0;
}

Hand::Hand(Card* & str_cards, int str_num_cards)
{
	cards = new Card[str_num_cards];
	for (int i = 0; i < str_num_cards; i++) 
	{
		cards[i].set_rank(str_cards[i].get_rank());
		cards[i].set_suit(str_cards[i].get_suit());
	}
	num_cards = str_num_cards;
}

Hand::~Hand() 
{
	//cout << "Hand destroyed" << endl;
	Card** cards_str = &cards;
	//Card* cards_ptr = &cards;
	delete[] * cards_str;
	*cards_str = NULL;
}

Card* & Hand::get_cards() 
{
	return cards;
}

int Hand::get_num_cards()
{
	return num_cards;
}

void Hand::set_num_cards(int new_num_cards)
{
	num_cards = new_num_cards;
}

void Hand::set_cards(const Card*& new_cards) 
{
	for (int i = 0; i < num_cards; i++)
		cards[i] = new_cards[i];
}

void Hand::add_card(Card& new_card) 
{
	Card** cards_str = &cards;
	Card* new_cards = new Card[num_cards + 1];
	for (int i = 0; i < num_cards; i++) 
	{
		new_cards[i].set_rank((*cards_str)[i].get_rank());
		new_cards[i].set_suit((*cards_str)[i].get_suit());
	}

	new_cards[num_cards].set_rank(new_card.get_rank());
	new_cards[num_cards].set_suit(new_card.get_suit());
	delete[] * cards_str;
	*cards_str = NULL;
	*cards_str = new_cards;
	num_cards++;
}

void Hand::remove_card(int rank, int suit) 
{
	Card** cards_str = &cards;
	Card* new_cards = new Card[num_cards - 1];
	bool card_reset = false;
	for (int i = 0; i < num_cards; i++) 
	{
		if (cards[i].get_rank() == rank && cards[i].get_suit() == suit) 
		{
			cards[i].reset_card();
			card_reset = true;
			break;
		}
	}
	if (!card_reset) 
	{
		cout << "Card not found" << endl;
		return;
	}
	int cards_copied = 0;
	int card_index = 0;
	while (card_index < num_cards) 
	{
		if (cards[card_index].is_valid_card()) 
		{
			new_cards[cards_copied].set_rank((*cards_str)[card_index].get_rank());
			new_cards[cards_copied].set_suit((*cards_str)[card_index].get_suit());
			cards_copied++;
		}
		card_index++;
	}
	delete[] * cards_str;
	*cards_str = NULL;
	*cards_str = new_cards;
	num_cards--;
	//num_cards++;
}

int Hand::get_suit(int index) 
{
	return cards[index].get_suit();
}

int Hand::get_rank(int index) 
{
	return cards[index].get_rank();
}

void Hand::print_hand() 
{
	cout << endl << "Your hand: " << endl;
	cout << "Number of cards: " << num_cards << endl;

	for (int i = 0; i < num_cards; i++)
	cout << "(" << i + 1 << ") " << "Rank: " << cards[i].get_string_rank() << ",  " << "Suit: " << cards[i].get_string_suit() << endl;
	cout << endl;
}