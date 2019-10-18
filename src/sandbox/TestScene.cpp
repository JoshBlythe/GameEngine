#include "TestScene.h"

TestScene::TestScene()
{
}

TestScene::~TestScene()
{
}

void TestScene::onDisplay()
{
	onTicks();
	entity.lock();

}
