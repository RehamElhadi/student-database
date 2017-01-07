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
	}student,std;
	FILE *fp ;
	FILE *temp ;
	int id = 1 ;
/*	FILE *Id ; 
	Id = fopen("FId","r");
	fscanf(Id, "%d",&id);
	fclose(Id);*/
	char c ;

	//file add ;
	//*fp = fopen("myfile.txt" ,"w");
	while(loophandler != 0){
		printf("   Menu  \n");
		printf("1.create new file .\n2.insert new student .\n3.view all student .\n4.search.\n5.delete student .\n0.exit .");
		scanf("%d",&casevar);
		//loophandler = 0 ;
		switch(casevar){
			case 1 :printf("file name :");
					char fname[10] ;
					scanf("%s",fname);
					fp = fopen(fname ,"w");
					fclose(fp);
					break ;
			case 2 ://student.id = id ; 
					id++;
					fp = fopen("myfile.txt" ,"r");
					temp = fopen("temp","w");
					//fseek(fp,0,SEEK_END);
					printf("student id :");
					scanf("%d",&student.id);
					printf("student name :");
					scanf("%s",student.name);
					printf("student degree in database :");
					scanf("%s",student.degree);
					student.deleted = 0 ;
					while(!feof(fp)){	
					fscanf(fp,"%d %d %s %s\n",&std.id,&std.deleted,std.name,std.degree);
					if(std.id < student.id)
					fprintf( temp,"%d %d %s %s\n",&std.id,&std.deleted,std.name,std.degree);
					else
					fprintf( temp,"%d %d %s %s\n",student.id,student.deleted,student.name,student.degree );	
					}
					fclose(temp);
					fclose(fp);
					temp = fopen("temp.txt","r");
					fp = fopen("myfile.txt" ,"w" );

					while(!feof(temp)){
											fscanf(temp,"%d %d %s %s\n",&student.id,&student.deleted,student.name,student.degree);
						fprintf(fp,"%d %d %s %s\n",student.id,student.deleted,student.name,student.degree );
					}
					fclose(fp);
					fclose(temp);

					break ;
			case 3 :
					fp = fopen("myfile.txt" ,"r" );
					printf("kkkk\n");
					int p = id-1 ;
					while(p > 0){
						printf("%d\n",p);
						fscanf(fp,"%d %d %s %s\n",&student.id,&student.deleted,student.name,student.degree);
						//if(student.deleted != 1)
						printf("%d&%s&%s\n",student.id,student.name,student.degree);
						p--;
					}
					fclose(fp);
					break ;
			case 4 :

					fp = fopen("myfile.txt" ,"r+" );
					printf("insert student id :\n");
					int key ;
					scanf("%d",&key);
					int p2 = 0 ;
					while(p2 < id){
					//printf("%d\n",p);
					fscanf(fp,"%d %d %s %s\n",&student.id,&student.deleted,student.name,student.degree);
						if(student.id == key){
	           			printf("%d %s %s\n",student.id,student.name,student.degree );
						break;
						}
					p2++;
					}
					break;
			case 5 :
					temp = fopen("temp.txt","w");
					fp = fopen("myfile.txt" ,"r+" );
					printf("insert student id :\n");
					int key2 ;
					scanf("%d",&key2);
					int p3 = 0 ;
					while(p3 < id){
					//printf("%d\n",p);
					fscanf(fp,"%d %d %s %s\n",&student.id,&student.deleted,student.name,student.degree);
						if(student.id != key2){
						fprintf(temp,"%d %d %s %s\n",student.id,student.deleted,student.name,student.degree );
						//printf("%s have been deleted \n",student.name);
						}
					p3++;
					}
					fclose(fp);
					fclose(temp);
					temp = fopen("temp.txt","r");
					fp = fopen("myfile.txt" ,"w" );

					while(!feof(temp)){
											fscanf(temp,"%d %d %s %s\n",&student.id,&student.deleted,student.name,student.degree);
						fprintf(fp,"%d %d %s %s\n",student.id,student.deleted,student.name,student.degree );
					}
					fclose(fp);
					fclose(temp);

					id--;				
					break;
			case 0 ://Id = fopen("FId","w");
			//printf("%d\n",id );
			//		fprintf(Id, "%d\n",id);
			//		fclose(Id);
					return 0;

		}//switch

		}
	}