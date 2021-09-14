#include "philosophers.h"

void	ft_init(t_philo *philo, t_mutex *mutex, t_data *data, int n)
{
	u_int64_t	i;

	i = 0;
	while (i < (u_int64_t)n)
	{
		pthread_mutex_init(&mutex->mutex[i], NULL);
		philo[i].data = data;
		i++;
	}
	ft_init2(philo, mutex, data, data->np);
	i = 0;
	while (i < (u_int64_t)n)
	{
		pthread_join(philo[i].philo, NULL);
		pthread_join(philo[i].check, NULL);
		i++;
	}
}

void	ft_init2(t_philo *philo, t_mutex *mutex, t_data *data, int n)
{
	u_int64_t	i;

	i = 0;
	while (i < (u_int64_t)n)
	{
		//philo[i].eat_c = 0; //add
		//philo[i].has_eaten = 0; //add
		//philo[i].data = data; //add
		//philo[i].np = data->np; //add
		philo[i].t_mutex = mutex;
		philo[i].ind = i;
		//philo[i].eat = data->eat; //add
		pthread_create(&philo[i].philo, NULL, &routine, &philo[i]);
		pthread_create(&philo[i].check, NULL, &ft_check, &philo[i]);
		usleep(4);
		i += 2;
	}
	i = 1;
	while (i < (u_int64_t)n)
	{
		philo[i].eat_c = 0; //add
		//philo[i].has_eaten = 0; //add
		//philo[i].data = data; //add
		//philo[i].np = data->np; // add
		philo[i].t_mutex = mutex;
		philo[i].ind = i;
		//philo[i].eat = data->eat; //add
		pthread_create(&philo[i].philo, NULL, &routine, &philo[i]);
		pthread_create(&philo[i].check, NULL, &ft_check, &philo[i]);
		usleep(4);
		i += 2;
	}
}

void	ft_parsing(t_data *data, int argc, char **argv)
{
	if (ft_check_arguments(argc, &(*argv)) != 1)
	{
		printf("Invalid arguments\n");
		exit (0);
	}
	data->np = atoi(argv[1]);
	data->ttd = atoi(argv[2]);
	data->tte = atoi(argv[3]);
	data->tts = atoi(argv[4]);
	if (argc == 6)
		data->eat = ft_atoi(argv[5]);
	else
		data->eat = -1;
}

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_data		data;
	t_mutex		mutex;
	u_int64_t		i;

	i = 0;
	mutex.mutex = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	philo = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	data.start = ft_get_time();
	data.end1 = 0;
	data.end2 = 0;
	ft_parsing(&data, argc, &(*argv));
	pthread_mutex_init(&mutex.mutex_stampa, NULL);
	ft_init(philo, &mutex, &data, data.np);
	while (i < (u_int64_t)data.np)
	{
		pthread_mutex_destroy(&mutex.mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->t_mutex->mutex_stampa);
	free(&philo);
	free(&data);
	return (0);
}
