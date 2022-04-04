//Link: https://leetcode.com/problems/simple-bank-system/

class Bank {
public:
    vector<long long> bal;
    int n;
    
    Bank(vector<long long>& balance) {
        bal = balance;
        n = bal.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--, account2--;
        if(min(account1, account2) >= 0 and max(account1, account2) < n) {
            if(money <= bal[account1]) {
                bal[account1] -= money;
                bal[account2] += money;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    
    bool deposit(int account, long long money) {
        account--;
        if(account >= 0 and account < n) {
            bal[account] += money;
            return 1;
        }
        return 0;
    }
    
    bool withdraw(int account, long long money) {
        account--;
        if(account >= 0 and account < n and bal[account] >= money) {
            bal[account] -= money;
            return 1;
        }
        return 0;
    }
};