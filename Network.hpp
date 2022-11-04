// Kazi Mansha
// Date Created (or Due Date): 10/11/2022
// Network.hpp
// Project 3 - We create a template class called Network and customize the Account class that allows people to follow accounts, add accounts, print feed for the account, and add feed for the account
#ifndef NETWORK_CLASS_HPP
#define NETWORK_CLASS_HPP
#include <vector>
#include "Post.hpp"
#include "LinkedList.hpp"

//Creation of the Network Template Class
template <class TypeName>
class Network {
    //Creation of Public Methods
    public:
        //Default Network Constructor
        Network();
        //Method for getting the size of the network
        int getSizeOfNetwork() const;
        //Method for telling the user if the network is empty or not
        bool isEmpty() const;
        //Method to add account to the network
        bool addAccount(TypeName* item);
        //Method to remove an account from the network
        bool removeAccount(const TypeName* item);
        //Method to clear the network from all accounts
        void clear();
        //Method to check if the network contains an account or not
        bool containsAccount(const TypeName* item) const;
        //Method to populate the network with accounts
        void populateNetwork(const std::string fileName);
        //Method to take the reference to a network and remove any accounts that are in both networks
        void operator-=(const Network& reference);
        //Method to print the feed of an account
        void printFeedForAccount(TypeName& item);
        //Method to authenticate following for a specific account
        bool authenticateFollow(TypeName& item, const std::string username);
        //Method to add a post to the account post vector
        bool addToFeed(Post* post_pointer);
        //Method to remove a post object if it contains the specified word
        int removeIfContains(const std::string &word);
        //Method to remove a post from the network
        bool removePost(Post* post);
        //Method to move item to top
        bool moveItemToTop(Post* post);
    //Creation of Private Data Members
    private:
        //Creation of private data members default capacity, pointers, account count, account post, username
        static const int DEFAULT_CAPACITY = 200;
        TypeName *pointers_[DEFAULT_CAPACITY];
        int account_count_;
        LinkedList<Post*> account_posts_;
        int getIndexOf(const std::string username) const;
};

#include "Network.cpp"
#endif