// Kazi Mansha
// Date Created (or Due Date): 09/23/2022
// General.hpp
// Project 2 - Creates three new classes called General, Poll, and Promotional that inherits properties from the Post class with a few unique methods and private data members

#pragma once
#include <iostream>
#include "Post.hpp"

//Creating an enum of reactions (Like, Dislike, Laugh, Wow, Sad, Angry)
enum Reactions {LIKE, DISLIKE, LAUGH, WOW, SAD, ANGRY};

//Creating a General Class as a Subclass of the Post Class
class General : public Post {
    //Creation of Unique Public Methods of the General Class
    public:
    //Creation of the General Constructor that takes in a title, body, and username parameter
    General(const std::string title, const std::string body, const std::string username);
    //Creation of a method that takes a reaction and adds to our reactions array at that index
    bool reactToPost(const Reactions reaction);
    //Creation of a method to print out our reactions
    void getReactions() const;
    //Creation of a method that displays the post title, post body, post time, and post reactions with the number of times that reactions has been done
    void displayPost() const;
    //Creation of Unique Private Members of the General Class
    private:
    //Creation of an array to hold the values for our reaction
    int num_of_reactions_[6];
};