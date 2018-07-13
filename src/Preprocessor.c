/**
 ============================================================================
 Name        : Preprocessor.c
 Author      : moguzyildiz
 Version     :
 Copyright   : Your copyright notice
 Description : Simple Preprocessor, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <string.h>

int main()
{
	char macro[15][15];		// #define MACRO value
	char value[15][15];		// #define macro VALUE
	char line[160]={'\0'};  // use to take lines from file
	char restored[160]={'\0'};

	int defineCounter=0,i,j,spin=1;
	char *fPtr;	//pointer for "#define" in program
	char *ptr2;	//auxiliary pointer

	FILE *RFptr;	// pointer for reading file
	FILE *WFptr;	//pointer for writing file

	//Opens for file to read file content
	if((RFptr=fopen("simplepp.c","r+"))==NULL){
		printf("File couldn't find.\n");
	}
	else
		if((WFptr=fopen("result.c","w"))==NULL)
			printf("dosya bulunamadi\n");
		else
			while(!feof(RFptr)){ 	// go until reach end of read file
				fgets(line,120,RFptr);		//Every time takes 120 byte(char) from reading file
											//(assuming each line has max. 120 char.)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				if((fPtr=strstr(line,"#define"))!=NULL){	// if this line has #define word.
					//fPtr=strstr(dizi,"#define");
					fPtr=fPtr+sizeof("#define");	//ahead to after #define
					sscanf(fPtr,"%s%s",macro[defineCounter],value[defineCounter]);
					printf("%s - %s\n",macro[defineCounter],value[defineCounter]);
					++defineCounter;
				}// end of if
				else{
					for(i=0;i<defineCounter;i++){	//find MACRO's on the code
						while(spin){
							if((ptr2=strstr(line,macro[i]))==NULL)	// if line hasn't MACRO[i]
								break;
							else{	//if has..
								fPtr=strstr(line,macro[i]);
								ptr2=fPtr+strlen(macro[i]);
								*fPtr='\0';
								fPtr=line;
								for(j=0;;j++,ptr2++){
									restored[j]=*ptr2;
									if(*ptr2=='\n')
										break;
								}
								printf("fPtr:-- %s value:-- %s dizi2:-- %s --\n",fPtr,value[i],restored);
								sprintf(line,"%s%s%s",fPtr,value[i],restored);
								for(j=0;j<120;j++)
									restored[j]='\0';
							}//end of else statement
						}//end of while loop with spin
					}//end of for loop with k
					fprintf(WFptr,"%s",line);	//Write the each restored line to result.c
				}//end of else statement
			}// end of while loop

	fclose(RFptr);	//close resource
	return 0;
}
