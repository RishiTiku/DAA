#include <stdio.h>
#include <string.h>
 
// d is the number of characters in the input alphabet
#define d 256

int flag = 0;

void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
 
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
 
        // If the hash values match then only
        // check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1,
            // ...i+M-1]
            if (j == M){
                printf("Pattern found at index %d \n", i);
                flag = 1;
            }
        }
 
        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            // if t<0, change t to positive
            if (t < 0)
                t = (t + q);
        }
    }
}
 
/* Driver Code */
int main()
{
    char txt[500] = "";
    char pat[500] = "";
    int q = 101;// q should be a prime number

    printf("Enter txt string.\n");
    scanf("%[^\n]s", txt);
    fflush(stdin);
    printf("Enter pattern string.\n");
    scanf("%[^\n]s", pat);
    printf("Enter a prime number.\n");
    scanf("%d", &q);
    search(pat, txt, q);
    if(flag == 0){
        printf("No sequence matched.\n");
    }
    return 0;
}