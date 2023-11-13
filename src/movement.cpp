#include "../include/Globals.h"
#include <vector>

void continuousBaseMovement() {
    const float basePosX = base.getPosition().x;
    const int rightSideOfBase = base.getLocalBounds().width + basePosX;

    if (rightSideOfBase < screenWidth + 10) {
        base.setPosition(0, 400);
    }
}
