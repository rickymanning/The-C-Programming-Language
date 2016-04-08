/* 2-4 Write an alternate version of squeeze(s1,s2) that deletes each
character in s1 that matches any character in s2, page 48 */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "a1b2c3d4e5f6g7h8i9j";
    char s2[] = "123456789";

    squeeze(s1, s2);

    return 0;
}

/* squeeze: delete all s2 from s1 */
void squeeze(char s1[], char s2[])
{
    int i, j, k, c, match;

    // explain what we are doing
    printf("Removing all [%s] from [%s]\n", s2, s1);

    // loop through s1 until we reach the end
    for (i = j = 0; s1[i] != '\0'; i++) {
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
        if (!match)
            s1[j++] = s1[i];
    }

    // terminate the string
    s1[j] = '\0';

    // show the resulting string
    printf("Result [%s]\n", s1);
}
