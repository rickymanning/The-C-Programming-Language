/* 3-3 Write a function expand(s1,s2) that expands shorthand notations like 
a-z in the string in the string s1 into the equivalent complete list 
abc...xyz in s2. Allow for letters of either case and digits, and be prepared
to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
trailing - is taken literally, page 63 */

#include <stdio.h>

#define MAXLINE 1000
#define HYPHEN  '-'

int isAlphaNumeric(int c);
int isAlphabetic(int c);
int isLowercaseAlpha(int c);
int isUppercaseAlpha(int c);
int isNumeric(int c);
int isHyphen(int c);
int isValidRange(int a, int b);
int isSmallerOrEqual(int a, int b);
int isBothLower(int a, int b);
int isBothUpper(int a, int b);
int isBothNumeric(int a, int b);
void expand(char a[], char b[]);

/* NOTE: I am aware that there are standard library implementations of some
of the routines that I have written here -- e.g. isAlphabetic(int) serves the
same purpose as isalpha(int) -- and the starndard library versions will be 
more robust, but I deemed it against the spirit of the exercise to use them,
so I wrote my own versions. */

main()
{
    char s1[MAXLINE] = "-a-z 0-9 a-b-f -0-2 A-z z-a a-zA-Z0-9 some text 1-1 WITH CAPITALS! 0-0 5-3 -";
    char s2[MAXLINE]; 
    
    expand(s1, s2);
    printf("When passed through the routine expand(), the string [%s] is converted to: \n", s1); 
    printf("%s\n", s2);

    return 0;
}

/* expand: populates s2 with the expanded groups in s1 */
void expand(char s1[], char s2[])
{
    int i;                  /* counter for s1 */
    int j;                  /* counter for s2 */
    int k;                  /* counter when expanding the group */
    int thePrevRangeEnd;    /* stores the index of the last valid range */
    int cur, next, prev;    /* hold current, previous and next values */

    for (i = j = 0; (cur = s1[i]) != '\0'; ++i) {
        
        /* only look for hyphens */
        if (isHyphen(cur)) { 
            
            if (isLeadingOrTrailing(s1, i)) {
                /* it is a leading or trailing hyphen so copy it */
                s2[j++] = cur;
            
            } else { 
                /* it is NOT leading or trailing so determine of it is part
                of a group */
                prev = s1[i-1];
                next = s1[i+1];

                /* check that the range matches first though */
                if (isValidRange(prev, next)) {

                    /* if we are the 2nd+ hypehen in a group e.g. between 
                    b and c in "a-b-c" then skip the first char in the 
                    group */
                    if (thePrevRangeEnd == (i - 1)){
                       ++prev;
                    }

                    /* now loop through each character in the range and add 
                    it to s2 */
                    for (k = prev; k <= next; ++k) {
                        s2[j++] = k;   
                    }

                    /* update the previous range end */
                    thePrevRangeEnd = i+1;
                }
            }
        }
    }

    /* we've finished expanding so close add in the terminator char */
    s2[j++] = '\0';
}


/* isAlphaNumeric: determines whether a char is an (upper or lowercase)
alpha char, a numeric char or none of the above. */
int isAlphaNumeric(int c)
{
    return isAlphabetic(c) || isNumeric(c);
}

/* isAlphabetic: determines whether or not a char is an alpha char in
either lowercase or uppercase range. */
int isAlphabetic(int c)
{
    return isLowercaseAlpha(c) || isUppercaseAlpha(c);
}

/* isLowercaseAlpha: determines whether or not a char is an alpha char in
the lowercase range. Assumes that lowercase alpha chars appear in one 
contiguous block in the character set. */
int isLowercaseAlpha(int c)
{
    return ('a' <= c && c <= 'z');
}

/* isUppercaseAlpha: determines whether or not a char is an alpha char in
the uppercase range. Assumes that uppercase alpha chars appear in one 
contiguous block in the character set. */
int isUppercaseAlpha(int c)
{
    return ('A' <= c && c <= 'Z');
}

/* isNumeric: determines whether or not a char is a numeric char i.e. 0-9.
Assumes that numeric chars appear in one contiguous block in the character
set. */
int isNumeric(int c)
{
    return ('0' <= c && c <= '9');
}

/* isHyphen: determines whether or not a char is a hyphen i.e. '-' */
int isHyphen(int c)
{
    return (c == HYPHEN);
}

/* isLeadingOrTrailing: determines if the hyphen just found is leading or
trailing */
int isLeadingOrTrailing(char s[], int pos)
{
    return pos == 0 || 
            !isAlphaNumeric(s[pos-1]) || 
            !isAlphaNumeric(s[pos+1]);
}

/* isValidRange: receives two integers and determines whether or not the 
first is smaller than the other and that they both represent chars in the
same character set grouping (i.e. between 'a' and 'z', 'A' and 'Z' and '0'
and '9'. */ 
int isValidRange(int a, int b)
{
    return isSmallerOrEqual(a, b) && 
            (isBothLower(a, b) || isBothUpper(a, b) || isBothNumeric(a, b)); 
}

/* isSmallerOrEqual: receives to integers and determines whether or not the first is 
smaller than (or euqal to) the latter. */
int isSmallerOrEqual(int a, int b)
{
    return (a <= b);
}

/* isBothLower: receives two integers and determines if they both represent 
lowercase chars in the characterset*/
int isBothLower(int a, int b)
{
    return isLowercaseAlpha(a) && isLowercaseAlpha(b);
}

/* isBothUpper: receives two integers and determines if they both represent 
uppercase chars in the characterset*/
int isBothUpper(int a, int b)
{
    return isUppercaseAlpha(a) && isUppercaseAlpha(b);
}

/* isBothNumeric: receives two integers and determines if they both represent 
numeric chars in the characterset*/
int isBothNumeric(int a, int b)
{
    return isNumeric(a) && isNumeric(b);
}
