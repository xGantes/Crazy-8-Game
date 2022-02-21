#ifndef CARD_H
#define CARD_H

using namespace std;

class Card 
{
	private:
		int rank;
		int suit;

	public:
		Card();
		Card(int str_rank, int str_suit);
		~Card();

		int get_rank(),
			get_suit();

		string get_string_rank(),
			   get_string_suit();

		void set_rank(int new_rank),
			 set_suit(int new_suit),
			 reset_card();

		bool is_valid_card();
};

#endif