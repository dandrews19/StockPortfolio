#include "driver.h"
#include "strlib.h"
#include <fstream>


//buyStock implementation
bool buyStock(StockPortfolio& inPort, const std::string& inString) {
    
    // splitting the string into parsable vector
    std::vector<std::string> infoVector = strSplit(inString, '|');
    
    // checking if there's enough info in vector to create a new Stock object
    if (infoVector.size() >= 4) {
        // turning purchase price string into Money object
        Money purchasePrice = Money(stod(infoVector[2]));
        // creating a new stock to be added to portfolio
        Stock newStock = Stock(infoVector[1], infoVector[0], purchasePrice, stod(infoVector[3]));
        
        // adding stock to vector
        inPort.addStock(newStock);
        // returning true indicating success
        return true;
    
    }
    else {
        // outputting an error occurred
        std::cout << "Not enough information in string for stock, unable to add to portfolio";
        // returning false indicating no success
        return false;
    }
    
    
}

// updateStock implementation
bool updateStock(StockPortfolio& inPort, const std::string& inString) {
    
    // splitting the string into parsable vector
    std::vector<std::string> infoVector = strSplit(inString, '|');
    
    
    // if stock is in portfolio, set the current price in the map and return true
    if (inPort.containsStock(infoVector[0])) {
        // getting stock from portfolio and updating the price
        inPort[infoVector[0]].setCurrentPrice(Money(stod(infoVector[1])));
        
        return true;
        
    }
    // if not in portfolio, display error message and return false
    else {
        std::cout << "Stock not in portfolio, unable to update!";
        
        return false;
    }
    
}

//processFile implementation

bool processFile(StockPortfolio& inPort, const std::string& inString) {
    
    // initializing file input stream
    std::ifstream fileInput(inString);
    
    std::vector<std::string> data;
    // looping thru each line of file and appending it to vector as string
    if (fileInput.is_open()) {
        while (fileInput.eof() != true) {
            std::string str;
            std::getline(fileInput, str);
            // add to vector if not empty or a new line
            if (!str.empty() and str != "\n") {
            data.push_back(str);
            }
        }
        fileInput.close();
    }
    else {
        std::cout << "Error: File not found :(" << std::endl;
        return false;
    }
    // initializing output bool to return with function
    bool outputBool = true;
    for (std::string inString : data) {
    // splitting the string into parsable vector
    std::vector<std::string> infoVector = strSplit(inString, '|');
    
    
    // checking size of information, and doing operations accordingly
    if (infoVector.size() >= 4) {
        // adding stock to portfolio, making output false if not successful
        if (buyStock(inPort, inString) == false) {
            outputBool = false;
        }
        
    }
    else if (infoVector.size() >= 2) {
        // initializing a string that will contain the inString without the + at the beginning
        std::string stringWithoutPlus;
        
        // adding every character from inString to stringWithoutPlus besides the first character
        for (int i = 1; i < inString.length(); i++) {
            stringWithoutPlus.push_back(inString[i]);
        }
        // sending stock to be updated, if returns false then output of function will be false
        if (updateStock(inPort, stringWithoutPlus ) == false) {
            outputBool = false;
        }
        
        
    }
    // if size of vector isn't 4 or 2, print out error message and return false
    else {
        
        std::cout << "Error: not enough information given, can't update or add stock to portfolio";
        return false;
    }
    }
    return outputBool;
}
