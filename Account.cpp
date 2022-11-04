// Kazi Mansha
// Date Created (or Due Date): 10/11/2022
// Network.hpp
// Project 3 - We create a template class called Network and customize the Account class that allows people to follow accounts, add accounts, print feed for the account, and add feed for the account
#include <iostream>
#include <string>
#include <vector>
#include "Account.hpp"

//Initializing Constructor for Account Class that sets the Account Username to an Empty String, Account Password to an Empty String, and empties the Post Vector
Account::Account() {
    account_username_ = "";
    account_password_ = "";
    followed_accounts_.clear();
    post_objects_.clear();
}

//Initializing Constructor for the Account Class that sets the Account Username to the username parameter, the Account Password to the password parameter, and empties the Post Vector
Account::Account(const std::string username, const std::string password) {
    account_username_ = username;
    account_password_ = password;
    followed_accounts_.clear();
    post_objects_.clear();
}

//Initializing Account Username Method to set the Account Username to the username parameter
void Account::setUsername(const std::string username) {
    account_username_ = username;
}

//Initializing Account Username method to return the Account Username
std::string Account::getUsername() const{
    return account_username_;
}

//Initializing Account Password Method to set the Account Password to the password parameter
void Account::setPassword(const std::string password) {
    account_password_ = password;
}

//Initializing Account Password Method to return the Account Password
std::string Account::getPassword() const{
    return account_password_;
}

//Initializing Adding Post to Account Method that checks if the title and body are empty, if not, it will create a new post with that title and body and add that to our Post vector, otherwise it won't
bool Account::addPost(Post *post_item) {
    post_objects_.insert(post_item, 0);
    account_network_ -> addToFeed(post_item);
    return true;
}

//Initializing Posting Posts from Account Methods that displays all the posts using the displayPost()
void Account::viewPosts() const{
    Node<Post*> * temp_ptr = post_objects_.getHeadPtr();
    while(temp_ptr != nullptr) {
        temp_ptr -> getItem() -> displayPost();
        temp_ptr = temp_ptr -> getNext();
    }
}

//Initializing the get network method that returns the network the account is in
Network<Account> *Account::getNetwork() const{
    return account_network_;
}

//Initializing the set network method to set the account network to the pointer of the network referenced
void Account::setNetwork(Network<Account> * network) {
    account_network_ = network;
}

//Initializing the follow account method that follows the account that it specified in the parameter
bool Account::followAccount(const std::string account) {

    bool exists = false;

    for(std::string username_ : followed_accounts_) {
        if(username_ == account) {
            exists = true;
        }
    }

    if(!exists && account_network_ != nullptr) {
        followed_accounts_.push_back(account);
        return true;
    }
    return false; 
}

//Initializing the view following method that returns the vector of followed accounts
std::vector<std::string> Account::viewFollowing() const {
    return followed_accounts_;
}

//Initializing the remove post method for our account objects
bool Account::removePost(Post* post) {
    if (post_objects_.getIndexOf(post) <= -1) {
        return false;
    }
    post_objects_.remove(post_objects_.getIndexOf(post));
    account_network_ -> removePost(post);
    return true;
}

//Initializing the update post function
void Account::updatePost(Post* post, std::string title, std::string body) {
    if (post_objects_.getIndexOf(post) > -1) {
        if (!title.empty()) {
            post -> setTitle(title);
        }
        if (!body.empty()) {
            post -> setBody(body);
        }
        post -> setTimeStamp();
        post_objects_.moveItemToTop(post);
        account_network_ -> moveItemToTop(post);
    }
}