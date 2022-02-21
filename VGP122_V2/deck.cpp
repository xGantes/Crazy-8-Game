#include <iostream>
#include <cstdlib>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include <time.h>

#define DECK_SIZE 52

Deck::Deck() 
{
	for (int i = 0; i < DECK_SIZE; i++) 
	{
		Card new_card = Card();
		cards[i] = new_card;
	}
	num_cards = DECK_SIZE;
}

Deck::Deck(const Card(&str_cards)[DECK_SIZE]) 
{
	for (int i = 0; i < DECK_SIZE; i++)
		cards[i] = str_cards[i];
		num_cards = DECK_SIZE;
}

Deck::~Deck() 
{
	//cout << "Deck destroyed" << endl;
}

Card* Deck::get_cards()
{
	return cards;
}

int Deck::get_num_cards() 
{
	return num_cards;
}

void Deck::set_cards(const Card*& new_cards) 
{
	for (int i = 0; i < DECK_SIZE; i++)
		cards[i] = new_cards[i];
}

void Deck::set_num_cards(int new_num_cards) 
{
	num_cards = new_num_cards;
}

void Deck::print_cards() 
{
	for (int i = 0; i < DECK_SIZE; i++)
		cout << cards[i].get_rank() << " " << cards[i].get_suit() << endl;
}

void Deck::deal_card(Hand& hand, int num_cards) 
{
	for (int i = 0; i < num_cards; i++) 
	{
		int card_index = 0;
		for (int i = 0; i < DECK_SIZE; i++) 
		{
			if (cards[i].is_valid_card()) 
			{
				card_index = i;
				break;
			}
		}
		hand.add_card(cards[card_index]);
		cards[card_index].reset_card();
		//num_cards++;
		num_cards--;
	}
}

void Deck::fill_cards() 
{
	for (int i = 0; i < 13; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			cards[(j * 13) + i].set_rank(i);
			cards[(j * 13) + i].set_suit(j);
		}
	}
	num_cards = DECK_SIZE;
}

void Deck::shuffle_cards() 
{
	srand(time(NULL));
	for (int i = DECK_SIZE - 1; i > 0; i--) 
	{
		int j = rand() % (i + 1);
		swap_cards(&cards[i], &cards[j]);
	}
}

void Deck::swap_cards(Card* a, Card* b) 
{
	Card temp = *a;
	*a = *b;
	*b = temp;
}