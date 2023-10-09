#include "../philo.h"



void	clear_args(t_args	*args)
{
	if (args->tid)
		free(args->tid);
	if (args->forks)
		free(args->forks);
	if (args->philos)
		free(args->philos);
}

void	ft_exit(t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->nbr_of_philo)
	{
		pthread_mutex_destroy(&args->forks[i]);
		pthread_mutex_destroy(&args->philos[i].lock);
	}
	pthread_mutex_destroy(&args->write);
	pthread_mutex_destroy(&args->lock);
	clear_args(args);
}

int	error(char *str, t_args *args)
{
	printf("%s\n", str);
	if (args)
		ft_exit(args);
	return (1);
}

int	case_one(t_args *args)
{
	args->start_time = get_time();
	if (pthread_create(&args->tid[0], NULL, &ft_routine, &args->philos[0]))
		return (error(TH_ERR, args));
	pthread_detach(args->tid[0]);
	while (args->dead == 0)
		ft_usleep(0);
	ft_exit(args);
	return (0);
}