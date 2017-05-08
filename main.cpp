#include <iostream>
using namespace std;
/*
 * created by musab
 * This function converts integers from 0 to 1000000000 into Turkish words
 */
string convertIntToWord(long num){
    //Corner cases:
    switch(num) {
        case 0:          return "sıfır";
        case 1:          return "bir";
        case 2:          return "iki";
        case 3:          return "üç";
        case 4:          return "dört";
        case 5:          return "beş";
        case 6:          return "altı";
        case 7:          return "yedi";
        case 8:          return "sekiz";
        case 9:          return "dokuz";
        case 10:         return "on";
        case 20:         return "yirmi";
        case 30:         return "otuz";
        case 40:         return"kırk";
        case 50:         return "elli";
        case 60:         return "altmış";
        case 70:         return "yetmiş";
        case 80:         return "seksen";
        case 90:         return "doksan";
        case 100:        return "yüz";
        case 1000:       return "bin";
        //million:
        case 1000000:    return "bir milyon";
        //billion:
        case 1000000000: return "bir milyar";
    }
    //between 0 - 100
    for (long i = 1; i < 10; ++i) {
        long l = i * 10;
        if( l < num && l+10 >num){
            long t = num - l;
            if (t>0)
                return convertIntToWord(l) + " " + convertIntToWord(t);
            else
                return convertIntToWord(l) + "";
        }
    }
    //between 100-1000
    for (long i = 1; i < 10; ++i) {
        long l = i * 100;
        if( l <= num && l+100 >num){
            long t = num - l;
            if (t>0){
                if(num/100!=1) // if the num is xyz where x != 1
                    return convertIntToWord(num/100) + " yüz " + convertIntToWord(t);
                else // if the num is 1xy
                    return convertIntToWord(num-t) + " " + convertIntToWord(t);
            }
            else
                return convertIntToWord(num/100) + " yüz";
        }
    }
    //between 1000-1000000
    for (long i = 1; i < 1000; ++i) {
        long l = i * 1000;
        if( l <= num && l+1000 >num){
            long t = num - l;
            if (t>0){
                if(num/100!=1) // if the num is xyz wthere x != 1
                    return convertIntToWord(num/1000) + " bin " + convertIntToWord(t);
                else // if the num is 1xyz
                    return convertIntToWord(num-t) + " " + convertIntToWord(t);
            }
            else
                return convertIntToWord(num/1000) + " bin";
        }
    }
    //between 1000000-1000000000
    for (long i = 1; i < 1000; ++i) {
        long l = i * 1000000;
        if( l <= num && l+1000000 >num){
            long t = num - l;
            if (t>0){
                if(num/100!=1) // if the num is xyz wthere x != 1
                    return convertIntToWord(num/1000000) + " milyon " + convertIntToWord(t);
                else // if the num is 1xyz
                    return convertIntToWord(num-t) + " " + convertIntToWord(t);
            }
            else
                return convertIntToWord(num/1000000) + " milyon";
        }
    }
}
int main() {
    int num;
    cout<<"Enter an integer to convert: ";
    cin>>num;
    cout<<"Converted in Turkish is: " + convertIntToWord(num);
    return 0;
}
