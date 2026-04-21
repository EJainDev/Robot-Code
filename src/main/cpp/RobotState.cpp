#include "RobotState.h"

RobotState* RobotState::s_instance = nullptr;

RobotState* RobotState::GetInstance() {
    if (s_instance == nullptr) {
        s_instance = new RobotState();
    }
    return s_instance;
}

void RobotState::UpdateLEDState() {
    // TODO: Implement LED state updates
}
