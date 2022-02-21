#include <iostream>
#include <cstdlib>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "game.h"

#define DECK_SIZE 52

Game::Game() 
{
	cards = Deck();
	cards.fill_cards();
	cards.shuffle_cards();

	flip_card();

	players[0] = Player(Hand(), "You");
	players[1] = Player(Hand(), "Computer");
	player_turn = 0;
}

Game::Game(const Deck & str_cards, const Player(&str_players)[2]) 
{
	cards = str_cards;
	players[0] = str_players[0];
	players[1] = str_players[1];
}

Game::~Game() 
{
	cout << "Game over" << endl;
};

Deck & Game::get_cards() 
{
	return cards;
}

Player * Game::get_players() 
{
	return players;
}

Card & Game::get_faceup_card() 
{
	return faceup_card;
}

int Game::get_player_turn() 
{
	return player_turn;
}

void Game::set_cards(const Deck& new_cards) 
{
	cards = new_cards;
}

void Game::set_players(const Player(&new_players)[2]) 
{
	players[0] = new_players[0];
	players[1] = new_players[1];
}

void Game::set_faceup_card(Card& new_faceup_card) 
{
	faceup_card.set_rank(new_faceup_card.get_rank());
	faceup_card.set_suit(new_faceup_card.get_suit());
}

bool Game::game_over() 
{
	int deck_cards_left = cards.get_num_cards();
	int player0_cards = players[0].get_hand().get_num_cards();
	int player1_cards = players[1].get_hand().get_num_cards();
	if (deck_cards_left == 0) 
	{
		if (player1_cards > player0_cards)
			cout << "You Win!" << endl;
		else if (player1_cards < player0_cards)
			cout << "You Lose!" << endl;
		else
			cout << "Game Draw!" << endl;
		return true;
	}
	else if (player0_cards == 0) {
		cout << "You Win!" << endl;
		return true;
	}
	else if (player1_cards == 0) {
		cout << "You Lose!" << endl;
		return true;
	}
	else
		return false;
}

void Game::game_status() 
{
	cout << endl << "Cards left in deck: " << cards.get_num_cards() << endl;
	string faceup_rank = "";
	if (faceup_card.get_rank() == -1)
		faceup_rank = "any";
	else
		faceup_rank = faceup_card.get_string_rank();
	cout << "Card on top of stockpile: Rank: " << faceup_rank << ", Suit: " << faceup_card.get_string_suit() << endl;
	if (player_turn == 0) 
	{
		Hand& player_hand = players[0].get_hand();
		player_hand.print_hand();
	}
	else if (player_turn == 1) 
	{
		cout << endl << "Computer has " << players[1].get_hand().get_num_cards() << " cards left" << endl;
	}
}

void Game::flip_card() 
{
	Card* deck = cards.get_cards();
	for (int i = 0; i < DECK_SIZE; i++) 
	{
		if (deck[i].is_valid_card()) 
		{
			faceup_card = deck[i];
			deck[i].reset_card();
			break;
		}
	}
}

void Game::deal_cards() 
{
	Hand & human_hand = players[0].get_hand();
	cards.deal_card(human_hand, 7);
	cout << endl << "Dealt 7 cards to human" << endl;
	Hand & computer_hand = players[1].get_hand();
	cards.deal_card(computer_hand, 7);
	cout << "Dealt 7 cards to computer" << endl;
}

void Game::start_turn() 
{
	string card_string = "";
	int card_num = 0;
	if (!players[player_turn].check_hand(faceup_card.get_rank(), faceup_card.get_suit())) 
	{
		string player = (player_turn == 0 ? "you" : "computer");
		cout << "No possible cards in hand, " << player << " draw one card." << endl;
		Hand& hand = players[player_turn].get_hand();
		cards.deal_card(hand, 1);
	}
	else 
	{
		if (player_turn == 0)
			card_num = get_card_num();
		else
			card_num = get_random_card_num();
		place_card(card_num);
	}
	end_turn();
}

int Game::get_card_num() 
{
	string card_string = "";
	int card_num = 0;
	while (true) 
	{
		cout << "Enter the number for the card you want to place: ";
		getline(cin, card_string);
		card_num = atoi(card_string.c_str()) - 1;
		if (!card_is_valid(card_num))
			cout << "Invalid card number. Please enter a card with either rank " << faceup_card.get_string_rank() << " or suit " << faceup_card.get_string_suit() << endl;
		else
			break;
	}
	return card_num;
}

int Game::get_random_card_num() 
{
	int card_num = 0;
	while (true) 
	{
		if (card_is_valid(card_num))
		return card_num;
		card_num++;
	}
}

bool Game::card_is_valid(int card_num) 
{
	Hand & hand = players[player_turn].get_hand();
	if (card_num < 0 || card_num >(hand.get_num_cards() - 1))
		return false;

	int rank = faceup_card.get_rank();
	int suit = faceup_card.get_suit();

	int card_rank = hand.get_rank(card_num);
	int card_suit = hand.get_suit(card_num);

	if (rank == card_rank || suit == card_suit)
		return true;
	else
		return false;
}

void Game::end_turn() 
{
	if (player_turn == 0)
		player_turn = 1;
	else
		player_turn = 0;
}

void Game::place_card(int card_num) 
{
	Hand& hand = players[player_turn].get_hand();
	Card*& cards = hand.get_cards();

	int rank = cards[card_num].get_rank();
	int suit = cards[card_num].get_suit();

	string player = (player_turn == 0 ? "You" : "Computer");
	cout << player << " placed card with Rank " << cards[card_num].get_string_rank() << " and Suit " << cards[card_num].get_string_suit() << endl;
	
	faceup_card.set_rank(rank);
	faceup_card.set_suit(suit);
	hand.remove_card(rank, suit);
	
	if (rank == 8) 
	{
		int next_suit = players[player_turn].ask_suit();
		faceup_card.set_rank(-1);
		faceup_card.set_suit(next_suit);
	}
}