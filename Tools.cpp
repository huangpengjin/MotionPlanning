#include "pch.h"
#include "Tools.h"

bool equals(Point T, Point U)
{
	if (T.x == U.x && T.y == U.y)
	{
		return true;
	}
	else
		return false;
};

bool DetectWall::ArriveWall(Point current)
{
	if (current.x<xMin || current.x>xMax || current.y<yMin || current.y>yMax)
	{
		return true;
	}
	else
		return false;
}

bool DetectCircle::collide(Point current, std::vector<Circle> circles)
{
	int count = 0;
	for (int i = 0; i < (int) circles.size(); i++)
	{
		if (pow(current.x - circles[i].centerX, 2) + pow(current.y - circles[i].centerY, 2) <= pow(circles[i].radius, 2))
		{
			count += 1;
		}
	}
	if (count >=1)
	{
		return true;
	}
	else
		return false;
}

std::vector<Point> Successor::arr(Point current, std::vector<Circle> circles)
{
	DetectWall wall = DetectWall();
	DetectCircle circleBarrier = DetectCircle();
	std::vector<Point> successors;
	Point up; up.x = current.x; up.y = current.y + 0.05;
	Point upright; upright.x = current.x + 0.05; upright.y = current.y + 0.05;
	Point right; right.x = current.x + 0.05; right.y = current.y;
	Point rightdown; rightdown.x = current.x + 0.05; rightdown.y = current.y - 0.05;
	Point down; down.x = current.x; down.y = current.y - 0.05;
	Point leftdown; leftdown.x = current.x - 0.05; rightdown.y = current.y - 0.05;
	Point left; left.x = current.x - 0.05; left.y = current.y;
	Point leftup; leftup.x = current.x - 0.05; leftup.y = current.y + 0.05;
	if (!wall.ArriveWall(up) && !circleBarrier.collide(up, circles))
	{
		successors.push_back(up);
	}

	if (!wall.ArriveWall(upright) && !circleBarrier.collide(upright, circles))
	{
		successors.push_back(upright);
	}

	if (!wall.ArriveWall(right) && !circleBarrier.collide(right, circles))
	{
		successors.push_back(right);
	}

	if (!wall.ArriveWall(rightdown) && !circleBarrier.collide(rightdown, circles))
	{
		successors.push_back(rightdown);
	}

	if (!wall.ArriveWall(down) && !circleBarrier.collide(down, circles))
	{
		successors.push_back(down);
	}

	if (!wall.ArriveWall(leftdown) && !circleBarrier.collide(leftdown, circles))
	{
		successors.push_back(leftdown);
	}

	if (!wall.ArriveWall(left) && !circleBarrier.collide(left, circles))
	{
		successors.push_back(left);
	}

	if (!wall.ArriveWall(leftup) && !circleBarrier.collide(leftup, circles))
	{
		successors.push_back(leftup);
	}

	return successors;
}