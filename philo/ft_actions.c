#include "philo.h"

// forks
void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->R_fork);
	messages(TAKE_FORKS, philo);
	pthread_mutex_lock(philo->L_fork);
	messages(TAKE_FORKS, philo);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->L_fork);
	pthread_mutex_unlock(philo->R_fork);
	messages(SLEEPING, philo);
	ft_usleep(philo->args->time_to_sleep);
}

// eat
void	eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->lock);
	philo->eating = 1;
	philo->time_to_die = get_time() + philo->args->time_to_die;
	messages(EATING, philo);
	philo->must_meals++;
	ft_usleep(philo->args->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->lock);
	drop_forks(philo);
}

// sleep
// static inline void	_sleep(t_philo *philo)
// {
// 	monitoring(philo, SLEEP);
// 	usleep(philo->args->time_to_sleep * MICROSEC);
// }
int	ft_usleep(useconds_t time)
{
	u_int64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

// think


// die


// routine
// void	*ft_routine(void *philo_pointer)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *) philo_pointer;
// 	philo->time_to_die = philo->args->time_to_die + get_time();
// 	if (pthread_create(&philo->t1, NULL, &ft_supervise, (void *)philo))
// 		return ((void *)1);
// 	while (philo->args->dead == 0)
// 	{
// 		eat(philo);
// //        printf("Philosopher %d is thinking", philo);
// 		messages(THINKING, philo);
// 	}
// 	if (pthread_join(philo->t1, NULL))
// 		return ((void *)1);
// 	return ((void *)0);
// }