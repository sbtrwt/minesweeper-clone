#pragma once

struct Position
{
	int x;
	int y;
	Position() {}
	Position(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	bool operator==(Position const& position);
	
};

