#pragma once

#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/voltage.h>
#include <units/current.h>

struct IntakeExtendInputs {
    units::radian_t position{0};
    units::radians_per_second_t velocity{0};
    units::volt_t appliedVolts{0};
    units::ampere_t current{0};
};

class IntakeExtendIO {
public:
    virtual ~IntakeExtendIO() = default;
    virtual void UpdateInputs(IntakeExtendInputs& inputs) = 0;
    virtual void SetVoltage(units::volt_t output) = 0;
    virtual void Stop() = 0;
};
