#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student_t
{
	char email[40];
	char branch[4];
};
typedef struct Student_t Student;

int main()
{
	char id[14];
	Student *s = malloc(sizeof(Student));
	scanf("%s", s->email);
	scanf("%s", s->branch);
	id[0] = '2';
	id[1] = '0';
	id[2] = s->email[3];
	id[3] = s->email[4];
	id[4] = 'A';
	if (strcmp(s->branch, "CS") == 0)
		id[5] = '7';
	else if (strcmp(s->branch, "ECE") == 0)
		id[5] = 'A';
	else if (strcmp(s->branch, "EEE") == 0)
		id[5] = '3';
	id[6] = 'P';
	id[7] = 'S';
	for (int i = 8; i <= 11; i++)
		id[i] = s->email[i - 3];
	id[12] = 'H';
	printf("%s\n", id);

	return 0;
}
