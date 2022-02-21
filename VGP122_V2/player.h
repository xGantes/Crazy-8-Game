#include "card.h"
#include "hand.h"

using namespace std;

class Player 
{
	private:
		Hand hand;
		string name;

	public:
		Player();
		Player(const Hand & str_hand, string str_name);
		~Player();

		Hand & get_hand();
		string get_name();

		void set_hand(const Hand & new_hand),
			 set_name(string new_name),
			 add_card(Card & new_card),
			 remove_card(int rank, int suit);

		bool check_hand(int rank, int suit);
		int ask_suit();
};

