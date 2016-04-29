/* 2-5 Write the function any(s1, s2), which returns the first location in
the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2 (The standard library function strpbrk does
the same job but returns a pointer to the location), page 48 */

#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char s1[] = "a1b2c3d4e5f6g7h8i9j";
    char s2[] = "123456789";
    char s3[] = "klmnopq";
    printf("The first matching char in s2 [%s] that occurs in s1[%s] is at "
            "location [%d]\n", s2, s1, any(s1, s2));

    printf("There isn't a matching char in s3 [%s] that occurs in s1[%s], "
            "so -1 should be returned [%d]\n", s3, s1, any(s1, s3));

    return 0;
}

int any(char s1[], char s2[])
{
    int loc, i, k, c, match;

    // assume that we will not find a match and update if we do
    loc = -1;

    // loop through s1 until we reach the end
    for (i = 0; s1[i] != '\0' && loc == -1; i++) {
        // we are going to be looping through s2 and comparing with the
        // current s1 char, until we either reach the end, or we find a
        // match. make sure that we clear k (counter) and match (match flag)
        // before we start.
        k = match = 0;

        // now perform the loop through s2 (note the use of k++)
        while((c = s2[k++]) != '\0' && !match)
            match = (c == s1[i]);

        // if we didn't find a match then include re-write the char back
        // into the string (note the use of j++)
        if (match)
            loc = i;
    }

    return loc;
}
