#pragma once
//*******************************************

//Every segment posesses its unique ID.

//In debug mode both constructor and destructor

//report the ID and the coordinates

//of a segment created or resp. deleted

//Developed by Perun Yelyzaveta

//at 30.01.2021

//Version 1.0

//*******************************************



// Êëàñ â³äð³çê³â
#include "Point.h"
class Segment

{

private:

	// Çàñîáè îáë³êóâàííÿ â³äð³çê³â

	static int _freeID;

	const int _myId;

	// Òî÷êà ïî÷àòêó â³äð³çêó

	Point _a;

	// Òî÷êà ê³íöÿ â³äð³çêó

	Point _b;

public:

	// Êîíñòðóêòîðè â³äð³çê³â

	// 1) çà êîîðäèíàòàìè éîãî ê³íö³â

	Segment(const double x1 = 0, const double y1 = 0,

		const double x2 = 1, const double y2 = 0);

	// 2) çà òî÷êàìè ïî÷àòêó ³ ê³íöÿ

	Segment(const Point& start, const Point& end);

	// 3) êîï³þâàëüíèé êîíñòðóêòîð

	Segment(const Segment&);

	// Äåñòðóêòîð

	~Segment();

	// Ïðèñâîºííÿ

	Segment& operator=(const Segment&);

	// Ñåëåêòîðè  òî÷îê

	const Point& start() const { return _a; };

	const Point& end() const { return _b; };

	// Ñåëåêòîðè-ìîäèô³êàòîðè òî÷îê

	Point& start() { return _a; };

	Point& end() { return _b; };

	// Ñåëåêòîðè êîîðäèíàò òî÷îê

	const double& startX() const { return _a.x(); };

	const double& startY() const { return _a.y(); };

	const double& endX() const { return _b.x(); };

	const double& endY() const { return _b.y(); };

	// Ñåëåêòîðè-ìîäèô³êàòîðè êîîðäèíàò òî÷îê

	double& startX() { return _a.x(); };

	double& startY() { return _a.y(); };

	double& endX() { return _b.x(); };

	double& endY() { return _b.y(); };

	// Îá÷èñëåííÿ äîâæèíè â³äð³çêà

	double length() const;

	// Îá÷èñëåííÿ â³äñòàí³ â³ä â³äð³çêà äî òî÷êè

	double distance(const Point&) const;

	// Ñåëåêòîð ID

	const int getID() const;

};



ostream& operator<<(ostream&, const Segment&);