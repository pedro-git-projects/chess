#ifndef CHESS_HEADERS_ALPHABET_H_
#define CHESS_HEADERS_ALPHABET_H_

#include <memory>
#include <mutex>
#include <string>

// TODO: make node the singleton 

class Node {
	public:
		Node(std::string letter);
		std::string letter;
		class Node* next;
};

class BoardLettersSingleton {
	private:
		static std::shared_ptr<BoardLettersSingleton> board_letters_instance_; 
		static std::mutex mutex_;
	protected:
		BoardLettersSingleton(const std::string& first_letter);
		Node first_letter_;
		Node* next_letter_;
	public:
		BoardLettersSingleton(BoardLettersSingleton& other) = delete;
		void operator=(const BoardLettersSingleton&) = delete;
		static std::shared_ptr<BoardLettersSingleton> get_instance(const std::string& first_letter); 
		std::string next();
};

#endif
