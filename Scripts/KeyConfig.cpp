#include "KeyConfig.h"

bool KeyConfig::Up()
{
	return Input.GetKeyDown(Input.key.UP);
}

bool KeyConfig::Down()
{
	return Input.GetKeyDown(Input.key.DOWN);
}

bool KeyConfig::Right()
{
	return Input.GetKeyDown(Input.key.RIGHT);
}

bool KeyConfig::Left()
{
	return Input.GetKeyDown(Input.key.LEFT);
}

bool KeyConfig::Shot()
{
	return Input.GetKeyDown(Input.key.SPACE);
}