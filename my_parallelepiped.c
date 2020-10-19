/*
** ETNA PROJECT, 02/10/2020 by nouar_a
** my_parallelepiped.c
** File description:
**      print parallelepiped
*/

#include <unistd.h>

void lign_b(int x,int y,int z);
void lign_a(int x,int y,int z);
void writ_gen_b (int x);
void writ_spac(int a,int b);
void l1( int x,int z);
void writ_car(int x,int y,int z,int n);
void lign(int x,int y,int z);
void writ_gen_a(int x,int n,int z);
int my_parallelepiped(int x, int y, int z)
{
    if (x == 0 || y == 0 || z == 0)
        return (-1);
    if (x == 0 && y == 0 && z == 0)
        return 0;
    else if (x == 1 && y == 1 && z == 1) {
        write (1,"*",1);
        write (1,"\n",1);
    }else {
        l1(x,z);
        lign_a(x , y , z);
        lign_b(x , y , z);
    }
    return 0;
}

void l1( int x,int z)
{
    writ_spac (z ,1);
    write (1,"*",1);
    for (x ; x > 2 ; x--) {
        write (1,"-",1);
    }
    write (1,"*\n",2);
}

void lign_a(int x,int y,int z)
{
    int n = 2;
    while (n < z) {
        writ_gen_a (x , n , z);
        if (n < y){ 
            writ_spac (n , 2);
            write (1 ,"|\n" , 2);
        }
        else if (n == y) {
            writ_spac (y , 2);
            write (1, "*\n" , 2);
        } else {
            writ_spac (y , 2);
            write (1, "/\n" , 2);
        }
        n++;
    }      
}
void lign_b(int x,int y,int z)
{
    int n = z;
    while (n < (z + y)) {
        if (n == z) {
            writ_gen_b (x);
            if ( z < y )
                writ_spac (z , 2);
            else
                writ_spac (y , 2);
            if ( z < y ) 
                write (1, "|\n" , 2);
            else if (z == y)
                write (1, "*\n" , 2);
            else {
                write (1, "/\n" , 2);
            }
        }
        else if (n > z && n < z + y - 1)
            writ_car(x , y , z , n);
        else {
            writ_gen_b (x);
            write (1, "\n" , 1);
        }
        n++;
    }
}
void writ_spac(int a,int b)
{
    for (a ; a > b ; a--) {
        write (1," ",1);
    }
}
void writ_gen_a(int x,int n,int z)
{
    writ_spac (z , n);
    write (1,"/",1);
    writ_spac (x , 2);
    write (1,"/",1);
} 
void writ_gen_b (int x)
{
    write (1,"*",1);
    for (x ; x > 2 ; x--) {
        write (1,"-",1);
    }
    write (1,"*",1);
}
void writ_car(int x,int y,int z,int n)
{
    write (1,"|",1);
    writ_spac(x , 2);
    write (1,"|",1);
    if (n < y ) {
        writ_spac(z , 2);
        write (1,"|\n",2);
    }else if (n == y) {
        writ_spac(z , 2);
        write (1,"*\n",2);
    }
    else {
        writ_spac((z + y) , (n + 2));
        write (1,"/\n",2);
    }
}
