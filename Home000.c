#include<stdio.h>
#include<string.h>
#include <stdlib.h>
void Add(char a[6][200],char*home);
//----------Add-------------
void enter1(char*ss,char*ss2);
void cat1(char*home,char a[6][200]);
void info(char a[6][200]);
void filetotxt(char *home);
void filetotxt2(char *home,char *num);
void filetotxt3(char *home,char *num);
void filetotxt4(char *home,char *num,int num2);
//----------Add-------------

//----------Edit-------------
void Edit(char *home);
//----------Edit-------------

//----------Delete-------------
void Delete(char *home);
//----------Delete-------------

//----------Search-------------
void Search(char *home);
//----------Search-------------

//----------Save-------------
void Save(char *home);
//----------Save-------------

//----------Load-------------
void Load(char *home);
//----------Load-------------

//----------Exit-------------
void Exit1(char *home);
//----------Exit-------------




int main()
{
int no;
char a[6][200],home[1000],num[100]; 
//FILE *p=fopen("add000.txt","w");
//fprintf(p,"");
//fclose(p);
while(1)
{
printf("1-Add\n2-Modify\n3-Delete\n4-Search\n5-Save\n6-load\n7-Exit\nEnter the order number.");
scanf("%d",&no);
if(no==1) Add(a,home);
else if(no==2) Edit(home);
else if(no==3) Delete(home);
else if(no==4) Search(home);
else if(no==5) Save(home); 
else if(no==6) Load(home);
else if(no==7) Exit1(home);
//filetotxt2(home); 
//printf(home);







}


}

//------------------------


void Exit1(char *home)
{
char q[20];
enter1("Do you want to save the database? Write yes or no.",q);

if(strcmp(q,"yes")==0 || strcmp(q,"Yes")==0)
Save(home);
FILE *p; 
p=fopen("add000.txt","w");
fclose(p);


exit(0);
}


void Load(char *home)
{
char q[20];
enter1("Warning, database information will will be replaced.\nAre you sure? Write yes or no.",q);

if(strcmp(q,"yes")==0 || strcmp(q,"Yes")==0)
{
char ff[100];
enter1("Enter the file name: ",ff);
strcat(ff,".txt");

FILE *p,*p2; 
p=fopen("add000.txt","w");
fclose(p);

p=fopen("add000.txt","a");
p2=fopen(ff,"r");
char c;

while((c=fgetc(p2))!=EOF)
{
fprintf(p,"%c",c);
}

fclose(p);
fclose(p2);
}

}


void Save(char *home)
{
char ff[100];
enter1("Enter the file name: ",ff);
strcat(ff,".txt");

FILE *p,*p2; 
p=fopen("add000.txt","r");
p2=fopen(ff,"a");
char c;

while((c=fgetc(p))!=EOF)
{
fprintf(p2,"%c",c);
}

fclose(p);
fclose(p2);

printf("Saved Successfully.\n");



}


void Search(char *home)
{
char num[100]; 
int num2;
printf("\n1- Personal Number.\n2-Name.\n3-Study Program.\n4-statistics\nEnter the order number.");
scanf("%d",&num2);
if(num2==1) 
{printf("Enter the personal number.");
scanf("\n");
gets(num);
filetotxt4(home,num,num2);
}
else if(num2==2) 
{printf("Enter the name."); scanf("\n"); 
gets(num); filetotxt4(home,num,num2);
}
else if(num2==3) 
{printf("Enter the study program."); scanf("\n");
gets(num); filetotxt4(home,num,num2);
}
else if(num2==4) filetotxt4(home,num,num2);
	
	
}

void Delete(char *home)
{
char num[100];
printf("Enter the student number: ");
scanf("\n");
gets(num);
filetotxt3(home,num);

}



void Edit(char *home)
{
char num[100];
printf("Enter the student number: ");
scanf("\n");
gets(num);
filetotxt2(home,num);

}

void Add(char a[6][200],char*home)
{

info(a);
cat1(home,a);

FILE *p;
//p=fopen("add000.txt","w");

//fclose(p);
p=fopen("add000.txt","a");
//home[strlen(home)-1]='\0';
fprintf(p,"%s",home);
fprintf(p,"%s","\n");


fclose(p);
}

//----------Add-------------





