#include "philosophers.h"

int	ft_check_arguments(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (argc < 5 || argc > 6)
		return (0);
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if (argv[i][k] >= '0' && argv[i][k] <= '9')
				k++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	nbr;

	i = 0;
	neg = 1;
	nbr = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\v') || \
		(str[i] == '\f') || (str[i] == '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	nbr = nbr * neg;
	return (nbr);
}

void	*ft_check(void *argp)
{
	t_philo	*philo;

	philo = (t_philo *)argp;
	philo->starve_check = ft_get_time();
	int i = ft_controllo_fame(philo);
	int j = ft_controllo(philo);
	printf ("dio cane %d muori%d\n", i, j);
	while (ft_controllo(philo) && !ft_controllo_fame(philo))
	{
		usleep(5);
	}
	return (NULL);
}

int	ft_controllo(t_philo *philo)
{
	u_int64_t	time;
	u_int64_t	time_check;
	int			i;

	i = 0;
	time_check = ft_get_time();
	time = time_check - philo->starve_check;
	if (time > ((u_int64_t)philo->data->ttd))
	{
		//printf("sono qui1");
		ft_stampa(philo, 'd');
		return (0);
	}
	return (1);
}

int ft_controllo_fame(t_philo *philo)
{
	int i = 0;

	//printf("eat %i\n", philo->data->eat);
	if (philo->data->eat != -1)
	{
		while ( i <= philo->data->np - 1)
		{
			if (philo->eat_c != philo->data->eat + 1 && philo->eat_c < philo->data->eat + 1)
				return (1);
			i++;
			if (i == philo->data->np - 1)
				return (i);
			//printf("eat_c %i ind %i i  %d np  %d \n", philo->eat_c, philo->ind, i, philo->data->np);
		}
	}
	return (0);
}