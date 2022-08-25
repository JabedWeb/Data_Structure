//the sum of every diagonal,column,row is equal to 15
//addition of every row and column and both diagonal in same constant n(n^2+1)/2
/*2 7 6
9 5 1
4 3 8
*/

#include<stdio.h>

const int row;
const int col;

int magicSquare(int array[row][col],int i,int j,int *sum)
{
    int diagonal1=0,diagonal2=0,sumRow=0,sumCol=0,flag=-1;

    //check row and col are same constant or not


    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i==j)
            {
                *sum=*sum+array[i][j];
                diagonal1=diagonal1+array[i][j];
            }
            if(i+j==2)
            {
                diagonal2=diagonal2+array[i][j];
            }
        }
    }
    if(diagonal1!=diagonal2)
    {
        flag=-1;
        return flag;
    }
    else
    {

        for(int i=0; i<3; i++)
        {
        sumRow=0;
        sumCol=0;
            for(int j=0; j<3; j++)
            {
                sumRow=sumRow+array[i][j];
                sumCol=sumCol+array[j][i];
            }

            if(sumRow!=diagonal1)
            {
                flag=-1;
            }
            else if(sumCol!=diagonal2){
                flag=-1;
            }
            else{
                flag=1;
            }
        }
    }
    return flag;
}


int main()
{
    printf("Please enter the desire grid dimension:  ");
    scanf("%d %d",&row,&col);

    printf("Please enter the desired input:\n");

     printf("\n");

    int array[row][col],i,j,sum=0;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
    int isMagicSquare= magicSquare(array,i,j,&sum);

    if(isMagicSquare==-1)
    {
        printf("This is not Lo Shu Magic Square.");
    }
    else
    {
        printf("This is a Lo Shu Magic Square.\n");
        printf("And, the magic number is %d.\n",sum);
        printf("\n");
        printf("\n");
        printf("Thank you!!!");
    }
    return 0;
}

