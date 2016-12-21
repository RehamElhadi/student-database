#include <stdio.h>
#include <stdbool.h>
 main(){
struct STD{
int deleted ;//if true 1
int id ;
char name[30] ;
};
struct STD s1 = {0,2012,"Mohamed Adam"};
struct STD s2 = {1,2013,"Reham elhadi"};
FILE *fp = fopen("myfile.txt" ,"w");

printf("%d%s\n",s1.id,s1.name);
fprintf( fp,"$%d&%d&%s\n",s1.deleted,s1.id,s1.name );
fprintf( fp,"$%d&%d&%s\n",s2.deleted,s2.id,s2.name );
fclose(fp);
//fputs("trying open and close then open again",fp);
//int id ;
//char name[30] ;
char c ;
fp = fopen("myfile.txt" ,"r" );
//while (fscanf(fp, "%s", name)!=EOF)
 while((c = fgetc(fp)) != EOF ){
if(c=='&')
printf(" ");
else if(c=='$'){
if((c = fgetc(fp)) != '0' )
while((c = fgetc(fp)) != '$'){}
//c = fgetc(fp);
printf("");
}
else
printf("%c",c);
}
    fclose(fp);
}