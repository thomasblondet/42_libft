#include "libft.h"

static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		n *= -1;
		++digits;
	}
	if (n == 0)
		digits = 1;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	*fill_negative(char *s, int n)
{
	int	i;
	int	len;

	i = 0;
	len = count_digits(n);
	n *= -1;
	s[0] = '-';
	while (n && len > 0)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
		len--;
		i++;
	}
	s[++i] = '\0';
	return (s);
}

static char	*fill_positive(char *s, int n)
{
	int	i;
	int	len;

	i = 0;
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	len = count_digits(n) - 1;
	while (n)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
		len--;
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*is_min(void)
{
	char	*min;

	min = malloc(12 * sizeof(char));
	if (!min)
		return (NULL);
	ft_memcpy(min, "-2147483648", 12);
	return (min);
}

char	*ft_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
		return (is_min());
	if (n >= 0)
	{
		s = malloc((count_digits(n) + 1) * sizeof(char));
		if (!s)
			return (NULL);
		s = fill_positive(s, n);
	}
	else
	{
		s = malloc((count_digits(n) + 2) * sizeof(char));
		if (!s)
			return (NULL);
		s = fill_negative(s, n);
	}
	return (s);
}
