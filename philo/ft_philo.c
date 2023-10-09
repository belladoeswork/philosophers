
#include "philo.h"


// init threads


// join threads

// free memory

// allocate memory

int	alloc(t_args *args)
{
	args->tid = malloc(sizeof(pthread_t) * args->nbr_of_philo);
	if (!args->tid)
		return (error(ALLOC_ERR_1, args));
	args->forks = malloc(sizeof(pthread_mutex_t) * args->nbr_of_philo);
	if (!args->forks)
		return (error(ALLOC_ERR_2, args));
	args->philos = malloc(sizeof(t_philo) * args->nbr_of_philo);
	if (!args->philos)
		return (error(ALLOC_ERR_3, args));
	return (0);
}


// philo

// create

// init
void	init_philos(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->nbr_of_philo)
	{
		args->philos[i].args = args;
		args->philos[i].id = i + 1;
		args->philos[i].time_to_die = args->time_to_die;
		args->philos[i].must_meals = 0;
		args->philos[i].eating = 0;
		args->philos[i].status = 0;
		pthread_mutex_init(&args->philos[i].lock, NULL);
		i++;
	}
}
// join