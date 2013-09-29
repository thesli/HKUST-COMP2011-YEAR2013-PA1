// NAME: Man Jin Hay
// ID: 20041763
// EMAIL: sliv.phone@gmail.com 
// Lab Section: LA3
#include <iostream>
#include <math.h>
using namespace std;
int MAX_NUM_ITERATIONS = 40;// Max. no. of reverse-and-add iterations allowed
int LONG_LONG_OVERFLOW = -1; // To signal an overflow of a long long int
// TODO 1: Return the reversed number. e.g. if x is 1234, return 4321.
long long reverse(long long x)
{  
  long long r=0;  
  long long l=1;
  long long j=0;
  while((x/(long long)pow(10,l))!=0){
    l++;    
  }
  while(l>0){
    r+=((long long)x%((long long)pow(10,l))/(long long)pow(10,l-1))*(long long)pow(10,j);
    l--;
    j++;
  }
  return r;
}
// TODO 2: Checking a palindromic number
bool is_palindrome(long long x)
{
  return reverse(x)==x;
}
// TODO 3: Make a palindromic number by iterative reverse-and-add, 
//         and return the number of iterations taken
// It is assumed that under 2 conditions, the given integer is lychrel:
// (a) more than 400 reverse-and-add iterations have been tried
// (b) the number overflows even when it is represented by long long int.
long long make_palindrome(long long x)
{
  long long i=0;
  while(i<MAX_NUM_ITERATIONS||x<LONG_LONG_OVERFLOW){
    x = x+reverse(x);
    if(is_palindrome(x)){
      return x;
    }
    i++;
  }
  return -1;
}
// TODO 4: Print out the derivation in make_palindrome
void print_derivation(long long x)
{      
  long long i=0;
  while(i<MAX_NUM_ITERATIONS){
    cout << "" << x << " + " << reverse(x) << " = ";
    x+=reverse(x);
    cout << x;
    if(!is_palindrome(x)){
      cout << ", ";
    }else{
      break;
    }
    i++;
  }
  cout << endl;
}
long long count_iteration(long long x){
  long long i=0;
  while(i<MAX_NUM_ITERATIONS){        
    x = x+reverse(x);
    i++;
    if(is_palindrome(x)){
      return i;
    }
  }
  return -1;
}
// TODO 5: Receive the user input and print out the result
int main(void)
{              
    start:                      
    long long k=0;    
    while(k<1||k>10000){
      cout << "Enter a natural number (1-10000): ";
      cin >> k;      
    }
    if(is_palindrome(k)){
      cout << "Originally, " << k << " is a palindromic number." << endl;
    }else if(make_palindrome(k)==-1){
      cout << k << " is a lychrel number." << endl;
    }else{
      cout << k << " becomes palindromic after "<< count_iteration(k) <<" iteration(s): ";
      print_derivation(k);
    }
    goto start;
    return 0;
}