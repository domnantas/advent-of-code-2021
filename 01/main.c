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
		// skip first iteration and check if value increased
		if(previous_value != 0 && current_value > previous_value)
			increased_count++;
		previous_value = current_value;
	}
	return increased_count;
}

int
count_increased_values_sliding_window(int *values)
{
	int increased_window_count = 0;
	int previous_window_value = 0;
	int current_window_value;
	for(int index = 0; index < DEPTH_MEASUREMENT_COUNT; index++) {
		// prevent buffer overflow
		if(index == DEPTH_MEASUREMENT_COUNT - 2)
			break;

		current_window_value = values[index] + values[index + 1] + values[index + 2];
		if(previous_window_value != 0 && current_window_value > previous_window_value)
			increased_window_count++;
		previous_window_value = current_window_value;
	}
	return increased_window_count;
}

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
