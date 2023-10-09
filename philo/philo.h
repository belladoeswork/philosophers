
#ifndef PHILO_H
# define PHILO_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

//	alloc_err
# define ALLOC_ERR_1 "ERROR WHILE ALLOCATING THREADS IDs"
# define ALLOC_ERR_3 "ERROR WHILE ALLOCATING PHILOS"
# define ALLOC_ERR_2 "ERROR WHILE ALLOCATING FORKS"
//	input_err
# define ERR_IN_1 "INVALID INPUT CHARACTER"
# define ERR_IN_2 "INVALID INPUT VALUES"
//	pthread_err
# define TH_ERR "ERROR WHILE CREATING THREADS"
# define JOIN_ERR "ERROR WHILE JOINING THREADS"
# define INIT_ERR_1 "ERROR WHILE INIT FORKS"
//	time_err
# define TIME_ERR "UNABLE TO RETRIVE UTC"
//	philo_msg
# define TAKE_FORKS "has taken a fork"
# define THINKING "is thinking"
# define SLEEPING "is sleeping"
# define EATING "is eating"
# define DIED "died"

//struct	s_data;

typedef struct s_philo
{
	struct s_args	*args;
	pthread_t		t1;
	int				id;
	int				must_meals;
	int				status;
	int				eating;
	uint64_t		time_to_die;
	pthread_mutex_t	lock;
	pthread_mutex_t	*R_fork;
	pthread_mutex_t	*L_fork;

}	t_philo;

typedef struct s_args
{
	pthread_t		*tid;
	int				nbr_of_philo;
	int				meals;
	int				dead;
	int				finished;
	t_philo			*philos;
	u_int64_t   time_to_die;
    //int		time_to_die;
	u_int64_t	time_to_eat;	
    //int time_to_eat;
	u_int64_t	time_to_sleep;	
    //int time_to_sleep;
	u_int64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;

}	t_args;

//	utils
long		ft_atoi(const char *str);

//

void	*ft_monitor(void *data_pointer);
void	*ft_supervise(void *philo_pointer);
void	*ft_routine(void *philo_pointer);
//
int	alloc(t_args *args);
void	init_philos(t_args *args);
//
int	init_forks(t_args *args);
//
int	error(char *str, t_args *args);
int			ft_strcmp(char *s1, char *s2);
void		messages(char *str, t_philo *philo);
void		ft_exit(t_args *args);
//
u_int64_t	get_time(void);
//
void	messages(char *str, t_philo *philo);
//
void	eat(t_philo *philo);
//
int	ft_usleep(useconds_t time);
//
int	init_args(t_args *args, char **argv, int argc);
int	init(t_args *args, char **argv, int argc);
int	init_thread(t_args *args);
//
int			input_checker(char **argv);
//
int	case_one(t_args *args);
//int check_args(const t_args *args, char **argv);
int	check_args(char **argv);



#endif