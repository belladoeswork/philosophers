#include "philo.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc < 5 || argc > 6)
		return (1);
	if (check_args(argv))
		return (1);
	if (init(&args, argv, argc))
		return (1);
	if (args.nbr_of_philo == 1)
		return (case_one(&args));
	if (init_thread(&args))
		return (1);
	ft_exit(&args);
	return (0);
}
