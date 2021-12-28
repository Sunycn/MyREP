#include "pcpy.h"


int main(int argc,char ** argv)
{
	int pos=atoi(argv[4]);
	int blocksize=atoi(argv[3]);
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));

	//argv[1]=sfile,2=desfile,3=blocksize,4=pos
	int sfd=open(argv[1],O_RDONLY);//源文件目标描述符
	int dfd=open(argv[2],O_WRONLY|O_CREAT,0664);//目标文件
	lseek(sfd,pos,SEEK_SET);//偏移
	lseek(dfd,pos,SEEK_SET);
	printf("Copy Cpro pid [%d] Pos [%d] Block [%d]\n",getpid(),pos,blocksize);

	int rsize;
	rsize=read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,rsize);
	printf("拷贝完毕..\n");
	return 0;
}
