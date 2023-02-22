#include <iostream>
#include <deque>

int main()
{
	std::deque<int>	_first;
	std::deque<int>	_second;
	for (int i = 0; i < 5; i++) 
	{
		int x;
		std::cin >> x;
		_first.push_back(x);
	}
	for (int i = 0; i < 5; i++) 
	{
		int x;
		std::cin >> x;
		_second.push_back(x);
	}

	int	round = 0;
	for (; !_first.empty() && !_second.empty() && round < 1000000; round++)
	{
		int first_card = _first.front();
		_first.pop_front();
		int second_card = _second.front();
		_second.pop_front();
		if (first_card == 0 && second_card == 9) 
		{
			_first.push_back(first_card);
			_first.push_back(second_card);

		}
		else if (second_card == 0 && first_card == 9)
		{
			_second.push_back(first_card);
			_second.push_back(second_card);
		}
		else if (first_card > second_card)
		{
			_first.push_back(first_card);
			_first.push_back(second_card);
		}
		else
		{
			_second.push_back(first_card);
			_second.push_back(second_card);
		}
	}
	if (round == 1000000)
		std::cout << "botva";
	else if (_first.empty())
		std::cout << "second " << round;
	else
		std::cout << "first " << round;
	return 0;
}


// #include <iostream>
// #include <deque>

// using namespace std;

// int main() {
//     deque<int> first_player_cards, second_player_cards;
//     for (int i = 0; i < 5; i++) {
//         int card;
//         cin >> card;
//         first_player_cards.push_back(card);
//     }
//     for (int i = 0; i < 5; i++) {
//         int card;
//         cin >> card;
//         second_player_cards.push_back(card);
//     }
//     int turns = 0;
//     while (!first_player_cards.empty() && !second_player_cards.empty() && turns < 106) {
//         int first_card = first_player_cards.front();
//         first_player_cards.pop_front();
//         int second_card = second_player_cards.front();
//         second_player_cards.pop_front();
//         if (first_card == 0 && second_card == 9) {
//             first_player_cards.push_back(first_card);
//             first_player_cards.push_back(second_card);
//         } else if (second_card == 0 && first_card == 9) {
//             second_player_cards.push_back(second_card);
//             second_player_cards.push_back(first_card);
//         } else if (first_card > second_card) {
//             first_player_cards.push_back(first_card);
//             first_player_cards.push_back(second_card);
//         } else {
//             second_player_cards.push_back(second_card);
//             second_player_cards.push_back(first_card);
//         }
//         turns++;
//     }
//     if (turns == 106) {
//         cout << "botva";
//     } else if (first_player_cards.empty()) {
//         cout << "second " << turns;
//     } else {
//         cout << "first " << turns;
//     }
//     return 0;
// }
