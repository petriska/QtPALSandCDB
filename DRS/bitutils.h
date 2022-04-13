#ifndef bitutils_H
#define bitutils_H
#include <cmath>

inline void dec2bin(int indec, int len ){
using namespace std;
long ndec =  indec % (long)(pow(2.0,len)); // truncating to max length!
  for (int i = len -1 ; i >= 0; i--)
      {
        long pw = (long)pow(2.0,i);
        if ( ndec - pw >= 0 ) {
            printf("1");
            ndec -= pw;
        }else{
            printf("0");
        }
    }
}

#endif
