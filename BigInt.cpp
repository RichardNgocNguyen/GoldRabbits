#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#include "BigInt.h" 

using namespace std;

BigInt::BigInt(){
  
}

BigInt::BigInt(string m){
  for (int i = m.size()-1; i >= 0; i-- ){
    char s = m[i] - '0';
    digits.push_back(s);
  }
}

BigInt::BigInt(int n){
  int count = 0;
  int digit = 0;
  if (n == 0){
    digits.push_back(0);
    count = count + 1;
  }
  while (n > 0 and count == 0){
    digit = n % 10;
    n =(n / 10);
    digits.push_back(digit);
    }
}

void BigInt::print()const{
  for (int i = digits.size() - 1; i >= 0; i--){
    cout << (int)digits[i];
  }
  cout << endl;
}

BigInt BigInt::operator=(int n){
  BigInt i(n);
  *this = i;
  return *this;
  
}

BigInt operator+(BigInt d1, BigInt d2){
  BigInt addi;
  int siz1 = d1.digits.size();
  int siz2 = d2.digits.size();
  int difference = abs(siz1 - siz2);
  
  if (difference != 0){
    if (siz1 < siz2){
      for (int i = 0; i < difference; i++){
        d1.digits.push_back(0);
      }
    }
    else{
      for (int i = 0; i < difference; i++){
        d2.digits.push_back(0);
      }
    }
  }  
  int size = d1.digits.size();
  
  int remainder = 0;
  int addc;
  for (int j = 0; j < size; j++){
    int add = d1.digits[j] + d2.digits[j] + remainder;
    remainder = 0;
    
    addc = (add % 10);
    
    addi.digits.push_back(addc);
    
    if (add >= 10){
      remainder = 1;
    }
  }
  if (remainder == 1) {
    addi.digits.push_back(1);
  }
  return addi;
}

BigInt operator-(BigInt d1, int n){
  BigInt sub(d1);
  BigInt s(n);
  int siz1 = d1.digits.size();
  int siz2 = s.digits.size();
  int difference = abs(siz1 - siz2);
  
  if (difference != 0){
    if (siz1 < siz2){
      for (int i = 0; i < difference; i++){
        d1.digits.push_back(0);
      }
    }
    else{
      for (int i = 0; i < difference; i++){
        s.digits.push_back(0);
      }
    }
  }  
  int size = d1.digits.size();
  
  int borrow = 0;
  int subc;
  for (int j = 0; j < size; j++){
    int subt = d1.digits[j] - s.digits[j] - borrow;
    borrow = 0;
    if (subt < 0){
      subc = 10 + subt;
      sub.digits[j] = subc;
      borrow = 1;
    }
    else {
      subc = subt;
      sub.digits[j] = subc;
      break;
    }

  }
  if (borrow == 1){
    sub.digits.back() = sub.digits.back() - 1;
  }
  if (sub.digits.back() == 0){
    sub.digits.pop_back();
  }
  return sub;
}

bool operator<=(BigInt d1, BigInt d2){
  int siz1 = d1.digits.size();
  int siz2 = d2.digits.size();
  int difference = abs(siz1 - siz2);
  if (difference != 0){
    if (siz1 > siz2){
      return false;
    }
    else
      return true;
  }
  else{ 
    for (int i = siz1 - 1; i >=0;i--){
      if (d1.digits[i] == d2.digits[i]){
        continue;
      }
      else if (d1.digits[i] > d2.digits[i]){
        return false;
      }
      else{
        return true;
      }
    }
  }
  return true;
}

bool operator<(const BigInt& d1, const BigInt& d2){
  int count = 0;
  int siz1 = d1.digits.size();
  int siz2 = d2.digits.size();
  int difference = abs(siz1 - siz2);
  if (difference != 0){
    if (siz1 > siz2){
      return false;
    }
    else
      return true;
  }
  else{ 
    for (int i = siz1 - 1; i >=0;i--){
      if (d1.digits[i] == d2.digits[i]){
        count = count + 1;
        continue;
      }
      else if (d1.digits[i] > d2.digits[i]){
        return false;
      }
      else{
        return true;
      }
    }
  }
  if (count == d1.digits.size()){
    return false;
  }
  else{ 
    return true;
  }
}

BigInt BigInt::operator++(int){ 
  BigInt i(1);
  *this = *this + i;
  return *this;
}

bool operator==(BigInt d1, BigInt d2){
  if (d1.digits.size() == d2.digits.size()){
    for (int i = 0; i < d1.digits.size();i++){
      if (d1.digits[i] != d2.digits[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

ostream& operator<<(ostream& out, const BigInt& d){
  int count = 0;
  for (int i = d.digits.size() - 1; i >= 0; i--){
    if (count == 1 and d.digits.size() >= 13){
      cout << '.' ;
    }
    if (count == 13) {
      break;
    }
    cout << (int)d.digits[i];
    count++;
  }
  if (count >= 13){ 
    cout << "e" << d.digits.size() - 1;
  }
  return out;
  
}