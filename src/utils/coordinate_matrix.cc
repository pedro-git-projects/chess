#include "coordinate_matrix.h"
#include "circular_linked_coords.h"
#include "linked_coords.h"
#include <iostream>
#include <iterator>
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



std::vector<std::pair<std::string, int>> CoordinateMatrix::row(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position) {
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row;
	std::vector<std::pair<std::string, int>>::iterator col;
	std::vector<std::pair<std::string, int>> matrix_row;

	auto row_coord = current_position.second;
	auto col_coord = LinkedCoords{current_position.first};
	col_coord.current = col_coord.current->next; 

	auto next_row = std::make_pair(col_coord.current->value, row_coord);

	while(CoordinateMatrix::find(matrix, next_row)) {
		matrix_row.push_back(next_row);
		col_coord.current = col_coord.current->next;

		if(col_coord.current) {
			next_row = std::make_pair(col_coord.corresponding_string(), row_coord);
		} else { break; }
	}

	return matrix_row;
}


std::vector<std::pair<std::string, int>> CoordinateMatrix::col(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position) {
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row;
	std::vector<std::pair<std::string, int>>::iterator col;
	std::vector<std::pair<std::string, int>> result;

	auto col_coord  = current_position.first;

	for(row = matrix.begin(); row != matrix.end(); row++) {
		for(col = row->begin(); col != row->end(); col++) {
			if(col->first ==  col_coord) {
				auto contained_pair = std::make_pair(col->first, col->second);
				result.push_back(contained_pair);
			}
		}
	}
	return result;
}


// break into eight functions
std::vector<std::pair<std::string, int>> CoordinateMatrix::l(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> current_position) {
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row;
	std::vector<std::pair<std::string, int>>::iterator col;
	std::vector<std::pair<std::string, int>> result;

	// foward right L
	auto foward_r_col_coord = LinkedCoords{current_position.first};
	foward_r_col_coord.current = foward_r_col_coord.current->next;
	auto foward_r_row_coord = current_position.second;
	foward_r_row_coord += 2;
	auto next_foward_r_l = std::make_pair(foward_r_col_coord.corresponding_string(), foward_r_row_coord);
	if(CoordinateMatrix::find(matrix, next_foward_r_l)) {
		result.push_back(next_foward_r_l);
	}

	//foward left L
	auto foward_l_col_coord = LinkedCoords{current_position.first};
	foward_l_col_coord.current = foward_l_col_coord.current->previous;
	auto foward_l_row_coord = current_position.second;
	foward_l_row_coord += 2;
	auto next_foward_l_l = std::make_pair(foward_l_col_coord.corresponding_string(), foward_r_row_coord);
	if(CoordinateMatrix::find(matrix, next_foward_l_l)) {
		result.push_back(next_foward_l_l);
	}

	// backward right L
	auto backward_r_col_coord = LinkedCoords{current_position.first};
	backward_r_col_coord.current = backward_r_col_coord.current->next;
	auto backward_r_row_coord = current_position.second;
	backward_r_row_coord -= 2;
	auto next_backward_r_l = std::make_pair(backward_r_col_coord.corresponding_string(), backward_r_row_coord);
	if(CoordinateMatrix::find(matrix, next_backward_r_l)) {
		result.push_back(next_backward_r_l);
	}

	//backward left L
	auto backward_l_col_coord = LinkedCoords{current_position.first};
	backward_l_col_coord.current = backward_l_col_coord.current->previous;
	auto backward_l_row_coord = current_position.second;
	backward_l_row_coord -= 2;
	auto next_backward_l_l = std::make_pair(backward_l_col_coord.corresponding_string(), backward_l_row_coord);
	if(CoordinateMatrix::find(matrix, next_backward_l_l)) {
		result.push_back(next_backward_l_l);
	}

	// right down col L
	auto r_down_col_coord = LinkedCoords{current_position.first};
	r_down_col_coord .current = r_down_col_coord.current->next;
	r_down_col_coord .current = r_down_col_coord.current->next;
	auto r_down_row_coord = current_position.second;
	r_down_row_coord--;
	auto next_r_down_l = std::make_pair(r_down_col_coord.corresponding_string(), r_down_row_coord);
	if(CoordinateMatrix::find(matrix, next_r_down_l)) {
		result.push_back(next_r_down_l);
	}
	
	// left down col L
	auto l_down_col_coord = LinkedCoords{current_position.first};
	l_down_col_coord.current = l_down_col_coord.current->previous;
	l_down_col_coord.current = l_down_col_coord.current->previous;
	auto l_down_row_coord = current_position.second;
	l_down_row_coord--;
	auto next_l_down_l = std::make_pair(l_down_col_coord.corresponding_string(), l_down_row_coord);
	if(CoordinateMatrix::find(matrix, next_l_down_l)) {
		result.push_back(next_l_down_l);
	}

	// left up left L
	auto l_up_col_coord = LinkedCoords{current_position.first};
	l_up_col_coord.current = l_up_col_coord.current->previous;
	l_up_col_coord.current = l_up_col_coord.current->previous;
	auto l_up_row_coord = current_position.second;
	l_up_row_coord++;
	auto next_l_up_l = std::make_pair(l_up_col_coord.corresponding_string(), l_up_row_coord);
	if(CoordinateMatrix::find(matrix, next_l_up_l)) {
		result.push_back(next_l_up_l);
	}
	
	// right up right L
	auto r_up_col_coord = LinkedCoords{current_position.first};
	r_up_col_coord.current = r_up_col_coord.current->next;
	r_up_col_coord.current = r_up_col_coord.current->next;
	auto r_up_row_coord = current_position.second;
	r_up_row_coord++;
	auto next_r_up_l = std::make_pair(r_up_col_coord.corresponding_string(), r_up_row_coord);
	if(CoordinateMatrix::find(matrix, next_r_up_l)) {
		result.push_back(next_r_up_l);
	}	

	return result;
}
