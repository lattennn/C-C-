/*
 ============================================================================
 Name        : cars.c
 Author      : Yufeng Duan
 Version     :
 Copyright   : Copyright reserved
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

#define N 5
#define NEW 1
#define USED 0

typedef struct sname{//3 fields
    char brand[10];
    int price;
    int status;
}Car;

int main()
{
    int i, j, minprice, p;
    Car cars[N], temp;
    char thestate[10];
    char status[10];
    //status = "abc\0\0\0\0\0\0\0" is a string
    //status = "a,b,c,d,e,f,g,h,i,j" is a character-array

    //String's definition :character array with termination \0,所以一般情况下(strlen(s)+1)作为维度 去给一个string分配数组空间 +1 为了给换行符位置
    //character array != string


    // Let the user enter the information of the cars
    for(i=0; i<N; i++){
        printf("Enter the information(brand,price,status) of the car %d: ", i+1);//%c ->character %s->string
        scanf("%s%d%s", cars[i].brand, &cars[i].price,status);//&ȡֵ ->& means get the address
        if(strcmp(status, "new") == 0)//strcmp(A,B)>0 means means srtingA> stringB strcmp(A,B)<0 means stringA < stringB   eg: cc < cd
            cars[i].status = NEW; //alphebetically
        else
            cars[i].status = USED;
    }
    //Insertion Sorting the cars by their prices
    for (i = 1; i<N; i++) {
        temp = cars[i];
        for(j=i-1; j >= 0 && temp.price < cars[j].price; j--) { // This is actually insertion sort
            cars[j+1] = cars[j];
        }
        cars[j+1] = temp;
    }

    // Print the cars
    for (i = 0; i <N; i++) {
        if(cars[i].status == 1){
            printf("%s %d %s\n", cars[i].brand, cars[i].price,cars[i].status==NEW?"new":"used");
        }
       //->Optional strcpy(thestate,cars[i].status==NEW?"new":"used");
       // printf("%s %d %s\n", cars[i].brand, cars[i].price,thestate);//cars[i].status==NEW?"new":"used" );
    }

    // Find the cheapest new car

    minprice = 1000000; // a very large number
    p = -1;
    for(i=0; i<N; i++){
        if(cars[i].status == NEW && cars[i].price < minprice){
            minprice = cars[i].price;
            p = i;
        }
    }

    // Result
    if(p == -1)
        printf("No new cars inserted\n");
    else
        printf("The cheapset new is %s with the price of %d\n", cars[p].brand, minprice);

    return 0;
}

