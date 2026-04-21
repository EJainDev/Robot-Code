#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <memory>
#include "subsystems/drive/Drive.h"
#include "subsystems/intake/Intake.h"
#include "subsystems/shooter/Shooter.h"
#include "subsystems/indexer/Indexer.h"
#include "subsystems/magicCarpet/MagicCarpet.h"
#include "subsystems/leds/Leds.h"
#include "Orchestrator.h"

class RobotContainer {
public:
    RobotContainer();

    frc2::CommandPtr GetAutonomousCommand();
    void RobotPeriodic();

private:
    void ConfigureButtonBindings();

    // Subsystems
    std::unique_ptr<Drive> m_drive;
    std::unique_ptr<Vision> m_vision;
    std::unique_ptr<Leds> m_leds;
    std::unique_ptr<MagicCarpet> m_magicCarpet;
    std::unique_ptr<Indexer> m_indexer;
    std::unique_ptr<Shooter> m_shooter;
    std::unique_ptr<Intake> m_intake;
    std::unique_ptr<IntakeRollers> m_intakeRollers;
    std::unique_ptr<IntakeExtend> m_intakeExtend;

    std::unique_ptr<Orchestrator> m_orchestrator;

    // Controllers
    frc2::CommandXboxController m_driverController{0};
    frc2::CommandXboxController m_operatorController{1};
};
