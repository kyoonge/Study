#include <cmath>
#include <iostream>

class Point {
	int x, y;
public:
	Point(int pos_x, int pos_y);
	int X();
	int Y();
};

Point::Point(int pos_x, int pos_y) {
	x = pos_x;
	y = pos_y;
}

int Point::X() {
	return x;
}

int Point::Y() {
	return y;
}

class Geometry {
	// 점 100 개를 보관하는 배열.
	Point* point_array[100];
	int numPoint;
private:
	float CalculateDistance(Point* a, Point* b);
	bool IsMeet(Point* a1, Point* a2, Point* b1, Point* b2);
	int crossProduct(int x1, int y1, int x2, int y2);

public:
	Geometry(Point** point_list);
	Geometry();
	void AddPoint(const Point& point);
	// 모든 점들 간의 거리를 출력하는 함수 입니다.
	void PrintDistance();
	// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
	// 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
	// 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
	// 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
	void PrintNumMeets();
};

Geometry::Geometry(Point** point_list) {
	
	numPoint = 0;
	int size = (sizeof(point_list) / sizeof(*point_list));

	for (int i = 0; i < size; ++i) {
		point_array[i] = point_list[i];
		numPoint++;
	}
}


Geometry::Geometry() {
	numPoint = 0;
}

void Geometry::AddPoint(const Point& point) {
	if (numPoint < 100) {
		point_array[numPoint] = new Point(point);
		numPoint++;
	}
}

void Geometry::PrintDistance() {
	
	float dist;
	
	for (int i = 0; i < numPoint; i++) {
		for (int j = i+1; j < numPoint; j++) {
			dist = CalculateDistance(point_array[i], point_array[j]);
			std::cout << "점" << i << " 와 점" << j << " 사이의 거리: " << dist << std::endl;
		}
	}

}

float Geometry::CalculateDistance(Point* a, Point* b) {
	int dx = a->X() - b->X();
	int dy = a->Y() - b->Y();
	float dist = sqrt(dx * dx + dy * dy);

	return dist;
}

void Geometry::PrintNumMeets() {
	int count = 0;
	for (int i = 0; i < numPoint; i++) {
		for (int j = i + 1; j < numPoint; j++) {
			for (int k = 0; k < numPoint; k++) {
				for (int l = k + 1; l < numPoint; l++) {
					if (i != k && i != l && j != k && j != l) {
						if (IsMeet(point_array[i], point_array[j], point_array[k], point_array[l])) {
							count++;
						}
					}
				}
			}
		}
	}
	std::cout << "교점 개수: " << count << std::endl;
}

bool Geometry::IsMeet(Point* a1, Point* a2, Point* b1, Point* b2) {
	int d1 = crossProduct(b1->X() - a1->X(), b1->Y() - a1->Y(), a2->X() - a1->X(), a2->Y() - a1->Y());
	int d2 = crossProduct(b2->X() - a1->X(), b2->Y() - a1->Y(), a2->X() - a1->X(), a2->Y() - a1->Y());
	int d3 = crossProduct(a1->X() - b1->X(), a1->Y() - b1->Y(), b2->X() - b1->X(), b2->Y() - b1->Y());
	int d4 = crossProduct(a2->X() - b1->X(), a2->Y() - b1->Y(), b2->X() - b1->X(), b2->Y() - b1->Y());

	return (d1 * d2 <= 0) && (d3 * d4 <= 0);
}

int Geometry::crossProduct(int x1, int y1, int x2, int y2) {
	return x1 * y2 - y1 * x2;
}


int main() {
	Point p1(1, 2);
	Point p2(2, 1);

	Geometry g;

	g.AddPoint(p1);
	g.AddPoint(p2);

	Point* pList[2]{};
	pList[0] = new Point(1, 1);
	pList[1] = new Point(2, 2);
	Geometry g2(pList);
}