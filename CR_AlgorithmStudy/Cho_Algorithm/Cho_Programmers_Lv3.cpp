//#include <memory>
//#include <iostream>
//
//using namespace std;
//
//class Point
//{
//public:
//	Point(int x, int y) : x(x)
//						, y(y)
//	{
//
//	}
//
//	void SetX(int newVal) { x = newVal; }
//	void SetY(int newVal) { y = newVal; }
//	int GetX() { return x; }
//	int GetY() { return y; }
//
//private:
//	int x;
//	int y;
//};
//
//struct RectData
//{
//	Point ulhc;
//	Point lrhc;
//};
//
//class Rectangle
//{
//public:
//	Rectangle(Point& a, Point& b)
//	{
//		pData = make_shared<RectData>(RectData{ a, b });
//	}
//
//	Point& upperLeft() const { return pData->ulhc; }
//	Point& lowerRight() const { return pData->lrhc; }
//
//private:
//	std::shared_ptr<RectData> pData;
//};
//
//int main()
//{
//	Point coord1(0, 0);
//	Point coord2(100, 100);
//
//	const Rectangle rec(coord1, coord2);
//	rec.upperLeft().SetX(50);
//
//	cout << rec.upperLeft().GetX() << ' ' << rec.upperLeft().GetY() << '\n';
//}