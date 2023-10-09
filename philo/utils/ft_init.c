#include "../philo.h"

// init input args
int	init_args(t_args *args, char **argv, int argc)
{
   // (u_int64_t) (int)
	args->nbr_of_philo = (int) ft_atoi(argv[1]);
	args->time_to_die = (u_int64_t) ft_atoi(argv[2]);
	args->time_to_eat = (u_int64_t) ft_atoi(argv[3]);
	args->time_to_sleep = (u_int64_t) ft_atoi(argv[4]);
	if (argc == 6)
		args->meals = (int) ft_atoi(argv[5]);
    else
        args->meals = -1;
	args->dead = 0;
	args->finished = 0;
	pthread_mutex_init(&args->write, NULL);
	pthread_mutex_init(&args->lock, NULL);
	return (0);
}

// init args, memory, forks, philos
int	init(t_args *args, char **argv, int argc)
{
	if (init_args(args, argv, argc))
		return (1);
	if (alloc(args))
		return (1);
	if (init_forks(args))
		return (1);
	init_philos(args);
	return (0);
}

// init threads
int	init_thread(t_args *args)
{
	int			i;
	pthread_t	t0;

	i = -1;
	args->start_time = get_time();
	if (args->meals > 0)
	{
		if (pthread_create(&t0, NULL, &ft_monitor, &args->philos[0]))
			return (error(TH_ERR, args));
	}
	while (++i < args->nbr_of_philo)
	{
		if (pthread_create(&args->tid[i], NULL, &ft_routine, &args->philos[i]))
			return (error(TH_ERR, args));
		ft_usleep(1);
	}
	i = -1;
	while (++i < args->nbr_of_philo)
	{
		if (pthread_join(args->tid[i], NULL))
			return (error(JOIN_ERR, args));
	}
	return (0);
}
