#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generate_r(char *str,int k,int m,int pos,char *sol,int l,int* mark);

void generate(char *str,int n,int m)
{
    int l,j,i,*mark;
    char *sol;
    l=strlen(str);
    mark=calloc(l,sizeof(int));

    sol=malloc(n*sizeof(char));

    if(sol == NULL || mark == NULL)
    {
        fprintf(stderr,"memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
    if(n==1)
    {
        for(j=0; j<l; j++)
        {
            if((str[j]-'0')==m)
            {
                printf("%d\n",m);
            }
        }
    }
    else
        for(i=n; i>=1; i--)
        {
            generate_r(str,i,m,0,sol,l,mark);
        }
    free(sol);
}

void generate_r(char *str,int k,int m,int pos,char *sol,int l,int* mark)
{
    int flag,sum,i;
    if(pos>=k)
    {
        flag = 1;
        sum = 0;

        for(i=0; i<k; i++)
        {
            sum+=sol[i]-'0';
        }
        if(sum!=m)
        {
            flag =0;
            sum =0;
        }
        if(flag ==1)
        {
            printf("{");
            for(i=0; i<pos; i++)
            {
                printf(" %c ",sol[i]);
            }
            printf("}");
        }
        return;
    }
    for(i=0; i<l; i++)
    {
        if(mark[i]==0){
        mark[i]==1;
        sol[pos]=str[i];
        generate_r(str,k,m,pos+1,sol,l,mark);
        mark[i]=0;
        }
    }
    return;
}

int main()
{
    char *str="1234567890";
	generate(str, 2, 9);

	return 0;
}
