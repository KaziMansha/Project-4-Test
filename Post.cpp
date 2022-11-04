// Kazi Mansha
// Date Created (or Due Date): 09/23/2022
// Post.cpp
// Project 2 - Creates three new classes called General, Poll, and Promotional that inherits properties from the Post class with a few unique methods and private data members

#include <iostream>
#include <time.h>
#include "Post.hpp"

//Initilizing Constructor for Post Class by Setting the Post Title to the Title Parameter, Post Body to the Body Parameter, Post Time to the time right now, and Post Username to the Username Parameter
Post::Post(const std::string title, const std::string body, const std::string username) {
    post_title_ = title;
    post_body_ = body;
    post_username_ = username;
    post_time_ = time(NULL);
}

//Initializing Post Title Method that sets the Post Title to what the User inputs to the Parameter
void Post::setTitle(const std::string title) {
    post_title_ = title;
}

//Initializing Post Title Method that Returns the Post Title
std::string Post::getTitle() const {
    return post_title_;
}

//Initializing Post Body method that sets the Post Body to what the User inputs to the Parameter
void Post::setBody(const std::string body) {
    post_body_ = body;
}

//Initializing Post Body Method that Returns the Post Body
std::string Post::getBody() const {
    return post_body_;
}

//Initializing Post Username method that sets the Post Username to what the user inputs to the Parameter
void Post::setUsername(const std::string username) {
    post_username_ = username;
}

//Initializing Post Username method that Returns the Post Username
std::string Post::getUsername() const {
    return post_username_;
}

//Initializing Time Stamp method that gets the Post Time and then creates the Sub-String to take out the '\n' in the string itself to later to print in DisplayPost()
void Post::getTimeStamp() const {
    std::string time_string = asctime(localtime(&post_time_));
    std::string time_string_sub = time_string.substr(0, time_string.length() - 1);
    std::cout << time_string_sub;
}

//Initializing Display Post Method that takes the Post Title, Post Body, and the Post Time and prints it out the way the Display wants it to be
void Post::displayPost() const {
    std::cout << "\n" << post_title_ << " at ";
    getTimeStamp();
    std::cout << ": \n" << post_body_ << "\n";
}

//Initializing get time stamp method to get the time stamp
void Post::setTimeStamp() {
    post_time_ = time(NULL);
}