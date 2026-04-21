#include "subsystems/intake/extend/IntakeExtend.h"

IntakeExtend::IntakeExtend(std::unique_ptr<IntakeExtendIO> io)
    : m_io(std::move(io)) {}

frc2::CommandPtr IntakeExtend::RunIntakeExtendVolts(units::volt_t) {
    return frc2::cmd::None();
}

frc2::CommandPtr IntakeExtend::StopExtendingCommand() {
    return frc2::cmd::None();
}

frc2::CommandPtr IntakeExtend::ExtendToAngle(units::radian_t) {
    return frc2::cmd::None();
}

frc2::CommandPtr IntakeExtend::ResetExtendPosition() {
    return frc2::cmd::None();
}
