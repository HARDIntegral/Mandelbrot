#include "prog_bar.h"

void update_bar(int current_iter, int total_iter) {
	int num_chars = current_iter*BAR_LEN/total_iter;
	printf("[");
	for (int i=0; i<num_chars; i++)
		printf("-");
	for (int i=0; i<BAR_LEN-num_chars; i++)
		printf(" ");
	printf("]\n%d / %d Iterations Complete\n", current_iter, total_iter);
}
