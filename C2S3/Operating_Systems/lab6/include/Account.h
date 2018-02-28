#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <cmath>
#include <float.h>

class Account
{
    private:
        unsigned int id;
        double balance;

    public:
        Account(unsigned int paramID)
        {
            id = paramID;
            balance = 0;
        }

        unsigned int getID()
        {
            return id;
        }

        double getBalance()
        {
            return balance;
        }

        void putMoney(double money)
        {
            balance += money;
        }

        bool withdrawMoney(double money)
        {

            if ((int)(balance * 100) < (int)(money * 100))
            {
                return false;
            }
            else
            {
                balance -= money;

                return true;
            }
        }
};

#endif
