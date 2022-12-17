#ifndef CHESS_HEADERS_MATRIX_H_
#define CHESS_HEADERS_MATRIX_H_

#include <vector>
#include <string>

namespace Matrix {
	std::vector<std::vector<std::pair<std::string, int>>> rotate_clockwise(const std::vector<std::vector<std::pair<std::string, int>>>& matrix);

	void print(const std::vector<std::vector<std::pair<std::string, int>>>& matrix); 

	const std::string& stringify(const std::vector<std::vector<std::pair<std::string, int>>>& matrix); 
};

#endif
