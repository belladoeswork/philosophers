#include "philo.h"

void	*ft_monitor(void *data_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) data_pointer;
	pthread_mutex_lock(&philo->args->write);
	printf("data val: %d", philo->args->dead);
	pthread_mutex_unlock(&philo->args->write);
	while (philo->args->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (philo->args->finished >= philo->args->nbr_of_philo)
			philo->args->dead = 1;
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}
