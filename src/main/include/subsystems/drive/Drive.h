#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/ChassisSpeeds.h>
#include <memory>
#include "ModuleIO.h"
#include "GyroIO.h"

class Drive : public frc2::SubsystemBase {
public:
    Drive(std::unique_ptr<GyroIO> gyroIO,
          std::unique_ptr<ModuleIO> frontLeft,
          std::unique_ptr<ModuleIO> frontRight,
          std::unique_ptr<ModuleIO> backLeft,
          std::unique_ptr<ModuleIO> backRight);

    void Periodic() override;

    frc::Pose2d GetPose() const;
    void SetPose(const frc::Pose2d& pose);
    frc::ChassisSpeeds GetChassisSpeeds() const;
    void RunVelocity(const frc::ChassisSpeeds& speeds);

    frc2::CommandPtr SysIdQuasistatic(frc2::sysid::Direction direction);
    frc2::CommandPtr SysIdDynamic(frc2::sysid::Direction direction);

    void AddVisionMeasurement(const frc::Pose2d& visionRobotPoseMeters,
                              units::second_t timestampSeconds);

private:
    std::unique_ptr<GyroIO> m_gyroIO;
    std::array<std::unique_ptr<ModuleIO>, 4> m_modules;
    frc::Pose2d m_odometryPose;
};
