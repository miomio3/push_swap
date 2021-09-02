void	bouble(int	*a, int argc)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while(i < argc - 2)
	{
		j = 0;
		while(j < argc - 2)
		{
			if(a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
