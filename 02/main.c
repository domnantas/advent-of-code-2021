#include <stdio.h>

#define DEPTH_MEASUREMENT_COUNT 2000

int
main()
{
	int depth_measurements[DEPTH_MEASUREMENT_COUNT];
	int depth_measurement_index = 0;
	while(fscanf(stdin, "%d", &depth_measurements[depth_measurement_index++]) == 1)
		;
	int increased_depth_count = count_increased_values(depth_measurements);

	printf("part 1: depth increased %d times\n", increased_depth_count);

	int increased_depth_window_count = count_increased_values_sliding_window(depth_measurements);

	printf("part 2: sliding window depth increased %d times\n", increased_depth_window_count);

	return 0;
}
