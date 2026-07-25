#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int ft_strlen(char *s)
{
    int len;

    len = 0;
    while(s[len])
        len++;
    return (len);
}

typedef struct tuple
{
    char    *ptr;
    int     n;
} tuple;

tuple t_split(char *s, int acc, int nw)
{
    int     nb_char;
    int     i;
    tuple   tup;

    nb_char = 0;
    if (*s == 0)
        return (tup.ptr = malloc(
                acc + nw), tup.ptr[acc + nw - 1] = 0, tup.n = nw, tup);
    while (*s && (*s >= 8 && *s <= 13) || *s == 32)
        s++;
    while (s[nb_char] && !((
        s[nb_char] >= 8 && s[nb_char] <= 13) || s[nb_char] == 32))
        s[nb_char++];
    tup = t_split(s + nb_char, acc + nb_char, nw + (nb_char > 0));
    i = -1;
    while (++i < nb_char)
        tup.ptr[acc + nw + i] = s[i];
    return (tup.ptr[acc + nw + i] = 0, tup);
}

int main(int ac, char **av)
{
    char *buf;
    tuple tup;
    int len;
    char *cpy;
    char s[] = "abricot_boite   3\nbacking_powder  200\nblanc_oeuf      9000\nbeurre          1500\nbeurre_cacao    0\ncafe_arome      20\ncafe_grain      500\ncassonnade      1000\nchoc_blanc      5000\nchoc_noir       4000\ncitron          2000\ncompote_pomme	4000\ncreme			5000\nfarine			50000\n";
    if (ac > 2)
        return 1;
    if (ac == 2)
        tup = t_split(av[ac - 1], 0,0);
    else
        tup = t_split(s, 0, 0);
      cpy = tup.ptr;
    while (tup.n--)
    {
        len = ft_strlen(tup.ptr);
        write(1, tup.ptr, len);
        write(1, "\n", 1);
        tup.ptr += len + 1;
    }
    free(cpy);
    return 0;
}