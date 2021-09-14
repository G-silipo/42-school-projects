
#include "philosophers.h"

void	ft_fork(t_philo *philo, char c)
{
	if (c == 'r')
		printf("\e[1;37mPhilosopher %d has taken the right fork 🥢\n\e[0m",
			philo->ind);
	else if (c == 'l')
		printf("\e[1;37mPhilosopher %d has taken the left fork 🥢\n\e[0m",
			philo->ind);
	else
		return ;
}

void	ft_sleep_think(t_philo *philo, char c)
{
	if (c == 's')
		printf("\e[0;33mPhilosopher %d is sleeping 💤\n\e[0m", philo->ind);
	else if (c == 't')
		printf("\e[1;32mPhilosopher %d is thinking 💭\n\e[0m", philo->ind);
	else
		return ;
}

void	ft_eating(t_philo *philo, char c)
{
	u_int64_t	end;
	u_int64_t	time;

	end = ft_get_time();
	time = end - philo->data->start;
	if (c == 'e')
	{
		philo[philo->ind].eat_c++;
		printf("\e[0;35mPhilosopher %d is eating  🍝\n\e[0m", philo->ind);
		//printf("\e[0;35mPhilosopher %d has eaten %d times 🍝\n\e[0m", philo->ind, philo[philo->ind].eat_c);
		philo->starve_check = end;
	}
	else
		return ;
}

void	ft_stampa(t_philo *philo, char c)
{
	u_int64_t	end;
	u_int64_t	time;

	end = ft_get_time();
	time = end - philo->data->start;
	pthread_mutex_lock(&philo->t_mutex->mutex_stampa);
	printf("\e[0;34m%lu \e[0m ", time);
	ft_fork(philo, c);
	ft_sleep_think(philo, c);
	ft_eating(philo, c);
	if (c == 'd')
	{
		printf("\e[0;31mPhilosopher %d has died 💀\n\e[0m", philo->ind);
		philo->data->end1 = 1;
		exit (0);
	}
	else if (c == 'y')
	{
		printf("\e[0;36mAll Philosophers has eaten! 🤢\n\e[0m");
		philo->data->end2 = 1;
		exit(0);
	}
	pthread_mutex_unlock(&philo->t_mutex->mutex_stampa);
}
