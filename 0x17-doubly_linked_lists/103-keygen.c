#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int __attribute__((__unused__)) argc, char *argv[]);

/**
 * main - Generates a key based on input string
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char key[7], *charset;
	int str_len = strlen(argv[1]), sum, product, max_char, rand_seed;

	charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	/* Calculate first character based on XOR and masking */
	key[0] = charset[(str_len ^ 59) & 63];

	/* Calculate second character based on sum of ASCII values */
	sum = 0;
	for (int i = 0; i < str_len; i++)
		sum += argv[1][i];
	key[1] = charset[(sum ^ 79) & 63];

	/* Calculate third character based on product of ASCII values */
	product = 1;
	for (int i = 0; i < str_len; i++)
		product *= argv[1][i];
	key[2] = charset[(product ^ 85) & 63];

	/* Calculate fourth character based on maximum ASCII value */
	max_char = 0;
	for (int i = 0; i < str_len; i++)
	{
		if (argv[1][i] > max_char)
			max_char = argv[1][i];
	}
	srand(max_char ^ 14);
	key[3] = charset[rand() & 63];

	/* Calculate fifth character based on XOR and masking */
	sum = 0;
	for (int i = 0; i < str_len; i++)
		sum += (argv[1][i] * argv[1][i]);
	key[4] = charset[(sum ^ 239) & 63];

	/* Generate a random seed and calculate the sixth character */
	for (int i = 0; i < argv[1][0]; i++)
		rand_seed = rand();
	key[5] = charset[(rand_seed ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}

