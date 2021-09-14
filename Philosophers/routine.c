#include "philosophers.h"

void	*routine(void *argp)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = (t_philo *)argp;
	while(1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
		if (ft_controllo_fame(philo) == philo->data->np - 1)
		{
			ft_stampa(philo, 'y');
			return ;
		}
	}
	return (NULL);
}

void	ft_sleep(t_philo *philo)
{
	ft_usleep(philo->data->tts);
	ft_stampa(philo, 's');
	
}

void	ft_think(t_philo *philo)
{
	ft_stampa(philo, 't');
	
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->t_mutex->mutex[philo->ind]);
	ft_stampa(philo, 'l' );
	if (philo->ind == 0)
		pthread_mutex_lock(&philo->t_mutex->mutex[philo->data->np - 1]);
	pthread_mutex_lock(&philo->t_mutex->mutex[philo->ind - 1]);
	ft_stampa(philo, 'r');
	ft_stampa(philo, 'e');
	ft_usleep(philo->data->tte);
	if(philo[philo->ind].eat_c >= philo->data->eat)
		philo[philo->ind].has_eaten = 1;
	pthread_mutex_unlock(&philo->t_mutex->mutex[philo->ind]);
	if (philo->ind == (0))
		pthread_mutex_unlock(&philo->t_mutex->mutex[philo->data->np - 1]);
	pthread_mutex_unlock(&philo->t_mutex->mutex[philo->ind - 1]);
	
}
