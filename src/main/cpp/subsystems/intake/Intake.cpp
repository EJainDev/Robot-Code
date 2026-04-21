#include "subsystems/intake/Intake.h"

Intake::Intake(std::unique_ptr<IntakeRollers> rollers,
               std::unique_ptr<IntakeExtend> extend)
    : m_rollers(std::move(rollers)), m_extend(std::move(extend)) {}

frc2::CommandPtr Intake::RunIntakeMotor() {
    return frc2::cmd::None();
}

frc2::CommandPtr Intake::ExtendToAngle(units::radian_t) {
    return frc2::cmd::None();
}

frc2::CommandPtr Intake::ExtendToAngleAndIntake(units::radian_t) {
    return frc2::cmd::None();
}
