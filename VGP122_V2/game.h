#include "card.h"

class Game 
{
	private:
		Deck cards;
		Card faceup_card;
		Player players[2];
		int player_turn;

	public:
		Game();
		Game(const Deck & str_cards, const Player(&str_players)[2]);
		~Game();

		Deck& get_cards();
		Player* get_players();
		Card& get_faceup_card();

		int get_player_turn(),
			get_card_num(),
			get_random_card_num();

		bool game_over(),
			 card_is_valid(int card_num);

		void flip_card(), 
			 deal_cards(), 
			 start_turn(), 
			 game_status(), 
			 end_turn(),
			 set_cards(const Deck& new_cards),
			 set_players(const Player(&new_players)[2]),
			 set_faceup_card(Card& new_faceup_card),
			 place_card(int card_num);
};