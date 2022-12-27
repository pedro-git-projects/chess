#ifndef CHESS_HEADERS_MATRIX_H_
#define CHESS_HEADERS_MATRIX_H_

#include <utility>
#include <vector>
#include <string>

namespace Matrix {
	std::vector<std::vector<std::pair<std::string, int>>> rotate_clockwise(const std::vector<std::vector<std::pair<std::string, int>>>& matrix);
	void print(const std::vector<std::vector<std::pair<std::string, int>>>& matrix); 
	const std::string& stringify(const std::vector<std::vector<std::pair<std::string, int>>>& matrix); 
	bool find(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> target);
std::vector<std::pair<std::string, int>> filter_by_col(std::vector<std::vector<std::pair<std::string, int>>>& matrix, const std::string& col);
	std::vector<std::pair<std::string, int>> filter_by_row(std::vector<std::vector<std::pair<std::string, int>>>& matrix, int row);

	std::vector<std::pair<std::string, int>> foward_right_diagonal(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position);

	std::vector<std::pair<std::string, int>> foward_left_diagonal(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position);

	std::vector<std::pair<std::string, int>> backward_right_diagonal(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position);

	std::vector<std::pair<std::string, int>> backward_left_diagonal(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position);

	std::pair<std::string, int> first_foward(std::pair<std::string, int> current_position);
};

#endif
