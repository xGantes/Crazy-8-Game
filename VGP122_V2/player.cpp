#include <cstdlib>
#include <iostream>
#include <string>
#include "card.h"
#include "hand.h"
#include "player.h"
#include <time.h>

using namespace std;

Player::Player() 
{
	hand = Hand();
	name = "";
}

Player::Player(const Hand & str_hand, string str_name)
{
	hand = str_hand;
	name = str_name;
}

Player::~Player()
{
	// cout << "Player destroyed" << endl;
}

Hand& Player::get_hand() 
{
	return hand;
}

string Player::get_name() 
{
	return name;
}

void Player::set_hand(const Hand& new_hand)
{
	hand = new_hand;
}

void Player::set_name(string new_name) 
{
	name = new_name;
}

void Player::add_card(Card & new_card) 
{
	hand.add_card(new_card);
}

void Player::remove_card(int rank, int suit) 
{
	hand.remove_card(rank, suit);
}

bool Player::check_hand(int rank, int suit) 
{
	Card* & cards = hand.get_cards();
	for (int i = 0; i < hand.get_num_cards(); i++) 
	{
		if (cards[i].get_rank() == rank || cards[i].get_suit() == suit)
			return true;
	}
	return false;
}

int Player::ask_suit() 
{
	srand(time(NULL));
	string suit;
	cout << "Since " << name << " played an eight, " << name << " may now choose a suit that the following player must play." << endl;
	if (name == "You") 
	{
		while (suit != "1" && suit != "2" && suit != "3" && suit != "4") 
		{
			cout << "Select one of the following: (1) Club, (2) Diamond, (3) Heart, (4) Spade: ";
			getline(cin, suit);
		}
	}
	else if (name == "Computer") 
	{
		int suit_num = (rand() % 4);
		switch (suit_num) 
		{
			case 0:
				cout << "Computer selected Clubs" << endl; break;
			case 1:
				cout << "Computer selected Diamond" << endl; break;
			case 2:
				cout << "Computer selected Heart" << endl; break;
			case 3:
				cout << "Computer selected Spade" << endl;
		}
		return suit_num;
	}
	//return suit;
	return atoi(suit.c_str()) - 1;
}