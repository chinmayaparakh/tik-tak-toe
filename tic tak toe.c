#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int i;
    int j;
    int value;
}arr[9];

char a[3][3];

//linked start from here till pop function.

struct nod
{
    int data;
    struct nod* next;
};

struct nod* head=NULL;
struct nod* tail;

void push(int a)
{
    struct nod* newnode=(struct nod*)malloc(sizeof(struct nod));
    newnode->data=a;
    newnode->next=head;
    head=newnode;

}

void pop()
{
    if(head->next==NULL)
        head=NULL;
    head=head->next;

}



int result(char r[3][3])
{int i,c=0;
    if(r[0][0]==r[1][1] && r[1][1]==r[2][2] && (r[1][1]=='O' || r[1][1]=='X'))
    {if(r[0][0]=='O')
       return 0;
    else
        return 1;

    }
    else if(r[0][2]==r[1][1] && r[1][1]==r[2][0] && (r[1][1]=='O' || r[1][1]=='X'))
    {if(r[0][2]=='O')
        return 0;
    else
        return 1;

    }
    for(i=0;i<3;i++)
        {
            if(r[i][0]==r[i][1] && r[i][1]==r[i][2] && (r[i][1]=='O' || r[i][1]=='X'))
            {if(r[i][0]=='O')
               return 0;
            else
               return 1;

            }
            else if(r[0][i]==r[1][i] && r[1][i]==r[2][i] && (r[1][i]=='O' || r[1][i]=='X'))
            {if(r[0][i]=='O')
                return 0;
            else
                return 1;

            }
            for(int j=0;j<3;j++)
            {
                if(r[i][j]==' ')
                {
                    c++;
                }
            }

        }
        if(c==0)
        {
            return -1;

        }



}

void print(char r[3][3])
{
    for(int i=0; i<3; i++)
    {printf("                                                        ");
        for(int j=0; j<3; j++)
        {
            if(j==1)
                printf("| %c |",r[i][j]);


            else
                printf(" %c ",r[i][j]);
        }
        printf("\n");
        if(i==0 || i==1)
            printf("                                                        --- --- ---\n");

    }
    printf("------------------------------------------------------------------------------------------------------\n");
}

char undo(char r[3][3], struct node n[],char xox)
{

    for(int k=0; k<9;k++)
    {
        if(n[k].value==head->data)
        {
            r[n[k].i][n[k].j]=' ';
        }
    }
    pop();

if(xox=='O')
{
    return 'X';
}
else
{
    return 'O';
}

}

int main()
{int k,l,n=0,u[9],m=6;
char ch='O',name[50],nam[50];
    for(k=0;k<3;k++)
    {
        for(l=0;l<3;l++)
        {m++;
            arr[n].i=k;
            arr[n].j=l;
            arr[n].value=m;
            a[k][l]=' ';
            n++;
        }
        m=m-6;
    }

printf("INSTRUCTIONS:-\n(i) From number 1 to 9 each number represent a cell of tic tac toe.\n(ii) Insert the number on number pad as each number represent respective cell of tic tac toe.\n(iii) The action that you have taken will be printed on the screen.\n(iv)For undo insert '0'.\n(v)First chance is of 'Player O'.\n(vi)Let the game begin.\n");

printf("\nPlease enter the name of Player O:");
gets(name);

printf("\nPlease enter the name of Player X:");
gets(nam);


first:
if(ch=='O')
    printf("\nPLAYER O TURN");
else
    printf("\nPLAYER X TURN");

printf("\nEnter the position.\n");
scanf("%d",&n);
if(n==0)
{
    ch=undo(a,arr,ch);
    print(a);
    goto first;
}
else if(n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=6 && n!=7 && n!=8 && n!=9)
  {
      goto first;
  }

tail=head;
while(tail!=NULL)
{
    if(n==tail->data)
    {printf("Don't repeat the number.");
        goto first;
    }
    tail=tail->next;
}

push(n);//via linked list

switch(ch)
{
case 'O':
        for(k=0;k<9;k++)
        {
            if(arr[k].value==n)
            {
                a[arr[k].i][arr[k].j]=ch;
            }
        }
        ch='X';
        break;
case 'X':
        for(k=0;k<9;k++)
        {
            if(arr[k].value==n)
            {
                a[arr[k].i][arr[k].j]=ch;
            }
        }
        ch='O';
        break;
}

print(a);
if(result(a)==0)
    {
        printf("Congratulations!!! Winner is:%s",name);
        exit(0);
    }
else if(result(a)==1)
    {
        printf("Congratulations!!! Winner is:%s",nam);
        exit(0);
    }
else if(result(a)==-1)
    {
        printf("Match is a Draw");
        exit(0);
    }

goto first;


}
