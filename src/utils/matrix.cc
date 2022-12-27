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

