#ifndef BANK_H
#define BANK_H

#include <string>
#include <memory>
#include <list>

#include "Account.h"

class Bank
{
    private:
        unsigned short id;
        std::list<std::shared_ptr<Account>> clients;

    public:
        Bank(unsigned short paramID)
        {
            id = paramID;
        }

        void newAccount(unsigned int clientID)
        {
            for (auto client : clients) 
            {
                if (client->getID() == clientID) 
                {
                    return;
                }
            }

            clients.push_back(std::make_shared<Account>(clientID));
        }

        double getBalanceOf(unsigned int clientID)
        {
            for (auto client : clients) 
            {
                if (client->getID() == clientID)
                {
                    return client->getBalance();
                }
            }

            return -1; // barely possible situation
        }

        void putMoneyTo(unsigned int targetClientID, double money)
        {
            newAccount(targetClientID);
            
            for (auto client : clients) 
            {
                if (client->getID() == targetClientID)
                {
                    client->putMoney(money);
                }
            }
        }

        bool withdrawMoneyFrom(unsigned int clientID, double money)
        {
            for (auto client : clients) 
            {
                if (client->getID() == clientID) 
                {
                    return client->withdrawMoney(money);
                }
            }

            return false; // barely possible situation
        }
};

#endif
