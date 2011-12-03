#include "stdafx.h"
#include "CtrledSnake.h"

CtrledSnake::CtrledSnake(std::list<CPoint>& lBody, DIRECTION direct)
: Snake(lBody, direct)
{
}

CtrledSnake::~CtrledSnake(void)
{
}
