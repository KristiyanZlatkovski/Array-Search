#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<dir.h>
void randomA(int x[],int y);
void userInput (int x[],int y);
void printer(int x[],int size);
int rearange(int z[],int x[],int size,int mode);
void sort(int x[],int n);
int fileA(int x[],int n,char name[]);
void combineA(int x[],int y[],int z[],int size1,int size2);
void writeAtoF (int x[],int number,char name[]);
int userChoice(int x[],int size,char name[]);
void FnumberCheck(char name[]);
void user(char array[]);
void endProgram(void);
int main() 
{
	system("COLOR F0");
	int aSize=100;
	char userName[20];
	int array[aSize];
	int array1[aSize];
	int array2[aSize];
	int arrayF[aSize];
    int	size1=0,size2=0;
	int choice=0;
	user(userName);
	printf("                                DOBRE DOSHLI %s\n",userName);
	printf("Za da zapochnete obrabotkata molia posochete nachina na vuvejdane na masiva:\n");
	printf(" ___________________________________________________________________________\n");
	printf("| Za ruchno vuvejdane na masiva vuvedete 1.                                 |\n");
	printf("| Za proizvolno generiran masiv vuvedete 2.                                 | \n");
	printf("| Za izvlichane na masiv ot daden fail vuvedete 3.                          | \n");
	printf("|___________________________________________________________________________|\n");
	printf(" ___________________________________________________________________________\n");
	printf("| Za proverka dali cifrata 9 se sudurja v redovete na daden fail vuvedetev 4| \n");
	printf("|___________________________________________________________________________|\n");
	aSize=userChoice(array,aSize,userName);
    printf("_________________________________\n");
    printf("Tova e vashiat nachalen masiv\n");
    printer(array,aSize);
    printf("tova e purvia masiv predi sortiraneto\n");
    size1=rearange(array,array1,aSize,1);
    printer(array1,size1);
    printf("tova e vtoria masiv predi sortiraneto\n");
    size2=rearange(array,array2,aSize,2);
    printer(array2,size2);
    sort(array1,size1);
    sort(array2,size2);
    printf("tova e purvia masiv sled sortiraneto\n");
    printer(array1,size1);
    printf("tova e vtoria masiv sled sortiraneto\n");
    printer(array2,size2);
    printf("tova e krainiat obraboten masiv\n");
    combineA(array1,array2,arrayF,size1,size2);
    printer(arrayF,(size1+size2));
    printf("Naspishi imeto na faila v koito iskate da zapishete masiva\n");
    writeAtoF (arrayF,(size1+size2),userName);
    endProgram();
}



void randomA(int x[],int y){
int i;
    srand ( time(NULL) );
    for( i=0;i<y;i++){
	x[i]=(rand()%100)+1;
    
	
	}

}






void userInput (int x[],int y)
{
	int i;
	int n,flag=0;
	for(i=0;i<y;i++)
	{
		
		while(flag==0)
		{ 
		printf("vyvedete chislo %d:",i+1);
		
		if(scanf("%d",&n)&&n<=100&&n>=-100) {
			
			flag=1;
		}
		fflush(stdin);
	    } 
		flag=0;
		x[i]=n;
	}

}



void printer(int x[],int size){
		int count=0;
		int i;
for(i=0;i<size;i++){		
			count+=1;
if(count%10==0){
	printf("%d,\n",x[i]);
	}
	else if(i==size-1){
		printf("%d,",x[i]);
		printf("\n");
	}
	else{
	printf("%d,",x[i]);	
	}	
}
printf("_________________________________\n");
}






int rearange(int z[],int x[],int size,int mode){
	int counter1=0;
int i;
	for(i=0;i<size;i++){
		switch(mode){
		
	case(1):
	    if(z[i]%2==1&&i%2==1){
		x[counter1]=z[i];
		counter1+=1;
	}	
	break;
	case(2):
	if(z[i]%4==0){
		x[counter1]=z[i];
		counter1+=1;
	}
	break;	
         }
	}
return counter1;	
}








void sort(int x[],int n)
{
    
 
    int a=0;
    int i;
    int j;
    for ( i= 0; i < n; i++)
    {
        for ( j= i + 1; j < n; j++)
        {
            if (x[i] > x[j])
            {
                a =  x[i];
                x[i] = x[j];
                x[j] = a;
                
            }
        }
    }
    
}






