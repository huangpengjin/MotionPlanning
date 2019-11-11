#include "pch.h"
#include <iostream>
#include <vector>
#include "Tools.h"
#include "Astar.h"

int main(int arg, char** argc)
{
	Point origin, destination;
	origin.x = 0.1;
	origin.y = 0.1;
	destination.x = 0.9;
	destination.y = 0.9;

	Circle circle1, circle2, circle3;
	circle1.centerX = 0.2; circle1.centerY = 0.3; circle1.radius = 0.2;
	circle2.centerX = 0.8; circle2.centerY = 0.2; circle2.radius = 0.1;
	circle3.centerX = 0.5; circle3.centerY = 0.6; circle3.radius = 0.3;

	std::vector<Circle> circles;
	circles.push_back(circle1);
	circles.push_back(circle2);
	circles.push_back(circle3);

	Astar astar = Astar(origin, destination, circles);
	Point current = origin;
	std::list<Point> path;
	if (!astar.isGoal(current))
	{
		path=astar.AstarMethod(current);
		for (std::list<Point>::iterator iter = path.begin(); iter != path.end(); ++iter)
		{
			Point xx = *iter;
			std::cout << xx.x << " " << xx.y << " ; ";
		}
		std::cout << std::endl;
	}
	return 0;
}