#include <algorithm>
#include <utility>
#include <iostream>
#include <gtest/gtest.h>
#include "board.h"
#include "matrix.h"
#include "circular_linked_coords.h"

TEST(BoardTest, PositionsMatrixInvartiant) {
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
