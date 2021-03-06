#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "global.h"

int main(int argc, char *argv[]){
	if(argc>2){
		printf("invalid arguement.\nFormat:\n./format disk_path\n\tExample:./format /home/cwh/diskimg\n");
		return 0;
	}
	
	disk_path=argv[1];
	FILE * fp=NULL;
	fp=fopen(disk_path, "r+");
	if(fp==NULL) {
		printf("please create diskimg on disk_path!\nvia:\n\tdd bs=1K count=5K if=/dev/zero of=diskimg\n");
		fprintf(stderr,"open diskimg fail!\n");
		return 0;
	}
	
	sb *super_blk=malloc(sizeof(sb));

	//计算这个磁盘包含的块数目
	fseek(fp, 0, SEEK_END);	
	//5242880byte/512byte=10240
	super_blk->fs_size=ftell(fp)/BLOCK_BYTES;	
	//根目录块在super block和bitmap block后
	super_blk->first_blk=1 + BITMAP_LENGTH;
	super_blk->bitmap=BITMAP_LENGTH;
		
	//初始化super block
	if(fseek(fp, 0, SEEK_SET )!=0)
		fprintf(stderr,"failed!\n");	
	fwrite(super_blk, sizeof(sb), 1, fp);
	if(fseek(fp, 512, SEEK_SET )!=0)
		fprintf(stderr,"failed!\n");	

	//初始化bitmap block
	//bitmap中super block区和bitmap区共1281bit,加root所在block为1282bit
	int a[40];
	memset(a,-1,40);//-1为32个1	
	fwrite(a, 40, 1, fp);//前1280个bit
	
	int f=0;//1280-1311个bit
	//1280
	int mask=1;
	mask<<=1;	
	f|= mask;
	//1281
	mask<<= 2;
	f|= mask;
	fwrite(&f, sizeof(int), 1, fp);
	int b[87];
	memset(b,0,87);//0为32个0	
	fwrite(b, 87, 1, fp);//填充bitmap后续block
	
	//后续1280-1个block置为0，对5M磁盘，只用到前面10240bit（2.5个block）
	int total=(BITMAP_LENGTH-1)*BLOCK_BYTES;
	char rest[total];
	memset(rest, 0, total);
	fwrite(rest, total, 1, fp);

/*  initialize the root directory block */
	fseek(fp, BLOCK_BYTES * (BITMAP_LENGTH+1), SEEK_SET);
    u_fs_disk_block *root=malloc(sizeof(u_fs_disk_block));
    root->size= 0;
    root->nNextBlock=-1;
    root->data[0]='\0';
    fwrite(root, sizeof(u_fs_disk_block), 1, fp);
    			
	if(fclose(fp)==0)printf("format done!\n");
	else printf("close fp failed!\n");
	
	return 0;
}

