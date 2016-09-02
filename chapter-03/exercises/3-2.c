/* 3-2 Write a function escape(s,t) that converts characters like newline
and tab into visible escape sequences like \n and \t as it copies the string
t to s. Use a switch. Write a function for the other direction as well, 
converting escape sequences into the real characters, page 60 */

#include <stdio.h>

#define MAXLINE 1000 

void escape(char s[], char t[]);
void unescape(char t[], char s[]);

int getline(char line[], int lim);

main()
{
    char x[MAXLINE];
    char y[MAXLINE * 2];
    char z[MAXLINE];

    /* get a line to process */
    printf("Please input a line with tabs, spaces and a newline: \n");
    getline(x, MAXLINE);    

    /* escape the newline and tab chars */
    escape(y, x);
    printf("ESCAPED\n%s\n", y);

    /* unescape the escaped chars */
    unescape(z, y);
    printf("UNESCAPED\n%s\n", z);
   
    return 0;
}

/* getline: gets a line of input and returns it */
int getline(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim -1 && (c = getchar()) != EOF; ++i)
        line[i] = c;

    line[++i] = '\0';

    return i;
}

/* escape: loops though the the array t and copies to s, replacing any tab
and newline characters with their corresponding escape chars */
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; ++i) {
       switch(t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;

            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;

            default:
                 s[j++] = t[i];
                 break;
        }
    } 
}

/* unescape: loops though the the array s and copies to t, replacing any 
escaped tab and newline characters with their corresponding unescaped chars */
void unescape(char t[], char s[])
{
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; ++i) 
        if (s[i] == '\\') 
            switch(s[i+1]) {
                case 'n':
                    t[j++] = '\n';
                    ++i;
                    break;

                case 't':
                    t[j++] = '\t';
                    ++i;
                    break;
               
                default:
                    t[j++] = s[i];
                    break;
            }
        else
            t[j++] = s[i];    
    
    t[j] = '\0';
}  
