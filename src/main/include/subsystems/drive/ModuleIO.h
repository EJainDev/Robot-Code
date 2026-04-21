#pragma once

#include <frc/geometry/Rotation2d.h>
#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/voltage.h>

struct ModuleState {
    units::radian_t position{0};
    units::radians_per_second_t velocity{0};
    units::volt_t appliedVolts{0};
    units::ampere_t current{0};
    units::radian_t absolutePosition{0};
};

class ModuleIO {
public:
    virtual ~ModuleIO() = default;
    virtual void UpdateInputs(ModuleState& inputs) = 0;
    virtual void SetOpenLoop(units::volt_t output) = 0;
    virtual void SetVelocity(units::radians_per_second_t velocity) = 0;
    virtual void Stop() = 0;
};
