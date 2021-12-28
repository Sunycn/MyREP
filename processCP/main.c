#include "pcpy.h"

int main(int argc,char** argv)
{
	int pronum;
	int blocksize;
	if(argv[3]==0)
		pronum=5;//用户没传进程数，默认设为5
	else
		pronum=atoi(argv[3]);
	check_arg(argv[1],argc,pronum);//参数校验
	blocksize=block(argv[1],pronum);//进程拷贝字节数
	procreate(argv[1],argv[2],pronum,blocksize);//创建进程

	return 0;
}
