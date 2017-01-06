#include <stdio.h>
main(){
	int loophandler = 9 ;
	int casevar ;
	printf("Welcome our admin , let ous start :)\n");
	struct STD{
	int deleted ;//if true 1
	int id  ;
	char name[30] ;
	char degree[2] ;
	}student;
	FILE *fp ;
	/*int id = 1 ;
	FILE *Id ; 
	Id = fopen("FId","r");
	fscanf(Id, "%d",&id);
	fclose(Id);*/
	char c ;

	//file add ;
	//*fp = fopen("myfile.txt" ,"w");
	while(loophandler != 0){
		printf("   Menu  \n");
		printf("1.create new file .\n2.insert new student .\n3.view all student .\n4.delete student .\n0.exit .");
		scanf("%d",&casevar);
		//loophandler = 0 ;
		switch(casevar){
			case 1 :printf("file name :");
					char fname[10] ;
					scanf("%s",fname);
					fp = fopen(fname ,"w");
					fclose(fp);
			case 2 ://student.id = id ; id++;
					fp = fopen("myfile.txt" ,"a");
					//fseek(fp,0,SEEK_END);
					printf("student id :");
					scanf("%d",&student.id);
					printf("student name :");
					scanf("%s",student.name);
					printf("student degree in database :");
					scanf("%s",student.degree);
					student.deleted = 0 ;
					fprintf( fp,"$%d&%d&%s&%s\n",student.deleted,student.id,student.name,student.degree );
					fclose(fp);
					break ;
			case 3 :
					fp = fopen("myfile.txt" ,"r" );
					//while (fscanf(fp, "%s", name)!=EOF)
					 while((c = fgetc(fp)) != EOF ){
					if(c=='&')
					printf(" ");
					else if(c=='$'){
					if((c = fgetc(fp)) != '0' ){
					while((c = fgetc(fp)) != '$'){}
					}
					else c = fgetc(fp) ;
					printf("");
					}
					//else if(c == '0');
					else
					printf("%c",c);
					}
					fclose(fp);
					break ;
			//case 4 :
			case 0 ://Id = fopen("FId","w");
			//printf("%d\n",id );
			//		fprintf(Id, "%d\n",id);
			//		fclose(Id);
					return 0;

		}//switch

		}
	}