#pragma once

enum HitResult
{
	MISS,
	HIT,
	D_DESTROY,
	C_DESTROY,
	B_DESTROY,
	A_DESTROY,
	ERROR
};

enum Direction
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
	DIR_MAX,
};