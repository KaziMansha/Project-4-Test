// Kazi Mansha
// Date Created (or Due Date): 09/23/2022
// General.cpp
// Project 2 - Creates three new classes called General, Poll, and Promotional that inherits properties from the Post class with a few unique methods and private data members


#include <iostream>
#include "General.hpp"

//Initializing Constructor for General Class that uses the constructor from the Post class, takes the parameters title, body, and username, and initializes our array of reaction values
General::General(const std::string title, const std::string body, const std::string username):Post(title, body, username){ 
    for (int i = 0; i < 6; i++) {
        num_of_reactions_[i] = 0;
    }
}

//Initializing Method to add a reaction that checks to see if the index is within the range, and if it is it will add 1 to the integer on that array
bool General::reactToPost(const Reactions reaction) {
    if (reaction < 0 || reaction > 5) {
        return false;
    } else {
        num_of_reactions_[reaction]++;
        return true;
    }
}

//Initializing Method to display the current reaction amount
void General::getReactions() const {
    std::cout << "Like : " << num_of_reactions_[0] << " | Dislike : " << num_of_reactions_[1] << " | Laugh : " << num_of_reactions_[2] << " | Wow : " << num_of_reactions_[3] << " | Sad : " << num_of_reactions_[4] << " | Angry : " << num_of_reactions_[5];
}

//Initializing Method to display the post
void General::displayPost() const{
    Post::displayPost();
    getReactions();
    std::cout << "\n";
}