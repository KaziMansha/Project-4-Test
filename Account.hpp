// Kazi Mansha
// Date Created (or Due Date): 10/11/2022
// Account.hpp
// Project 3 - We create a template class called Network and customize the Account class that allows people to follow accounts, add accounts, print feed for the account, and add feed for the account
#include <string>
#include <vector>
#include "Post.hpp"
#include "Network.hpp"
#include "LinkedList.hpp"

//Creation of the Account Class
class Account{

    //Creation of Public Methods of Account Class
    public:
    //Account Constructor without Parameters (Uses Account Username, Account Password, and Post Objects Vector)
    Account();
    //Account Constructor with Parameters (Uses Account Username, Account Password, and Post Objects Vector)
    Account(const std::string username, const std::string password);

    //Methods for Setting Account Username
    void setUsername(const std::string username);
    //Methods for Getting Account Username
    std::string getUsername() const;

    //Methods for Setting Account Password
    void setPassword(const std::string password);
    //Methods for Getting Account Password
    std::string getPassword() const;

    //Methods for Adding Posts of the Account
    bool addPost(Post *post_item);

    //Methods for Posting Posts of the Account
    void viewPosts() const;

    //Method for Getting Network
    Network<Account> * getNetwork() const;

    //Method for Setting the Network of an Account
    void setNetwork(Network<Account>* network);

    //Method for Following an Account
    bool followAccount(const std::string account);

    //Method for Returning the Vector of Followed Accounts
    std::vector<std::string> viewFollowing() const;

    //Method for Removing Post from Account
    bool removePost(Post* post);

    //Method for Updating Post from Account
    void updatePost(Post* post, std::string new_title, std::string new_body);

    //Creation of Private Data Members of Account Class (Account Username, Account Password, Post Objects Vector, Followed Accounts Vector, Account Network)
    private:
    std::string account_username_;
    std::string account_password_;
    LinkedList<Post*> post_objects_;
    std::vector <std::string> followed_accounts_;
    Network<Account> *account_network_ = nullptr;
};