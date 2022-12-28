#include "coordinate_matrix.h"
#include "circular_linked_coords.h"
#include "linked_coords.h"
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::vector<std::pair<std::string, int>>> CoordinateMatrix::rotate_clockwise(const std::vector<std::vector<std::pair<std::string, int>>>& matrix) {
	std::vector<std::vector<std::pair<std::string, int>>> result;
	for (int i = 0; i < matrix[0].size(); i++) {
		std::vector<std::pair<std::string, int>> row;
		for (int j = matrix.size() - 1; j >= 0; j--) {
			row.push_back(matrix[j][i]);
		}
		result.push_back(row);
	}
	return result;
}


void CoordinateMatrix::print(const std::vector<std::vector<std::pair<std::string, int>>>& matrix) {
	for(int i = 0; i < matrix[0].size(); i++) {
		for(int j = matrix.size() - 1; j >= 0; j-- ) {
			std::cout << matrix[i][j].first << matrix[i][j].second << " ";  
		}
		std::cout << std::endl;
	}
} 


bool CoordinateMatrix::find(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> target) {
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row;
	std::vector<std::pair<std::string, int>>::iterator col;

	for(row = matrix.begin(); row != matrix.end(); row++) {
		for(col = row->begin(); col != row->end(); col++) {
			if(col->first == target.first && col->second == target.second) return true; 
		}
	}
	return false;
}


std::vector<std::pair<std::string, int>> CoordinateMatrix::filter_by_col(std::vector<std::vector<std::pair<std::string, int>>>& matrix, const std::string& col) {
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row_it;
	std::vector<std::pair<std::string, int>>::iterator col_it;
	std::vector<std::pair<std::string, int>> result;

	for(row_it = matrix.begin(); row_it != matrix.end(); row_it++) {
		for(col_it = row_it->begin(); col_it != row_it->end(); col_it++) {
			if(col_it->first == col) {
				auto filtered_pair = std::make_pair(col_it->first, col_it->second);
				result.push_back(filtered_pair);
			}
		}
	}
	return result;
}

std::vector<std::pair<std::string, int>> CoordinateMatrix::filter_by_row(std::vector<std::vector<std::pair<std::string, int>>>& matrix, int row) {
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row_it;
	std::vector<std::pair<std::string, int>>::iterator col_it;
	std::vector<std::pair<std::string, int>> result;

	for(row_it = matrix.begin(); row_it != matrix.end(); row_it++) {
		for(col_it = row_it->begin(); col_it != row_it->end(); col_it++) {
			if(col_it->second == row) {
				auto filtered_pair = std::make_pair(col_it->first, col_it->second);
				result.push_back(filtered_pair);
			}
		}
	}
	return result;
}


std::vector<std::pair<std::string, int>> CoordinateMatrix::foward_right_diagonal(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position) {
	std::vector<std::pair<std::string, int>>right_diagonal{};
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row;
	std::vector<std::pair<std::string, int>>::iterator col;

	auto coord = LinkedCoords{current_position.first};
	coord.current = coord.current->next;
	auto position = current_position.second + 1;
	auto next_right_diagonal = std::make_pair(coord.current->value, position);

	while(CoordinateMatrix::find(matrix, next_right_diagonal)) {
		right_diagonal.push_back(next_right_diagonal);	
		coord.current = coord.current->next;
		position++;
		if(coord.current) {
			next_right_diagonal = std::make_pair(coord.corresponding_string(), position);
		} else { break; }
	}

	return right_diagonal; 
}

std::vector<std::pair<std::string, int>> CoordinateMatrix::foward_left_diagonal(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position) {
	std::vector<std::pair<std::string, int>>left_diagonal{};
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row;
	std::vector<std::pair<std::string, int>>::iterator col;

	auto coord = LinkedCoords{current_position.first};
	coord.current = coord.current->previous;
	auto position = current_position.second + 1;
	auto next_left_diagonal = std::make_pair(coord.current->value, position);

	while(CoordinateMatrix::find(matrix, next_left_diagonal)) {
		left_diagonal.push_back(next_left_diagonal);	
		coord.current = coord.current->previous;
		position++;
		if(coord.current) {
			next_left_diagonal = std::make_pair(coord.corresponding_string(), position);
		} else { break; }
	}

	return left_diagonal; 
}

std::vector<std::pair<std::string, int>> CoordinateMatrix::backward_left_diagonal(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position) {
	std::vector<std::pair<std::string, int>>left_diagonal{};
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row;
	std::vector<std::pair<std::string, int>>::iterator col;

	auto coord = LinkedCoords{current_position.first};
	coord.current = coord.current->previous;
	auto position = current_position.second - 1;
	auto previous_left_diagonal = std::make_pair(coord.current->value, position);

	while(CoordinateMatrix::find(matrix, previous_left_diagonal)) {
		left_diagonal.push_back(previous_left_diagonal);	
		coord.current = coord.current->previous;
		position--;
		if(coord.current) {
			previous_left_diagonal = std::make_pair(coord.corresponding_string(), position);
		} else { break; }
	}

	return left_diagonal; 
}

std::vector<std::pair<std::string, int>> CoordinateMatrix::backward_right_diagonal(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position) {
	std::vector<std::pair<std::string, int>>right_diagonal{};
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row;
	std::vector<std::pair<std::string, int>>::iterator col;

	auto coord = LinkedCoords{current_position.first};
	coord.current = coord.current->next;
	auto position = current_position.second - 1;
	auto previous_right_diagonal = std::make_pair(coord.current->value, position);

	while(CoordinateMatrix::find(matrix, previous_right_diagonal)) {
		right_diagonal.push_back(previous_right_diagonal);	
		coord.current = coord.current->next;
		position--;
		if(coord.current) {
			previous_right_diagonal = std::make_pair(coord.corresponding_string(), position);
		} else { break; }
	}

	return right_diagonal; 
}


std::pair<std::string, int> CoordinateMatrix::first_foward(std::pair<std::string, int> current_position) {
	auto next_line = current_position.second + 1;
	std::pair<std::string, int> result = std::make_pair(current_position.first, next_line);
	return result;
}

