#include<stdlib.h>
#include<float.h>
#include<stdio.h>

#define N 10
#define MAX_N 10
//permutation

//input parameters
int taken[MAX_N] = {0};//mark array in the slides
float sol[MAX_N] = {0};//current solution
float best_sol[MAX_N] = {0};//solution with minimum balance difference
float best_diff = FLT_MAX;//minimum balance difference
float mov[MAX_N] = {1,-2,3,14,-5,16,7,8,-9,120};
float min, max;

void evaluate(float *v);

void evaluate(float *v) {
  int i;
  float tot = 0, cmin = FLT_MAX, cmax = FLT_MIN;

  for(i=0;i<N;i++) {
    tot += v[i];
    cmin = tot < cmin ? tot : cmin;
    cmax = tot > cmax ? tot : cmax;
  }

  if ((cmax - cmin) < best_diff) {
    best_diff = cmax-cmin;
    for(i=0;i<N;i++) {
      best_sol[i] = v[i];//v is sol
    }
    min = cmin;
    max = cmax;
  }
}

void permute(int start) {//start is pos in the slides
  if (start == N) {
    evaluate(sol);
    return;
  }

  int i;
  for(i=0;i<N;i++) {
    if (taken[i]) continue;
    taken[i] = 1;
    sol[start] = mov[i];
    permute(start +1);
    taken[i] = 0;
  }
  return;
}

int main(int argc, char **argv) {
  int i;
  float init = 0;

  permute(0);

  printf("The best ordering is: \n");
  for(i=0;i<N;i++) {
      printf("%.1f ", best_sol[i]);
  }
  printf("\n");
  printf("[Max balance = %.1f  Min balance =  %.1f Minimum difference = %.1f]\n",
    max, min, best_diff);

  return 0;
}
