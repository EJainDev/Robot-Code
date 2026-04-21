#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include "subsystems/drive/Drive.h"
#include "subsystems/intake/Intake.h"
#include "subsystems/shooter/Shooter.h"
#include "subsystems/indexer/Indexer.h"
#include "subsystems/magicCarpet/MagicCarpet.h"

class Orchestrator {
public:
    Orchestrator(std::unique_ptr<Drive> drive,
                 std::unique_ptr<MagicCarpet> magicCarpet,
                 std::unique_ptr<Shooter> shooter,
                 std::unique_ptr<Indexer> indexer,
                 std::unique_ptr<Intake> intake,
                 std::unique_ptr<IntakeRollers> intakeRollers,
                 frc2::CommandXboxController& driverController);

    void OrchestratorPeriodic();

    frc2::CommandPtr FeedUp();
    frc2::CommandPtr DriveToHub();
    frc2::CommandPtr ZoneBasedAim();
    frc2::CommandPtr ZoneBasedShooter();
    frc2::CommandPtr SpinUpShooterHub();
    frc2::CommandPtr SpinUpShooterDistance(units::meter_t distance);
    frc2::CommandPtr PreloadBalls();
    frc2::CommandPtr PrepShooter();
    frc2::CommandPtr ShootBalls();
    frc2::CommandPtr ShootBallsonClimb();
    frc2::CommandPtr ShootBallsAtDistance();

    units::meter_t GetHubDistance();

private:
    std::unique_ptr<Drive> m_drive;
    std::unique_ptr<MagicCarpet> m_magicCarpet;
    std::unique_ptr<Shooter> m_shooter;
    std::unique_ptr<Indexer> m_indexer;
    std::unique_ptr<Intake> m_intake;
    std::unique_ptr<IntakeRollers> m_intakeRollers;
    frc2::CommandXboxController* m_driverController;
};
