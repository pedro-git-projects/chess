#ifndef CHESS_HEADERS_MATRIX_PAIR_H_
#define CHESS_HEADERS_MATRIX_PAIR_H_

#include <utility>
#include <vector>
template <typename P, typename Q>
class MatrixPair {
	public:
		MatrixPair<P, Q>() : matrix_{std::vector<std::vector<std::pair<P, Q>>>()} {};

	private:
		std::vector<std::vector<std::pair<P, Q>>> matrix_;

};

#endif