void filetotxt4(char *home,char *num,int num2)
{
FILE *p; int i,j,k,n,h1,m,f,sum1,sum2;
float avg;
p=fopen("add000.txt","r");
char c;

n=0;
while((c=fgetc(p))!=EOF)
{
if(c=='\n')
n++;
}
fclose(p);

//printf("%d\n",n);
char new1[n][6][200];

//printf("%d",n);

p=fopen("add000.txt","r");
i=0; j=0; k=0;
while((c=fgetc(p))!=EOF)
{
	
if(c!=')' && c!='\n')
new1[i][j][k++]=c;
else if(c==')')
{new1[i][j][k]='\0'; j++; k=0;}

if(c=='\n')
{new1[i][j][k]='\0';i++; h1=j; j=0; k=0;}
}
//new1[i-1][h1][strlen(new1[i-1][h1])]='\0';
fclose(p);
n=i; m=h1+1;

if(num2==1) num2=0;
else if(num2==2) num2=1;
//else num2=3;

if(num2<4)
{
for(i=0;i<n;i++)
if(strcmp(new1[i][num2],num)==0)
break;
if(i==n)
printf("%s","not found\n");
else
{
for(i=0;i<n;i++)
if(strcmp(new1[i][num2],num)==0)
{
for(j=0;j<6;j++)
{
if(j==0) {printf("\nPersonal Number: "); printf("%s",new1[i][j]); printf("\n");}
else if(j==1) {printf("Name: "); printf("%s",new1[i][j]); printf("\n");}
else if(j==2) {printf("Sex: "); printf("%s",new1[i][j]); printf("\n");}
else if(j==3) {printf("Study Program: "); printf("%s",new1[i][j]); printf("\n");}
else if(j==4) {printf("Old: "); printf("%s",new1[i][j]); printf("\n");}
else if(j==5) {printf("Email: "); printf("%s",new1[i][j]); printf("\n\n");
}


}
}
}

}
else if(num2==4)
{
printf("The total number of students = "); printf("%d",n); printf("\n");
k=0;
for(i=0;i<n;i++)
if(strcmp(new1[i][2],"male")==0 || strcmp(new1[i][2],"Male")==0)
k++;
printf("Number of male students = "); printf("%d",k); printf("\n");
k=n-k;
printf("Number of female students = "); printf("%d",k); printf("\n");

sum1=0; sum2=0; 
for(i=0;i<n;i++)
sum1=sum1+atoi(new1[i][4]);

avg=(float)sum1/n;

printf("The average age of all students = "); printf("%f",avg); printf("\n");

char dr[100]; int y=1,s1,s2,s3;
strcpy(dr,new1[0][3]);
while(y==1)
{
 s1=0; s2=0; s3=0;
for(i=0;i<n;i++)
if(strcmp(dr,new1[i][3])==0)
{
if(strcmp(new1[i][2],"male")==0) s1++;
if(strcmp(new1[i][2],"female")==0) s2++; 

s3=s3+atoi(new1[i][4]); strcpy(new1[i][3],"0"); y=0;
}

printf("Study Program("); printf(dr); printf("):\n");
printf("The total number of students = "); printf("%d",s1+s2); printf("\n");
printf("Number of male students = "); printf("%d",s1); printf("\n");
printf("Number of female students = "); printf("%d",s2); printf("\n");
if((s1+s2)!=0)
{avg=(float)s3/(s1+s2);
printf("The average age of all students = "); printf("%f",avg); printf("\n");
}

for(i=0;i<n;i++)
if(new1[i][3][0]!='0')
{
strcpy(dr,new1[i][3]); y=1;
}


}

 k=1;


}

	
//if(i==n)
//printf("%s","not found\n");







}





//-------------------------------------------------------------------------------






void filetotxt3(char *home,char *num)
{
FILE *p; int i,j,k,n,h1,m,f;
p=fopen("add000.txt","r");
char c;

n=0;
while((c=fgetc(p))!=EOF)
{
if(c=='\n')
n++;
}
fclose(p);

//printf("%d\n",n);
char new1[n][6][200];

//printf("%d",n);

p=fopen("add000.txt","r");
i=0; j=0; k=0;
while((c=fgetc(p))!=EOF)
{
	
if(c!=')' && c!='\n')
new1[i][j][k++]=c;
else if(c==')')
{new1[i][j][k]='\0'; j++; k=0;}

if(c=='\n')
{new1[i][j][k]='\0';i++; h1=j; j=0; k=0;}
}
//new1[i-1][h1][strlen(new1[i-1][h1])]='\0';
fclose(p);
n=i; m=h1+1;

for(i=0;i<n;i++)
if(strcmp(new1[i][0],num)==0)
{printf("%s","found number\n"); break;}
if(i==n)
printf("%s","not found number\n");

if(i!=n)
{

//printf(new1[0][0]);

p=fopen("add000.txt","w");
fclose(p);
//home[strlen(home)-1]='\0';
//fprintf(p,"%s","sasasa");
//fprintf(p,"%s","\n");

p=fopen("add000.txt","a");

f=i;
for(i=0;i<n;i++)
{
if(i==f) continue;
for(j=0;j<6;j++)
{

	if(j==0)
	fprintf(p,"%s",new1[i][j]);
	else if(j<m)
	{fprintf(p,"%s",")");
	fprintf(p,"%s",new1[i][j]);
	}
	//else if(j==m)
	//fprintf(p,"%s",new1[i][j]);
}
fprintf(p,"%s","\n");
}
fclose(p);

}




}





