#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_mutex
{
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_stampa;
}				t_mutex;

typedef struct s_data
{
	int			np;
	int			tte;
	int			ttd;
	int			tts;
	int			eat;
	u_int64_t	start;
	int			end1;
	int			end2;
	struct s_philo	*philos; // aggiunto
}				t_data;

typedef struct s_philo
{
	pthread_t			philo;
	int					ind;
	struct s_data		*data;
	struct s_mutex		*t_mutex;
	int					eat_c; //add
	int					has_eaten; // add
	int					np; // add
	int					eat; //add
	u_int64_t			starve;
	u_int64_t			starve_check;
	pthread_t			check;
}				t_philo;

void		*routine(void *argp);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_stampa(t_philo *philo, char c);
void		ft_usleep(int time);
u_int64_t	ft_get_time(void);
void		*ft_check(void *argp);
int			ft_controllo(t_philo *philo);
int			ft_atoi(char *str);
int			ft_check_arguments(int argc, char **argv);
void		ft_init2(t_philo *philo, t_mutex *mutex, t_data *data, int n);
void		ft_stampa2(t_philo *philo, char c);
void		ft_fork(t_philo *philo, char c);
void		ft_sleep_think(t_philo *philo, char c);
int			ft_count(t_philo *philo); // add
int 		ft_controllo_fame(t_philo *philo);

#endif