You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
code:
int maxProfit(int* prices, int pricesSize) {
    // Edge case: If there are no prices or only one day, profit is 0
    if (pricesSize <= 1) {
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        // If current price is lower than our minimum, update minPrice
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } 
        // Otherwise, calculate potential profit and update maxProfit if it's higher
        else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}
