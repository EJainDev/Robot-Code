#include "subsystems/drive/Drive.h"

Drive::Drive(std::unique_ptr<GyroIO> gyroIO,
             std::unique_ptr<ModuleIO> frontLeft,
             std::unique_ptr<ModuleIO> frontRight,
             std::unique_ptr<ModuleIO> backLeft,
             std::unique_ptr<ModuleIO> backRight)
    : m_gyroIO(std::move(gyroIO)),
      m_modules{std::move(frontLeft), std::move(frontRight),
                std::move(backLeft), std::move(backRight)} {
}

void Drive::Periodic() {}

frc::Pose2d Drive::GetPose() const {
    return m_odometryPose;
}

void Drive::SetPose(const frc::Pose2d& pose) {
    m_odometryPose = pose;
}

frc::ChassisSpeeds Drive::GetChassisSpeeds() const {
    return frc::ChassisSpeeds{};
}

void Drive::RunVelocity(const frc::ChassisSpeeds& speeds) {}

frc2::CommandPtr Drive::SysIdQuasistatic(frc2::sysid::Direction direction) {
    return frc2::cmd::None();
}

frc2::CommandPtr Drive::SysIdDynamic(frc2::sysid::Direction direction) {
    return frc2::cmd::None();
}

void Drive::AddVisionMeasurement(const frc::Pose2d&, units::second_t) {}
