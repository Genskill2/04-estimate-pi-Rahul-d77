#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int);

float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}



float mc_pi(int n)
 { 
  int count_square=0;
  int count_circle=0;
  for(int i=0;i<n;i++)
   {float x=frandom();
    float y=frandom();
    float a=pow(x, 2);
    float b=pow(y, 2);
    float c=a+b;      
     if(pow(c,0.5)<=1)
         {
           count_circle++;
         }
       count_square++;
   }
    float d=(float)count_circle/(float)count_square;
    return 4*d;
 } 