//-------------------------------------------------------------------------------

void filetotxt2(char *home,char *num)
{
FILE *p; int i,j,k,n,h1,m;
p=fopen("add000.txt","r");
char c;

n=0;
while((c=fgetc(p))!=EOF)
{
if(c=='\n')
n++;
}
fclose(p);

//printf("%d\n",n);
char new1[n][6][200];

//printf("%d",n);

p=fopen("add000.txt","r");
i=0; j=0; k=0;
while((c=fgetc(p))!=EOF)
{
	
if(c!=')' && c!='\n')
new1[i][j][k++]=c;
else if(c==')')
{new1[i][j][k]='\0'; j++; k=0;}

if(c=='\n')
{new1[i][j][k]='\0';i++; h1=j; j=0; k=0;}
}
//new1[i-1][h1][strlen(new1[i-1][h1])]='\0';
fclose(p);
n=i; m=h1+1;

for(i=0;i<n;i++)
if(strcmp(new1[i][0],num)==0)
{printf("%s","found number\n"); break;}
if(i==n)
printf("%s","not found number\n");

if(i!=n)
{
for(j=0;j<6;j++)
{
	if(j==0) enter1("New Personal Number: ",new1[i][j]);
	else if(j==1) enter1("New Name: ",new1[i][j]);
	else if(j==2) enter1("New Sex: ",new1[i][j]);
	else if(j==3) enter1("New Study Program: ",new1[i][j]);
	else if(j==4) enter1("New Old: ",new1[i][j]);
	else if(j==5) enter1("New Email: ",new1[i][j]);
}

//printf(new1[0][0]);

p=fopen("add000.txt","w");
fclose(p);
//home[strlen(home)-1]='\0';
//fprintf(p,"%s","sasasa");
//fprintf(p,"%s","\n");

p=fopen("add000.txt","a");


for(i=0;i<n;i++)
{
for(j=0;j<6;j++)
{
	if(j==0)
	fprintf(p,"%s",new1[i][j]);
	else if(j<m)
	{fprintf(p,"%s",")");
	fprintf(p,"%s",new1[i][j]);
	}
	//else if(j==m)
	//fprintf(p,"%s",new1[i][j]);
}
fprintf(p,"%s","\n");
}
fclose(p);

}
//printf("%d\n",i);
//printf("%d\n",h1);
//int t1,t2,t3;
//for(t1=0;t1<i;t1++)
//for(t2=0;t2<=h1;t2++)
//printf("%s\n",new1[t1][t2]);




}



void filetotxt(char *home)
{
FILE *p; int i;
p=fopen("add000.txt","r");
char c;
i=0; home[0]='\0';
while((c=fgetc(p))!=EOF)
{
home[i++]=c;
}
home[i]='\0';
fclose(p);

}


void info(char a[6][200])
{
int i;
for(i=0;i<6;i++)
{
	if(i==0) enter1("Personal Number: ",a[i]);
	else if(i==1) enter1("Name: ",a[i]);
	else if(i==2) enter1("Sex: ",a[i]);
	else if(i==3) enter1("Study Program: ",a[i]);
	else if(i==4) enter1("Old: ",a[i]);
	else if(i==5) enter1("Email: ",a[i]);
}
}

void cat1(char*home,char a[6][200])
{
int i;
home[0]='\0';
for(i=0;i<6;i++)
{
strcat(home,a[i]);
if(i<5)
strcat(home,")");
}

}

void enter1(char*ss,char*ss2)
{
printf(ss); scanf("\n"); gets(ss2);

}

//----------End--Add-------------
