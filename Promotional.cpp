// Kazi Mansha
// Date Created (or Due Date): 09/23/2022
// Promotional.cpp
// Project 2 - Creates three new classes called General, Poll, and Promotional that inherits properties from the Post class with a few unique methods and private data members

#include <iostream>
#include <regex>
#include "Promotional.hpp"

//Initializing Promotional constructor that takes a parameter for post title, body, username, and link, and uses the Post constructor to create an object while checking the link with the set link method
Promotional::Promotional(const std::string title, const std::string body, const std::string username, const std::string link) : Post(title, body, username) {
    setLink(link);
}

//Initializing method that returns the url
std::string Promotional::getLink() const {
    return url_;
}

//Initializing method that checks to see if the link is valid or not using the regex library (Source Code: https://www.geeksforgeeks.org/check-if-an-url-is-valid-or-not-using-regular-expression/)
bool Promotional::setLink(const std::string link) {
    const std::regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    if (link.empty()) {
        return false;
    }
    if(std::regex_match(link, pattern)) {
        url_ = link;
        return true;
    } else {
        url_ = "Broken link";
        return false;
    }
}

//Initializing method that displays the post title, body, username, and link
void Promotional::displayPost() const{
    Post::displayPost();
    getLink();
    std::cout << url_ << "\n";
}