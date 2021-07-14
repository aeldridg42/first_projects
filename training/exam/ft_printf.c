#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int g_res;
int g_width;
int g_prec;

static void ft_putchar(char c)
{
    write(1, &c, 1);
    ++g_res;
}

static void ft_putstr(char *str, int len)
{
    int i = 0;
    while(len-- && str[i])
        ft_putchar(str[i++]);
}

static int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return (0);
    while(*str++)
        ++i;
    return (i);
}

static char *ft_itoa_base(unsigned long num, int base)
{
    char *str;
    unsigned long temp = num;
    int len = 0;
    if (num == 0)
        ++len;
    while(temp)
    {
        temp /= base;
        ++len;
    }
    str = malloc(len + 1);
    str[len] = '\0';
    while(len)
    {
        str[len - 1] = num % base;
        if (num % base > 9)
            str[len - 1] += 'a' - 10;
        else
            str[len - 1] += '0';
        --len;
        num = num / base;
    }
    return (str);
}

static void ft_printhex(unsigned long num)
{
    char *str = ft_itoa_base(num, 16);
    int len = ft_strlen(str);

    if (g_prec != -1 && g_prec > len)
        len = g_prec;
    while(g_width > len)
    {
        ft_putchar(' ');
        --g_width;
    }
    while(len > ft_strlen(str))
    {
        ft_putchar('0');
        --len;
    }
    ft_putstr(str, ft_strlen(str));
    free(str);
}

static void ft_printint(long num)
{
    int minus = 0;
    char *str;
    int len;

    if (num < 0)
    {
        minus = 1;
        num *= -1;
        g_width--;
    }
    str = ft_itoa_base(num, 10);
    len = ft_strlen(str);
    if (g_prec != -1 && g_prec > len)
        len = g_prec;
    while(g_width > len)
    {
        ft_putchar(' ');
        --g_width;
    }
    if (minus)
        ft_putchar('-');
    while(len > ft_strlen(str))
    {
        ft_putchar('0');
        --len;
    }
    ft_putstr(str, len);
    free(str);
}

static void ft_printstr(char *str)
{
    int len = ft_strlen(str);
    if (g_prec != -1 && g_prec < len)
        len = g_prec;
    while(g_width > len)
    {
        ft_putchar(' ');
        --g_width;
    }
    ft_putstr(str, len);
}

int ft_printf(const char *format, ...)
{
    int i = 0;
    g_res = 0;
    va_list parg;

    va_start(parg, format);

    while(format[i])
    {
        if(format[i] != '%')
            ft_putchar(format[i++]);
        else if(format[i] == '%' && format[i + 1])
        {
            ++i;
            g_width = 0;
            g_prec = -1;
            while(format[i] >= '0' && format[i] <= '9')
                g_width = (g_width * 10) + (format[i++] - '0');
            if(format[i] == '.')
            {
                ++i;
                g_prec = 0;
                while(format[i] >= '0' && format[i] <= '9')
                    g_prec = (g_prec * 10) + (format[i++] - '0');
            }
            if(format[i] == 's')
            {
                ft_printstr(va_arg(parg, char *));
                ++i;
            }
            else if(format[i] == 'd')
            {
                ft_printint(va_arg(parg, int));
                ++i;
            }
            else if(format[i] == 'x')
            {
                ft_printhex(va_arg(parg, unsigned long));
                ++i;
            }
            else
                ft_putchar(format[i++]);
        }
        if (format[i] == '\0')
                break; 
    }
    va_end(parg);
    return (g_res);
}

int main()
{
    int i = -12515;
    printf("|%10.8d|\n", i);
    ft_printf("|%10.8d|\n", i);
}