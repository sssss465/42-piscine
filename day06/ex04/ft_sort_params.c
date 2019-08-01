/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andhuang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:34:17 by andhuang          #+#    #+#             */
/*   Updated: 2019/07/17 15:52:42 by andhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_printword(char *word)
{
	int i;

	i = 0;
	while (word[i] != '\0')
		ft_putchar(word[i++]);
	ft_putchar('\n');
}

void	swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	i = 2;
	while (i < argc)
	{
		j = i;
		while (j > 1 && ft_strcmp(argv[j - 1], argv[j]) > 0)
		{
			swap(&argv[j], &argv[j - 1]);
			j--;
		}
		i++;
	}
	i = 1;
	while (i < argc)
		ft_printword(argv[i++]);
	return (0);
}
