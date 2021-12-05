#include <stdio.h>

#define DEPTH_MEASUREMENT_COUNT 2000

int
count_increased_values(int *values)
{
	int increased_count = 0;
	int previous_value = 0;
	int current_value;
	for(int index = 0; index < DEPTH_MEASUREMENT_COUNT; index++) {
		current_value = values[index];
		if(previous_value != 0 && current_value > previous_value)
			increased_count++;
		previous_value = current_value;
	}
	return increased_count;
}

int
main()
{
	int depth_measurements[DEPTH_MEASUREMENT_COUNT];
	int depth_measurement_index = 0;
	while(fscanf(stdin, "%d", &depth_measurements[depth_measurement_index++]) == 1)
		;
	int increased_depth_count = count_increased_values(depth_measurements);

	printf("depth increased %d times\n", increased_depth_count);

	return 0;
}
