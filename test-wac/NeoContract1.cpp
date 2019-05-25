//#include <stdio.h>

struct X
{
  int method();
  int k;
};


void nop();

int main () {
    nop();
    X x;
    x.k = 10;
    if(x.method()>5)
      x.k+=2;

    //printf("ola mundso!\n");
    return x.k;
}

