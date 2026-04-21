#pragma once

#include <frc/TimedRobot.h>
#include <frc2/command/Command.h>
#include "RobotContainer.h"
#include "RobotState.h"
#include <memory>
#include <frc/filter/LinearFilter.h>
#include <frc/Timer.h>
#include <frc/Alert.h>

class Robot : public frc::TimedRobot {
public:
    Robot();
    void RobotInit() override;
    void RobotPeriodic() override;
    void DisabledInit() override;
    void DisabledPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void SimulationPeriodic() override;

private:
    std::unique_ptr<frc2::Command> m_autonomousCommand;
    std::unique_ptr<RobotContainer> m_robotContainer;
    RobotState* m_state;

    frc::LinearFilter m_batteryFilter;
    frc::Timer m_canInitialErrorTimer;
    frc::Timer m_canErrorTimer;
    frc::Timer m_disabledTimer;

    frc::Alert m_canErrorAlert;
    frc::Alert m_lowBatteryAlert;

    static constexpr double kLoopOverrunWarningTimeout = 0.2;
    static constexpr double kCanErrorTimeThreshold = 0.5;
    static constexpr double kLowBatteryVoltage = 11.8;
    static constexpr double kLowBatteryDisabledTime = 1.5;
    static constexpr int kLowBatteryMinCycleCount = 10;
    static inline int m_lowBatteryCycleCount = 0;
};
