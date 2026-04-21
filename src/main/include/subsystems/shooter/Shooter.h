#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/sysid/SysIdRoutine.h>
#include "ShooterIO.h"
#include <memory>

class Shooter : public frc2::SubsystemBase {
public:
    explicit Shooter(std::unique_ptr<ShooterIO> io);

    void Periodic() override;

    frc2::CommandPtr SpinUp();
    frc2::CommandPtr Stop();
    frc2::CommandPtr SysIdQuasistatic(frc2::sysid::Direction direction);
    frc2::CommandPtr SysIdDynamic(frc2::sysid::Direction direction);

private:
    std::unique_ptr<ShooterIO> m_io;
};
