#include "../philo.h"

// checks args values and inputs

// int check_args_value(const t_args *args) {
//     if (args->nbr_of_philo <= 0 || args->nbr_of_philo > 200 || args->time_to_die < 0
//         || args->time_to_eat < 0 || args->time_to_sleep < 0)
//         return (error(ERR_IN_2, NULL));
    
//     return (0);
// }

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				return (error(ERR_IN_1, NULL));
			j++;
		}
		i++;
	}
	return (0);
}


// int check_args(const t_args *args, char **argv) {
//     int i = 1;
    
//     while (argv[i]) {
//         int j = 0;
        
//         while (argv[i][j]) {
//             if (argv[i][j] == ' ') 
//             {
//                 j++;
//                 continue;  // Ignore spaces
//             }
//             if (argv[i][j] < '0' || argv[i][j] > '9') 
//             {
//                 return (error(ERR_IN_1, NULL)); // Invalid character encountered
//             }
//             j++;
//         }
//         i++;
//     }

//     if (args->nbr_of_philo <= 0 || args->nbr_of_philo > 200 || args->time_to_die < 0
//         || args->time_to_eat < 0 || args->time_to_sleep < 0) {
//         return (error(ERR_IN_2, NULL)); // Invalid argument values
//     }

//     return (0); // Arguments are valid
// }

int	input_checker(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if ((argv[i][j] < 48 || argv[i][j] > 57))
				return (error(ERR_IN_1, NULL));
			j++;
		}
		i++;
	}
	return (0);
}