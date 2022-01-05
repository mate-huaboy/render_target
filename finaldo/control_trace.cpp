#include "control_trace.h"
#include <cstdlib>

#include <random>
bool control_trace::loc_pos(GLdouble& eyex,
	GLdouble& eyey,
	GLdouble& eyez,
	GLdouble& centerx,
	GLdouble& centery,
	GLdouble& centerz, int curent_t)//给定坐标及方向
{
	eyey = -0.5;
	std::default_random_engine e; //引擎
	std::normal_distribution<double> n(0, 0.05); //均值, 方差
	centerx = n(e);
	centery = -0.5;
	centerz = n(e);
	return get_x_z(curent_t, eyex, eyez);
}

bool control_trace::loc_pos01(
	GLdouble& eyex,
	GLdouble& eyey,
	GLdouble& eyez,
	GLdouble& centerx,
	GLdouble& centery,
	GLdouble& centerz, int curent_t
)
{
	std::default_random_engine e; //引擎
	std::normal_distribution<double> n(0, 0.05); //均值, 方差
	if (curent_t>100)
	{
		return false;
	}
	eyex = curent_t%12*0.1-0.6;
	eyey = curent_t / 12 * 0.1 - 0.6;
	eyez = 5+n(e);
	centerx = eyex + n(e);
	centery = eyey + n(e);
	centerz = n(e);
	return true;
}
