#include "RobotContainer.h"
#include "Constants.h"
#include "commands/auto/Autos.h"
#include "commands/drive/DriveWithDpad.h"
#include "util/CustomTriggers.h"
#include <frc2/command/Commands.h>
#include <frc/DriverStation.h>
#include <pathplanner/lib/auto/AutoBuilder.h>
#include <pathplanner/lib/pathfinding/Pathfinding.h>
#include <pathplanner/lib/util/PathPlannerLogging.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <units/angle.h>

using namespace frc2::cmd;

RobotContainer::RobotContainer() {
    // Initialize subsystems based on robot type
    switch (Constants::GetRobot()) {
        case Constants::RobotType::ROBOT_2026_COMP:
            m_drive = std::make_unique<Drive>(
                std::make_unique<GyroIOPigeon2>(),
                std::make_unique<ModuleIOTalonSpark>(0),
                std::make_unique<ModuleIOTalonSpark>(1),
                std::make_unique<ModuleIOTalonSpark>(2),
                std::make_unique<ModuleIOTalonSpark>(3));
            m_shooter = std::make_unique<Shooter>(std::make_unique<ShooterIOSparkMax>());
            m_magicCarpet = std::make_unique<MagicCarpet>(std::make_unique<MagicCarpetSparkMax>());
            m_indexer = std::make_unique<Indexer>(std::make_unique<IndexerIOSparkMax>());
            m_intakeRollers = std::make_unique<IntakeRollers>(std::make_unique<IntakeRollersIOKraken>());
            m_intakeExtend = std::make_unique<IntakeExtend>(std::make_unique<IntakeExtendIOSparkMax>());
            m_leds = std::make_unique<Leds>();
            break;
        case Constants::RobotType::ROBOT_SIMBOT:
            m_drive = std::make_unique<Drive>(
                std::make_unique<GyroIO>(),
                std::make_unique<ModuleIOSim>(),
                std::make_unique<ModuleIOSim>(),
                std::make_unique<ModuleIOSim>(),
                std::make_unique<ModuleIOSim>());
            m_leds = std::make_unique<Leds>();
            break;
        default:
            m_drive = std::make_unique<Drive>(
                std::make_unique<GyroIO>(),
                std::make_unique<ModuleIO>(),
                std::make_unique<ModuleIO>(),
                std::make_unique<ModuleIO>(),
                std::make_unique<ModuleIO>());
            break;
    }

    // Create missing subsystems
    if (!m_intakeRollers) {
        m_intakeRollers = std::make_unique<IntakeRollers>(std::make_unique<IntakeRollersIO>());
    }
    if (!m_intakeExtend) {
        m_intakeExtend = std::make_unique<IntakeExtend>(std::make_unique<IntakeExtendIO>());
    }
    m_intake = std::make_unique<Intake>(std::move(m_intakeRollers), std::move(m_intakeExtend));
    if (!m_magicCarpet) {
        m_magicCarpet = std::make_unique<MagicCarpet>(std::make_unique<MagicCarpetIO>());
    }
    if (!m_shooter) {
        m_shooter = std::make_unique<Shooter>(std::make_unique<ShooterIO>());
    }
    if (!m_indexer) {
        m_indexer = std::make_unique<Indexer>(std::make_unique<IndexerIO>());
    }

    m_orchestrator = std::make_unique<Orchestrator>(
        std::move(m_drive), std::move(m_magicCarpet),
        std::move(m_shooter), std::move(m_indexer),
        std::move(m_intake), std::move(m_intakeRollers),
        m_driverController);

    // Configure AutoBuilder
    pathplanner::AutoBuilder::configure(
        [this]() { return m_drive->GetPose(); },
        [this](const frc::Pose2d& pose) { m_drive->SetPose(pose); },
        [this]() { return m_drive->GetChassisSpeeds(); },
        [this](const frc::ChassisSpeeds& speeds) { m_drive->RunVelocity(speeds); },
        pathplanner::PPHolonomicDriveController(
            pathplanner::PIDConstants{14.0, 0, 0},
            pathplanner::PIDConstants{7, 0, 0}),
        DriveConstants::ppConfig,
        []() {
            return frc::DriverStation::GetAlliance().value_or(
                       frc::DriverStation::Alliance::kBlue) ==
                   frc::DriverStation::Alliance::kRed;
        },
        *m_drive);

    ConfigureButtonBindings();
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
    return frc2::cmd::None();
}

void RobotContainer::ConfigureButtonBindings() {
    // Default commands
    m_indexer->SetDefaultCommand(m_indexer->Stop());
    m_shooter->SetDefaultCommand(m_shooter->Stop());

    // Driver controls
    // m_drive->SetDefaultCommand(DriveCommands::joystickDrive(...));
}

void RobotContainer::RobotPeriodic() {
    RobotState::GetInstance()->UpdateLEDState();
    m_orchestrator->OrchestratorPeriodic();
}
