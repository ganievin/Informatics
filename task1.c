#include <stdio.h>
#include <stdlib.h>

double *find(double *d) //для вариации 1
{
    for (; *d!=12; d++);
    return d;
}
char *f(char *p1, char *p2)
{
    for (; *p1!= p2[2]; p1++);
    return p1-3;
}
int main()
{
    /* для вариации 1: double d[] = {5, 1, 4, 2, 3, 7, 9, 8, 6, 11, 12, 10,
                  13, 17, 14, 16, 15, 19, 21, 22, 18, 20, 26, 25, 23, 24};
    double *p = find(d) - 11;
    printf("%f%f", p[1], *(p+22));
    return 0; */
    char s[] = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
    char *p1 = s+7; char *p2 = f(s, &p1[7]);
    printf("%s%c", p2+2, *(&p2[5] - 1));
    return 0;
}

