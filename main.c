// אחמד שמאסנה 212478994
#include <stdio.h>
#define true 1
#define false 0
#include <limits.h>
//defining the functions.
int nextPrime(int);
int isPrime(int);
int isPalindrom(int);
int containsNonPrimesDigitsOnly(int);
int isSpecial(int num);
void printAllSpecial(int from, int to);
 //checking which number is prime after the given num.
int nextPrime(int num) {
     int i;
     if (num < 2)
         return 2;
     for (i=num+1; i< INT_MAX; i++) {
    if(isPrime(i)==true){
        return i;
    }

        }
    }
//checking if the given num is prime or not(it is a function refer to nextprime function).
int isPrime(int num) {
    int i;
    if (num < 2)
        return false;
    for (i = 2; i < num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}
//checking if the number can be read from the both sides.
    int isPalindrom(int num) {
        int temp, sum=0;
        temp = num;
        while (temp > 0) {
    int temp1=temp%10;
            sum = (sum * 10)+temp1;
            temp /= 10;
        }
        if (sum == num)
            return true;

        return false;


    }
//checking if the number contains a prime digit.
int containsNonPrimesDigitsOnly(int num) {
    int temp;
    temp = num;
    while (temp > 0) {


        if (isPrime(temp%10) == 1)
            return false;
        temp=temp/10;
    }
    return true;

}
//checking if the given num is special (prime + palindrom + containsNonPrimesDigitsOnly)
int isSpecial(int num) {
     if(isPalindrom(num)==1&& containsNonPrimesDigitsOnly(num)==1&& isPrime(num)==1)
         return 1;
     return 0;

}
//printing all the numbers between the given nums "from,to".
void printAllSpecial(int from, int to){
     for(int i=from; i<=to; i++){
         if(isSpecial(i)==1)
             printf("the special numbers is: %d \n",i);
     }
 }

