#include "stock.h"

// parameterized constructor implementation
Stock::Stock(std::string inName, std::string inSymbol, const Money& inPurPrice, double inNumShares) {
    
    mName = inName;
    mSymbol = inSymbol;
    mPurchasePrice = inPurPrice;
    mNumShares = inNumShares;
    mCurrentPrice = inPurPrice;
}

// default constructor
Stock::Stock() {
    
    mName = "";
    mSymbol = "";
    mPurchasePrice = Money(0);
    mNumShares = 0;
    mCurrentPrice = mPurchasePrice;
}


//getter for member variables

Money Stock::getCurrPrice() const {
    
    return mCurrentPrice;
}

Money Stock::getPurPrice() const {
    
    return mPurchasePrice;
}

std::string Stock::getSymbol() const {
    return mSymbol;
}

std::string Stock::getName() const {
    return mName;
}

double Stock::getNumShares() const {
    return mNumShares;
}

// getChange implementation
Money Stock::getChange() const {
    
    // getting difference between current price and purchase price (possible thru - overload in Money class)
    return mCurrentPrice - mPurchasePrice;
}

// setter for current price
void Stock::setCurrentPrice(const Money& inCurrPrice) {
    
    mCurrentPrice = inCurrPrice;
}

// operator (<<) overload implementation
std::ostream& operator<<(std::ostream& out, const Stock& stock) {
    
    return out << stock.mSymbol << " : " << stock.mNumShares << " @ " << stock.mCurrentPrice;
    
}
