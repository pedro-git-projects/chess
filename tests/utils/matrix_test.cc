#include <gtest/gtest.h>
#include <utility>
#include "circular_linked_coords.h"
#include "coordinate_matrix.h"
#include "board.h"

TEST(MatrixTest, NextFowardTest) {
	auto current_position = std::make_pair("a", 1);	
	auto foward = CoordinateMatrix::first_foward(current_position);
	auto expected = std::make_pair("a", 2);

	EXPECT_TRUE(foward.first == expected.first && foward.second == expected.second);
}

TEST(MatrixTest, FilterByColTest) {
	auto board = Board {};
	auto column = CoordinateMatrix::filter_by_col(board.positions_matrix(), "b");
	bool control = false;
	int coord = 8;

	for(int i = 0; i < column.size(); i++) {
		if(column[i].first == "b" && column[i].second == coord) {
			control = true;
			coord--;
		}
	}

	EXPECT_TRUE(control);
}

TEST(MatrixTest, FilterByRowTest) {
	auto board = Board {};
	auto row = CoordinateMatrix::filter_by_row(board.positions_matrix(), 3);
	bool control = false;
	auto clc = CircularLinkedCoords{};

	for(int i = 0; i < row.size(); i++) {
		if(row[i].first == clc.current->value  && row[i].second == 3) {
			control = true;
			clc.current = clc.current->next;
		}
	}

	EXPECT_TRUE(control);
}
