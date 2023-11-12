#include "../include/Globals.h"

void continuousBaseMovement() {
    const float basePosX = base.getPosition().x;
    const int rightSideOfBase = base.getLocalBounds().width + basePosX;

    if (rightSideOfBase < screenWidth + 10) {
        base.setPosition(0, 400);
    }
}
