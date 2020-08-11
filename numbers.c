#include "numbers.h"

int main (int args, char *argv[])
{
	int num;
	switch (args)
	{
		case 1: /* No input and output files received */
			printf("enter numbers between 0-99: ");
			while (scanf("%d",&num) != EOF)
				convert_numbers(num, outNotExist);
		break;
		
		case 2: /* Only input file received */
			if (!(input = fopen(*++argv,"r")))
				{
				fprintf(stderr,"cannot open %s file\n",*argv ); 
				exit(0);
				}
			while (fscanf(input,"%d",&num) != EOF)
				convert_numbers(num, outNotExist);
			fclose (input);
		break;
		
		case 3: /* Input and output file received */
			if (!(input = fopen(*++argv,"r")))
			{
				fprintf(stderr,"cannot open %s file\n",*argv ); 
				exit(0);
			}
			if (!(output = fopen(*++argv,"w")))
			{
				fprintf(stderr,"cannot create %s file\n",*argv ); 
				exit(0);
			}
			while (fscanf(input,"%d",&num) != EOF)
				convert_numbers(num, outExist);
			fclose (input);
			fclose (output);
		break;
		
		default:  /* More than 2 arguments were accepted */
				fprintf(stderr,"More than 2 arguments were accepted\n"); 
				exit(0);
	}
	return 0;
}


/*
This method obtains an integer between 0 and 99 and converts each number into English words and prints them into output
@param num - integer between 0 and 99
@param out - out =1 if output file received, out =0 no if output file received
*/
void convert_numbers(int num, int out)
{
	char *str1[] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char *str2[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	char *str3[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteeen", "seventeen", "eighteen", "nineteen"};
	if ((num >= 0) && (num < 10))     /* between 0-9 */
	{
		if (out) /* have output file */
			fprintf(output,"%s\n",*(str1 + num)); 
		else /* dont have output file */         
			printf("%s\n",*(str1 + num));
	}
	else if ((num > 10) && (num < 20 ))   /* between 11-19 */
	{
		if (out) /* have output file */
			fprintf(output,"%s\n",*(str3 + (num % 10)-1)); 
		else /* dont have output file */                        
			printf("%s\n",*(str3 + (num % 10)-1));
	}
	else if ((num % 10 == 0 ))   /* if the number its dozens */
	{
		if (out) /* have output file */
			fprintf(output,"%s\n",*(str2 + (num / 10)-1)); 
		else /* dont have output file */                        
			printf("%s\n",*(str2 + (num / 10)-1));
	}
	else
	{
		if (out) /* have output file */
			fprintf(output,"%s %s\n", *(str2 + (num/10) -1), *(str1 + (num % 10))); 
		else /* dont have output file */                        
			printf("%s %s\n", *(str2 + (num/10) -1), *(str1 + (num % 10)));
	}
}
