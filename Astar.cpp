#include "pch.h"
#include "Astar.h"

Astar::Astar(Point origin, Point destination, std::vector<Circle> circles):origin_(origin), destination_(destination), circles_(circles)
{

}
struct Astar::cmp
{
	template<typename T, typename U>
	bool operator()(T const &left, U const &right)     // lesser value has the priority
	{
		if (left.second > right.second)
		{
			return true;
		}
		else
			return false;
	}
};

std::list<Point> Astar::AstarMethod(Point current)
{
	std::priority_queue<std::pair<std::list<Point>, double>, std::vector<std::pair<std::list<Point>, double>>, cmp> q;   // left coordiante list; right value(prev+future)
	double prev = abs(sqrt(pow(current.x - origin_.x, 2) + pow(current.y - origin_.y, 2)));
	std::list<Point> list;   //收集agent实际经过的节点
	list.push_back(current);
	double future = heuristic(current);
	double A = prev +10*future;
	std::vector<Point> visited;
	visited.push_back(current);   //收集agent考察过的节点
	int k = 1;
	while (!isGoal(current))
	{
		Successor successor;
		std::vector<Point> arr = successor.arr(current, circles_);
		int size = arr.size();
		if (size == 0) break;
		for (int i = 0; i<size; i++)
		{
			std::list<Point> temp = list;
			bool flag = false;
			for (int j = 0; j < (int)visited.size(); j++)
			{
				if (equals(arr[i], visited[j]))
				{
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				prev += abs(sqrt(pow(arr[i].x - current.x, 2) + pow(arr[i].y - current.y, 2)));
				future = heuristic(arr[i]);
				A = prev + 10*future;
				temp.push_back(arr[i]);
				std::pair<std::list<Point>, double> pair_element(temp, A);
				q.push(pair_element);
			}
		}
		if (!q.empty())
		{
			k += 1;
			std::pair<std::list<Point>, double> Shortest_Point = q.top();
			list = Shortest_Point.first;
			current = list.back();
			visited.push_back(current);
			q.pop();
		}
		else
			break;
	}
	return list;
}

double Astar::heuristic(Point current)
{
	double Manhattan = abs(current.x - destination_.x) + abs(current.y - destination_.y);
	return Manhattan;
}

bool Astar::isGoal(Point current)
{
	if (abs(sqrt(pow(destination_.x - current.x, 2) + pow(destination_.y - current.y, 2))<0.01))
	{
		return true;
	}
	else
		return false;
}

