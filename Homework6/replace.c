#define MAX_LINE_SIZE 100
#define LINE_BUF_SIZE (MAX_LINE_SIZE + 1)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//Input validation
	//wrong num of command line args are passed in
	if(argc != 7){
		return 1;
	}
	//start line num > end line
	if(atoi(argv[3]) > atoi(argv[4])){
		return 1;
	}
	//start or end are not >0
	if(atoi(argv[3]) < 0 || atoi(argv[4]) < 0){
		return 1;
	}
	//either input or output cannot be opened
	FILE *input = fopen(argv[1],"r");
	if(!input){
		perror("fopen");
		return 1;
	}
	FILE *output = fopen(argv[2],"w");
	if(!output){
		perror("fopen");
		return 1;
	}
	char x[LINE_BUF_SIZE];
	int count = 0;
	int szPattern = strlen(argv[5]);
	int szNewPattern = strlen(argv[6]);
	//Actual Program
	while(1) {
		if (fgets(x,LINE_BUF_SIZE,input) == NULL) {
			break;
		}
		count++;
		//printf("%s %d", x, count);
		if (count >= atoi(argv[3]) && count <= atoi(argv[4])){
			char* loc = strstr(x,argv[5]);
			if (loc != NULL) {
				int index = loc - x;
				char mem1[MAX_LINE_SIZE];
				char mem3[MAX_LINE_SIZE];
				int szBalance = (loc+szPattern)-x;
				memcpy(mem1,x,index);
				memcpy(mem3, loc+szPattern, szBalance);
				mem3[szBalance+1] = '\0';
				memcpy(mem1+index, argv[6], szNewPattern);
				memcpy(mem1+index+szNewPattern, mem3, szBalance+1);
				fprintf(output, "%s", mem1);
			} else {
				fprintf(output, "%s", x);
			}
		}
		else{
			fprintf(output, "%s", x);
		}

	}
	fclose(input);
	fclose(output);
	return 0;
}