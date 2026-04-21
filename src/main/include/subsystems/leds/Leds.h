#pragma once

#include <frc2/command/SubsystemBase.h>

class Leds : public frc2::SubsystemBase {
public:
    Leds();

    void Periodic() override;

private:
};
