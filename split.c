#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int len;

    len = 0;
    while(s[len])
        len++;
    return (len);
}

char    *t_split(char *buf, char *s, int acc, int nw)
{
    int     nb_char;
    int     i;

    nb_char = 0;
    if (*s == 0)
        return (buf = calloc(acc + nw + 1, 1), buf);
    while (*s && (*s >= 8 && *s <= 13) || *s == 32)
        s++;
    while (s[nb_char] && !((
        s[nb_char] >= 8 && s[nb_char] <= 13) || s[nb_char] == 32))
        s[nb_char++];
    buf = t_split(buf, s + nb_char, acc + nb_char, nw + (nb_char > 0));
    i = -1;
    while (++i < nb_char)
        buf[acc + nw + i] = s[i];
    return (buf[acc + nw + i] = 0, buf);
}

int main(int ac, char **av)
{
    char *buf;
    int len;
    int i;
    char s[] = "abricot_boite   3\nbacking_powder  200\nblanc_oeuf      9000\nbeurre          1500\nbeurre_cacao    0\ncafe_arome      20\ncafe_grain      500\ncassonnade      1000\nchoc_blanc      5000\nchoc_noir       4000\ncitron          2000\ncompote_pomme	4000\ncreme			5000\nfarine			50000\n";
    
    i = 0;
    buf = t_split(buf, s, 0, 0);
    while (buf[i])
    {
        len = ft_strlen(&buf[i]);
        write(1, &buf[i], len);
        write(1, "\n", 1);
        i += len + 1;
    }
    free(buf);
    return 0;
}
