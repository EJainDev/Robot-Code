#pragma once

#include <units/angular_velocity.h>
#include <units/voltage.h>
#include <units/current.h>

struct IntakeRollersInputs {
    units::radians_per_second_t velocity{0};
    units::volt_t appliedVolts{0};
    units::ampere_t current{0};
};

class IntakeRollersIO {
public:
    virtual ~IntakeRollersIO() = default;
    virtual void UpdateInputs(IntakeRollersInputs& inputs) = 0;
    virtual void SetVelocity(units::radians_per_second_t velocity) = 0;
    virtual void SetVoltage(units::volt_t output) = 0;
    virtual void Stop() = 0;
};
