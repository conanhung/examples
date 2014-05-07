#pragma once
#include <wx/gdicmn.h>
#include <cxcore.h>
#include <math.h>

//extend wxPoint to support scaling with an int or wxRealPoint
class MyPoint :
	public wxPoint
{
public:
	MyPoint() : wxPoint() {}
	MyPoint(int x_, int y_) : wxPoint(x_,y_) { }
	MyPoint(int x_) : wxPoint(x_,x_) { }
	MyPoint(const wxPoint &p) : wxPoint(p) { }
	MyPoint(const wxSize &p) : wxPoint(p.GetWidth(), p.GetHeight()) { }
	MyPoint(const CvPoint p) : wxPoint(p.x, p.y) { }
	MyPoint(const CvPoint* p) : wxPoint(p->x, p->y) { }
	MyPoint(const CvPoint2D32f p) : wxPoint(p.x, p.y) { }
	MyPoint(const CvSize &p) : wxPoint(p.width, p.height) { }
	MyPoint(const CvRect &p) : wxPoint(p.width, p.height) { }

    MyPoint operator*(const wxRealPoint& p) const { return MyPoint(x*p.x, y*p.y); }
    MyPoint operator/(const wxRealPoint& p) const { return MyPoint(x/p.x, y/p.y); }

	MyPoint operator*(const int &s) const { return MyPoint(x*s, y*s); }
    MyPoint operator/(const int &s) const { return MyPoint(x/s, y/s); }
//    MyPoint operator-(const int &s) const { return MyPoint(x/s, y/s); }
	bool	operator==(const MyPoint &p) const { return x==p.x && y==p.y; }
	bool	operator!=(const MyPoint &p) const { return !operator==(p); }
	bool	operator==(const int p) const { return x==p && y==p; }
	bool	operator!=(const int p) const { return !operator==(p); }
	bool	operator>(const MyPoint &p) const { return x>p.x && y>p.y; }
	bool	operator>=(const MyPoint &p) const { return x>=p.x && y>=p.y; }
	bool	operator<(const MyPoint &p) const { return x<p.x && y<p.y; }
	bool	operator<=(const MyPoint &p) const { return x<=p.x && y<=p.y; }

	wxSize ToSize(){ return wxSize(x,y); }
	CvSize ToCvSize(){ return cvSize(x,y); }
	CvPoint ToCvPoint(){ return cvPoint(x,y); }
	wxPoint ToWxPoint(){ return wxPoint(x,y); }
	float ToDist(){ return sqrt((double)x*x+y*y); }
	int ToDistSqr(){ return x*x+y*y; }
	int ToDist_Manhattan(){ return abs(x)+abs(y); }
	float Euclidean(const wxPoint &p){ return sqrt((double)(p.x-x)*(p.x-x)+(p.y-y)*(p.y-y)); }
};
