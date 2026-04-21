#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/Commands.h>
#include "IntakeConstants.h"
#include "rollers/IntakeRollers.h"
#include "extend/IntakeExtend.h"

class Intake {
public:
    Intake(std::unique_ptr<IntakeRollers> rollers,
           std::unique_ptr<IntakeExtend> extend);

    frc2::CommandPtr RunIntakeMotor();
    frc2::CommandPtr ExtendToAngle(units::radian_t angle);
    frc2::CommandPtr ExtendToAngleAndIntake(units::radian_t angle);

private:
    std::unique_ptr<IntakeRollers> m_rollers;
    std::unique_ptr<IntakeExtend> m_extend;
};
