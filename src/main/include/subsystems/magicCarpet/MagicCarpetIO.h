#pragma once

#include <units/angular_velocity.h>
#include <units/voltage.h>
#include <units/current.h>

struct MagicCarpetInputs {
    units::radians_per_second_t velocity{0};
    units::volt_t appliedVolts{0};
    units::ampere_t current{0};
};

class MagicCarpetIO {
public:
    virtual ~MagicCarpetIO() = default;
    virtual void UpdateInputs(MagicCarpetInputs& inputs) = 0;
    virtual void SetVelocity(units::radians_per_second_t velocity) = 0;
    virtual void SetVoltage(units::volt_t output) = 0;
    virtual void Stop() = 0;
};
