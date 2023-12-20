class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int minCost = INT_MAX;

        int n = prices.size();

        for (int firstChoco = 0; firstChoco < n; firstChoco++) {
            for (int secondChoco = firstChoco + 1; secondChoco < n; secondChoco++) {
                int cost = prices[firstChoco] + prices[secondChoco];
                if (cost < minCost) {
                    minCost = cost;
                }
            }
        }

        if (minCost <= money) {
            return money - minCost;
        } else {
            return money;
        }
    }
};