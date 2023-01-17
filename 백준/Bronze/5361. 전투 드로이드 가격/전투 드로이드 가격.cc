#include <iostream>

using namespace std;

int main ()
{
  int t;
  float sum;
  int a, b, c, d, e;
  scanf("%d", &t);
  
  for(int i = 0; i < t; i++) {
      scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
      sum = a * 350.34 + b * 230.90 + c * 190.55 + d * 125.30 + e * 180.90;
      printf("$%.2f\n", sum);
      
  }
  
  return 0;
}