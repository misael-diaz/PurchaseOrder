#include <cstdlib>
#include <cstring>
#include <cstdio>

void prompt(void);

int main ()
{
	int in = 0;
	int sw = 0;
	int count = 0;
	do {
		prompt();
		printf("are you satisfied with this list of items? (0:NO, 1:YES)");
		// DEVNOTE: uses a simple hack to read the newline char from the stream
		count = scanf("%d%*c", &in);
		if (count != 1) {
			fprintf(stderr, "user input error\n");
			return EXIT_FAILURE;
		}

		// not complaining if the user inputs a value greater than one
		if (in >= 1) {
			sw = 1;
		}
	} while (!sw);

	return 0;
}

void prompt (void)
{
	size_t num_items = 0;
	printf("Please input the number of items: ");
	if (scanf("%zu%*c", &num_items) != 1) {
		fprintf(stderr, "user input error\n");
		exit(EXIT_FAILURE);
	}

	printf("items: %zu\n", num_items);
	// DEVNOTE: would be easier to use a std::vector<std::string> to store the names
	// but for the sake of learning this is done the hard way
	size_t const size = (num_items * sizeof(void*));
	void **item_names = (void**) malloc(size);
	if (!item_names) {
		fprintf(stderr, "memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	char **names = (char**) item_names;
	for (size_t i = 0; i != num_items; ++i) {
		names[i] = NULL;
	}

	// DEVNOTE:
	// - getline() does the memory allocation for us
	// - for simplicity we are going to assume that the user will input valid data
	//   so we are not checking for errors here to **Not** complicate things
	// - the nice thing about getline() is that we can read item names with
	//   whitespace, and this simplifies the logic of the code
	printf("Please input the names of the items:\n");
	for (size_t i = 0; i != num_items; ++i) {
		size_t n = 0;
		printf("item %zu: ", i + 1);
		getline(&names[i], &n, stdin);
	}

	// DEVNOTE: here we free the pointers to the strings from memory as we should
	for (size_t i = 0; i != num_items; ++i) {
		printf("%s", names[i]);
		free(names[i]);
		names[i] = NULL;
	}

	// DEVNOTE: here we free our one-dimensional array of pointers
	free(item_names);
	item_names = NULL;
}

/*

PurchaseOrder					May 16, 2024

source: src/client/client.cpp
author: @misael-diaz

Copyright (C) 2024 Misael Díaz-Maldonado

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.

References:
[0] https://en.cppreference.com/w/cpp
[1] https://www.man7.org/linux/man-pages/man3/getline.3.html

*/
