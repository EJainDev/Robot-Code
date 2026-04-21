#pragma once

#include <frc/geometry/Rotation2d.h>

struct GyroInputs {
    bool connected = false;
    frc::Rotation2d yawPosition{0};
    units::radians_per_second_t yawVelocity{0};
};

class GyroIO {
public:
    virtual ~GyroIO() = default;
    virtual void UpdateInputs(GyroInputs& inputs) = 0;
};
