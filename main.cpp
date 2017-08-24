#include <iostream>
#include <stdio.h>
#include <sys/stat.h>
#include "darabol1.h"
using namespace std;
//stat(const char* file1, structstat* p1);




int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "hun");
	if (argc < 2) 
	{
		printf("usage file_darabol filename\n");
		exit(1);
	}
	struct stat p1; //stat.h-ban l�v� be�p�tett strukt�ra
	
	//az argv[1] a f�jl n�v!
	int a = stat(argv[1], &p1);
	//a<0 akkor hiba van
	//a=0 akkor j�
	if (a<0)
	{
		printf("%s error", argv[1]);
	}
	if (a==0)
	{
		printf("%s ok", argv[1]);
	}
	
	char* buf = new char[p1.st_size+1];
	FILE* fajl; //FILE* egy be�p�tett strukt�ra
	fajl = fopen(argv[1], "rb");//read only �s bin�ris
	//a fajl egy strukt�r�ra mutat� pointer 
	if (fajl==NULL)
	{
		printf("%s not found", argv[1]);
		exit(1);
	}
	a=fread(buf,1, p1.st_size, fajl);
	//felt�telezz�k, hogy sz�veg f�jlt olvasunk be
	//ez�rt a 2. param�ter 1 byte
	//int* p1 = new int[];
	buf[p1.st_size] = 0;
	fclose(fajl);
	printf("%s\n", buf);

	darabol1 peldany;
	char* szavak_elejet_tartalmazo_pointer_tomb[1000];
	int size=peldany.darabol_fuggveny(buf, szavak_elejet_tartalmazo_pointer_tomb);
	
	for (int j = 0; j < size; j++)
	{
		printf("%s\n", szavak_elejet_tartalmazo_pointer_tomb[j]);
	}
	system("pause");
	return 0;
}