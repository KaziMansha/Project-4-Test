// Kazi Mansha
// Date Created (or Due Date): 09/23/2022
// Poll.cpp
// Project 2 - Creates three new classes called General, Poll, and Promotional that inherits properties from the Post class with a few unique methods and private data members

#include <iostream>
#include "Poll.hpp"

//Initializing the Poll constructor that connects to the Post constructor that takes in a paramter for title, body, username, and options, and intializes our poll results vector and our poll options vector
Poll::Poll(const std::string title, const std::string body, const std::string username, const std::vector <std::string> options):Post(title, body, username) {
    poll_options_ = options;
    for (size_t i = 0; i < poll_options_.size(); i++) {
        poll_results_.push_back(0);
    }
}

//Initializing the cote method that checks to see if the option number is within the list range and if it is it will add 1 to that vote
bool Poll::votePoll(const int option_num) {
    if (option_num < 0 || option_num > poll_results_.size() - 1) {
        return false;
    } else {
        poll_results_[option_num]++;
        return true;
    }
}

//Initializing the Change Post Option or Add Post Option Method by using the New Poll Option Parameter and the Option Num Parameter to represent what gets replaced where
void Poll::changePollOption(const std::string new_poll_option, const int option_num) {
    if (option_num >= poll_options_.size()) {
        poll_options_.push_back(new_poll_option);
        poll_results_.push_back(0);
    } else {
        poll_options_[option_num] = new_poll_option;
        poll_results_[option_num] = 0;
    }
}

//Initializnig the method that prints out the poll results for each poll option
void Poll::getPollOptions() const{
    for (int i = 0; i < poll_options_.size(); i++) {
        std::cout << poll_results_[i] << " votes for : " << poll_options_[i] << "\n";
    }
}

//Initializing the method that returns the number of votes a specific poll option has
int Poll::getPollVotes(const int option_num) {
    return poll_results_[option_num];
}


//Initializing the method that displays the post title, body, username, poll options, and poll resutls
void Poll::displayPost() const{
    Post::displayPost();
    getPollOptions();
    std::cout << "\n";
}