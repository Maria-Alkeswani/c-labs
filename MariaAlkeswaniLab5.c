#include <stdio.h>
#include<string.h>
#include<ctype.h>


void maria(char *w, char chr)
{
   int i, j = 0;
   for ( i = 0; w[i] != '\0'; i++ )
   {
      if ( w[i] != chr )
        w[j++] = w[i]; 
   }
   w[j] = '\0'; 
}
char *erase_c(char *s, int ch)
{
    char *ptr;

    while (ptr == strchr(s, ch))
        strcpy(ptr, ptr + 1);

    return s;
}
int main(int argc, char** argv)
{ 
  FILE *I=fopen("mariaalkeswani.txt","w");
  char str[100],str1[100],str2[100],m,*c,t,l;
  int i,j,count,f;
  double x;
  printf("1.Split text\n2.Upper case to lower case\n3.Lower case to upper case\n4.Remove a character\n5.Add a character\n6.Replace a character\n7.Statistics\n8.Exit\nEnter the string: ");
  scanf("%[^\n]", str);
  fprintf(I,"%s",str);
  strcpy(str1,str);
    
  while(x){
    strcpy(str,str1);
    printf("\nEnter an option: ");
    scanf("\n%lf",&x);
    
   if (x==1){
     for ( c = str; *c != (long)NULL; c++){
        if ( *c == ' ')
           *c = '\n';
         
        }
       printf("\nSplit text : %s\n",str);
     } 
    else if (x==2){
     for(i=0;i<=strlen(str);i++){
      if(str[i]>=65&&str[i]<=90)
         str[i]=str[i]+32; 
       }
     printf("\nUpper case to lower case : %s\n",str);  
    } 
    else if (x==3){
     for(i=0;i<=strlen(str);i++){
      if(str[i]>=97&&str[i]<=122)
         str[i]=str[i]-32;
      }
     printf("\nLower case to upper case : %s\n",str);
    }
    else if (x==4){
     printf("\nEnter the char to be removed : ");
     scanf("\n%c",  &m);
     maria(str,m);
     printf("result  : %s\n",str); 
     }
    else if (x==5){
     j=0;
     printf("\nEnter the char like to append : ");
     scanf("\n%c" , &t);
     for( i=0; i < strlen(str); i++){
        if ( str[i] == ' '){
           str2[j]= t;
           ++ j;
           str2[j]=str[i];
         }
        else 
        str2[j]=str[i];
        ++j;
       }
      printf("source  : %s\n", str); 
      printf("\nresult  : %s\n",str2);
     }
    else if (x==6){
      printf("\nInput replace character : ");
      scanf("\n%c" , &t);
      printf("\nInput alternate character : ");
      scanf("\n%c" , &l);
      for( i=0; i<=strlen(str)-1; i++){
           if ( str[i] == t){
           str[i]= l;
         }
       }
      printf("After replacing the space with  %c the new string is : %s\n",t, str); 
       }
    else if (x==7){
      strcpy(str2,str);
  
     printf("\nCharacters: %lu\n" ,  strlen(str)-1);
    
         count=1;
         for ( c = str; *c != (int)NULL; c++)
         {
        if ( *c == ' ') ++count;
        }
       printf("\nWords: %d\n",count);
    
    
      	for(i = 0; i < strlen(str); i++){
  		  for(j = i + 1; str[j] != '\0'; j++){
  			if(str[j] == str[i]){
  			for(f = j; str[f] != '\0'; f++){
				str[f] = str[f + 1];
				     }
 			     }
	      	}
	      }

	
	     for(i = 0; i < strlen(str); i++){
  		  count=0;
  		  for(j = 0; str2[j] != '\0'; j++){
  			if(str2[j] == str[i]){
  				++count;
 			   }
		   }
		  printf("\n '%c' : %d" ,str[i],count);
	    }
    }
    else if (x==8)
    {
       printf("exit");
     break;
    }
    
   continue;
   }
 return(0); 
   
}