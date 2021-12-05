#include <stdio.h>
#include <string.h>

#define BINARY_COUNT 12
#define MAX_BINARY_STRING_LENGTH 6
#define MAX_BINARY_LENGTH MAX_BINARY_STRING_LENGTH - 1

int
binary_to_decimal(int *binary)
{
	int decimal = 0;
	for(int binary_index = 0; binary_index < MAX_BINARY_LENGTH; binary_index++) {
		decimal = decimal * 2 + binary[binary_index];
	}
	return decimal;
}

int
calculate_power_consumption(char *string_list[])
{
	int gamma[MAX_BINARY_LENGTH] = {0};
	int epsilon[MAX_BINARY_LENGTH] = {0};

	for(int binary_index = 0; binary_index < MAX_BINARY_LENGTH; binary_index++) {
		for(int list_index = 0; list_index < BINARY_COUNT; list_index++) {
			if(string_list[list_index][binary_index] == '1')
				gamma[binary_index] += 1;
			else
				gamma[binary_index] -= 1;
		}

		if(gamma[binary_index] > 0) {
			gamma[binary_index] = 1;
			epsilon[binary_index] = 0;
		} else {
			gamma[binary_index] = 0;
			epsilon[binary_index] = 1;
		}
	}
	int gamma_decimal = binary_to_decimal(gamma);
	int epsilon_decimal = binary_to_decimal(epsilon);

	return gamma_decimal * epsilon_decimal;
}

int
main()
{
	char binary_string_list[BINARY_COUNT][MAX_BINARY_STRING_LENGTH];
	int binary_string_index = 0;
	while(fscanf(stdin, "%s", binary_string_list[binary_string_index++]) == 1)
		;

	int power_consumption = calculate_power_consumption(binary_string_list);
	printf("%d\n", power_consumption);

	return 0;
}
