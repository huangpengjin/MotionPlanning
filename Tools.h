#pragma once
#include "pch.h"
#include <math.h>
#include <list>
#include <vector>

class Point
{
public:
	double x;
	double y;
};

class Circle
{
public:
	double centerX;
	double centerY;
	double radius;

};

bool equals(Point T, Point U);

class DetectCircle
{
public:
	bool collide(Point current, std::vector<Circle> circles);
};

class DetectWall 
{
public:
	bool ArriveWall(Point current);
	DetectWall() {};
	double xMin = 0;
	double xMax = 1;
	double yMin = 0;
	double yMax = 1;
};

class Successor
{
public:
	std::vector<Point> arr(Point current, std::vector<Circle> circles);
};