int fileA(int x[],int n,char name[]){
printf("Vuvedete imeto na faila ot koito iskate da izvlechete masiva\n");
FILE *fp;
char file[20];
scanf("%s",file);
strcat(name,"\\");
strcat(name,file);
system("cls");
fp=fopen(name,"r");
int number;
int sizes=0;
int i=0;
fseek(fp, 0, SEEK_END);
sizes = ftell(fp);
fseek(fp, 0, SEEK_SET);


while(ftell(fp)<sizes){
	
	fscanf(fp,"%d",&number);
	x[i]=number;
	++i;
}
	fclose(fp);	
	return i;
}




void combineA(int x[],int y[],int z[],int size1,int size2){
	int i=0;
	int count=0;
	for(;i<size1;i++){
		z[i]=x[i];
		
	}
	for(;i<(size1+size2);i++){
		
		z[i]=y[count];
	++count;
	}
}



void writeAtoF (int x[],int number,char name[]){
	FILE *fp;
	char file1[10];
	mkdir(name);
    scanf("%s",&file1);
    
    strcat(name,"\\");
    strcat(name,file1);
    
    fp=fopen(name,"w");
    int i;
	for(i=1;i<=number;i++){
		if(i%3==0){
		fprintf(fp,"%d\n",x[i-1]);	
		}
		else{
	     fprintf(fp,"%d ",x[i-1]);
	}
	}
	
	fclose(fp);	
	
}





int userChoice(int x[],int size,char name[]) {
int choice;
int i=100;
scanf("%d",&choice);
	
	switch(choice){
	case(1):userInput(x,size);
	system("cls");
	break;
	case(2):randomA(x,size);
	system("cls");
	break;
	case(3):i=fileA(x,size,name);
	system("cls");
	break;
	case(4):FnumberCheck(name);
	system("cls");
	endProgram();
	break;
	default:
	fflush(stdin);
	printf("Vuveli ste nevalidna cifra molia opitaite otnovo\n");
	userChoice(x,size,name);
	break;
}		

return i;
}





void user(char array[]){
		printf("Vuvedi potrebitelskoto si ime maksimum 10 simvola:");
		scanf("%s",array);
		system("cls");
	}




void FnumberCheck(char name[]){
FILE *fp;
FILE *fp2;
char file1[20];
char name1[20];
char file2[20];
strcpy(name1,name);
printf("Vuvedete imeto na faila koito iskate da obrabotite:");
scanf("%s",&file1);
printf("Vuvedete imeto na faila v koito iskate da zapishete rezultata:");
scanf("%s",&file2);
strcat(name,"\\");
strcat(name,file1);
strcat(name1,"\\");
strcat(name1,file2);
fp=fopen(name,"r");
fp2=fopen(name1,"w");
int number;
int sizes=0;
int i=0;
int k;
int check=0;
fseek(fp, 0, SEEK_END);
sizes = ftell(fp);
fseek(fp, 0, SEEK_SET);


for( k=1;ftell(fp)<sizes;k++){
	int j;
	for(i=0;j<3;j++){
		
		fscanf(fp,"%d",&number);
		if(number%10==9||number/10==9){
			i+=1;
			
			
		}
	}
	if(i==0){
		printf("%d",check);
		fprintf(fp2,"Line%d:NO\n",k);
		check+=1;
	}
	else{
		printf("%d",check);
		fprintf(fp2,"Line%d:YES\n",k);
	}

i=0;
}
fprintf(fp2,"Redovete na koito niama cifrata 9 sa %d",check);
	fclose(fp);	
	fclose(fp2);	
	
}







void endProgram(void){
	int choice;
	 printf(" Iskate li da restartirate programata i da zapochnete otnachalo(1) ili da sprete programata(2) ");
    scanf("%d",&choice);
    switch(choice){
	case(1): system("cls");
    main();
	break;
	case(2):system("taskkill /F /IM ConsolePauser.exe");
	system("taskkill /F /IM Kursova.exe");
	break;
	default:
	system("cls");
	printf("Vuveli ste nevaliden izbor");
	fflush(stdin);
	endProgram();
}
}
	




