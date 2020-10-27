/*Mengyue Duan
 * First I read the file
 * Second I entere the word I want to search on puzzle
 * Third I output the times of northward, southward,eastward,westward,northeast,southeastward,southwestward,northwestward direction*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **allocatePuzzle(int size)
{
	char **matrix=malloc(size*sizeof(int*));
	for(int i=0;i<size;i++){
		matrix[i]=malloc(size*sizeof(int));
	}
	return matrix;
}

void readPuzzle(FILE *fp,char **matrix, int size)
{
	char ch;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
		fscanf(fp,"%c",&ch);
		if(ch == '\n'){
			fscanf(fp,"%c",&ch); 
		}
			matrix[i][j] = ch;
		}
	}
}
void printPuzzle(char **matrix,int size)
{
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			printf("%c", matrix[i][j]);
			}
		printf("\n");
	}
}
void freeSpace(char **matrix,int size)
{
	for(int i=0;i<size;i++) free(matrix[i]);
	free(matrix);
}

int northward(char **puzzle, int size,char *input,char **x)
{
//printf("northword bigin\n");
	int n=0;
	int count = 1;
	int m=strlen(input);
	for(int j=0;j<size;j++){
		for(int i=size-1;i>=0;i--){
			if(puzzle[i][j]==input[0]){
				for (int k=1;k<m;k++){//check input loop from index 0 -> m-1
				if(i-k >= size || i-k <0) break;// if out bound break;
				if(puzzle[i-k][j]!=input[k])
					break;
				count++;
				//printf("count is %d, m is %d\n",count,m);
				}
				if(count == m)//if match every character
				{
					n++;
					for(int k=0;k<m;k++){
					x[i-k][j]=puzzle[i-k][j];}
				}
				count =1;
			}
		}
	}
	return n;
}

int southward(char **puzzle, int size, char *input,char **x)
{
	int n=0;
	int count =1;
	int m=strlen(input);
	for(int j=0;j<size;j++){
		for(int i=0;i<size;i++){
			if(puzzle[i][j]==input[0]){
				for(int k=1;k<m;k++){
				if(i+k >=size ||i+k<0) break;
				if(puzzle[i+k][j]!=input[k])
					break;
				count++;
				}
				if(count ==m)
				{
					n++;
					for(int k=0;k<m;k++){
					x[i+k][j]=puzzle[i+k][j];}
				}
				count =1;
				
				
			}
		}
	}
	return n;
}

int eastward(char **puzzle, int size, char *input,char **x)
  {
          int n=0;
          int count =1;
          int m=strlen(input);
          for(int i=0;i<size;i++){
                  for(int j=0;j<size;j++){
                          if(puzzle[i][j]==input[0]){
                                  for(int k=1;k<m;k++){
                                  if(j+k >=size ||j+k<0) break;
                                  if(puzzle[i][j+k]!=input[k])
                                          break;
                                  count++;
                                  }
                                  if(count ==m)
                                  {
					n++;
					for(int k=0;k<m;k++){
					x[i][j+k]=puzzle[i][j+k];}
				}
                                  count =1;
                          }
                  }
          }
          return n;
  }

int westward(char **puzzle, int size,char *input,char **x)
 {
         int n=0;
         int count = 1;
         int m=strlen(input);
         for(int i=0;i<size;i++){
                 for(int j=size-1;j>=0;j--){
                         if(puzzle[i][j]==input[0]){
                                 for (int k=1;k<m;k++){//check input loop from index 0 -> m-1
                                 if(j-k >= size || j-k <0) break;// if out bound break;
                                 if(puzzle[i][j-k]!=input[k])
                                         break;
                                 count++;
                                 }
                                 if(count == m)//if match every character
                                { 
					n++;
					for(int k=0;k<m;k++){
					x[i][j-k]=puzzle[i][j-k];}}
                                 count =1;
                         }
                 }
         }
         return n;
 }

int northeastward(char **puzzle, int size,char *input,char **x)
{
       	 int n=0;
           int count =1;
           int m=strlen(input);
           for(int i=0;i<size;i++){
                   for(int j=0;j<size;j++){
                           if(puzzle[i][j]==input[0]){
                                   for(int k=1;k<m;k++){
                                   if(j+k >=size ||j+k<0||i-k>=size||i-k<0) break;
                                   if(puzzle[i-k][j+k]!=input[k])
                                           break;
                                   count++;
                                   }
                                   if(count ==m)
                                   {
					n++;
					for(int k=0;k<m;k++){
					x[i-k][j+k]=puzzle[i-k][j+k];}
					}
                                   count =1;
                           }
                   }
           }
           return n;
   }

int southeastward(char **puzzle, int size,char *input,char **x)
  {
           int n=0;
             int count =1;
             int m=strlen(input);
             for(int i=0;i<size;i++){
                     for(int j=0;j<size;j++){
                             if(puzzle[i][j]==input[0]){
                                     for(int k=1;k<m;k++){
                                     if(j+k >=size ||j+k<0||i+k>=size||i+k<0) break;
                                     if(puzzle[i+k][j+k]!=input[k])
                                             break;
                                     count++;
                                     }
                                     if(count ==m)
                                     {
					n++;
					for(int k=0;k<m;k++){
				        x[i+k][j+k]=puzzle[i+k][j+k];}
				}
                                     count =1;
                             }
                     }
             }
             return n;
     }


int southwestward(char **puzzle, int size,char *input,char **x)
 {
          int n=0;
            int count =1;
            int m=strlen(input);
            for(int i=0;i<size;i++){
                    for(int j=0;j<size;j++){
                            if(puzzle[i][j]==input[0]){
                                    for(int k=1;k<m;k++){
                                    if(j-k >=size ||j-k<0||i+k>=size||i+k<0) break;
                                    if(puzzle[i+k][j-k]!=input[k])
                                            break;
                                    count++;
                                    }
                                    if(count ==m)
                                    {
					n++;
					for(int k=0;k<m;k++){
					x[i+k][j-k]=puzzle[i+k][j-k];
					}
				}
                                    count =1;
                            }
                    }
            }
            return n;
    }

int northwestward(char **puzzle, int size,char *input,char **x)
  {
           int n=0;
             int count =1;
             int m=strlen(input);
             for(int i=0;i<size;i++){
                     for(int j=0;j<size;j++){
                             if(puzzle[i][j]==input[0]){
                                     for(int k=1;k<m;k++){
                                     if(j-k >=size ||j-k<0||i-k>=size||i-k<0) break;
                                     if(puzzle[i-k][j-k]!=input[k])
                                             break;
                                     count++;
                                     }
                                     if(count ==m)
                                     {
					n++;
					for(int k=0;k<m;k++){
					x[i-k][j-k]=puzzle[i-k][j-k];
					}
					}
                                     count =1;
                             }
                     }
             }
             return n;
     }


int main(int argc, char *argv[]){
	char **puzzle;
	char ch;
	int size=0;
	char input[100];
	char **x;
	if(argc!=2){
		printf("Usage: %s datafile\n", argv[0]);
		return 1;
	}

	FILE *fp=fopen(argv[1], "r");
	if(fp==NULL){
		printf("Unable to open %s for reading\n", argv[1]);
		return 2;
	}

	
	while(!feof(fp)){
		fscanf(fp, "%c", &ch);
		if(ch=='\n')
			break;
		size++;
	}
fclose(fp);
fp=fopen(argv[1],"r");
puzzle = allocatePuzzle(size);
readPuzzle(fp,puzzle, size);
printf("The word puzzle is: \n");
printPuzzle(puzzle, size);
x=allocatePuzzle(size);

while(1)
{
	 for(int i=0;i<size;i++){
         	for(int j=0;j<size;j++){
                 x[i][j]='-';
         }
 }

	printf("Enter a word to search in the puzzle (or CRTL-D to exit): ");
	scanf("%s",input);
	
	if(feof(stdin))
		break;

	printf("\n\"%s\" was found as below.\n",input);

	int northwardnu=northward(puzzle,size,input,x);
	int southwardnu=southward(puzzle,size,input,x);
	int eastwardnu=eastward(puzzle,size,input,x);
	int westwardnu=westward(puzzle,size,input,x);
	int northeastwardnu=northeastward(puzzle,size,input,x);
	int southwestwardnu=southwestward(puzzle,size,input,x);
	int southeastwardnu=southeastward(puzzle,size,input,x);
	int northwestwardnu=northwestward(puzzle,size,input,x);

	printf("%d times in the northward direction\n",northwardnu);
	printf("%d times in the southward direction\n",southwardnu);
	printf("%d times in the eastward direction\n",eastwardnu);
	printf("%d times in the westward direction\n",westwardnu);
	printf("%d times in the northeastward direction\n",northeastwardnu);
	printf("%d times in the southeastward direction\n",southeastwardnu);
	printf("%d times in the southwestward direction\n",southwestwardnu);
	printf("%d times in the northwestward direction\n",northwestwardnu);
	


printPuzzle(x, size);
}
freeSpace(puzzle,size);
return 0;
}
