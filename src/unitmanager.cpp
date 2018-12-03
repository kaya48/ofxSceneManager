#include "unitmanager.h"

UnitManager::UnitManager(Unit &_unit)
    : unit(_unit)
{

}

void UnitManager::keyPressed(int key)
{
    unit.keyPressed(key);
}

void UnitManager::keyReleased(int key)
{
    unit.keyReleased(key);
}

void UnitManager::mouseDragged(int button)
{
    unit.mouseDragged(button);
}

void UnitManager::mousePressed(int button)
{
    unit.mousePressed(button);
}

void UnitManager::mouseReleased(int button)
{

}
