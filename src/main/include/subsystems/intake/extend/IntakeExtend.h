#pragma once

#include <frc2/command/CommandPtr.h>
#include "IntakeExtendIO.h"
#include <memory>
#include <units/angle.h>
#include <units/voltage.h>

class IntakeExtend {
public:
    explicit IntakeExtend(std::unique_ptr<IntakeExtendIO> io);

    frc2::CommandPtr RunIntakeExtendVolts(units::volt_t volts);
    frc2::CommandPtr StopExtendingCommand();
    frc2::CommandPtr ExtendToAngle(units::radian_t angle);
    frc2::CommandPtr ResetExtendPosition();

private:
    std::unique_ptr<IntakeExtendIO> m_io;
};
