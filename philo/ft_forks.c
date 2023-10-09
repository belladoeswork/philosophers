#include "philo.h"

// init (clockwise) forks
int	init_forks(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nbr_of_philo)
		pthread_mutex_init(&args->forks[i], NULL);
	i = 0;
	args->philos[0].R_fork = &args->forks[0];
	args->philos[0].L_fork = &args->forks[args->nbr_of_philo - 1];
	i = 1;
	while (i < args->nbr_of_philo)
	{
		args->philos[i].R_fork = &args->forks[i];
		args->philos[i].L_fork = &args->forks[i - 1];
		i++;
	}
	return (0);
}


