#include <stdio.h>
#include "../get_next_line.h"

int main()
{
	int     fd;
	char    *line;

	fd = open("files/Lorem_Ipsum.txt", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
		usleep(100000);
	}
	
	close(fd);
	return 0;
}
