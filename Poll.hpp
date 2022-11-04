// Kazi Mansha
// Date Created (or Due Date): 09/23/2022
// Poll.hpp
// Project 2 - Creates three new classes called General, Poll, and Promotional that inherits properties from the Post class with a few unique methods and private data members

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Post.hpp"


//Creation of Poll Class as a Subclass of the Post Class
class Poll : public Post {
    //Creation of Unique Public Methods of the Poll Class
    public:
    //Creation of Poll constructor that takes in a parameter for the title, body, username, and a vector of strings
    Poll(const std::string title, const std::string body, const std::string username, const std::vector <std::string> options);
    //Creation of a method that takes the index that the user wants to vote for and then adds a vote to that
    bool votePoll(const int option_num);
    //Creation of a method that takes the index and a new poll option from the user to either create a new poll option or replace a prior one depending on the index
    void changePollOption(const std::string new_poll_option, const int option_num);
    //Creation of a method that prints out the poll options
    void getPollOptions() const;
    //Creation of a method that returns the number of votes for that specific index
    int getPollVotes(const int option_num);
    //Creation of a method that displays the post title, post body, post time, and the post options with their respective votes
    void displayPost() const;
    //Creation of Unique Private Methods of the Poll Class
    private:
    //Creation of a string vector that holds our poll options 
    std::vector <std::string> poll_options_;
    //Creation of a int vector that holds our poll results for the poll options
    std::vector <int> poll_results_;
};