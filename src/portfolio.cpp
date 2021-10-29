#include "portfolio.h"

// empty constructor (initializing map to empty
StockPortfolio::StockPortfolio() {
    
    std::map<std::string, Stock> mStocks;
    
}

// method to add stock to map
void StockPortfolio::addStock(Stock inStock) {
    mStocks.emplace(inStock.getSymbol(), inStock);
    
}

// method to determine if stock is already in map
bool StockPortfolio::containsStock(std::string inSymbol) {
    if (mStocks.count(inSymbol) != 0) {
        return true;
    }
    else {
        return false;
    }
}

// operator [] overload
Stock& StockPortfolio::operator[](std::string inSymbol) {
    // returning value of symbol from map
    return mStocks.at(inSymbol);
}

// getTotalValue implementation
Money StockPortfolio::getTotalValue() const{
    // creating a new Money object to return
    Money total = Money();
    // looping thru map
    for(auto const& x : mStocks) {
        // getting currPrice and numShares
        Money currPrice = x.second.getCurrPrice();
        double numShares = x.second.getNumShares();
        // getting total value by multiplying stock price and number of shares
        total = total + (currPrice * numShares);
        
    }
    
    return total;
}


// getOriginalValue implementation
Money StockPortfolio::getOrigValue() const{
    // creating new Money object to return
    Money total = Money();
    // looping thru stocks map
    for(auto const& x : mStocks) {
        // adding to total purchase price * number of shares
        total += (x.second.getPurPrice()*x.second.getNumShares());
        
    }
    // returning total
    return total;
    
}
// getProfit implementation
Money StockPortfolio::getProfit() const {
    // creating money object to be returned
    Money change;
    // looping through map
    for(auto const& x : mStocks) {
        // adding change * numShares to change
        change += (x.second.getChange()*x.second.getNumShares());
        
    }
    
    
    
    // returning total change
    return change;
    
}

// Function: selectSort
// Purpose: Performs a selection sort on a vector
// Input: Vector of ints to sort (modified in function)
// Returns: Nothing
void selectSort(std::vector<std::string>& vec) {
// We need to perform the select *size* times
    
    for (int i = 0; i < vec.size(); i++) {
        int minIndex = i;
        // Find the smallest element from i to size...
        // We start at index i because everything before i has been sorted already!
        for(int h = i; h < vec.size(); h++) {
            // Is this smaller than the current smallest?
            if (vec[h] < vec[minIndex]) {
                minIndex = h;
            }
        }
        // Swap the smallest value with the value at index i
        if (minIndex != i) {
            std::string tmp = vec[i];
            
            vec[i] = vec[minIndex];
            vec[minIndex] = tmp;
            
        }
    }

}

//getAlphaList implementation
std::vector<std::string> StockPortfolio::getAlphaList() {
    // initializing vector to be filled in with strings
    std::vector<std::string> initList;
    // filling vector with keys
    for(auto const& x : mStocks) {
        
        initList.push_back(x.first);
        
    
        
    }
    // sorting the vector
    selectSort(initList);
    // returning the vectpr
    return initList;
    
    
    
}
// Function: selectSort
// Purpose: Performs a selection sort on a vector
// Input: Vector of ints to sort (modified in function)
// Returns: Nothing
void selectSort(std::vector<Money>& vec) {
// We need to perform the select *size* times
    
    for (int i = 0; i < vec.size(); i++) {
        int maxIndex = i;
        // Find the largest element from i to size...
        // We start at index i because everything before i has been sorted already!
        for(int h = i; h < vec.size(); h++) {
            // Is this larger than the current largest?
            if (vec[h] > vec[maxIndex]) {
                maxIndex = h;
            }
        }
        // Swap the largest value with the value at index i
        if (maxIndex != i) {
            Money tmp = vec[i];
            
            vec[i] = vec[maxIndex];
            vec[maxIndex] = tmp;
            
        }
    }
}


//getValueList() implementation
std::vector<std::string> StockPortfolio::getValueList() {
    // initialzing maps and vectors to be filled
    std::map<Money, std::string> priceToSymbol;
    std::vector<Money> currValueList;
    std::vector<std::string> sortedVec;
    // looping thru stocks map
    for(auto const& x : mStocks) {
        // adding to map where price is the key and symbol is the value
        priceToSymbol.emplace(x.second.getCurrPrice(), x.first);
        // adding to vector of current prices
        currValueList.push_back(x.second.getCurrPrice());
        
        
    
        
    }
    // sorting the value list
    selectSort(currValueList);
    // creating a new vector sorted based on value
    for (int i = 0; i < currValueList.size(); i++) {
        sortedVec.push_back(priceToSymbol.at(currValueList[i]));
        
    }
    
    return sortedVec;
    
}


//getDiffList() implementation
std::vector<std::string> StockPortfolio::getDiffList() {
    // initialzing maps and vectors to be filled
    std::map<Money, std::string> symbolToDiff;
    std::vector<Money> diffList;
    std::vector<std::string> sortedVec;
    // looping thru stoocks map
    for(auto const& x : mStocks) {
        // adding to map where difference is the key and symbol is the value
        symbolToDiff.emplace(x.second.getChange(), x.first);
        // adding to vector of differences
        diffList.push_back(x.second.getChange());
        
        
    
        
    }
    // sorting the difference list
    selectSort(diffList);
    
    // creating a new sorted vector based on value
    for (int i = 0; i < diffList.size(); i++) {
        sortedVec.push_back(symbolToDiff.at(diffList[i]));
        
    }
    
    return sortedVec;
    
}






