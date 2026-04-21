#include "subsystems/shooter/Shooter.h"

Shooter::Shooter(std::unique_ptr<ShooterIO> io)
    : m_io(std::move(io)) {}

void Shooter::Periodic() {}

frc2::CommandPtr Shooter::SpinUp() {
    return frc2::cmd::None();
}

frc2::CommandPtr Shooter::Stop() {
    return frc2::cmd::None();
}

frc2::CommandPtr Shooter::SysIdQuasistatic(frc2::sysid::Direction) {
    return frc2::cmd::None();
}

frc2::CommandPtr Shooter::SysIdDynamic(frc2::sysid::Direction) {
    return frc2::cmd::None();
}
