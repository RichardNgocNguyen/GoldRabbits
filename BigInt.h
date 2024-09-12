#ifndef Big_H
#define Big_H

#include <vector>
#include <string>


class BigInt{
  private:
    std::vector<char> digits;
  public:
    BigInt();
    BigInt(std::string);
    BigInt(int);
    void print()const; 
    BigInt operator=(int n);
    BigInt operator++(int); 
    friend BigInt operator+(BigInt d1, BigInt d2);
    friend BigInt operator-(BigInt d1, int n);
    friend bool operator<=(BigInt i, BigInt d);
    friend bool operator<(const BigInt& i, const BigInt& d);
    friend bool operator==(BigInt d1, BigInt d2);
    friend std::ostream& operator<<(std::ostream& os, const BigInt& d);

};

#endif 