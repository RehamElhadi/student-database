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
	int fid ;
	char c ;
	while(loophandler != 0){
		printf("   Menu  \n");
		printf("1.create new file .\n2.insert new student .\n3.view all student .\n4.search.\n5.delete student .\n0.exit .");
		scanf("%d",&casevar);
				switch(casevar){
			case 1 :printf("file name :");
					char fname[10] ;
					scanf("%s",fname);
					fp = fopen(fname ,"w");
					fclose(fp);
					break ;
			case 2 :
					id++;
					fp = fopen("myfile.txt" ,"r");
					temp = fopen("temp.txt","w+");
					printf("student id :");
					scanf("%d",&student.id);
					printf("student name :");
					scanf("%s",student.name);
					printf("student degree in database :");
					scanf("%s",student.degree);
					student.deleted = 0 ;
					int x=1;
					
					int iswrite=0;	
					while(!feof(fp)){
					int r=fscanf(fp,"%d %d %s %s\n",&fid,&std.deleted,std.name,std.degree);
					if(r>0 &&(fid < student.id || iswrite > 0))
					fprintf( temp,"%d %d %s %s\n",fid,std.deleted,std.name,std.degree);
					else if(r>0){
					fprintf( temp,"%d %d %s %s\n",student.id,student.deleted,student.name,student.degree );
					fprintf( temp,"%d %d %s %s\n",fid,std.deleted,std.name,std.degree);
					++iswrite;
					}	
					++x;
					}
					if(iswrite == 0)
						fprintf( temp,"%d %d %s %s\n",student.id,student.deleted,student.name,student.degree );
					fclose(temp);
					fclose(fp);
					temp = fopen("temp.txt","r");
					fp = fopen("myfile.txt" ,"w+" );

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
					while(!feof(fp)){
						fscanf(fp,"%d %d %s %s\n",&student.id,&student.deleted,student.name,student.degree);
						printf("%d %s %s\n",student.id,student.name,student.degree);
					}
					fclose(fp);
					break ;
			case 4 :

					fp = fopen("myfile.txt" ,"r+" );
					printf("insert student id :\n");
					int key ;
					scanf("%d",&key);
					int p2 = 0 ;
					while(!feof(fp)){
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
					while(!feof(fp)){
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