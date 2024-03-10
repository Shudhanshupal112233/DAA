#include<stdio.h>
#include<time.h>
int  fib(int n){
    if(n<=1){
        return n;
    }
    else{
       return fib(n-1)+fib(n-2); 
       
    }}
    double comput_time(int n){
        clock_t start,end;
        double cpu_time;
        start = clock();
        fib(n);
        end=clock();
        cpu_time= ((double)(end-start))/CLOCKS_PER_SEC;
        return cpu_time;
    }


int main(){
    int n=13;
    printf("fibbonaci series %d\n",fib(n));
    printf("time taken %f",comput_time(n));
    

}