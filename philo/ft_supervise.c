# include "philo.h"

void	*ft_supervise(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	while (philo->args->dead == 0)
	{
		pthread_mutex_lock(&philo->lock);
		if (get_time() >= philo->time_to_die && philo->eating == 0)
//            printf("Philosopher %d died", philo);

			messages(DIED, philo);
		if (philo->must_meals == philo->args->meals)
		{
			pthread_mutex_lock(&philo->args->lock);
			philo->args->finished++;
			philo->must_meals++;
			pthread_mutex_unlock(&philo->args->lock);
		}
		pthread_mutex_unlock(&philo->lock);
	}
	return ((void *)0);
}
