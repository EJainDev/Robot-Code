#pragma once

#include <frc2/command/CommandPtr.h>
#include "IntakeRollersIO.h"
#include <memory>

class IntakeRollers {
public:
    explicit IntakeRollers(std::unique_ptr<IntakeRollersIO> io);

    frc2::CommandPtr RunIntake();
    frc2::CommandPtr Outtake();
    frc2::CommandPtr Stop();

private:
    std::unique_ptr<IntakeRollersIO> m_io;
};
