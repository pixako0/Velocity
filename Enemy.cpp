#include "Enemy.h"
#include <cstdio>

namespace Tmpl8
{
    void Enemy::AIMove(IEntity* target)
    {
        int xDistance = this->x - target->x;
        int yDistance = this->y - target->y;

        int distanceSquared = xDistance * xDistance + yDistance * yDistance;
        int targetRangeSquared = this->targetRange * this->targetRange;

        printf("%dkm\n", distanceSquared / 10000);

        if (distanceSquared > targetRangeSquared) { // return to spawn
            this->MoveToSpawn();
            return;
        }

        if (xDistance > 0 && yDistance > 0) {
            this->moveGoal = 7;
        }
        else if (xDistance > 0 && yDistance < 0) {
            this->moveGoal = 5;
        }
        else if (xDistance < 0 && yDistance < 0) {
            this->moveGoal = 3;
        }
        else if (xDistance < 0 && yDistance > 0) {
            this->moveGoal = 1;
        }
        else if (xDistance == 0 && yDistance > 0) {
            this->moveGoal = 0;
        }
        else if (xDistance == 0 && yDistance < 0) {
            this->moveGoal = 4;
        }
        else if (xDistance > 0 && yDistance == 0) {
            this->moveGoal = 2;
        }
        else if (xDistance < 0 && yDistance == 0) {
            this->moveGoal = 6;
        }

        int diff = (this->moveGoal - this->ship.direction + 8) % 8;

        if (diff == 0) // continue
        {
            this->moveUp = true;
            this->moveRight = false;
            this->moveLeft = false;
        }
        else if (diff > 0 && diff <= 4) // turn right
        {
            this->moveRight = true;
            this->moveLeft = false;
        }
        else // turn left
        {
            this->moveRight = false;
            this->moveLeft = true;
        }
    }

    void Enemy::MoveToSpawn()
    {
        float xDistance = this->x - this->GetSpawnX();
        float yDistance = this->y - this->GetSpawnY();

        int distanceSquared = xDistance * xDistance + yDistance * yDistance;
        int targetRangeSquared = this->targetRange * this->targetRange;

        if (xDistance > 0 && yDistance > 0) {
            this->moveGoal = 7;
        }
        else if (xDistance > 0 && yDistance < 0) {
            this->moveGoal = 5;
        }
        else if (xDistance < 0 && yDistance < 0) {
            this->moveGoal = 3;
        }
        else if (xDistance < 0 && yDistance > 0) {
            this->moveGoal = 1;
        }
        else if (xDistance == 0 && yDistance > 0) {
            this->moveGoal = 0;
        }
        else if (xDistance == 0 && yDistance < 0) {
            this->moveGoal = 4;
        }
        else if (xDistance > 0 && yDistance == 0) {
            this->moveGoal = 2;
        }
        else if (xDistance < 0 && yDistance == 0) {
            this->moveGoal = 6;
        }

        int diff = (this->moveGoal - this->ship.direction + 8) % 8;
        if (diff == 0) // continue
        {
            this->moveUp = true;
            this->moveRight = false;
            this->moveLeft = false;
        }
        else if (diff > 0 && diff <= 4) // turn right
        {
            this->moveRight = true;
            this->moveLeft = false;
        }
        else // turn left
        {
            this->moveRight = false;
            this->moveLeft = true;
        }
    }

}