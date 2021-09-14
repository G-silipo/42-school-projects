#include "philosophers.h"

u_int64_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int time)
{
	unsigned long	end;

	end = ft_get_time() + time;
	while (ft_get_time() < end)
		usleep(time);
}

/*int	ft_burp(t_philo *philo)
{
	t_philo	*philos;
	int		i;

	philos = philo->table->philos;
	i = 0;
	if (philo->table->goal == -1)
		return (0);
	else
	{
		while (i < philo->table->n_philo)
		{
			if (philos[i].n_eaten != philo->table->goal && \
			philos[i].n_eaten < philo->table->goal)
				return (0);
			i++;
		}
	}
	return (1);
}*/

/*int	ft_someone_dead(t_philo *philo)  // add
{
	t_philo	*philos;
	int		i;

	philos = philo->data->philo;
	i = 0;
	while (i < philo->data->np - 1)
	{
		if (philos[i].dead == 1)
			return (1);
		i++;
	}
	return (0);
}*/

