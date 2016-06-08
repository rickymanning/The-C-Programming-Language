/* 2-10 Rewrite the function lower, which converts upper case letters to 
lower case, with a conditional expression instead of if-else, page 52 */

#include <stdio.h>

int lower(int c);

int main()
{
	int c;
    
    c = 'G';
    
	printf("%c\n", lower(c));
}

/* lower: convert c to lower case; ASCII only (original)*/
//int lower(int c)
//{
//    if (c >= 'A' && c <= 'Z')
//        return c + 'a' - 'A';
//    else
//        return c;
//}

/* lower: convert c to lower case; ASCII only (mine)*/
int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}
