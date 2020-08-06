
# From labuladong:https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/er-fen-cha-zhao-xiang-jie
# Smart way:

int binarySearch(int[] nums, int target) {
    int left = 0; 
    int right = nums.length - 1; // 注意

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid; 
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}







#STUPID WAY:


#include <stdio.h>
#include <stdlib.h>
#define N 10

 // 判断多个条件时 条件和条件之间的关系 一般都是 && AND 同时成立 ||OR 其中一个成立

int main()
{
    int n,i,right,left,mid,flag;
    int a[N]={33,35,45,66,78,96,100,189,267,354};//sorted array

    printf("enter one number \n");
    scanf("%d",&n);

    flag=0;
    left=0;
    right=N-1;
    mid=(left+right)/2;
    while( left<right && mid>=0 && mid<=N-1 ){//mid go out as soon as left==right or left > right
        if(left==right-1){ //只要left和right指针相邻 如果不写这部 mid永远会等于left 然后会无限循环 无法退出
            if(a[left]==n){
                mid=left;
                flag=1;
                break;
            }
            else if(a[right]==n){
                mid=right;
                flag=1;
                break;
            }
            else{
                break;
            }
        }
        else{
            mid=(left+right)/2;
        }

    ///////上面的if 和else是一起的
    // 下面的if else if 和else 是一起的
        if(a[mid]<n){
            left=mid;
        }
        else if(a[mid]>n){
            right=mid;
        }
        else if(a[mid]==n){
            flag=1;
            break;
        }
        else{
            break;//为了严谨 写上 其实一般没有这个情况
        }
    }

    if(a[mid]==n || flag==1){
        printf("found!in the position %d of the array \n",mid+1);
    }
    if(flag==0){
        printf("not found\n");
    }
    return 0;
}
