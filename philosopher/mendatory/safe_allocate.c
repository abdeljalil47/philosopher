#include "philo.h"

void	*safe_allocate(size_t data)
{
	void *mal;

	mal = malloc(data);
	if (mal == NULL)
	{
		error_exit("\tfunction malloc() failed!\n");
		return NULL;
	}
	return mal;
}
