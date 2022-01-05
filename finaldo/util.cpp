#include <cstdlib>
#include <time.h>
#include<Windows.h>
#include <gl/GL.h>

void rand_num(int n, GLfloat*& m)
{
	m = new GLfloat[n];
	for (int i = 0; i < n - 1; i++)
	{
		srand(time(0));
		m[i] = rand() % 100 / (float)101;
	}
	m[n - 1] = 1;
	return;
}
void rand_num2(int n, GLfloat*& m)//-1dao1Ö®¼ä
{
	m = new GLfloat[n];
	for (int i = 0; i < n; i++)
	{
		srand(time(0));
		m[i] = rand() % 50 / (float)101-1;
	}
	return;
}
