#include<math.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double lenCurve(int n) {
   double interval = 1.0 / (double) n;
   double position = interval;
   double length = 0;
   
   while(position < (1.0 + interval)){
   length += sqrt(pow(interval, 2) + pow(pow(position - interval ,2) - pow(position, 2) ,2));
   printf("%lf\n", position);
   position += interval;
   }
   return length;
}

int main(){

	printf("%lf\n", lenCurve(10));
}
