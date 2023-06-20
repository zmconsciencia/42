#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int x = 10;

void	*routine()
{
	x++;
	printf("Value of x: %d\n", x);
	return (0);
}

void	*routine2()
{
	sleep(3);
	x += 5;
	printf("Value of x: %d\n", x);
	return (0);
}

int main(int ac, char **av)
{
	pthread_t t1, t2;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0) //igual a fork
		return (1); 
	if (pthread_create(&t2, NULL, &routine2, NULL) != 0) //igual a fork
		return (1); 
	if (pthread_join(t1, NULL) != 0) // wait ate acabar exec
		return (2);
	if (pthread_join(t2, NULL) != 0) // wait ate acabar exec
		return (2);
	return (0);
}