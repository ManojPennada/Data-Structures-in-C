1ST QUESTION  ( *Sparse Matrix printing)


#include<stdio.h>
int main()
{
    int m,n,i,j;
    scanf("%d",&m);
    int tuple[m][3],a,b,c;
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        scanf("%d",&tuple[i][j]);
    }
    a=tuple[0][0];
    b=tuple[0][1];
    c=tuple[0][2];
    int sparse[a][b];
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        sparse[i][j] = 0;
    }
    int row,col,value;
    for(i=1;i<m;i++)
    {
        row = tuple[i][0];
        col = tuple[i][1];
        value = tuple[i][2];
        sparse[row][col] = value;
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        printf("%d\t",sparse[i][j]);
        printf("\n");
    }
    return 0;
}

2nd question: (*Tuple Matrix Printing)


#include<stdio.h>
int main()
{
    int array[10][10],m,n,i,j,flag=0;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&array[i][j]);
            if(array[i][j]!=0) flag++;
        }
    }
    int tuple[flag+1][3],c=1;
    tuple[0][0] = m;
    tuple[0][1] = n;
    tuple[0][2] = flag;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(array[i][j]!=0)
            {
                tuple[c][0]=i;
                tuple[c][1]=j;
                tuple[c][2]=array[i][j];
                c++;
            }
        }
    }
    for(i=0;i<=flag;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",tuple[i][j]);
        }
        printf("\n");
    }
}






