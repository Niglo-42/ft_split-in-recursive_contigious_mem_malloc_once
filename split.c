#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int len;

    len = 0;
    while(s[len])
        len++;
    return (len);
}

char    **t_split(char *s, int acc, int nw)
{
    int     nb_char;
    int     i;
    char    **buf;

    nb_char = 0;
    i = -1;
    if (*s == 0)
    {
        buf = calloc((nw + 1) * sizeof(char *) + acc + nw, 1);
        while (++i < nw)
            buf[i] = (char *)((char *)buf + (nw + 1) * sizeof(char *));
        return (buf);
    }
    while (*s && ((*s >= 8 && *s <= 13) || *s == 32))
        s++;
    while (s[nb_char] && !((
        s[nb_char] >= 8 && s[nb_char] <= 13) || s[nb_char] == 32))
        nb_char++;
    buf = t_split(s + nb_char, acc + nb_char, nw + (nb_char > 0));
    if (nb_char == 0)
        return (buf);
    buf[nw] = buf[nw] + acc + nw;
    while (++i < nb_char)
        buf[nw][i] = s[i];
    return (buf[nw][i] = 0, buf);
}//" mot1   mot2  mot3 "
// [nc:4 nw: 0 acc: 0] [nc:4 nw:1 acc:4] [nc:4 nw:2 acc:8] [nc: 0 nw:3 acc:12]
//ptr1, ptr2, ptr3, mot1\0mot2\0mot3\0

int main(int ac, char **av)
{
    char **buf;
    int len;
    int i;
    int j;
    //char s[] = "abricot_boite   3\nbacking_powder  200\nblanc_oeuf      9000\nbeurre          1500\nbeurre_cacao    0\ncafe_arome      20\ncafe_grain      500\ncassonnade      1000\nchoc_blanc      5000\nchoc_noir       4000\ncitron          2000\ncompote_pomme     4000\ncreme                     5000\nfarine                        50000\n";
    char s[100] = "\tA\nBB\rCCC\fDDDD\vEEEEE FFFFFF";
    i = 0;
    if (ac == 2)
        buf = t_split(av[1], 0, 0);
    else
        buf = t_split(s, 0, 0);
    while (buf[i] != NULL)
        printf("%s\n", buf[i++]);
    free(buf);
    return 0;
}
