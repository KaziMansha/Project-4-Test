// Kazi Mansha
// Date Created (or Due Date): 10/11/2022
// Network.hpp
// Project 3 - We create a template class called Network and customize the Account class that allows people to follow accounts, add accounts, print feed for the account, and add feed for the account
#include "Network.hpp"
#include <iostream>
#include <fstream>
#include <string>

//Initializing Network Constrcutor and making the account count to equal 0
template<class TypeName>
Network<TypeName>::Network() {
    account_count_ = 0;
}

//Initializing the get size of network method to return the number of accounts in the network
template<class TypeName>
int Network<TypeName>::getSizeOfNetwork() const{
    return account_count_;
}

//Initializing the is empty method to make the account count vector empty
template<class TypeName>
bool Network<TypeName>::isEmpty() const{
    return account_count_ == 0;
}

//Initializing the add account method that adds the account and sets the network for the account to the current network
template<class TypeName>
bool Network<TypeName>::addAccount(TypeName* item) {
    bool has_room = (account_count_ < DEFAULT_CAPACITY);
	    if (has_room && getIndexOf(item->getUsername())  < 0) {
		    pointers_[account_count_] = item;
            item->setNetwork(this);
		    account_count_++;
            return true;
	    }
	    return false;
}

//Initializng the remove account method to remove the account specified from the network
template<class TypeName>
bool Network<TypeName>::removeAccount(const TypeName* item) {
    int found_index = getIndexOf(item -> getUsername());
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove) {
		account_count_--;
		pointers_[found_index] = pointers_[account_count_];
	} 
	return can_remove;
}

//Initializing the clear method to clear the account vector from the network
template<class TypeName>
void Network<TypeName>::clear() {
    account_count_ = 0;
}

//Initializing the contains account function to check if the account specified is in the network 
template<class TypeName>
bool Network<TypeName>::containsAccount(const TypeName* item) const{
    return getIndexOf(item -> getUsername()) > -1;
}

//Initializing a populate network method that takes a file and populates the network with the accounts from there
template<class TypeName>
void Network<TypeName>::populateNetwork(const std::string fileName) {
    std::ifstream infile(fileName);
    std::string line_string;
    while (getline(infile, line_string)) {
        if (line_string[0] == ';')
            break;
        std::string username, password;
        int pos = line_string.find(' ');
        username = line_string.substr(0, pos);
        password = line_string.substr(pos + 1, line_string.length());
        if (username.empty() || password.empty()) {
            std::cout << "Improper Format\n";
            infile.close();
            break;
        } else {
            TypeName *account = new TypeName(username, password);
            addAccount(account);
            username = "";
            password = "";
        }
    }
}

//Initializing the operator-= function that checks if the network that is referenced has the same account as an account in the current network and removes it
template<class TypeName>
void Network<TypeName>::operator-=(const Network& reference) {
    int index = 0;
    while (index < account_count_) {
        if (reference.containsAccount(pointers_[index])) {
            removeAccount(pointers_[index]);
        } else {
            index++;
        }
    }
}

//Initializing the print feed for account function that prints the feed for the account
template<class TypeName>
void Network<TypeName>::printFeedForAccount(TypeName& item) {
    for (int i = 0; i < item.viewFollowing().size(); i++) {
        if (getIndexOf(item.viewFollowing()[i]) > -1)
            pointers_[getIndexOf(item.viewFollowing()[i])]->viewPosts();
    }
}

//Initializing the authenticate follow to check if you can follow the account
template<class TypeName>
bool Network<TypeName>::authenticateFollow(TypeName& item, const std::string username) {
    int user_index = getIndexOf(item.getUsername());

    if(user_index > -1) {
        int current_index = getIndexOf(username);

        if(current_index > -1) {
            item.followAccount(username);
            return true; 
        }
    }
}

//Initializing the add to feed method that takes a post refernence and adds it to the account posts vector
template<class TypeName>
bool Network<TypeName>::addToFeed(Post* post_pointer) {
    if (getIndexOf(post_pointer -> getUsername()) >= 0) {
        account_posts_.insert(post_pointer, 0);
        return true;
    } else {
        return false;
    }
}

//Initializing the get index of function that checks the pointers vector to see if the target is there
template<class TypeName>
int Network<TypeName>::getIndexOf(const std::string target) const{
    for (int i = 0; i < account_count_; i++) {
        if (pointers_[i] -> getUsername() == target) {
            return i;
        }
    }
    return -1;
}

//Initializing the remove if contains method that checks each post member and removes if it contains the specified word
template<class TypeName>
int Network<TypeName>::removeIfContains(const std::string &word) {
    Node<Post*>* temp_ptr = account_posts_.getHeadPtr();
    int counter = 0;
    if (temp_ptr == nullptr) {
        return counter;
    }
    while (temp_ptr != nullptr) {
        //Create conditional that checks to see if the word is in the post title or body
        if ((temp_ptr -> getItem() -> getTitle().find(word) != std::string::npos)|| ((temp_ptr -> getItem() -> getBody().find(word) != std::string::npos))) {
            if (getIndexOf(temp_ptr -> getItem() -> getUsername()) > -1) {
                pointers_[getIndexOf(temp_ptr -> getItem() -> getUsername())] -> removePost(temp_ptr -> getItem());
            }
            removePost(temp_ptr -> getItem());
            counter ++;
        }
            temp_ptr = temp_ptr -> getNext();
    }
    return counter;
}

//Initializing the remove post method
template<class TypeName>
bool Network<TypeName>::removePost(Post* post) {
    if (account_posts_.getIndexOf(post) <= -1) {
        return false;
    }
    account_posts_.remove(account_posts_.getIndexOf(post));
    return true;
}

//Initializing the move item to top method
template<typename TypeName>
bool Network<TypeName>::moveItemToTop(Post* post) {
    if (account_posts_.getIndexOf(post) > -1) {
        post -> setTimeStamp();
        account_posts_.moveItemToTop(post);
        return true;
    }
    return false;
}