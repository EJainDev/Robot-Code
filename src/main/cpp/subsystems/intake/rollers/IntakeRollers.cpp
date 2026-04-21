#include "subsystems/intake/rollers/IntakeRollers.h"

IntakeRollers::IntakeRollers(std::unique_ptr<IntakeRollersIO> io)
    : m_io(std::move(io)) {}

frc2::CommandPtr IntakeRollers::RunIntake() {
    return frc2::cmd::None();
}

frc2::CommandPtr IntakeRollers::Outtake() {
    return frc2::cmd::None();
}

frc2::CommandPtr IntakeRollers::Stop() {
    return frc2::cmd::None();
}
