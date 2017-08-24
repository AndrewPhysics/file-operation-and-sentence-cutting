#include "darabol1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include <iostream>
using namespace std;


darabol1::darabol1()
{
}


darabol1::~darabol1()
{
}


int darabol1::darabol_fuggveny(char* buf, char** szavak_elejet_tartalmazo_pointer_tomb)
{
	char* p1 = buf;
	int i = 0;
	bool flag = true;
	while (*p1 != 0)
	{
		if (*p1 == ' ')
		{
			flag = true;
			*p1 = 0;
		}
		else if (flag)
		{
			szavak_elejet_tartalmazo_pointer_tomb[i] = p1;
			flag = false;
			i++;
		}
		else
		{
			flag = false;
		}
		p1++;
	}
	return i;
}