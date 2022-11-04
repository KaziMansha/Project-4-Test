// Kazi Mansha
// Date Created (or Due Date): 09/23/2022
// Promotional.hpp
// Project 2 - Creates three new classes called General, Poll, and Promotional that inherits properties from the Post class with a few unique methods and private data members

#pragma once
#include <iostream>
#include <regex>
#include "Post.hpp"

//Creation of Promotional subclass that inherits methods and private data members from the Post class
class Promotional : public Post {
    //Creation of Unique Public Methods of the Promotional Class
    public:
    //Creation of Promotional constructor that takes a parameter for post title, body, username, and link
    Promotional(const std::string title, const std::string body, const std::string username, const std::string link);
    //Creation of a method that returns the link
    std::string getLink() const;
    //Creation of a method that checks to see if the link is a proper link and if it is or isn't it will do different things
    bool setLink(const std::string link);
    //Creation of a method that displays the post title, body, username, and link
    void displayPost() const;
    //Creation of Unique Private Methods of the Promotional Class
    private:
    std::string url_;
};