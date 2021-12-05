#include <stdio.h>
#include <string.h>

#define COMMAND_COUNT 1000
#define MAX_DIRECTION_LENGHT 10

struct Command {
	char direction[MAX_DIRECTION_LENGHT];
	int value;
};

int
calculate_total_distance(struct Command commands[])
{
	int horizontal_distance = 0;
	int vertical_distance = 0;
	for(int index = 0; index < COMMAND_COUNT; index++) {
		struct Command command = commands[index];
		if(strcmp(command.direction, "forward") == 0) {
			horizontal_distance += command.value;
		} else if(strcmp(command.direction, "down") == 0)
			vertical_distance += command.value;
		else
			vertical_distance -= command.value;
	}

	return horizontal_distance * vertical_distance;
}

int
calculate_total_distance_by_aim(struct Command commands[])
{
	int horizontal_distance = 0;
	int vertical_distance = 0;
	int aim = 0;
	for(int index = 0; index < COMMAND_COUNT; index++) {
		struct Command command = commands[index];
		if(strcmp(command.direction, "forward") == 0) {
			horizontal_distance += command.value;
			vertical_distance += aim * command.value;
		} else if(strcmp(command.direction, "down") == 0) {
			aim += command.value;
		} else {
			aim -= command.value;
		}
	}

	return horizontal_distance * vertical_distance;
}

int
main()
{
	struct Command commands[COMMAND_COUNT];

	char direction[MAX_DIRECTION_LENGHT];
	int value;
	int command_index = 0;
	while(fscanf(stdin, "%s %d", direction, &value) == 2) {
		strcpy(commands[command_index].direction, direction);
		commands[command_index].value = value;
		command_index++;
	}

	int total_distance = calculate_total_distance(commands);

	printf("part 1: total distance traveled: %d\n", total_distance);

	int total_distance_by_aim = calculate_total_distance_by_aim(commands);

	printf("part 2: total distance traveled by aim: %d\n", total_distance_by_aim);

	return 0;
}
