#include <algorithm>
#include <utility>
#include <iostream>
#include <gtest/gtest.h>
#include "board.h"
#include "matrix.h"
#include "circular_linked_coords.h"

// contains all it should 
TEST(BoardTest, PositionsMatrixInvartiantContains) {
	auto board = Board{};
	auto positions = board.positions_matrix(); 

	int coord = 8;
	CircularLinkedCoords clc{"a"};

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			auto target = std::make_pair(clc.current->value, coord);
			auto contains = Matrix::find(positions, target);
			clc.current = clc.current->next;
			if(!contains) {
				EXPECT_TRUE(contains);
			}
		}
		coord--;
	}
}

// does not contain somehting it shouldn't
TEST(BoardTest, PositionsMatrixInvartiantDoesNotCotain) {
	auto board = Board{};
	auto positions = board.positions_matrix(); 

	int coord = 8;
	CircularLinkedCoords clc{"a"};

	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			auto target = std::make_pair(clc.current->value, coord);
			auto contains = Matrix::find(positions, target);
			clc.current = clc.current->next;
			if(!contains && !positions.empty()) {
				EXPECT_TRUE(positions.empty());
			}
		}
		coord--;
	}
}
