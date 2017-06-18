#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char* argv[])
{
	FILE *fp_maps,*fp_mem;
	char buffer[255];
	char sline[5][255];
	char *ptr;
	int i=0;
	long tokaddr[1][16];
	char *heap;
	//char addr,perm,offset,device,inode;
		
	
	if(strlen(argv[1]) != 4)
		exit(1);

	int pid=atoi(argv[1]);
	if(pid<=0)
		exit(1);
	char search_str= argv[2];
	if(search_atr=="")
		exit(1);
	char write_str= argv[3];
	if(write_str=="")
		exit(1);

	char maps_filename[100];
	char mam_filename[100];
	sprintf(maps_filename,100,"/proc/%d/maps",pid);
	sprintf(mam_filename,100,"/proc/%d/mam",pid);
	
	try
	{
		fp_maps= fopen(maps_filename,"r");
	}
	catch (IOException e)
	{
		printf("Can not open file!");
	}
	while( !feof(fp_maps) )
	{
		fget(buffer,255,fp_maps);		

		if(strstr(buffer,"[heap]")!=NULL)
		{	
			ptr=strtok(buffer," ");	
			while(ptr!=NULL)
			{		
				sline[i][255]=ptr;
				i++;
			}
		}
		else
			break;
	}
	//addr=sline[0];
	//perm=sline[1];
	//offset=sline[2];
	//device=sline[3];
	//inode=sline[4];

	if((strstr(sline[1],'r')==NULL) || (strstr(sline[1],'w')==NULL))
	{
		printf("does not have read/write permission");
		fclose(fp_maps);
		exit(0);
	}
		
	ptr=strtok(sline[0],"-");
	while(ptr!=NULL)
	{
		tokaddr[i][16]=atol(ptr);
		i++;
	}

	try
        {
                fp_mem= fopen(mem_filename,"rb+");
        }
        catch (IOException e)
        {
                printf("Can not open file!");
        }
	fseek(fp_mem,tokaddr[0],SEEK_SET);
	fread(heap,tokaddr[1]-tokaddr[0],1024,fp_mem);

	try
	{
		//int p = heap.index(bytes(search_str,"ASCII"));
	}
	catch (IOException e)
	{		
		printf("Can't find (%s)",search_str);
	}

	//write the new string

	fclose(fp_maps);
	fclose(fp_mem);
	
	break;



