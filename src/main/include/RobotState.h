#pragma once

#include <wpi/deprecated.h>

class RobotState {
public:
    static RobotState* GetInstance();

    // State variables
    bool intaking = false;
    bool shooterAtSpeed = false;

    enum class IntakePosition {
        STOWED,
        DEPLOYED
    };

    IntakePosition intakePosition = IntakePosition::STOWED;

    void UpdateLEDState();

private:
    RobotState() = default;
    static RobotState* s_instance;
};
