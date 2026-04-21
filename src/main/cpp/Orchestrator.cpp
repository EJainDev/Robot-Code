#include "Orchestrator.h"

Orchestrator::Orchestrator(std::unique_ptr<Drive> drive,
                           std::unique_ptr<MagicCarpet> magicCarpet,
                           std::unique_ptr<Shooter> shooter,
                           std::unique_ptr<Indexer> indexer,
                           std::unique_ptr<Intake> intake,
                           std::unique_ptr<IntakeRollers> intakeRollers,
                           frc2::CommandXboxController& driverController)
    : m_drive(std::move(drive)),
      m_magicCarpet(std::move(magicCarpet)),
      m_shooter(std::move(shooter)),
      m_indexer(std::move(indexer)),
      m_intake(std::move(intake)),
      m_intakeRollers(std::move(intakeRollers)),
      m_driverController(&driverController) {}

void Orchestrator::OrchestratorPeriodic() {}

frc2::CommandPtr Orchestrator::FeedUp() {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::DriveToHub() {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::ZoneBasedAim() {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::ZoneBasedShooter() {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::SpinUpShooterHub() {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::SpinUpShooterDistance(units::meter_t) {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::PreloadBalls() {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::PrepShooter() {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::ShootBalls() {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::ShootBallsonClimb() {
    return frc2::cmd::None();
}

frc2::CommandPtr Orchestrator::ShootBallsAtDistance() {
    return frc2::cmd::None();
}

units::meter_t Orchestrator::GetHubDistance() {
    return units::meter_t{0};
}
