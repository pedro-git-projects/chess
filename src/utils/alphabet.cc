#include <alphabet.h>
#include <memory.h>
#include <memory>
#include <mutex>

BoardLettersSingleton::BoardLettersSingleton(const std::string& first_letter) : 
	first_letter_(Node{first_letter}){}

std::shared_ptr<BoardLettersSingleton> BoardLettersSingleton::get_instance(const std::string& first_letter) {
	std::lock_guard<std::mutex> lock(mutex_);
	if(!board_letters_instance_) board_letters_instance_ = std::make_shared<BoardLettersSingleton>(first_letter);
	return board_letters_instance_;
}

std::string next() {
}
