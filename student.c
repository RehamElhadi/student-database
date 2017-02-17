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
	}student,std[100];
	FILE *fp ;
	FILE *temp ;
	FILE *otemp ;
	FILE *ntemp ;
	int id = 1 ;
/*	FILE *Id ; 
	Id = fopen("FId","r");
	fscanf(Id, "%d",&id);
	fclose(Id);*/
	char c ;
	int fc = 1 ; 
	char s[10] = "temp";
	int tc = 0 ; 
	int rc = 0 ;
	int ntc ;

	//file add ;
	//*fp = fopen("myfile.txt" ,"w");
	while(loophandler != 0){
		printf("   Menu  \n");
		printf("1.create new file .\n2.insert new student .\n3.view all student .\n4.search.\n5.delete student .\n6.sort. \n0.exit .");
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
					fp = fopen("myfile.txt" ,"a");
					//fseek(fp,0,SEEK_END);
					printf("student id :");
					scanf("%d",&student.id);
					printf("student name :");
					scanf("%s",student.name);
					printf("student degree in database :");
					scanf("%s",student.degree);
					student.deleted = 0 ;
					fprintf( fp,"%d %d %s %s\n",student.id,student.deleted,student.name,student.degree );
					fclose(fp);
					break ;
			case 3 :
					fp = fopen("myfile.txt" ,"r" );
					printf("kkkk\n");
					int p = id-1 ;
					while(!feof(fp)){
						//printf("%d\n",p);
						fscanf(fp,"%d %d %s %s\n",&student.id,&student.deleted,student.name,student.degree);
						//if(student.deleted != 1)
						printf("%d %s %s\n",student.id,student.name,student.degree);
						//p--;
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
			case 6 :
					fp = fopen("myfile.txt","r");//opening the original file to read from 
					while(!feof(fp)){
						if(fc == 3){
							sprintf(s,"temp%d",tc) ; 
							temp = fopen(s,"w");//opening the new temp which have been renamed in line 137 to write in 
							//printf("%d %d %d %s %s\n",rc-1,std[rc-1].id,std[rc-1].deleted,std[rc-1].name,std[rc-1].degree);
							//printf("%d %d %d %s %s\n",rc-2,std[rc-2].id,std[rc-2].deleted,std[rc-2].name,std[rc-2].degree);	
							if(std[rc-1].id<std[rc-2].id){//for deciding wich one have to be written first 
							    //printf("<");
							fprintf(temp,"%d %d %s %s\n",std[rc-1].id,std[rc-1].deleted,std[rc-1].name,std[rc-1].degree);
							fprintf(temp,"%d %d %s %s\n",std[rc-2].id,std[rc-2].deleted,std[rc-2].name,std[rc-2].degree);	
							}else{
								//printf(">");
							fprintf(temp,"%d %d %s %s\n",std[rc-2].id,std[rc-2].deleted,std[rc-2].name,std[rc-2].degree);
							fprintf(temp,"%d %d %s %s\n",std[rc-1].id,std[rc-1].deleted,std[rc-1].name,std[rc-1].degree);		
							}
								//printf("out>");

							fc = 1 ; 
							sprintf(s,"temp%d",tc) ; //change temp name to new temp with the counter
							//printf("%s\n",s );
							fclose(temp); //close the old temp after finishing from writing 
							++tc ; //increase the number of temp files 
							//printf("%d",rc);

						}
					fscanf(fp,"%d %d %s %s\n",&std[rc].id,&std[rc].deleted,std[rc].name,std[rc].degree);//reading from the original file 
					//printf("after read %d %d %d %s %s\n",rc,std[rc].id,std[rc].deleted,std[rc].name,std[rc].degree);	

					++rc;//increase record counter is used to count the number of records in the original file 
					++fc;//increase file counter is used to contrl number of records ber file 
					}
					if(rc%2 == 0 ){//to decide if the reminder records have to wrintten in one file or more 
							sprintf(s,"temp%d",tc) ;//rename the temp file 
							temp = fopen(s,"w");//open thhe new temp ffor writting 
							if(std[rc-1].id<std[rc-2].id){//decide whichh record have to be wwwritten first 
							printf("<");
							fprintf(temp,"%d %d %s %s\n",std[rc-1].id,std[rc-1].deleted,std[rc-1].name,std[rc-1].degree);
							fprintf(temp,"%d %d %s %s\n",std[rc-2].id,std[rc-2].deleted,std[rc-2].name,std[rc-2].degree);	
							}else{
								printf(">");
							fprintf(temp,"%d %d %s %s\n",std[rc-2].id,std[rc-2].deleted,std[rc-2].name,std[rc-2].degree);
							fprintf(temp,"%d %d %s %s\n",std[rc-1].id,std[rc-1].deleted,std[rc-1].name,std[rc-1].degree);		
							} 
							fclose(temp);//cllose thhe temppp 
							 //printf("%s%d\n",s,rc );

					}else
					if(rc%2 == 1 ){//hhavae to be writeen in one file 
							sprintf(s,"temp%d",tc) ;
							temp = fopen(s,"w");
							fprintf(temp,"%d %d %s %s\n",std[rc-1].id,std[rc-1].deleted,std[rc-1].name,std[rc-1].degree);		
							fclose(temp);//clllose thhhe temp ffile 
							//printf("%s0%d\n",s,rc);

						
					}
					ntc = 0 ;//new tempp counter
					while(tc > ntc ){
						sprintf(s,"itempv%d",ntc);
						printf("%s\n",s );
						ntemp = fopen(s,"r");//neww tempp
						sprintf(s,"itemp%d",ntc);
						printf("%s\n",s );
						temp = fopen(s,"r");
						++ntc;
						sprintf(s,"itemp%d",ntc);
						printf("%s\n",s );
						//++ntc;
						otemp = fopen(s,"r");//other tempp
						//sprintf(s,"tempv%d",ntc);
											//	printf("%s\n",s );

						printf("here%s\n",s );
						rc = 0 ;
						
						while(!feof(temp)&&!feof(otemp)){
								printf("here2%s\n",s );
							fscanf(temp,"%d %d %s %s\n",&std[rc].id,&std[rc].deleted,std[rc].name,std[rc].degree);
							fscanf(otemp,"%d %d %s %s\n",&std[rc+1].id,&std[rc+1].deleted,std[rc+1].name,std[rc+1].degree);
								if(std[rc].id<std[rc+1].id){
								printf("here3%d%d%s\n",std[rc].id,std[rc+1].id,s );
						    fprintf(ntemp,"%d %d %s %s\n",&std[rc].id,&std[rc].deleted,std[rc].name,std[rc].degree);	
						    fscanf(temp,"%d %d %s %s\n",&std[rc].id,&std[rc].deleted,std[rc].name,std[rc].degree);
							}else{
							//if(notSmallllest != 0 )//in case it does not enter thhe loop it means it is not less than the record in the otemp
						    fprintf(ntemp,"%d %d %s %s\n",&std[rc+1].id,&std[rc+1].deleted,std[rc+1].name,std[rc+1].degree);	
							fscanf(otemp,"%d %d %s %s\n",&std[rc+1].id,&std[rc+1].deleted,std[rc+1].name,std[rc+1].degree);
								}//else
  
						}//while tempp $ otemp 
						while(!feof(temp)){//in case that the other temppp finish 
							printf("here4%s\n",s );
							fscanf(temp,"%d %d %s %s\n",&std[rc].id,&std[rc].deleted,std[rc].name,std[rc].degree);
						    fprintf(ntemp,"%d %d %s %s\n",&std[rc].id,&std[rc].deleted,std[rc].name,std[rc].degree);								
						}
						while(!feof(otemp)){//in case that the temp runout hhh 
							fscanf(otemp,"%d %d %s %s\n",&std[rc].id,&std[rc].deleted,std[rc].name,std[rc].degree);
						    fprintf(ntemp,"%d %d %s %s\n",&std[rc].id,&std[rc].deleted,std[rc].name,std[rc].degree);								
						}
				
					fprintf(ntemp, "welcome\n");
					fclose(temp);
					fclose(otemp);
					fclose(ntemp);
				
				}
					break;
			case 0 ://Id = fopen("FId","w");
			//printf("%d\n",id );
			//		fprintf(Id, "%d\n",id);
			//		fclose(Id);
					return 0;

		}//switch

		}
	}