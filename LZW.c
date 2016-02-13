#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>

#define MAX 10240

void fill(int *s, char **stra, const char *temp)
{
	*stra=(char *)malloc(sizeof(char)*strlen(temp));
	strcpy(*stra, temp);
	*s=*s+1;
}


void print_table_entry(int i, char *stra)
{
	printf("%d\t\t\t", i);
	printf(" %s\n", stra);
}

void print_trans(int n, char *stra[])
{
	printf("%s", stra[n]);
}

void addchartostr(char cha, char *stra)
{
	stra[strlen(stra)+1]='\0';
	stra[strlen(stra)]=cha;
}

void init(int *sizea, char **stra)
{
	char temp[256];
	while(*sizea<256)
	{
		sprintf(temp, "%c", *sizea);
		fill(sizea, &stra[*sizea], temp);
	}
}



char *str[MAX], *ostr[MAX];
int size=0, osize=0;

int main()
{

	int i=0, j, k=0, flag, match, *term, n=0, choice=1;
	char txt[MAX]="the there then these their then they", STR[32], CHAR, *ptr,filename[20],chr;
	FILE *f;

	clrscr();

	while(choice>=1 && choice<=4)
	{
		printf("1. Enter text to be compressed\n");
		printf("2. See an Example\n");
		printf("3. Enter file name\n");
		printf("4. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		fflush(stdin);

		switch(choice)
			{
			case 1:	printf("\nEnter text: ");
				gets(txt);
				goto a;
				break;

			case 2: printf("\nSample text:\nthe there then these their then\n");
				goto a;
				break;

			case 3: {
					printf("\nEnter filenam:\n");
					fflush(stdin);
					gets(filename);
					f=fopen(filename,"r+");
					if(f==-1)
						{
							printf("Invalid File");
							getchar();
							exit(0);
						}
					else
					{
						while(chr==EOF)
						{
							chr=fgetc(f);
							txt[k]=chr;
							k++;
						}
					}
					fclose(f);
					goto a;
					break;
				}

			case 4:	return 0;
		}
	}

	  a:	term=(int *)malloc(sizeof(int)*strlen(txt));
		printf("\t\tCompression starts:\n");
		ptr=txt;
		init(&size, str);
		term=(int *)malloc(sizeof(int)*strlen(txt));
		i=0;
		STR[i++]=*ptr++;
		match=STR[0];
		do
		{
			CHAR=*ptr++;
			STR[i++]=CHAR;
			STR[i]='\0';
			flag=0;
			for(j=0; j<size; j++)
			{
				if(strncmp(str[j], STR, strlen(STR))==0)
				{
					match=j;
					printf("\n\nMatch for %s found at %d. Matches \"%s\".", STR, match, str[match]);
					flag=1;
					break;
				}
			}
			if(flag)
			{
				printf(" Continuing...\n");
				continue;
			}
			printf("\nMatch for %s not found. Last match was %s at %d. Entered entry for %s at %d.", STR, str[match], match, STR, size);	
			term[n++]=match;
			fill(&size, &str[size], STR);
			i=1;
			STR[0]=CHAR;
			match=STR[0];
		}while(CHAR!='\0');
		term[n++]=match;
		printf("\nOutput:\n");
		printf("\nChar no.\t\tEntry no.\t\tEntry\n");
		for(i=0; i<n; i++)
		{
			printf("i = %d\t\t\t", i);
			print_table_entry(term[i], str[term[i]]);
		}
			
		printf("\n\nUncompressed size: %d Bytes. Compressed size: %3.f Bytes\n", (int)strlen(txt), n*1.5);
		printf("\n*************END*************\n");
		getch();
		return 0;
	}