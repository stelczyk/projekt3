#include <stdio.h>
#include <stdlib.h>

void handle_memory_error() {
	fprintf(stderr, "failed to allocate memory");
	exit
}