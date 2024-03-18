#include "Position.h"

bool Position::operator==(Position const& position)
{
	if (x == position.x && y == position.y)return true;
	return false;
}
