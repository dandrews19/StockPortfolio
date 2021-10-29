#include "money.h"

// Money default constructor implementation
Money::Money() {
    mCents = 0;
}

// Money parameterized (dollars and cents) constructor implementation
Money::Money(long long inDollars, long long inCents) {
    
    // setting cents equal to parameter for cents
    mCents = inCents;
    // adding 100* dollars inputted (converting inputted dollars to cents and adding it to mCents)
    mCents += (100 * inDollars);
    
    
}


// Money parameterized (dollars) constructor implementation
Money::Money(double inDollars) {
    // initializing cents to 0
    mCents = 0;
    // adding 100*dollars inputted (converting dollars to cents)
    mCents += (100 * inDollars);
}

// Money parameterized (long long cents) constructor implementation
Money::Money(long long inCents) {
    // setting inputted cents equal to the member variable for cents
    mCents = inCents;
    
}

// Money parameterized (int cents) constructor implementation
Money::Money(int inCents) {
    // setting inputted cents equal to the member variable for cents
    mCents = inCents;
    
}

// operator overloading (+=) implementation
Money& Money::operator+=(const Money& right) {
 
    // adding cents from other Money object to this Money object
    mCents += right.mCents;
    // returning reference to this object
    return *this;
    
    
    
}

// operator overloading (+=) implementation
Money& Money::operator-=(const Money& right) {
 
    // subtracting cents from other Money object to this Money object
    mCents -= right.mCents;
    // returning reference to this object
    return *this;
    
    
    
}

// operator overloading (*=) implementation
Money& Money::operator*=(double right) {
 
    // multitplying and adding cents from other double to current Money object's cents
    mCents *= right;
    // returning reference to this object
    return *this;
    
    
    
}


// operator overloading (/=) implementation
Money& Money::operator/=(double right) {
 
    // dividing and adding cents from other double to current Money object's cents
    mCents /= right;
    // returning reference to this object
    return *this;
    
    
    
}

// operator overloading (<) implementation
bool operator<(const Money& left, const Money& right) {
    // returns the boolean when comparing each Money object's mCents with each other using <
    return left.mCents < right.mCents;
    
}

// operator overloading (>) implementation
bool operator>(const Money& left, const Money& right) {
    // returns the boolean when comparing each Money object's mCents with each other using >
    return left.mCents > right.mCents;
    
}

// operator overloading (<=) implementation
bool operator<=(const Money& left, const Money& right) {
    // returns the boolean when comparing each Money object's mCents with each other using <=
    return left.mCents <= right.mCents;
    
}

// operator overloading (>=) implementation
bool operator>=(const Money& left, const Money& right) {
    // returns the boolean when comparing each Money object's mCents with each other using >=
    return left.mCents >= right.mCents;
    
}

// operator overloading (==) implementation
bool operator==(const Money& left, const Money& right) {
    // returns the boolean when comparing each Money object's mCents with each other using ==
    return left.mCents == right.mCents;
    
}

// operator overloading (!=) implementation
bool operator!=(const Money& left, const Money& right) {
    // returns the boolean when comparing each Money object's mCents with each other using !=
    return left.mCents != right.mCents;
    
}

// operator overloading (+) implementation
Money operator+(const Money& left, const Money& right){
    
    // returning new Money object obtained by adding left and right
    return Money(left.mCents + right.mCents);
}

// operator overloading (-) implementation
Money operator-(const Money& left, const Money& right) {
    
    // returning new Money object obtained by subtracting left and right
    return Money(left.mCents - right.mCents);
}

// operator overloading (*) implementation
Money operator*(const Money& left, double right) {
    
    // returning new Money object obtained by multiplying left and right
    
    long long newMoney = left.mCents * right;
    return Money(newMoney);
}

// operator overloading (/) implementation
Money operator/(const Money& left, double right) {
    
    // returning new Money object obtained by dividing left by right
    long long newMoney = left.mCents / right;
    return Money(newMoney);
}


// operator overloading (<<) implementation
std::ostream& operator<<(std::ostream& out, const Money& money) {
    
    // initializing dollars and cents
    int dollars;
    int cents;
    
    // checking if it's positive
    if (money.mCents >= 0) {
        // getting dollars and cents from cents
        dollars = money.mCents / 100;
        cents = money.mCents % 100;
        
        // different outputs for each case
        if (cents == 0) {
            return out << "$" << dollars << '.' << "00";
            
        }
        else if (cents < 10) {
            return out << "$" << dollars << ".0" << cents;
        }
        
        return out << "$" << dollars << '.' << cents;
    }
    else {
        // does the same thing if negaative, except outputting with negative sign after dollar sign
        dollars = (-money.mCents) / 100;
        cents = (-money.mCents) % 100;
        
        if (cents == 0) {
            return out << "$-" << dollars << '.' << "00";
            
        }
        else if (cents < 10) {
            return out << "$-" << dollars << ".0" << cents;
        }
        
        return out << "$-" << dollars << '.' << cents;

    
    }

    

    
    
    
}



// operator >> overload
std::istream& operator>>(std::istream& in, Money& money) {
    
    // initialicng double to take in as input
    double dollarsAndCents;
    // reading in dollars and cents
    in >> dollarsAndCents;
    // setting Money object's mcents equal to 100* input
    money.mCents = (dollarsAndCents*100);
    
    
    return in;
    
    
}
