#include <iostream>
#include "card.h"

Card::Card() 
{
	rank = 0;
	suit = 0;
}

Card::Card(int str_rank, int str_suit) 
{
	rank = str_rank;
	suit = str_suit;
}

Card::~Card() 
{
	//cout << "Card Destroyed" << endl;
}

int Card::get_rank() 
{
	return rank;
}

int Card::get_suit() 
{
	return suit;
}

string Card::get_string_rank() 
{
	switch (rank) 
	{
		case 0:
			return "Jack"; 
			break;
		case 1:
			return "Queen"; 
			break;
		case 2:
			return "2"; 
			break;
		case 3:
			return "3"; 
			break;
		case 4:
			return "4"; 
			break;
		case 5:
			return "5"; 
			break;
		case 6:
			return "6"; 
			break;
		case 7:
			return "7"; 
			break;
		case 8:
			return "8";
			break;
		case 9:
			return "9"; 
			break;
		case 10:
			return "10"; 
			break;
		case 11:
			return "King"; 
			break;
		case 12:
			return "Ace";
			break;
	}
}

string Card::get_string_suit() 
{
	switch (suit) 
	{
		case 0:
			return "Clubs"; 
			break;
		case 1:
			return "Diamonds"; 
			break;
		case 2:
			return "Hearts"; 
			break;
		case 3:
			return "Spades";
			break;
	}
}

void Card::set_rank(int new_rank) 
{
	rank = new_rank;
}

void Card::set_suit(int new_suit) 
{
	suit = new_suit;
}

void Card::reset_card() 
{
	rank = -1;
	suit = -1;
}

bool Card::is_valid_card() 
{
	return !(rank == -1 || suit == -1);
}