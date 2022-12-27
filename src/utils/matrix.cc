#include "circular_linked_coords.h"
#include <matrix.h>
#include <iostream>
#include <utility>
#include <vector>

std::vector<std::vector<std::pair<std::string, int>>> Matrix::rotate_clockwise(const std::vector<std::vector<std::pair<std::string, int>>>& matrix) {
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


void Matrix::print(const std::vector<std::vector<std::pair<std::string, int>>>& matrix) {
	for(int i = 0; i < matrix[0].size(); i++) {
		for(int j = matrix.size() - 1; j >= 0; j-- ) {
			std::cout << matrix[i][j].first << matrix[i][j].second << " ";  
		}
		std::cout << std::endl;
	}
} 


bool Matrix::find(std::vector<std::vector<std::pair<std::string, int>>>& matrix, std::pair<std::string, int> target) {
	std::vector<std::vector<std::pair<std::string, int>>>::iterator row;
	std::vector<std::pair<std::string, int>>::iterator col;

	for(row = matrix.begin(); row != matrix.end(); row++) {
		for(col = row->begin(); col != row->end(); col++) {
			if(col->first == target.first && col->second == target.second) return true; 
		}
	}
	return false;
}


std::vector<std::pair<std::string, int>> Matrix::filter_by_col(std::vector<std::vector<std::pair<std::string, int>>>& matrix, const std::string& col) {
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


std::vector<std::pair<std::string, int>> Matrix::filter_by_row(std::vector<std::vector<std::pair<std::string, int>>>& matrix, int row) {
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

std::pair<std::string, int> Matrix::first_foward(std::pair<std::string, int> current_position) {
	auto next_line = current_position.second + 1;
	std::pair<std::string, int> result = std::make_pair(current_position.first, next_line);
	return result;
}

