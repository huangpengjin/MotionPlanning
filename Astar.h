#pragma once
#include "stdlib.h"
#include "pch.h"
#include <queue>
#include <vector>
#include <iostream>
#include <list>
#include "Tools.h"

class Astar
{
public:
	Astar(Point origin, Point destination, std::vector<Circle> circles);
	std::list<Point> AstarMethod(Point current);
	double heuristic(Point current);
	bool isGoal(Point current);
	~Astar() = default;

private:
	struct cmp;
	Point destination_;
	Point origin_;
	std::vector<Circle> circles_;
};

