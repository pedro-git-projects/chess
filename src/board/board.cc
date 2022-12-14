#include <board.h>
#include <utility>
#include <vector>
#include <iostream>

// TODO: Rotate vector
Board::Board() : 
	positions_vector() 
{
	std::vector<std::vector<std::pair<std::string, int>>> pv(8,std::vector<std::pair<std::string, int>>(8));
	for(int i = 0; i < pv.size(); i++) {
		for(int j = 0; j < pv.size(); j++) {
			pv[i][j].first = "b";
			pv[i][j].second = i + 1;
			std::cout << pv[i][j].first << pv[i][j].second << " ";
		}
		std::cout << std::endl;
	}
}



