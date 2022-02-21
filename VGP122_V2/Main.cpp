#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

#define DECK_SIZE 52

using namespace std;

int main() 
{
	string play_again = "1";
	while (play_again == "1") 
	{
		Game game = Game();
		game.deal_cards();
		game.game_status();
		do 
		{
			game.start_turn();
			game.game_status();
		} 
		while (!game.game_over());

		do 
		{
			cout << "Enter 1 to play again or 0 to exit the program: ";
			getline(cin, play_again);
		} 
		while (play_again != "1" && play_again != "0");
	}
	return 0;
}

