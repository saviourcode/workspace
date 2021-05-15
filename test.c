//
// main.c
// assignment5part2
//
// Created by Daniel Canizales on 5/1/21.
//
#include <stdio.h>
int strLength(char[]); //prototype
int main()
{
    //sizeof(array)/sizeof(array[0])
    char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int size_array = strLength(*suit);
    printf("The size of this string array is: %d\n", size_array);
}
//strLength function
int strLength(char suit[]) //suit
{
    return sizeof(suit) / sizeof(suit[0]);
}
