
/*
Siddharth Gautam
Bingo game*/

#include <stdio.h>
#include <stdlib.h>

void printcard(int bingo[][5]);
void fillcard(int bingo[][5]);
int PickNumber( int bingo[][5], int array[75]);
int numberexits (int bingo[][5], int picknum);
int completerow(int bingo[][5]);
int completecolumn(int bingo[][5]);
int diagonalcheck(int bingo[][5]);


void fillcard(int bingo[][5])
{
    int i,j,k,x=0;
    int range= 15;
    int min= 0;
	srand(time(0));
    for(i= 0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            x=  (rand()% (range)+1)+ min;
			for (k=0; k<5; k++)
			{
				if (bingo[k][i]==x)
				{
					 x=  (rand()% (range)+1)+ min;
					 k=-1;
				}
			}
				bingo[j][i]= x;
			
            if( i==2 && j==2)
            {
                bingo[2][2]= 0;
            }
        }
        min +=15;    
    }
}

void printcard(int bingo[][5])
{
int i,j,k=0;

	printf("\tB\t\tI\t\tN\t\tG\t\tO\n");
	for (i= 0; i<= 77; i++) 
	printf("-"); 
	printf("\n");
	for (i= 0; i< 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
			if(bingo[i][j]==0)
				printf("|\tX\t");
			else
				printf("|\t%d\t", bingo[i][j]);
        }
          printf("|\n");
        for(k=0; k<77; k++)
        {
            printf("-");
        }
        printf("\n");
    }
}

int PickNumber( int bingo[][5], int array[])
{
	int i;
	int x= rand()%76;
	for (i= 0; i<75; i++)
	{
		if(array[i] == x)
		{
			i=0;
			x= rand()%76;
			
		}
	}
	array[i]=x;
	return array[i];
	
}	
		
int numberexits (int bingo[][5], int picknum)
{
	int i, j, numexists=0;
	
	for (i=0;i<5;i++)
	{
		for(j=0; j<5; j++)
		{
			if(bingo[j][i] == picknum)
			{
				bingo[j][i]=0;
				numexists=1;	
			}
		}
	}
	return numexists;
}

int completerow(int bingo[][5])
{
	int i,j,check, rowcheck=0;
	
	for (i=0;i<5;i++)
	{
		rowcheck=0;
		for(j=0; j<5; j++)
		{
			if(bingo[i][j] == 0)
			{
				rowcheck+= 1;
			}
		}
		if(rowcheck==5)
		{
			check=1;
			i=6;
			printf(" You filled out a row - BINGO!!!\n"	);
		}
		
		else 
		{
			check=0;
		}
	}
	return check;

}
int completecolumn(int bingo[][5])
{
	int i,j,check, columncheck=0;
	for (i=0;i<5;i++)
	{
		columncheck=0;
		for(j=0; j<5; j++)
		{
			if(bingo[j][i] == 0)
			{
				columncheck+= 1;
			}
		}
		if(columncheck==5)
		{
			check=1;
			i=6;
			printf(" You filled out a column - BINGO!!!\n");
		}
		else
		{
			check=0;
		}
	}
	return check;
}		
int diagonalcheck(int bingo[][5])
{
	int check;
	int diagcheck=0;
	
		if (bingo[0][0]==0 && bingo[1][1] == 0 && bingo[2][2]==0 && bingo[3][3]==0 && bingo[4][4]==0 )
		{
			diagcheck=1;
		}
		else if (bingo[4][0]==0 && bingo[3][1] == 0 && bingo[2][2]==0 && bingo[1][3]==0 && bingo[0][4]==0 )
		{
			check=0;
		}
	
	return check;
}

int main(void)
{
    int bingo[5][5]={};
	int numexists=0, Number=0;
	char YN;
	int array[75] = {};
		
	fillcard(bingo);
    printcard(bingo);
	
	while (completerow(bingo)==0 && completecolumn(bingo)==0  && Number<75)
	{
		int picknum = PickNumber(bingo, array);
		if(picknum >0 && picknum <=15)
			printf("The next number is B%d. \n", picknum);
		else if(picknum >15 && picknum <=30)
			printf("The next number is I%d. \n", picknum);
		else if(picknum >30 && picknum <=45)
			printf("The next number is N%d. \n", picknum);
		else if(picknum >45 && picknum <=60)
			printf("The next number is G%d. \n", picknum);
		else if(picknum >60 && picknum <=75)
			printf("The next number is O%d. \n", picknum);
		Number++;
		printf("Do you have it? (Y/N) ");
		scanf(" %c", &YN);
		if (YN== 'Y' || YN == 'y')
		{
			numexists = numberexits(bingo, picknum);
			printcard(bingo);
			if(numexists ==0)
			{
				printf("That value is not on your BINGO card - are you trying to cheat??\n");
			}
			else
			{
				completerow(bingo);
				completecolumn(bingo);
				diagonalcheck(bingo);
			}
		}
		else
			printcard(bingo);
		
	}	
		
    return 0; 
}
		
