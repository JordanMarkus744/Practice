#include <iostream>
#include <vector>
#include <math.h>

/*
This program uses dynamic programming to determine the minimum number of given coins to generate the given amount.
*/

#define MAX INT32_MAX - 1;


int minCoins(std::vector<int> coins, int amount){
    int max = MAX;
    std::vector<int> dp(1 + amount, max); // making sure we have enough room for 0 - amount

    dp[0] = 0; // it takes 0 coins to get to an amount of 0

    for (int i = 1; i <= amount; ++i){
        for (int j = 0; j < coins.size(); j++){
            if (coins[j] <= i){
                if (dp[i - coins[j]] != max){
                    dp[i] = std::min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
    }
    return dp[amount] == max ? -1 : dp[amount];
}

int main() {
    std::vector<int> coins = {1, 3, 4};
    int amount = 13;

    int minCoinsVal = minCoins(coins, amount);
    
    if (minCoinsVal == -1) {
        std::cout << "It's not possible to make up the amount using given coins." << std::endl;
    } else {
        std::cout << "Minimum number of coins needed for amount " << amount << ": " << minCoinsVal << std::endl;
    }

    return 0;
}