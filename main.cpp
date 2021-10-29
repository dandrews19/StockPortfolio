#include <iostream>
#include "money.h"
#include "stock.h"
#include "portfolio.h"
#include "portfolio.cpp"
#include "driver.cpp"

int main()
{
	std::cout << "Hello world!" << std::endl;
    
//    std::cout << Money(10000) << std::endl;
//
//    StockPortfolio port;
//    Stock newStock = Stock("Apple", "AAPL", Money(90000), 26.9);
//
//    newStock.setCurrentPrice(Money(100,01));
//
//    std::cout << newStock.getCurrPrice() << std::endl;
//    Money newMoney(505);
//    std::cout << newMoney << std::endl;
//
//    newStock.setCurrentPrice(Money(-100));
//
//    std::cout << newStock.getCurrPrice();
    
//    Money multiplyMoney = Money(100) * 4.0;
//
//
//    std::cout << multiplyMoney << std::endl;
//
//    std::cout << Money(100) << std::endl;
//
//    Money newVar;
//    std::cin >> newVar;
//
//    std::cout << newVar << std::endl;
//	return 0;
    
    StockPortfolio portfolio;
    
    
    
    Stock newStock = Stock("Apple", "AAPL", Money(90000), 26.9);

    newStock.setCurrentPrice(Money(100,01));
    portfolio.addStock(newStock);
    
    Stock newStock1 = Stock("IBM", "IBM", Money(90000), 26.9);

    newStock1.setCurrentPrice(Money(200,01));
    portfolio.addStock(newStock1);
    
    Stock newStock3 = Stock("AAAA", "AAAA", Money(90000), 26.9);

    newStock.setCurrentPrice(Money(300,01));
    portfolio.addStock(newStock3);
    
    Stock newStock4 = Stock("CMA", "CAA", Money(90000), 26.9);

    newStock1.setCurrentPrice(Money(900,01));
    portfolio.addStock(newStock4);
    
    buyStock(portfolio, "WDAY|Workday Inc. Cl A|68.22|14");
    
    portfolio["WDAY"].setCurrentPrice(Money(1900));
    
    updateStock(portfolio, "WDAY|0.11");
    processFile(portfolio, "BRK.A|Berkshire Hathaway Inc. Cl A|1307.00|11");
    processFile(portfolio, "APPL|Apple Inc.|0.11|10000.0");
    processFile(portfolio, "MDLZ|Mondelez International Inc. Cl A|31.07|30");
//    processFile(portfolio, "+BRK.A|365500");
//    processFile(portfolio, "+APPL|135.43");
//
    for (int i = 0; i < portfolio.getAlphaList().size(); i++) {
        std::cout << portfolio.getAlphaList()[i] << " - "  <<  portfolio[portfolio.getAlphaList()[i]].getCurrPrice() << std::endl;
    }
    
    //std::cout << portfolio.containsStock("AAPL");
    
    
    
    

    
        
//    std::vector<std::string> newVec;
//    newVec.push_back("4");
//    newVec.push_back("2");
//    newVec.push_back("3");
//    newVec.push_back("1");
//    selectSort(newVec);
//
//    for (int i = 0; i < newVec.size(); i++) {
//        std::cout << newVec[i] << std::endl;
    
}
