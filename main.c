#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char lose_from_white[16];
char lose_from_black[16];
int countw=0,countb=0;

char BW[8][8];
char BW1[8][8];
char test[8][8];


int make_ch_num(char a);


void print_board();


int pawn1(int x ,int l,int y ,int m);  //WHITE
int pawn2(int x ,int l,int y ,int m) ; //BLACK
int knight1(int x ,int l,int y ,int m);  //white
int knight2(int x ,int l,int y ,int m) ; //Black
int rook1(int x,int l,int y,int m)  ;//White
int rook2(int x,int l,int y,int m)  ;//Black
int bishop1(int x ,int l,int y ,int m);  //WHITE
int bishop2(int x ,int l,int y ,int m) ; //BLACK
int queen1(int x,int l,int y,int m) ; //White
int queen2(int x,int l,int y,int m)  ;//Black
int king1(int x ,int l,int y ,int m)  ;//WHITE
int king2(int x ,int l,int y ,int m)  ;//BLACK




int make_ch_num(char a)
{
  int z,i;
  int found;
  char ch[8]={'A','B','C','D','E','F','G','H'};
  for(i=0;i<8;i++)
  {
    found=0;
    if(a==ch[i])
    {
        found=1;
    }
    if(found==1)
    {
        z=i;
    }
 }
 return z;
}




void print_board()
{
    int i,j;
    printf(" \t\t                      Chess Game           \n\n");
    printf(" \t\t      A     B     C     D     E     F     G     H\n\n");
    printf("    %s",lose_from_black);
    for(i=0;i<8;i++)
    {
        printf("\t\t %d    ",i+1);
        for(j=0;j<8;j++)
        {
            printf("%c     ",BW[i][j]);
        }
        printf("\n\n\n");
    }
    printf("    %s",lose_from_white);
}


void print_test()
{
    int i,j;
    printf(" \t\t                      Chess Game test           \n\n");
    printf(" \t\t      A     B     C     D     E     F     G     H\n\n");
    printf("    %s",lose_from_black);
    for(i=0;i<8;i++)
    {
        printf("\t\t %d    ",i+1);
        for(j=0;j<8;j++)
        {
            printf("%c     ",test[i][j]);
        }
        printf("\n\n\n");
    }
    printf("    %s",lose_from_white);
}

void save()
{
    FILE *file;
    fopen("Chess.TXT","W");
    int i,j;
    fprintf(file,"\n");
    fprintf(file," \t    A   B   C   D   E   F   G   H\n\n");
    for(i=0;i<8;i++)
    {
        fprintf(file," \t %d  ",i+1);
        for(j=0;j<8;j++)
        {
            fprintf(file,"%c   ",BW[i][j]);
        }
            fprintf(file,"\n\n");
    }
    fclose(file);
}

/*void load()
{
    FILE *file;
    fopen("Chess.TXT","W");
    int i,j;
    fscanf(file," %c %d %c %d",&v,&x,&t,&l);
    fclose(file);
}*/




