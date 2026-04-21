#include "Robot.h"
#include "Constants.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DriverStation.h>
#include <frc/RobotController.h>
#include <frc2/command/CommandScheduler.h>
#include <iostream>
#include <cstdlib>

Robot::Robot()
    : m_batteryFilter(frc::LinearFilter::MovingAverage(15)),
      m_canErrorAlert("CAN errors detected, robot may not be controllable.", frc::Alert::AlertType::kError),
      m_lowBatteryAlert("Battery voltage is very low, consider turning off the robot or replacing the battery.", frc::Alert::AlertType::kWarning) {
}

void Robot::RobotInit() {
    if (Constants::GetMode() == Constants::Mode::REAL) {
        std::system("sudo mount /dev/sda1 /media/sda1");
    }

    m_state = RobotState::GetInstance();

    // TODO: Add logging setup when AdvantageKit C++ is available
}

void Robot::RobotPeriodic() {
    frc2::CommandScheduler::GetInstance().Run();
    m_state->UpdateLEDState();
}

void Robot::DisabledInit() {
    m_disabledTimer.Restart();
}

void Robot::DisabledPeriodic() {
    double voltage = frc::RobotController::GetBatteryVoltage();
    if (voltage < kLowBatteryVoltage) {
        m_lowBatteryCycleCount++;
        if (m_disabledTimer.Get() > kLowBatteryDisabledTime &&
            m_lowBatteryCycleCount >= kLowBatteryMinCycleCount) {
            m_lowBatteryAlert.Set(true);
        }
    } else {
        m_lowBatteryCycleCount = 0;
        m_lowBatteryAlert.Set(false);
    }
}

void Robot::AutonomousInit() {
    if (m_robotContainer) {
        m_autonomousCommand = m_robotContainer->GetAutonomousCommand();
        if (m_autonomousCommand) {
            m_autonomousCommand->Schedule();
        }
    }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
    if (m_autonomousCommand) {
        m_autonomousCommand->Cancel();
    }
}

void Robot::TeleopPeriodic() {}

void Robot::SimulationPeriodic() {}
