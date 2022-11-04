// Kazi Mansha
// Date Created (or Due Date): 09/23/2022
// Post.hpp
// Project 2 - Creates three new classes called General, Poll, and Promotional that inherits properties from the Post class with a few unique methods and private data members

#pragma once
#include <time.h>
#include <string>

//Creation of the Post Class
class Post{

    //Creation of Public Methods
    public:
    //Post Constructor that Contains the Post Title, Post Body, Post time, and Post Username
    Post(const std::string title, const std::string body, const std::string username);

    //Method for Setting the Post Title
    void setTitle(const std::string title);
    //Method for Getting the Post Title
    std::string getTitle() const;

    //Method for Setting the Post Body
    void setBody(const std::string body);
    //Method for Getting the Post Body
    std::string getBody() const;

    //Method for Setting the Post Username
    void setUsername(const std::string username);
    //Method for Getting the Post Username
    std::string getUsername() const;

    //Method to get Time Stamp
    void getTimeStamp() const;

    //Method to Display Post
    virtual void displayPost() const;

    //Method to set the time stamp
    void setTimeStamp();

    //Creation of Private Data Members of the Post (Post Title, Post Body, Post Time, Post Username)
    private:
    std::string post_title_;
    std::string post_body_;
    std::string post_username_;
    std::string post_link_;
    time_t post_time_;
};