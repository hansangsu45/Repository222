#pragma once

class Missile
{
private:
	int x;
	int y;

	bool bMoveLeft;

public:
	void setMissile(int _y);
	void moveMissile();
	void drawMissile();

	int getX();
	int getY();

	bool checkEnd();
};