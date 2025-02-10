#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
char	*put_binary(int	num)
{
	int	i;
	char	*bin;

	i = 7;
	bin = ft_calloc(9, 1); 
	bin[0] = '0';
	while (num)
	{
		bin[i] = num % 2 + '0';
		i--;
		num = num / 2 ;
	}
	return bin;
}

char	*string_to_binary(char *str)
{
	int	i;
	char	*bin_string;

	bin_string = malloc(sizeof(char) * ft_strlen(str) + 1);
	bin_string[0] = 0;
	i = 0;
	while (str[i])
	{
		bin_string = ft_strjoin(bin_string,put_binary(str[i]));
		i++;
	}
	return bin_string;
}

int main()
{
	char *a;
	a = string_to_binary("abc");
	printf("%s\n",a);
	free(a);
	printf("%s$$$$$\n");
}
