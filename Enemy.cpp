#include "Enemy.h"
#include <cstdio>
#include "Rocket.h"
#include "Player.h"

namespace Tmpl8
{
    void Enemy::AIMove(IEntity* target)
    {
        int xDistance = this->x - target->x;
        int yDistance = this->y - target->y;

        int distanceSquared = xDistance * xDistance + yDistance * yDistance;
        int targetRangeSquared = this->targetRange * this->targetRange;

        //printf("%dkm\n", distanceSquared / 10000);

        // uncomment to give enemies a targetting distance
        //if (distanceSquared > targetRangeSquared) { // return to spawn
        //    this->MoveToSpawn();
        //    return;
        //}

        rocketLaunchCooldownCount++;
        if (distanceSquared < 30000 && rocketLaunchCooldown < rocketLaunchCooldownCount) {
            rocketLaunchCooldownCount = 0;
            this->launchRocket();
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

    void Enemy::initialize()
    {
        this->die();
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

    void Enemy::launchRocket()
    {
        Rocket rocket = Rocket(this->x, this->y, this->ship.direction);
        rocket.moveUp = true;
        rocket.initialize();

        rockets.push_back(rocket);
    }

    void Enemy::updateRockets(Surface* screen, IEntity* player)
    {
        // end rocket
        this->rockets.erase(
            std::remove_if(this->rockets.begin(), this->rockets.end(),
                [](const Rocket& rocket) { return rocket.age > 500; }),
            this->rockets.end());

        // update rocket
        for (Rocket& rocket : this->rockets) {
            rocket.age++;
            rocket.move();
            rocket.ship.update(screen, &rocket, player);
        }
    }

    bool Enemy::interactEntityRocket(IEntity* entity)
    {
        int radius = 12;
        bool colliding = false;
        this->rockets.erase(
            std::remove_if(this->rockets.begin(), this->rockets.end(),
                [&colliding, entity, radius](Rocket& rocket) {
                    if (rocket.checkCollision(entity, radius)) {
                        colliding = true;
                        return true;
                    }
                    return false;
                }),
            this->rockets.end());

        return colliding;
    }

    void Enemy::update(Surface* screen, IEntity* player)
    {
        this->updateRockets(screen, player);
        this->move();
    }
}