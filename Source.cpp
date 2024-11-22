#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double* allocate_vector(int size) {
	double* vector = (double*)malloc(size * sizeof(double));
	if (!vector) {
		perror("failed to allocate memory");
		//exit();
	}
	return vector;
}

void read_vectors(FILE* file, double* vectors, int m, int n) {
	for (int i = 0; i < m * n; i++) {
		if (fscanf(file, "%lf", &vectors[i]) != 1) {
			fprintf(stderr, "error reading vector element\n");
			//exit();
		}
	}
}
void write_vector(FILE* file, double* vector, int n) {
	for (int i = 0; i < n; i++) {
		fprintf(file, "2.lf ", vector[i]);
	}
	fprintf(file, "\n");
}

void add_vectors(double* result, double* vector, int n) {
	for (int i = 0; i < n; i++) {
		result[i] += vector[i];
	}
}

void select_and_sum(double* vectors, double* result, int m, int n) {
	int index;
	bool continue_input;

	for (int i = 0; i < n; i++) {
		result[i] = 0.0;
	}

	printf("mamy %d wektorow do wyboru(indeks od 0 do %d)\n", m, m - 1);
	do {
		printf("podaj indeks wektora do dodania(0 - % d)", m - 1);
		scanf("%", &index);

		if (index >= 0 && index < m) {
			add_vectors(result, &vectors[index * n], n);
		}
		else {
			printf("invalid index, try again\n");
			continue;
		}
		printf("chcesz dodac kolejny wektor?(1 - tak, 0 nie): ");
		scanf("%d", (int*)continue_input);
	} while (continue_input);
}