int self_check1(int x,int l,int y,int m)
{
    int get=0,i,j,not_valid=0;
    char z,u;
    z=test[y][m];
    u=test[x][l];
    test[y][m]=test[x][l];
    test[x][l]=BW1[x][l];
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(test[i][j]=='k')
            {
                get=1;
                break;
            }
        }
        if(get==1)
        {
            break;
        }
    }
    if(BW[x][l]=='p')
    {
            for(int a=0;a<8;a++)
            {
                for(int c=0;c<8;c++)
                {
                    if(test[a][c]=='P')
                    {
                        if(pawn2(a,c,i,j)==2)
                        {
                            not_valid=1;
                        }
                    }
                    else if(test[a][c]=='N')
                    {
                        if(knight2(a,c,i,j)==0)
                        {
                            not_valid=1;
                        }
                    }
                    else if(test[a][c]=='B')
                    {
                        if(bishop2(a,c,i,j)==0)
                        {
                            not_valid=1;
                        }
                    }
                    else if(test[a][c]=='R')
                    {
                        if(rook2(a,c,i,j)==0)
                        {
                            not_valid=1;
                        }
                    }
                    else if(test[a][c]=='Q')
                    {
                        if(queen2(a,c,i,j)==0)
                        {
                            not_valid=1;
                        }
                    }
                    else if(test[a][c]=='K')
                    {
                        if(king2(a,c,i,j)==0)
                        {
                            not_valid=1;
                        }
                    }
            }
        }
    }

            else if(BW[x][l]=='n')
            {
                    for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='P')
                            {
                                if(pawn2(a,c,i,j)==2)
                                {
                                   not_valid=1;
                                }
                            }
                            else if(test[a][c]=='N')
                            {
                              if(knight2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='B')
                            {
                               if(bishop2(a,c,i,j)==0)
                                {
                                not_valid=1;
                                }
                            }
                            else if(test[a][c]=='R')
                            {
                              if(rook2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }else if(test[a][c]=='Q')
                            {
                             if(queen2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='K')
                            {
                              if(king2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                        }
                    }
                }
            else if(BW[x][l]=='b')
            {
                    for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='P')
                            {
                                if(pawn2(a,c,i,j)==2)
                                {
                                   not_valid=1;
                                }
                            }
                            else if(test[a][c]=='N')
                            {
                              if(knight2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='B')
                            {
                               if(bishop2(a,c,i,j)==0)
                                {
                                not_valid=1;
                                }
                            }
                            else if(test[a][c]=='R')
                            {
                              if(rook2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }else if(test[a][c]=='Q')
                            {
                             if(queen2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='K')
                            {
                              if(king2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                        }
                    }
                }

            else if(BW[x][l]=='r')
            {
                    for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='P')
                            {
                                if(pawn2(a,c,i,j)==2)
                                {
                                   not_valid=1;
                                }
                            }
                            else if(test[a][c]=='N')
                            {
                              if(knight2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='B')
                            {
                               if(bishop2(a,c,i,j)==0)
                                {
                                not_valid=1;
                                }
                            }
                            else if(test[a][c]=='R')
                            {
                              if(rook2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }else if(test[a][c]=='Q')
                            {
                             if(queen2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='K')
                            {
                              if(king2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                        }
                    }
                }

            else if(BW[x][l]=='q')
            {
                    for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='P')
                            {
                                if(pawn2(a,c,i,j)==2)
                                {
                                   not_valid=1;
                                }
                            }
                            else if(test[a][c]=='N')
                            {
                              if(knight2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='B')
                            {
                               if(bishop2(a,c,i,j)==0)
                                {
                                not_valid=1;
                                }
                            }
                            else if(test[a][c]=='R')
                            {
                              if(rook2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }else if(test[a][c]=='Q')
                            {
                             if(queen2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='K')
                            {
                              if(king2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                        }
                    }
                }

            else if(BW[x][l]=='k')
            {
                    for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='P')
                            {
                                if(pawn2(a,c,i,j)==2)
                                {
                                   not_valid=1;
                                }
                            }
                            else if(test[a][c]=='N')
                            {
                              if(knight2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='B')
                            {
                               if(bishop2(a,c,i,j)==0)
                                {
                                not_valid=1;
                                }
                            }
                            else if(test[a][c]=='R')
                            {
                              if(rook2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }else if(test[a][c]=='Q')
                            {
                             if(queen2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='K')
                            {
                              if(king2(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                        }
                    }
                }


    test[y][m]=z;
    test[x][l]=u;

    return not_valid;
}



int self_check2(int x,int l,int y,int m)
{
    int get=0,i,j,not_valid=0;
    char z,u;
    z=test[y][m];
    u=test[x][l];
    test[y][m]=test[x][l];
    test[x][l]=BW1[x][l];
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(test[i][j]=='K')
            {
                get=1;
                break;
            }
        }
        if(get==1)
        {
            break;
        }
    }
    if(BW[x][l]=='P')
    {
        for(int a=0;a<8;a++)
        {
            for(int c=0;c<8;c++)
            {
                            if(test[a][c]=='p')  //can capture king
                            {
                                if(pawn1(a,c,i,j)==2)
                                {
                                    not_valid=1;
                                }
                            }
                            else if(test[a][c]=='n')
                            {
                             if(knight1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='b')
                            {
                                if(bishop1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }
                            }
                            else if(test[a][c]=='r')
                            {
                              if(rook1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='q')
                            {
                              if(queen1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if (test[a][c]=='k')
                            {
                                if(king1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }

                            }
                        }
                    }
                }

            else if(BW[x][l]=='N')
            {
                    for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='p')  //can capture king
                            {
                                if(pawn1(a,c,i,j)==2)
                                {
                                    not_valid=1;
                                }
                            }
                            else if(test[a][c]=='n')
                            {
                             if(knight1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='b')
                            {
                                if(bishop1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }
                            }
                            else if(test[a][c]=='r')
                            {
                              if(rook1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='q')
                            {
                              if(queen1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if (test[a][c]=='k')
                            {
                                if(king1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }

                            }
                        }
                    }
                }

            else if(BW[x][l]=='B')
            {
                     for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='p')  //can capture king
                            {
                                if(pawn1(a,c,i,j)==2)
                                {
                                    not_valid=1;
                                }
                            }
                            else if(test[a][c]=='n')
                            {
                             if(knight1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='b')
                            {
                                if(bishop1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }
                            }
                            else if(test[a][c]=='r')
                            {
                              if(rook1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='q')
                            {
                              if(queen1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if (test[a][c]=='k')
                            {
                                if(king1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }

                            }
                        }
                    }
                }

            else if(BW[x][l]=='R')
            {
                     for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='p')  //can capture king
                            {
                                if(pawn1(a,c,i,j)==2)
                                {
                                    not_valid=1;
                                }
                            }
                            else if(test[a][c]=='n')
                            {
                             if(knight1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='b')
                            {
                                if(bishop1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }
                            }
                            else if(test[a][c]=='r')
                            {
                              if(rook1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='q')
                            {
                              if(queen1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if (test[a][c]=='k')
                            {
                                if(king1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }

                            }
                        }
                    }
                }

            else if(BW[x][l]=='Q')
            {
                    for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='p')  //can capture king
                            {
                                if(pawn1(a,c,i,j)==2)
                                {
                                    not_valid=1;
                                }
                            }
                            else if(test[a][c]=='n')
                            {
                             if(knight1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='b')
                            {
                                if(bishop1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }
                            }
                            else if(test[a][c]=='r')
                            {
                              if(rook1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='q')
                            {
                              if(queen1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if (test[a][c]=='k')
                            {
                                if(king1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }

                            }
                        }
                    }
                }

            else if(BW[x][l]=='K')
            {
                    for(int a=0;a<8;a++)
                    {
                        for(int c=0;c<8;c++)
                        {
                            if(test[a][c]=='p')  //can capture king
                            {
                                if(pawn1(a,c,i,j)==2)
                                {
                                    not_valid=1;
                                }
                            }
                            else if(test[a][c]=='n')
                            {
                             if(knight1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='b')
                            {
                                if(bishop1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }
                            }
                            else if(test[a][c]=='r')
                            {
                              if(rook1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if(test[a][c]=='q')
                            {
                              if(queen1(a,c,i,j)==0)
                              {
                                not_valid=1;
                              }
                            }
                            else if (test[a][c]=='k')
                            {
                                if(king1(a,c,i,j)==0)
                               {
                                not_valid=1;
                               }

                            }
                        }
                    }
                }



    test[y][m]=z;
    test[x][l]=u;

    return not_valid;
}




int pawn1(int x ,int l,int y ,int m)  //WHITE
{
    int right=0,not_valid=0;
    if(x==6)
    {
        if(((y==(x-1)) || (y==x-2)) && (m==l) && ((test[y][m]=='-') || (test[y][m]=='+'))) //there is not any piece B/W in front of it
        {
            right=1;
        }
    }
    if((y==x-1) && (m==l) && ((test[y][m]=='-') || (test[y][m]=='+')))
    {
        right=1;
    }
    if((abs(x-y)>2) && (x!=6))
    {
        right=0;
    }
    if((test[y][m]=='R') || (test[y][m]=='N') || (test[y][m]=='B')
        || (test[y][m]=='Q') || (test[y][m]=='P') )
    {
        if(((l==0)&&(m==l+1)&&(y=x-1))||((l==6)&&(y==x-1)&&(m==l-1)))
        {
            lose_from_black[countb]=BW[y][m];
            countb++;
            right=2;
        }
        else if(((m==l+1)&&(y=x-1))||((y==x-1)&&(m==l-1)))
        {
            lose_from_black[countb]=BW[y][m];
            countb++;
            right=2;
        }
    }
    if (right==0)
    {
        not_valid=1;
    }
    else if (right==1)
    {
        not_valid=0;
    }
    else if(right==2) //if p captures right=2 so not_valid=2
    {
        not_valid=2;
    }
    return not_valid;
}


int pawn2(int x ,int l,int y ,int m)  //Black
{
    int right=0,not_valid=0;
    if(x==1)
    {
        if(((y==(x+1)) || (y==x+2)) && (m==l) && ((test[y][m]=='-') || (test[y][m]=='+'))) //there is not any piece B/W in front of it
        {
            right=1;
        }
    }
    if((y==x+1) && (m==l) && ((test[y][m]=='-') || (test[y][m]=='+')))
    {
        right=1;
    }
    if((abs(x-y)>2) && (x!=1))
    {
        right=0;
    }
    if ((test[y][m]=='r') || (test[y][m]=='n') || (test[y][m]=='b')
        || (test[y][m]=='q') || (test[y][m]=='p'))
    {
        if(((l==0)&&(m==l+1)&&(y=x+1))||((l==6)&&(y==x+1)&&(m==l-1)))
        {
            lose_from_white[countw]=BW[y][m];
            countw++;
            right=2;
        }
        else if(((m==l+1)&&(y=x+1))||((y==x+1)&&(m==l-1)))
        {
            lose_from_white[countw]=BW[y][m];
            countw++;
            right=2;
        }
    }
    if (right==0)
    {
        not_valid=1;
    }
    else if(right==1)
    {
        not_valid=0;
    }
    else if(right==2) //if p captures right=2 so not_valid=2
    {
        not_valid=2;
    }
    return not_valid;
}



int knight1(int x ,int l,int y ,int m)  //white
{
    int right=0,not_valid=0;
    if(((y==x+2) && (m==l+1)) || ((y==x+2) && (m==l-1)) || ((y==x-2) && (m==l+1))
        || ((y==x-2) && (m==l-1)) || ((y==x+1) && (m==l+2)) || ((y==x+1) && (m==l-2))
        || ((y==x-1) && (m==l+2)) || ((y==x-1) && (m==l-2)))
    {
        right=1;
    }
    if (right==0)
    {
        not_valid=1;
    }
    if(right==1)
    {
       not_valid=0;
    }
    return not_valid;
}


int knight2(int x ,int l,int y ,int m)  //Black
{
    int right=0,not_valid=0;
    if(((y==x+2) && (m==l+1)) || ((y==x+2) && (m==l-1)) || ((y==x-2) && (m==l+1))
       || ((y==x-2) && (m==l-1)) || ((y==x+1) && (m==l+2)) || ((y==x+1)&&(m==l-2))
       || ((y==x-1) && (m==l+2)) || ((y==x-1)&&(m==l-2)))
    {
        right=1;
    }
    if (right==0)
    {
        not_valid=1;
    }
    if (right==0)
    {
        not_valid=1;
    }
    if(right==1)
    {
       not_valid=0;
    }
    return not_valid;
}


int bishop1(int x ,int l,int y ,int m)  //White
{
    int right=1,i,way=0,not_valid=0,end=0;
    if(abs(x-y) != abs(l-m))
    {
        right=0;
    }
    if(right==0)
    {
        not_valid=1;
    }
    else if(right==1)
    {
        if((x<y) && (l<m)) //right down
        {
            //my way
            for(i=1;(x+i)<=y;i++)
            {
                if((test[x+i][l+i]=='+') || (test[x+i][l+i]=='-'))
                {
                    way=0;
                }
                else if((test[x+i][l+i]=='R') || (test[x+i][l+i]=='N') || (test[x+i][l+i]=='B')
                   || (test[x+i][l+i]=='Q') || (test[x+i][l+i]=='K') || (test[x+i][l+i]=='P')) //can't jump off a black
                {
                    end=1;
                    break;
                }
                else if((test[x+i][l+i]=='r') || (test[x+i][l+i]=='n') || (test[x+i][l+i]=='b')
                   || (test[x+i][l+i]=='q') || (test[x+i][l+i]=='k') || (test[x+i][l+i]=='p'))
                {
                    way=1;
                    break;
                }
            }
            if((end==1) && ((x+i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x+i)==y))
            {
                way=0;
            }
        }
        else if((x<y) && (l>m)) //left down
        {
            //my way
            for(i=1;(x+i)<=y;i++)
            {
                if((test[x+i][l-i]=='+') || (test[x+i][l-i]=='-'))
                {
                    way=0;
                }
                else if((test[x+i][l-i]=='R') || (test[x+i][l-i]=='N') || (test[x+i][l-i]=='B')
                   || (test[x+i][l-i]=='Q') || (test[x+i][l-i]=='K') || (test[x+i][l-i]=='P')) //can't jump off a black
                {
                    end=1;
                    break;
                }
                else if((test[x+i][l-i]=='r') || (test[x+i][l-i]=='n') || (test[x+i][l-i]=='b')
                   || (test[x+i][l-i]=='q') || (test[x+i][l-i]=='k') || (test[x+i][l-i]=='p'))
                {
                    way=1;
                    break;
                }
            }
            if((end==1) && ((x+i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x+i)==y))
            {
                way=0;
            }
        }
        else if((x>y) && (l<m))  //right up
        {
            //my way
            for(i=1;(x-i)>=y;i++)
            {
                if((test[x-i][l+i]=='+') || (test[x-i][l+i]=='-'))
                {
                    way=0;
                }
                else if((test[x-i][l+i]=='R') || (test[x-i][l+i]=='N') || (test[x-i][l+i]=='B')
                   || (test[x-i][l+i]=='Q') || (test[x-i][l+i]=='K') || (test[x-i][l+i]=='P')) //can't jump off a black
                {
                    end=1;
                    break;
                }
                else if((test[x-i][l+i]=='r') || (test[x-i][l+i]=='n') || (test[x-i][l+i]=='b')
                   || (test[x-i][l+i]=='q') || (test[x-i][l+i]=='k') || (test[x-i][l+i]=='p'))
                {
                    way=1;
                    break;
                }
            }
            if((end==1) && ((x-i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x-i)==y))
            {
                way=0;
            }
        }
        else if((x>y) && (l>m)) //left up
        {
            //my way
            for(i=1;(x-i)>=y;i++)
            {
                if((test[x-i][l-i]=='+') || (test[x-i][l-i]=='-'))
                {
                    way=0;
                }
                else if((test[x-i][l-i]=='R') || (test[x-i][l-i]=='N') || (test[x-i][l-i]=='B')
                   || (test[x-i][l-i]=='Q') || (test[x-i][l-i]=='K') || (test[x-i][l-i]=='P')) //can't jump off a black
                {
                    end=1;
                    break;
                }
                else if((test[x-i][l-i]=='r') || (test[x-i][l-i]=='n') || (test[x-i][l-i]=='b')
                   || (test[x-i][l-i]=='q') || (test[x-i][l-i]=='k') || (test[x-i][l-i]=='p'))
                {
                    way=1;
                    break;
                }
            }
            if((end==1) && ((x-i)!=y))
            {
                not_valid=1;
                way=1;
            }
            else if((end==1) && ((x-i)==y))
            {
                way=0;
            }
        }
        if(way==0)
        {
           not_valid=0;
        }
        else if(way==1)
        {
            not_valid=1;
        }
    }
    return not_valid;
}


int bishop2(int x ,int l,int y ,int m)  //BLACK
{
    int right=1,i,way=0,th_k=0,not_valid=0,end=0;
    if(abs(x-y) != abs(l-m))
    {
        right=0;
    }
    if(right==0)
    {
        not_valid=1;
    }
    else if(right==1)
    {
        if((x<y) && (l<m)) //right down
        {
            //my way
            for(i=1;(x+i)<=y;i++)
            {
                if((test[x+i][l+i]=='+') || (test[x+i][l+i]=='-'))
                {
                    way=0;
                }
                else if((test[x+i][l+i]=='r') || (test[x+i][l+i]=='n') || (test[x+i][l+i]=='b')
                   || (test[x+i][l+i]=='q') || (test[x+i][l+i]=='k') || (test[x+i][l+i]=='p')) //can't jump off a white
                {
                    end=1;
                    break;
                }
                else if((test[x+i][l+i]=='R') || (test[x+i][l+i]=='N') || (test[x+i][l+i]=='B')
                   || (test[x+i][l+i]=='Q') || (test[x+i][l+i]=='K') || (test[x+i][l+i]=='P'))
                {
                    way=1;
                    break;
                }
            }
            if((end==1) && ((x+i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x+i)==y))
            {
                way=0;
            }
        }
        else if((x<y) && (l>m)) //left down
        {
            //my way
            for(i=1;(x+i)<=y;i++)
            {
                if((test[x+i][l-i]=='+') || (test[x+i][l-i]=='-'))
                {
                    way=0;
                }
                else if((test[x+i][l-i]=='r') || (test[x+i][l-i]=='n') || (test[x+i][l-i]=='b')
                   || (test[x+i][l-i]=='q') || (test[x+i][l-i]=='k') || (test[x+i][l-i]=='p')) //can't jump off a white
                {
                    end=1;
                    break;
                }
                else if((test[x+i][l-i]=='R') || (test[x+i][l-i]=='N') || (test[x+i][l-i]=='B')
                   || (test[x+i][l-i]=='Q') || (test[x+i][l-i]=='K') || (test[x+i][l-i]=='P'))
                {
                    way=1;
                    break;
                }
            }
            if((end==1) && ((x+i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x+i)==y))
            {
                way=0;
            }
        }
        else if((x>y) && (l<m))  //right up
        {
            //my way
            for(i=1;(x-i)>=y;i++)
            {
                if((test[x-i][l+i]=='+') || (test[x-i][l+i]=='-'))
                {
                    way=0;
                }
                else if((test[x-i][l+i]=='r') || (test[x-i][l+i]=='n') || (test[x-i][l+i]=='b')
                   || (test[x-i][l+i]=='q') || (test[x-i][l+i]=='k') || (test[x-i][l+i]=='p')) //can't jump off a white
                {
                    end=1;
                    break;
                }
                else if((test[x-i][l+i]=='R') || (test[x-i][l+i]=='N') || (test[x-i][l+i]=='B')
                   || (test[x-i][l+i]=='Q') || (test[x-i][l+i]=='K') || (test[x-i][l+i]=='P'))
                {
                    way=1;
                    break;
                }
            }
            if((end==1) && ((x-i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x-i)==y))
            {
                way=0;
            }
        }
        else if((x>y) && (l>m)) //left up
        {
            //my way
            for(i=1;(x-i)>=y;i++)
            {
                if((test[x-i][l-i]=='+') || (test[x-i][l-i]=='-'))
                {
                    way=0;
                }
                else if((test[x-i][l-i]=='r') || (test[x-i][l-i]=='n') || (test[x-i][l-i]=='b')
                   || (test[x-i][l-i]=='q') || (test[x-i][l-i]=='p')) //can't jump off a white.
                {
                    end=1;
                    break;
                }
                else if((test[x-i][l-i]=='R') || (test[x-i][l-i]=='N') || (test[x-i][l-i]=='B')
                   || (test[x-i][l-i]=='Q') || (test[x-i][l-i]=='K') || (test[x-i][l-i]=='P'))
                {
                    way=1;
                    break;
                }
            }
            if((end==1) && ((x-i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x-i)==y))
            {
                way=0;
            }
        }
        if(way==0)
        {
           not_valid=0;
        }
        else if(way==1)
        {
            not_valid=1;
        }
    }
    return not_valid;

}



int rook1(int x,int l,int y,int m)  //White
{
	int right=1,i,way=0,not_valid=0,end=0;
	if(x==y)
	{
	    if(m>l)  //right
        {
            for(i=l+1;i<=m;i++)
	  	    {
			    if((test[x][i]=='r') || (test[x][i]=='n') || (test[x][i]=='b')
                   || (test[x][i]=='q') || (test[x][i]=='k') || (test[x][i]=='p'))
		     	{
		     		way=1;
		     		break;
	     		}
	     		if((test[x][i]=='R') || (test[x][i]=='N') || (test[x][i]=='B')
                   || (test[x][i]=='Q') || (test[x][i]=='K') || (test[x][i]=='P'))
		     	{
		     		end=1;
		     		break;
	     		}
    		}
    		if((end==1) && (i!=m))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && (i==m))
            {
                way=0;
            }
        }
        if(m<l)  //left
        {
            for(i=l-1;i>=m;i--)
    		{
	    		if((test[x][i]=='r') || (test[x][i]=='n') || (test[x][i]=='b')
                    || (test[x][i]=='q') || (test[x][i]=='k') || (test[x][i]=='p'))
		    	{
			    	way=1;
			    	break;
	    		}
	    		if((test[x][i]=='R') || (test[x][i]=='N') || (test[x][i]=='B')
                   || (test[x][i]=='Q') || (test[x][i]=='K') || (test[x][i]=='P'))
		     	{
		     		end=1;
		     		break;
	     		}
    		}
    		if((end==1) && (i!=m))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && (i==m))
            {
                way=0;
            }
        }
        if(way==1)
        {
            right=0;
        }
        else if(way==0)
        {
            right=1;
        }
 	}
	else if(l==m)
	{
	    if(y>x)  //down
        {
            for(i=1;x+i<=y;i++)
	  	    {
			    if((test[x+i][l]=='r') || (test[x+i][l]=='n') || (test[x+i][l]=='b')
                    || (test[x+i][l]=='q') || (test[x+i][l]=='k') || (test[x+i][l]=='p'))
		    	{
			    	way=1;
			    	break;
	    		}
	    		if((test[x+i][l]=='R') || (test[x+i][l]=='N') || (test[x+i][l]=='B')
                   || (test[x+i][l]=='Q') || (test[x+i][l]=='K') || (test[x+i][l]=='P'))
		     	{
		     		end=1;
		     		break;
	     		}
    		}
    		if((end==1) && ((x+i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x+i)==y))
            {
                way=0;
            }
        }
        if(y<x)  //up
        {
            for(i=1;(x-i)>=y;i++)
	  	    {
			    if((test[x-i][l]=='r') || (test[x-i][l]=='n') || (test[x-i][l]=='b')
                    || (test[x-i][l]=='q') || (test[x-i][l]=='k') || (test[x-i][l]=='p'))
		    	{
			    	way=1;
			    	break;
	    		}
	    		if((test[x-i][l]=='R') || (test[x-i][l]=='N') || (test[x-i][l]=='B')
                   || (test[x-i][l]=='Q') || (test[x-i][l]=='K') || (test[x-i][l]=='P'))
		     	{
		     		end=1;
		     		break;
	     		}
    		}
    		if((end==1) && ((x-i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x-i)==y))
            {
                way=0;
            }
        }
        if(way==1)
        {
            right=0;
        }
        else if(way==0)
        {
            right=1;
        }
	}
	else
    {
        right=0;
    }


	//check
	if(right==0)
    {
        not_valid=1;
    }
    else if(right==1)
    {
        not_valid=0;
    }
    return not_valid;
}


int rook2(int x,int l,int y,int m)  //Black
{
	int right=1,i,way=0,not_valid=0,end=0;
	if(x==y)
	{
	    if(m>l)  //right
        {
            for(i=l+1;i<=m;i++)
	  	    {
			    if((test[x][i]=='R') || (test[x][i]=='N') || (test[x][i]=='B')
                   || (test[x][i]=='Q') || (test[x][i]=='K') || (test[x][i]=='P'))
		     	{
		     		way=1;
		     		break;
	     		}
	     		if((test[x][i]=='r') || (test[x][i]=='n') || (test[x][i]=='b')
                  || (test[x][i]=='q') || (test[x][i]=='k') || (test[x][i]=='p'))
		     	{
		     		end=1;
		     		break;
	     		}
    		}
    		if((end==1) && (i!=m))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && (i==m))
            {
                way=0;
            }
        }
        if(m<l)  //left
        {
            for(i=l-1;i>=m;i--)
    		{
	    		if((test[x][i]=='R') || (test[x][i]=='N') || (test[x][i]=='B')
                   || (test[x][i]=='Q') || (test[x][i]=='K') || (test[x][i]=='P'))
		    	{
			    	way=1;
			    	break;
	    		}
	    		if((test[x][i]=='r') || (test[x][i]=='n') || (test[x][i]=='b')
                    || (test[x][i]=='q') || (test[x][i]=='k') || (test[x][i]=='p'))
		     	{
		     		end=1;
		     		break;
	     		}
    		}
    		if((end==1) && (i!=m))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && (i==m))
            {
                way=0;
            }
        }
        if(way==1)
        {
            right=0;
        }
        else if(way==0)
        {
            right=1;
        }
 	}
	else if(l==m)
	{
	    if(y>x)  //down
        {
            for(i=1;(x+i)<=y;i++)
	  	    {
			    if((test[x+i][l]=='R') || (test[x+i][l]=='N') || (test[x+i][l]=='B')
                   || (test[x+i][l]=='Q') || (test[x+i][l]=='K') || (test[x+i][l]=='P'))
		    	{
			    	way=1;
			    	break;
	    		}
	    		if((test[x+i][l]=='r') || (test[x+i][l]=='n') || (test[x+i][l]=='b')
                    || (test[x+i][l]=='q') || (test[x+i][l]=='k') || (test[x+i][l]=='p'))
		     	{
		     		end=1;
		     		break;
	     		}
    		}
    		if((end==1) && ((x+i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x+i)==y))
            {
                way=0;
            }
        }
        if(y<x)  //up
        {
            for(i=1;(x-i)>=y;i++)
	  	    {
			    if((test[x-i][l]=='R') || (test[x-i][l]=='N') || (test[x-i][l]=='B')
                    || (test[x-i][l]=='Q') || (test[x-i][l]=='K') || (test[x-i][l]=='P'))
		    	{
			    	way=1;
			    	break;
	    		}
	    		if((test[x-i][l]=='r') || (test[x-i][l]=='n') || (test[x-i][l]=='b')
                    || (test[x-i][l]=='q') || (test[x-i][l]=='k') || (test[x-i][l]=='p'))
		     	{
		     		end=1;
		     		break;
	     		}
    		}
    		if((end==1) && ((x-i)!=y))
            {
                way=1;
                not_valid=1;
            }
            else if((end==1) && ((x-i)==y))
            {
                way=0;
            }
        }
        if(way==1)
        {
            right=0;
        }
        else if(way==0)
        {
            right=1;
        }
	}
	else
    {
        right=0;
    }

	//check
	if(right==0)
    {
        not_valid=1;
    }
    else if(right==1)
    {
        not_valid=0;
    }
    return not_valid;
}


int queen1(int x,int l,int y,int m)  //White
{
   int not_valid=0;
   if((x==y) || (l==m))  //if queen moves in + direction
   {
       not_valid=rook1(x,l,y,m);
   }
   else if(abs(x-y)==abs(l-m))  //if queen moves in diagonal direction
   {
	   not_valid=bishop1(x,l,y,m);
   }
   else
   {
       not_valid=1;
   }
   return not_valid;
}



int queen2(int x,int l,int y,int m)  //Black
{
    int not_valid=0;
    if((x==y) || (l==m))  //if queen moves in + direction
    {
        not_valid=rook2(x,l,y,m);
    }
    else if(abs(x-y)==abs(l-m))  //if queen moves in diagonal direction
    {
	    not_valid=bishop2(x,l,y,m);
    }
    else
    {
        not_valid=1;
    }
    return not_valid;
}


int king1(int x ,int l,int y ,int m)  //WHITE
{
    int right=0,not_valid=0;
    if(((y==x+1) && (m==l)) || ((y==x+1) && (m==l+1)) || ((y==x+1) && (m==l-1))
       || ((y==x) && (m==l+1)) || ((y==x) && (m==l-1)) || ((y==x-1) && (m==l))
       || ((y==x-1) && (m==l+1)) || ((y==x-1) && (m==l-1)))
    {
        right=1;
    }
    if(right==0)
    {
        not_valid=1;
    }
    if(right==1)
    {
        not_valid=0;
    }
    return not_valid;
}


int king2(int x ,int l,int y ,int m)  //BLACK
{
    int right=0,not_valid=0;
    if(((y==x+1) && (m==l)) || ((y==x+1) && (m==l+1)) || ((y==x+1) && (m==l-1))
       || ((y==x) && (m==l+1)) || ((y==x) && (m==l-1)) || ((y==x-1) && (m==l))
       || ((y==x-1) && (m==l+1)) || ((y==x-1) && (m==l-1)))
    {
        right=1;
    }
    if(right==0)
    {
        not_valid=1;
    }
    if(right==1)
    {
        not_valid=0;
    }
    return not_valid;
}

int check1(int x ,int l,int y ,int m)  //check to player 2
{
    int get=0,i,j,t,h,check=0;
    char u,z;
    z=test[y][m];
    u=test[x][l];
    test[y][m]=test[x][l];
    test[x][l]=BW1[x][l];
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(test[i][j]=='K')
            {
                get=1;
                break;
            }
        }
        if(get==1)
        {
            break;
        }
    }
    for(t=0;t<8;t++)
    {
        for(h=0;h<8;h++)
        {
            if(test[t][h]=='p')
            {
                if(pawn1(t,h,i,j)==2)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='n')
            {
                if(knight1(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='r')
            {
                if(rook1(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='b')
            {
                if(bishop1(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='q')
            {
                if(queen1(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='k')
            {
               if(king1(t,h,i,j)==0)
               {
                    check=1;
                    break;
               }
            }
        }
    }
    test[y][m]=z;
    test[x][l]=u;
    return check;
}


int check2(int x ,int l,int y ,int m)  //check to player 1
{
    int get=0,i,j,t,h,check=0;
    char u,z;
    z=test[y][m];
    u=test[x][l];
    test[y][m]=test[x][l];
    test[x][l]=BW1[x][l];
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(test[i][j]=='k')
            {
                get=1;
                break;
            }
        }
        if(get==1)
        {
            break;
        }
    }
    for(t=0;t<8;t++)
    {
        for(h=0;h<8;h++)
        {
            if(test[t][h]=='P')
            {
                if(pawn2(t,h,i,j)==2)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='N')
            {
                if(knight2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='R')
            {
                if(rook2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='B')
            {
                if(bishop2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='Q')
            {
                if(queen2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='K')
            {
                if(king2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
        }
    }
    test[y][m]=z;
    test[x][l]=u;
    return check;
}
int save_king2(int x ,int l,int y ,int m)
{
    int get=0,i,j,t,h,a,c,not_valid=0,check=0,still_check=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(test[i][j]=='K')
            {
                get=1;
                break;
            }
        }
        if(get==1)
        {
            break;
        }
    }
    for(t=0;t<8;t++)
    {
        for(h=0;h<8;h++)
        {
            if(test[t][h]=='p')
            {
                if(pawn1(t,h,i,j)==2)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='n')
            {
                if(knight1(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='r')
            {
                if(rook1(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='b')
            {
                if(bishop1(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='q')
            {
                if(queen1(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='k')
            {
               if(king1(t,h,i,j)==0)
               {
                    check=1;
                    break;
               }
            }
        }
        if(check==1)
        {
           break;
        }
    }
    char z,u;
    z=test[y][m];
    u=test[x][l];
    if(check==1)
    {
    for(a=0;a<8;a++)
    {
        for(c=0;c<8;c++)
        {
            if(test[a][c]=='P')
            {
                if((a==x)&&(c==l))
                {
                  if(pawn2(a,c,y,m)==0 || pawn2(a,c,y,m)==2)
                  {
                      test[y][m]=test[x][l];
                      test[x][l]=BW1[x][l];
                     if(test[t][h]=='p')
                     {
                        if(pawn1(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                     }
                     else if(test[t][h]=='n')
                     {
                        if(knight1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                     }
                     else if(test[t][h]=='r')
                     {
                        if(rook1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                     }
                     else if(test[t][h]=='b')
                     {
                        if(bishop1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                     }
                     else if(test[t][h]=='q')
                     {
                        if(queen1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                     }
                  }
               }
            }
            else if(test[a][c]=='N')
            {
                if((a==x)&&(c==l))
                {
                  if(knight2(a,c,y,m)==0)
                  {
                      test[y][m]=test[x][l];
                      test[x][l]=BW1[x][l];
                    if(test[t][h]=='p')
                    {
                        if(pawn1(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='n')
                    {
                        if(knight1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='r')
                    {
                        if(rook1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='b')
                    {
                        if(bishop1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='q')
                    {
                        if(queen1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='k')
                    {
                        if(king1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
        }
            else if(test[a][c]=='R')
            {
                if((a==x)&&(c==l))
                {
                  if(rook2(a,c,y,m)==0)
                  {
                      test[y][m]=test[x][l];
                      test[x][l]=BW1[x][l];
                    if(test[t][h]=='p')
                    {
                        if(pawn1(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                     else if(test[t][h]=='n')
                    {
                        if(knight1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='r')
                    {
                        if(rook1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='b')
                    {
                        if(bishop1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='q')
                    {
                        if(queen1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='k')
                    {
                        if(king1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
        }
            else if(test[a][c]=='B')
            {
                if((a==x)&&(c==l))
                {
                   if(bishop2(a,c,y,m)==0)
                  {
                      test[y][m]=test[x][l];
                      test[x][l]=BW1[x][l];
                    if(test[t][h]=='p')
                    {
                        if(pawn1(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='n')
                    {
                        if(knight1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='r')
                    {
                        if(rook1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='b')
                    {
                        if(bishop1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='q')
                    {
                        if(queen1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='k')
                    {
                        if(king1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
        }
            else if(test[a][c]=='Q')
            {
                if((a==x)&&(c==l))
                {
                   if(queen2(a,c,y,m)==0)
                  {
                      test[y][m]=test[x][l];
                      test[x][l]=BW1[x][l];
                    if(test[t][h]=='p')
                    {
                        if(pawn1(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='n')
                    {
                        if(knight1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='r')
                    {
                        if(rook1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='b')
                    {
                        if(bishop1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='q')
                    {
                        if(queen1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='k')
                    {
                        if(king1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
        }
            else if(test[a][c]=='K')
            {
                if((a==x)&&(c==l))
                {
                   if(king2(a,c,y,m)==0)
                  {
                      test[y][m]=test[x][l];
                      test[x][l]=BW1[x][l];
                    if(test[t][h]=='p')
                    {
                        if(pawn1(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='n')
                    {
                        if(knight1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='r')
                    {
                        if(rook1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='b')
                    {
                        if(bishop1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='q')
                    {
                        if(queen1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='k')
                    {
                        if(king1(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
        }

    }
    if(still_check==1)
     {
        break;
     }
    }
    }
    test[y][m]=z;
    test[x][l]=u;
    if(still_check==1)
    {
        not_valid=1;
    }
    return not_valid;
}
int save_king1(int x ,int l,int y ,int m)
{
    int get=0,i,j,t,h,a,c,not_valid=0,check=0,still_check=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(test[i][j]=='k')
            {
                get=1;
                break;
            }
        }
        if(get==1)
        {
            break;
        }
    }

    for(t=0;t<8;t++)
    {
        for(h=0;h<8;h++)
        {
            if(test[t][h]=='P')
            {
                if(pawn2(t,h,i,j)==2)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='N')
            {
                if(knight2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='R')
            {
                if(rook2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='B')
            {
                if(bishop2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='Q')
            {
                if(queen2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
            else if(test[t][h]=='K')
            {
                if(king2(t,h,i,j)==0)
                {
                    check=1;
                    break;
                }
            }
        }
    }
    char z,u;
    z=test[y][m];
    u=test[x][l];
    if(check==1)
    {
    for(a=0;a<8;a++)
    {
        for(c=0;c<8;c++)
        {
            if(test[a][c]=='p')
            {
                if((a==x)&&(c==l))
                {
                  if(pawn1(a,c,y,m)==0 || pawn1(t,h,y,m)==2)
                 { test[y][m]=test[x][l];
                    test[x][l]=BW1[x][l];
                    if(test[t][h]=='P')
                    {
                        if(pawn2(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='N')
                    {
                        if(knight2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='R')
                    {
                        if(rook2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='B')
                    {
                        if(bishop2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='Q')
                    {
                        if(queen2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='K')
                    {
                        if(king2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
        }

            if(test[a][c]=='n')
            {
                if((a==x)&&(c==l))
                {
                 if(knight1(a,c,y,m)==0)
                 {    test[y][m]=test[x][l];
                      test[x][l]=BW1[x][l];
                    if(test[t][h]=='P')
                    {
                        if(pawn2(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='N')
                    {
                        if(knight2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='R')
                    {
                        if(rook2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='B')
                    {
                        if(bishop2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='Q')
                    {
                        if(queen2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='K')
                    {
                        if(king2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
            if(test[a][c]=='r')
            {
                if(rook1(a,c,y,m)==0)
                {
                    test[y][m]=test[x][l];
                    test[x][l]=BW1[x][l];
                    if(test[t][h]=='P')
                    {
                        if(pawn2(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='N')
                    {
                        if(knight2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='R')
                    {
                        if(rook2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='B')
                    {
                        if(bishop2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='Q')
                    {
                        if(queen2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='K')
                    {
                        if(king2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
        }
            if(test[a][c]=='b')
            {
                if((a==x)&&(c==l))
                {
                   if(bishop1(a,c,y,m)==0)
                  {
                      test[y][m]=test[x][l];
                      test[x][l]=BW1[x][l];
                    if(test[t][h]=='P')
                    {
                        if(pawn2(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='N')
                    {
                        if(knight2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='R')
                    {
                        if(rook2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='B')
                    {
                        if(bishop2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='Q')
                    {
                        if(queen2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='K')
                    {
                        if(king2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
       }

            if(test[a][c]=='q')
            {
                if((a==x)&&(l==c))
                {
                  if(queen1(a,c,y,m)==0)
                  {
                      test[y][m]=test[x][l];
                      test[x][l]=BW1[x][l];
                    if(test[t][h]=='P')
                    {
                        if(pawn2(t,h,i,j)==2)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='N')
                    {
                        if(knight2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='R')
                    {
                        if(rook2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                     else if(test[t][h]=='B')
                    {
                        if(bishop2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='Q')
                    {
                        if(queen2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                    else if(test[t][h]=='K')
                    {
                        if(king2(t,h,i,j)==0)
                        {
                            still_check=1;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(still_check==1)
     {
        break;
     }
    }
    }
    test[y][m]=z;
    test[x][l]=u;
    if(still_check==1)
    {
        not_valid=1;
    }
    return not_valid;
}


int help_me1(int x ,int l,int y ,int m)
{
    int t,h,remain_notvalid1=0,remain1=0;
    for(t=0;t<8;t++)
    {
        for(h=0;h<8;h++)
        {
            if(test[t][h]=='p')
            {
                if(save_king1(t,h,y,m)==1)
                {
                    remain_notvalid1++;
                }
                remain1++;
            }
            else if(test[t][h]=='n')
            {
                if(save_king1(t,h,y,m)==1)
                {
                    remain_notvalid1++;
                }
                remain1++;
            }
            else if(test[t][h]=='r')
            {
                if(save_king1(t,h,y,m)==1)
                {
                    remain_notvalid1++;
                }
                remain1++;
            }
            else if(test[t][h]=='b')
            {
                if(save_king1(t,h,y,m)==1)
                {
                    remain_notvalid1++;
                }
                remain1++;
            }
            else if(test[t][h]=='q')
            {
                if(save_king1(t,h,y,m)==1)
                {
                    remain_notvalid1++;
                }
                remain1++;
            }
        }
    }
    if(remain1==remain_notvalid1)
    {
      return 1;
    }
    return 0;
}
int help_me2(int x ,int l,int y ,int m)
{
    int t,h,remain2=0,remain_notvalid2=0;
    for(t=0;t<8;t++)
    {
        for(h=0;h<8;h++)
        {
            if(test[t][h]=='P')
            {
                if(save_king2(t,h,y,m)==1)
                {
                    remain_notvalid2++;
                }
                remain2++;
            }
            else if(test[t][h]=='N')
            {
                if(save_king2(t,h,y,m)==1)
                {
                    remain_notvalid2++;
                }
                remain2++;
            }
            else if(test[t][h]=='R')
            {
                if(save_king2(t,h,y,m)==1)
                {
                    remain_notvalid2++;
                }
                remain2++;
            }
            else if(test[t][h]=='B')
            {
                if(save_king2(t,h,y,m)==1)
                {
                    remain_notvalid2++;
                }
                remain2++;
            }
            else if(test[t][h]=='Q')
            {
                if(save_king2(t,h,y,m)==1)
                {
                    remain_notvalid2++;
                }
                remain2++;
            }
        }
    }
    if(remain2==remain_notvalid2)
    {
       return 1;
    }
    return 0;
}


int checkmate1(int x ,int l,int y ,int m)
{
   int get=0,i,j,t,h,found=0,s,v;
    int maybe_checkmate1=0,maybe_checkmate2=0;
    if(check2(x,l,y,m)==1)
    {
        maybe_checkmate1=1;
        return 1;

    }
    return 0;
}

int checkmate2(int x ,int l,int y ,int m)
{
   int get=0,i,j,t,h,found=0,s,v;
    int maybe_checkmate2=0;
    if(check1(x,l,y,m)==1)
    {
        maybe_checkmate2=1;
        return 1;
    }
    return 0;
}

int stalemate1(int x ,int l,int y ,int m)//for the white king
{
    int maybe_stalemate1=0;
    if(check2(x,l,y,m)==0)
    {
        maybe_stalemate1=1;
        return 1;

    }
    return 0;
}

int stalemate2(int x ,int l,int y ,int m)//for the white king
{
    int maybe_stalemate2=0;
    if(check1(x,l,y,m)==0)
    {
        maybe_stalemate2=1;
        return 1;

    }
    return 0;
}


int main()
{
    int i,j,k;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if ((i%2==0)&&(j%2==0))
            {
                BW[i][j]='-';
            }
            else if ((i%2!=0)&&(j%2!=0))
            {
                BW[i][j]='-';
            }
            else if ((i%2==0)&&(j%2!=0))
            {
                BW[i][j]='+';
            }
            else if ((i%2!=0)&&(j%2==0))
            {
                BW[i][j]='+';
            }

        }
    }
     //reference
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if ((i%2==0)&&(j%2==0))
            {
                BW1[i][j]='-';
            }
            else if ((i%2!=0)&&(j%2!=0))
            {
                BW1[i][j]='-';
            }
            else if ((i%2==0)&&(j%2!=0))
            {
                BW1[i][j]='+';
            }
            else if ((i%2!=0)&&(j%2==0))
            {
                BW1[i][j]='+';
            }

        }
    }
   //test
   for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if ((i%2==0)&&(j%2==0))
            {
                test[i][j]='-';
            }
            else if ((i%2!=0)&&(j%2!=0))
            {
                test[i][j]='-';
            }
            else if ((i%2==0)&&(j%2!=0))
            {
                test[i][j]='+';
            }
            else if ((i%2!=0)&&(j%2==0))
            {
                test[i][j]='+';
            }

        }
    }

    //for white
    char pawnW='p';
    char rookW='r';
    char knightW='n';
    char bishopsW='b';
    char queenW='q';
    char kingW='k';
    for(j=0;j<8;j++)
    {
        BW[6][j]=pawnW;
        test[6][j]=pawnW;
    }
    BW[7][0]=BW[7][7]=test[7][0]=test[7][7]=rookW;
    BW[7][1]=BW[7][6]=test[7][1]=test[7][6]=knightW;
    BW[7][2]=BW[7][5]=test[7][2]=test[7][5]=bishopsW;
    BW[7][3]=test[7][3]=queenW;
    BW[7][4]=test[7][4]=kingW;

    //for black
    char pawnB='P';
    char rookB='R';
    char knightB='N';
    char bishopsB='B';
    char queenB='Q';
    char kingB='K';
    for(j=0;j<8;j++)
    {
        BW[1][j]=pawnB;
        test[1][j]=pawnB;
    }
    BW[0][0]=BW[0][7]=test[0][0]=test[0][7]=rookB;
    BW[0][1]=BW[0][6]=test[0][1]=test[0][6]=knightB;
    BW[0][2]=BW[0][5]=test[0][2]=test[0][5]=bishopsB;
    BW[0][3]=test[0][3]=queenB;
    BW[0][4]=test[0][4]=kingB;
    printf(" \t\t                      Chess Game           \n\n");
    printf(" \t\t      A     B     C     D     E     F     G     H\n\n");

    for(i=0;i<8;i++)
    {
        printf("\t\t %d    ",i+1);
        for(j=0;j<8;j++)
        {
            printf("%c     ",BW[i][j]);
        }
        printf("\n\n\n");
    }
    printf(" \t\t                      Chess Game test           \n\n");
    printf(" \t\t      A     B     C     D     E     F     G     H\n\n");

    for(i=0;i<8;i++)
    {
        printf("\t\t %d    ",i+1);
        for(j=0;j<8;j++)
        {
            printf("%c     ",test[i][j]);
        }
        printf("\n\n\n");
    }
    int x,y,l,m;
    char v,t;

    i=0;
    int not_valid,not_white=0,not_black=0,small=0,check_1,check_2;
    printf("Player1:");
    scanf(" %c %d %c %d",&v,&x,&t,&y);
    if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
        || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
        || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
    {
        printf("Please enter Capital letters.\nPlayer1:");
        scanf(" %c %d %c %d",&v,&x,&t,&y);
    }
    l=make_ch_num(v);
    m=make_ch_num(t);
    if((BW[x-1][l]=='R') || (BW[x-1][l]=='N') || (BW[x-1][l]=='B')
        || (BW[x-1][l]=='Q') || (BW[x-1][l]=='K') || (BW[x-1][l]=='P'))
    {
        printf("This is not white Piece.\nPlayer1:");
        scanf(" %c %d %c %d",&v,&x,&t,&y);
        if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
            || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
            || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
        {
            printf("Please enter Capital letters.\nPlayer1:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);
        }
        l=make_ch_num(v);
        m=make_ch_num(t);
    }
    if((BW[x-1][l]=='+') || (BW[x-1][l]=='-'))
    {
        printf("There is no piece in this position.\nPlayer1:");
        scanf(" %c %d %c %d",&v,&x,&t,&y);
        l=make_ch_num(v);
        m=make_ch_num(t);
    }
    check_2=0;
    //white
    if(BW[x-1][l]=='p')
    {
        not_valid=pawn1(x-1,l,y-1,m);
        if (not_valid==0)
        {
            if(self_check1(x-1,l,y-1,m)==0)
            {
                not_valid=0;
            }
            else if(self_check1(x-1,l,y-1,m)==1)
            {
                not_valid=1;
            }
            if(check_1==1)
            {
                not_valid=save_king1(x-1,l,y-1,m);
            }
        }
        else if(not_valid==2)
        {
            if(self_check1(x-1,l,y-1,m)==0)
            {
                not_valid=2;
            }
            else if(self_check1(x-1,l,y-1,m)==1)
            {
                not_valid=1;
            }
            if(check1(x-1,l,y-1,m)==1)
            {
                printf("Warning it's check for Player2");
                check_2=1;
                not_valid=2;
            }
            else if(check1(x-1,l,y-1,m)==0)
            {
                not_valid=2;
            }
            if(check_1==1)
            {
                not_valid=save_king1(x-1,l,y-1,m);
            }
        }
        if(not_valid==0)
        {
            if((y-1)==0)
            {
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
                printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                scanf(" %c", &BW[y-1][m]);
                test[y-1][m]=BW[y-1][m];
            }
            else
            {
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
        }
        else if(not_valid==2)
        {
            if(BW[y-1][m]!='K')
            {
                if((y-1)==0)
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                    printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                    scanf(" %c", &BW[y-1][m]);
                    test[y-1][m]=BW[y-1][m];
                }
                else
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
        }
        print_board();
        print_test();
    }
    else if(BW[x-1][l]=='n')
    {
        not_valid=knight1(x-1,l,y-1,m);
        if(not_valid==0)
        {
            if(self_check1(x-1,l,y-1,m)==0)
            {
                not_valid=0;
            }
            else if(self_check1(x-1,l,y-1,m)==1)
            {
                not_valid=1;
            }
            if(check1(x-1,l,y-1,m)==1)
            {
                printf("Warning it's check for Player2");
                check_2=1;
                not_valid=0;
            }
            else if(check1(x-1,l,y-1,m)==0)
            {
                not_valid=0;
            }
            if(check_1==1)
            {
                not_valid=save_king1(x-1,l,y-1,m);
            }
        }
        if(not_valid==0)
        {
            if((BW[y-1][m]=='-') || (BW[y-1][m]=='+'))
            {
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='r') && (BW[y-1][m]!='n') && (BW[y-1][m]!='b')
                && (BW[y-1][m]!='k') && (BW[y-1][m]!='q') && (BW[y-1][m]!='p') && (BW[y-1][m]!='K')) //not equal K because it's check.
            {
                lose_from_black[countb]=BW[y-1][m];
                countb++;
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
        }
        print_board();
        print_test();
    }
    else if(BW[x-1][l]=='r')
    {
            not_valid=rook1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K'))
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='b')
        {
            not_valid=bishop1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K')) //not equal K because it's check
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='q')
        {
            not_valid=queen1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K')) //not equal K because it's check
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='k')
        {
            not_valid=king1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='+') || (BW[y-1][m]=='-'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='r') && (BW[y-1][m]!='n')
                    && (BW[y-1][m]!='b') && (BW[y-1][m]!='q') && (BW[y-1][m]!='p') && (BW[y-1][m]!='K')) //not equal K because it's check.
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        int o=check1(x-1,l,y-1,m);
        int n=help_me1(x-1,l,y-1,m);
        int w=help_me2(x-1,l,y-1,m);
        j=check1(x-1,l,y-1,m);
        while(not_valid==1)
        {
            printf("This isn't valid\nPlease enter another step\nPlayer1:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);

            if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
              || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
              || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
            {
                printf("Please enter Capital letters.\nPlayer1:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
            }
            l=make_ch_num(v);
            m=make_ch_num(t);
            if((BW[x-1][l]=='R') || (BW[x-1][l]=='N') || (BW[x-1][l]=='B')
              || (BW[x-1][l]=='Q') || (BW[x-1][l]=='K') || (BW[x-1][l]=='P'))
            {
                printf("This is not white Piece.\nPlayer1:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
                if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
                  || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
                  || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
                {
                    printf("Please enter Capital letters.\nPlayer1:");
                    scanf(" %c %d %c %d",&v,&x,&t,&y);
                }
                l=make_ch_num(v);
                m=make_ch_num(t);
            }
            if((BW[x-1][l]=='+') || (BW[x-1][l]=='-'))
            {
                printf("There is no piece in this position.\nPlayer1:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
                l=make_ch_num(v);
                m=make_ch_num(t);
            }
        check_2=0;
        //white
        if(BW[x-1][l]=='p')
        {
            not_valid=pawn1(x-1,l,y-1,m);
            if (not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            else if(not_valid==2)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=2;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=2;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=2;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if((not_valid==0) || (not_valid==2))
            {
                if((y-1)==0)
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                    printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                    scanf(" %c", &BW[y-1][m]);
                    test[y-1][m]=BW[y-1][m];
                }
                else
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='n')
        {
            not_valid=knight1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='-') || (BW[y-1][m]=='+'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='r') && (BW[y-1][m]!='n') && (BW[y-1][m]!='b')
                    && (BW[y-1][m]!='k') && (BW[y-1][m]!='q') && (BW[y-1][m]!='p') && (BW[y-1][m]!='K')) //not equal K because it's check.
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='r')
        {
            not_valid=rook1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K'))
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='b')
        {
            not_valid=bishop1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K')) //not equal K because it's check
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='q')
        {
            not_valid=queen1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K')) //not equal K because it's check
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='k')
        {
            not_valid=king1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='+') || (BW[y-1][m]=='-'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='r') && (BW[y-1][m]!='n')
                    && (BW[y-1][m]!='b') && (BW[y-1][m]!='q') && (BW[y-1][m]!='p') && (BW[y-1][m]!='K')) //not equal K because it's check.
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        o=check1(x-1,l,y-1,m);
        n=help_me1(x-1,l,y-1,m);
        w=help_me2(x-1,l,y-1,m);
        j=check1(x-1,l,y-1,m);
        }
        check_1=0;
        printf("Player2:");
        scanf(" %c %d %c %d",&v,&x,&t,&y);

        if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
           || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
           || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
        {
            printf("Please enter Capital letters.\nPlayer2:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);
        }
        l=make_ch_num(v);
        m=make_ch_num(t);

        if((BW[x-1][l]=='r') || (BW[x-1][l]=='n') || (BW[x-1][l]=='b')
            || (BW[x-1][l]=='q') || (BW[x-1][l]=='k') || (BW[x-1][l]=='p'))
        {
             printf("This is not black Piece.\nPlayer2:");
             scanf(" %c %d %c %d",&v,&x,&t,&y);
             if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
               || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
               || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
             {
                 printf("Please enter Capital letters.\nPlayer2:");
                 scanf(" %c %d %c %d",&v,&x,&t,&y);
             }
             l=make_ch_num(v);
             m=make_ch_num(t);
        }
        else if((BW[x-1][l]=='+') || (BW[x-1][l]=='-'))
        {
            printf("There is no piece in this position.\nPlayer1:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);
            l=make_ch_num(v);
            m=make_ch_num(t);
        }
        //black
        if(BW[x-1][l]=='P')
        {
            not_valid=pawn2(x-1,l,y-1,m);
            if (not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            else if(not_valid==2)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=2;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if ((not_valid==0)||(not_valid==2))
            {
                if((y-1)==7)
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                    printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                    scanf(" %c", &BW[y-1][m]);
                }
                else
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='N')
        {
            not_valid=knight2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='-') || (BW[y-1][m]=='+'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='R') && (BW[y-1][m]!='N') && (BW[y-1][m]!='B')
                    && (BW[y-1][m]!='Q') && (BW[y-1][m]!='K') && (BW[y-1][m]!='P') && (BW[y-1][m]!='k'))
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='R')
        {
            not_valid=rook2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k'))
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='B')
        {
            not_valid=bishop2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k')) //not equal K because it's check
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='Q')
        {
            not_valid=queen2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k')) //not equal K because it's check
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='K')
        {
            not_valid=king2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='+') || (BW[y-1][m]=='-'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='R') && (BW[y-1][m]!='N')
                    && (BW[y-1][m]!='B') && (BW[y-1][m]!='Q') && (BW[y-1][m]!='P') && (BW[y-1][m]!='k')) //not equal K because it's check.
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        int a=check2(x-1,l,y-1,m);
        w=help_me2(x-1,l,y-1,m);
        n=help_me1(x-1,l,y-1,m);
        int g=check2(x-1,l,y-1,m);
        while(not_valid==1)
        {
            printf("This isn't valid\nPlease enter another step\nPlayer2:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);

            if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
             || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
             || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
            {
                printf("Please enter Capital letters.\nPlayer2:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
            }
            l=make_ch_num(v);
            m=make_ch_num(t);
            if((BW[x-1][l]=='r') || (BW[x-1][l]=='n') || (BW[x-1][l]=='b')
             || (BW[x-1][l]=='q') || (BW[x-1][l]=='k') || (BW[x-1][l]=='p'))
            {
                printf("This is not black Piece.\nPlayer2:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
                if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
                  || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
                  || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
                {
                    printf("Please enter Capital letters.\nPlayer2:");
                    scanf(" %c %d %c %d",&v,&x,&t,&y);
                }
                l=make_ch_num(v);
                m=make_ch_num(t);
            }
            else if((BW[x-1][l]=='+') || (BW[x-1][l]=='-'))
            {
                printf("There is no piece in this position.\nPlayer1:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
                l=make_ch_num(v);
                m=make_ch_num(t);
            }
            check_1=0;
        //black
        if(BW[x-1][l]=='P')
        {
            not_valid=pawn2(x-1,l,y-1,m);
            if (not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            else if(not_valid==2)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=2;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if ((not_valid==0)||(not_valid==2))
            {
                if((y-1)==7)
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                    printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                    scanf(" %c", &BW[y-1][m]);
                }
                else
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='N')
        {
            not_valid=knight2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='-') || (BW[y-1][m]=='+'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='R') && (BW[y-1][m]!='N') && (BW[y-1][m]!='B')
                    && (BW[y-1][m]!='Q') && (BW[y-1][m]!='K') && (BW[y-1][m]!='P') && (BW[y-1][m]!='k'))
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='R')
        {
            not_valid=rook2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k'))
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='B')
        {
            not_valid=bishop2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            } if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k')) //not equal K because it's check
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='Q')
        {
            not_valid=queen2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k')) //not equal K because it's check
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='K')
        {
            not_valid=king2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='+') || (BW[y-1][m]=='-'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='R') && (BW[y-1][m]!='N')
                    && (BW[y-1][m]!='B') && (BW[y-1][m]!='Q') && (BW[y-1][m]!='P') && (BW[y-1][m]!='k')) //not equal K because it's check.
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        a=check2(x-1,l,y-1,m);
        w=help_me2(x-1,l,y-1,m);
        n=help_me1(x-1,l,y-1,m);
        g=check2(x-1,l,y-1,m);
    }
    while((o==0 && w==0) || (a==0 && n==0) || (j==1 && w==0) || (g==1 && n==0))
    {
    not_white=0,not_black=0,small=0;
    printf("Player1:");
    scanf(" %c %d %c %d",&v,&x,&t,&y);
    if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
        || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
        || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
    {
        printf("Please enter Capital letters.\nPlayer1:");
        scanf(" %c %d %c %d",&v,&x,&t,&y);
    }
    l=make_ch_num(v);
    m=make_ch_num(t);
    if((BW[x-1][l]=='R') || (BW[x-1][l]=='N') || (BW[x-1][l]=='B')
        || (BW[x-1][l]=='Q') || (BW[x-1][l]=='K') || (BW[x-1][l]=='P'))
    {
        printf("This is not white Piece.\nPlayer1:");
        scanf(" %c %d %c %d",&v,&x,&t,&y);
        if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
            || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
            || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
        {
            printf("Please enter Capital letters.\nPlayer1:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);
        }
        l=make_ch_num(v);
        m=make_ch_num(t);
    }
    if((BW[x-1][l]=='+') || (BW[x-1][l]=='-'))
    {
        printf("There is no piece in this position.\nPlayer1:");
        scanf(" %c %d %c %d",&v,&x,&t,&y);
        l=make_ch_num(v);
        m=make_ch_num(t);
    }
    check_2=0;
    //white
    if(BW[x-1][l]=='p')
    {
        not_valid=pawn1(x-1,l,y-1,m);
        if (not_valid==0)
        {
            if(self_check1(x-1,l,y-1,m)==0)
            {
                not_valid=0;
            }
            else if(self_check1(x-1,l,y-1,m)==1)
            {
                not_valid=1;
            }
            if(check_1==1)
            {
                not_valid=save_king1(x-1,l,y-1,m);
            }
        }
        else if(not_valid==2)
        {
            if(self_check1(x-1,l,y-1,m)==0)
            {
                not_valid=2;
            }
            else if(self_check1(x-1,l,y-1,m)==1)
            {
                not_valid=1;
            }
            if(check1(x-1,l,y-1,m)==1)
            {
                printf("Warning it's check for Player2");
                check_2=1;
                not_valid=2;
            }
            else if(check1(x-1,l,y-1,m)==0)
            {
                not_valid=2;
            }
            if(check_1==1)
            {
                not_valid=save_king1(x-1,l,y-1,m);
            }
        }
        if(not_valid==0)
        {
            if((y-1)==0)
            {
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
                printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                scanf(" %c", &BW[y-1][m]);
                test[y-1][m]=BW[y-1][m];
            }
            else
            {
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
        }
        else if(not_valid==2)
        {
            if(BW[y-1][m]!='K')
            {
                if((y-1)==0)
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                    printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                    scanf(" %c", &BW[y-1][m]);
                    test[y-1][m]=BW[y-1][m];
                }
                else
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
        }
        print_board();
        print_test();
    }
    else if(BW[x-1][l]=='n')
    {
        not_valid=knight1(x-1,l,y-1,m);
        if(not_valid==0)
        {
            if(self_check1(x-1,l,y-1,m)==0)
            {
                not_valid=0;
            }
            else if(self_check1(x-1,l,y-1,m)==1)
            {
                not_valid=1;
            }
            if(check1(x-1,l,y-1,m)==1)
            {
                printf("Warning it's check for Player2");
                check_2=1;
                not_valid=0;
            }
            else if(check1(x-1,l,y-1,m)==0)
            {
                not_valid=0;
            }
            if(check_1==1)
            {
                not_valid=save_king1(x-1,l,y-1,m);
            }
        }
        if(not_valid==0)
        {
            if((BW[y-1][m]=='-') || (BW[y-1][m]=='+'))
            {
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='r') && (BW[y-1][m]!='n') && (BW[y-1][m]!='b')
                && (BW[y-1][m]!='k') && (BW[y-1][m]!='q') && (BW[y-1][m]!='p') && (BW[y-1][m]!='K')) //not equal K because it's check.
            {
                lose_from_black[countb]=BW[y-1][m];
                countb++;
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
        }
        print_board();
        print_test();
    }
    else if(BW[x-1][l]=='r')
    {
            not_valid=rook1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K'))
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='b')
        {
            not_valid=bishop1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K')) //not equal K because it's check
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='q')
        {
            not_valid=queen1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K')) //not equal K because it's check
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='k')
        {
            not_valid=king1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='+') || (BW[y-1][m]=='-'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='r') && (BW[y-1][m]!='n')
                    && (BW[y-1][m]!='b') && (BW[y-1][m]!='q') && (BW[y-1][m]!='p') && (BW[y-1][m]!='K')) //not equal K because it's check.
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        int o;
        o=check_2;
        int n=help_me1(x-1,l,y-1,m);
        int w=help_me2(x-1,l,y-1,m);
        j=check_2;
        while(not_valid==1)
        {
            printf("This isn't valid\nPlease enter another step\nPlayer1:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);

            if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
              || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
              || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
            {
                printf("Please enter Capital letters.\nPlayer1:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
            }
            l=make_ch_num(v);
            m=make_ch_num(t);
            if((BW[x-1][l]=='R') || (BW[x-1][l]=='N') || (BW[x-1][l]=='B')
              || (BW[x-1][l]=='Q') || (BW[x-1][l]=='K') || (BW[x-1][l]=='P'))
            {
                printf("This is not white Piece.\nPlayer1:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
                if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
                  || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
                  || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
                {
                    printf("Please enter Capital letters.\nPlayer1:");
                    scanf(" %c %d %c %d",&v,&x,&t,&y);
                }
                l=make_ch_num(v);
                m=make_ch_num(t);
            }
            if((BW[x-1][l]=='+') || (BW[x-1][l]=='-'))
            {
                printf("There is no piece in this position.\nPlayer1:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
                l=make_ch_num(v);
                m=make_ch_num(t);
            }
        check_2=0;
        //white
        if(BW[x-1][l]=='p')
        {
            not_valid=pawn1(x-1,l,y-1,m);
            if (not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            else if(not_valid==2)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=2;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=2;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=2;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if((not_valid==0) || (not_valid==2))
            {
                if((y-1)==0)
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                    printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                    scanf(" %c", &BW[y-1][m]);
                    test[y-1][m]=BW[y-1][m];
                }
                else
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='n')
        {
            not_valid=knight1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='-') || (BW[y-1][m]=='+'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='r') && (BW[y-1][m]!='n') && (BW[y-1][m]!='b')
                    && (BW[y-1][m]!='k') && (BW[y-1][m]!='q') && (BW[y-1][m]!='p') && (BW[y-1][m]!='K')) //not equal K because it's check.
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='r')
        {
            not_valid=rook1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K'))
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='b')
        {
            not_valid=bishop1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K')) //not equal K because it's check
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='q')
        {
            not_valid=queen1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='K')) //not equal K because it's check
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='k')
        {
            not_valid=king1(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(self_check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check1(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player2");
                    check_2=1;
                    not_valid=0;
                }
                else if(check1(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_1==1)
                {
                    not_valid=save_king1(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='+') || (BW[y-1][m]=='-'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='r') && (BW[y-1][m]!='n')
                    && (BW[y-1][m]!='b') && (BW[y-1][m]!='q') && (BW[y-1][m]!='p') && (BW[y-1][m]!='K')) //not equal K because it's check.
                {
                    lose_from_black[countb]=BW[y-1][m];
                    countb++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        o=check_2;
        n=help_me1(x-1,l,y-1,m);
        w=help_me2(x-1,l,y-1,m);
        j=check_2;
        }
        check_1=0;
        if((o==0 && w==0) || (a==0 && n==0) || (j==1 && w==0) || (g==1 && n==0))
        {
        printf("Player2:");
        scanf(" %c %d %c %d",&v,&x,&t,&y);

        if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
           || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
           || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
        {
            printf("Please enter Capital letters.\nPlayer2:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);
        }
        l=make_ch_num(v);
        m=make_ch_num(t);

        if((BW[x-1][l]=='r') || (BW[x-1][l]=='n') || (BW[x-1][l]=='b')
            || (BW[x-1][l]=='q') || (BW[x-1][l]=='k') || (BW[x-1][l]=='p'))
        {
             printf("This is not black Piece.\nPlayer2:");
             scanf(" %c %d %c %d",&v,&x,&t,&y);
             if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
               || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
               || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
             {
                 printf("Please enter Capital letters.\nPlayer2:");
                 scanf(" %c %d %c %d",&v,&x,&t,&y);
             }
             l=make_ch_num(v);
             m=make_ch_num(t);
        }
        else if((BW[x-1][l]=='+') || (BW[x-1][l]=='-'))
        {
            printf("There is no piece in this position.\nPlayer1:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);
            l=make_ch_num(v);
            m=make_ch_num(t);
        }
        //black
        if(BW[x-1][l]=='P')
        {
            not_valid=pawn2(x-1,l,y-1,m);
            if (not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            else if(not_valid==2)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=2;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if ((not_valid==0)||(not_valid==2))
            {
                if((y-1)==7)
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                    printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                    scanf(" %c", &BW[y-1][m]);
                }
                else
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='N')
        {
            not_valid=knight2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='-') || (BW[y-1][m]=='+'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='R') && (BW[y-1][m]!='N') && (BW[y-1][m]!='B')
                    && (BW[y-1][m]!='Q') && (BW[y-1][m]!='K') && (BW[y-1][m]!='P') && (BW[y-1][m]!='k'))
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='R')
        {
            not_valid=rook2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k'))
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='B')
        {
            not_valid=bishop2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k')) //not equal K because it's check
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='Q')
        {
            not_valid=queen2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k')) //not equal K because it's check
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='K')
        {
            not_valid=king2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='+') || (BW[y-1][m]=='-'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='R') && (BW[y-1][m]!='N')
                    && (BW[y-1][m]!='B') && (BW[y-1][m]!='Q') && (BW[y-1][m]!='P') && (BW[y-1][m]!='k')) //not equal K because it's check.
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        int a=check_1;
        w=help_me2(x-1,l,y-1,m);
        n=help_me1(x-1,l,y-1,m);
        int g=check_1;
        while(not_valid==1)
        {
            printf("This isn't valid\nPlease enter another step\nPlayer2:");
            scanf(" %c %d %c %d",&v,&x,&t,&y);

            if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
             || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
             || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
            {
                printf("Please enter Capital letters.\nPlayer2:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
            }
            l=make_ch_num(v);
            m=make_ch_num(t);
            if((BW[x-1][l]=='r') || (BW[x-1][l]=='n') || (BW[x-1][l]=='b')
             || (BW[x-1][l]=='q') || (BW[x-1][l]=='k') || (BW[x-1][l]=='p'))
            {
                printf("This is not black Piece.\nPlayer2:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
                if(((v=='a') || (t=='a')) || ((v=='b') || (t=='b')) || ((v=='c') || (t=='c'))
                  || ((v=='d') || (t=='d')) || ((v=='e') || (t=='e')) || ((v=='f') || (t=='f'))
                  || ((v=='g') || (t=='g')) || ((v=='h') || (t=='h')))
                {
                    printf("Please enter Capital letters.\nPlayer2:");
                    scanf(" %c %d %c %d",&v,&x,&t,&y);
                }
                l=make_ch_num(v);
                m=make_ch_num(t);
            }
            else if((BW[x-1][l]=='+') || (BW[x-1][l]=='-'))
            {
                printf("There is no piece in this position.\nPlayer1:");
                scanf(" %c %d %c %d",&v,&x,&t,&y);
                l=make_ch_num(v);
                m=make_ch_num(t);
            }
            check_1=0;
        //black
        if(BW[x-1][l]=='P')
        {
            not_valid=pawn2(x-1,l,y-1,m);
            if (not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            else if(not_valid==2)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=2;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if ((not_valid==0)||(not_valid==2))
            {
                if((y-1)==7)
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                    printf("It's promotion.\nHere's a list you can promote the pawn to ( r, n, b, q ).\nThe piece you chose is:");
                    scanf(" %c", &BW[y-1][m]);
                }
                else
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='N')
        {
            not_valid=knight2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='-') || (BW[y-1][m]=='+'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='R') && (BW[y-1][m]!='N') && (BW[y-1][m]!='B')
                    && (BW[y-1][m]!='Q') && (BW[y-1][m]!='K') && (BW[y-1][m]!='P') && (BW[y-1][m]!='k'))
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='R')
        {
            not_valid=rook2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k'))
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='B')
        {
            not_valid=bishop2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            } if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k')) //not equal K because it's check
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='Q')
        {
            not_valid=queen2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='k')) //not equal K because it's check
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                }
                BW[y-1][m]=BW[x-1][l];
                BW[x-1][l]=BW1[x-1][l];
                test[y-1][m]=test[x-1][l];
                test[x-1][l]=BW1[x-1][l];
            }
            print_board();
            print_test();
        }
        else if(BW[x-1][l]=='K')
        {
            not_valid=king2(x-1,l,y-1,m);
            if(not_valid==0)
            {
                if(check1(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(self_check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                else if(self_check2(x-1,l,y-1,m)==1)
                {
                    not_valid=1;
                }
                if(check2(x-1,l,y-1,m)==1)
                {
                    printf("Warning it's check for Player1");
                    check_1=1;
                    not_valid=0;
                }
                else if(check2(x-1,l,y-1,m)==0)
                {
                    not_valid=0;
                }
                if(check_2==1)
                {
                    not_valid=save_king2(x-1,l,y-1,m);
                }
            }
            if(not_valid==0)
            {
                if((BW[y-1][m]=='+') || (BW[y-1][m]=='-'))
                {
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
                else if((BW[y-1][m]!='+') && (BW[y-1][m]!='-') && (BW[y-1][m]!='R') && (BW[y-1][m]!='N')
                    && (BW[y-1][m]!='B') && (BW[y-1][m]!='Q') && (BW[y-1][m]!='P') && (BW[y-1][m]!='k')) //not equal K because it's check.
                {
                    lose_from_white[countw]=BW[y-1][m];
                    countw++;
                    BW[y-1][m]=BW[x-1][l];
                    BW[x-1][l]=BW1[x-1][l];
                    test[y-1][m]=test[x-1][l];
                    test[x-1][l]=BW1[x-1][l];
                }
            }
            print_board();
            print_test();
        }
        a=check_1;
        w=help_me2(x-1,l,y-1,m);
        n=help_me1(x-1,l,y-1,m);
        g=check_1;
    }
    }
    }
    if ((o==1 && w==1))
    {
        printf("Game over.Player1 Wins. ");

    }
    else if((a==1 && n==1))
    {
        printf("Game over.Player2 Wins.");
    }
    else if((j==0 && w==1) || (g==0 && n==1))
    {
        printf("It's Stalemate.");
    }
    return 0;
}

