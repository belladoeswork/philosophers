#include "philo.h"

void	*ft_routine(void *philo_pointer)
{
	t_philo	*philo;

	philo = (t_philo *) philo_pointer;
	philo->time_to_die = philo->args->time_to_die + get_time();
	if (pthread_create(&philo->t1, NULL, &ft_supervise, (void *)philo))
		return ((void *)1);
	while (philo->args->dead == 0)
	{
		eat(philo);
//        printf("Philosopher %d is thinking", philo);
		messages(THINKING, philo);
	}
	if (pthread_join(philo->t1, NULL))
		return ((void *)1);
	return ((void *)0);
}
