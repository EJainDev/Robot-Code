#pragma once

#include <string>
#include <map>
#include <frc/DriverStation.h>
#include <frc/RobotBase.h>

namespace Constants {

enum class RobotType {
    ROBOT_2025_COMP,
    ROBOT_2025_TEST,
    ROBOT_BRIEFCASE,
    ROBOT_2026_COMP,
    ROBOT_SIMBOT
};

enum class Mode {
    REAL,
    REPLAY,
    SIM
};

inline RobotType GetRobot() {
    static RobotType cachedRobotType = RobotType::ROBOT_2026_COMP;

    if (frc::RobotBase::IsReal()) {
        if (cachedRobotType == RobotType::ROBOT_SIMBOT) {
            frc::DriverStation::ReportWarning("Invalid robot selected, using competition robot as default.");
            return RobotType::ROBOT_2026_COMP;
        }
        return cachedRobotType;
    }
    return cachedRobotType;
}

inline Mode GetMode() {
    switch (GetRobot()) {
        case RobotType::ROBOT_BRIEFCASE:
        case RobotType::ROBOT_2025_COMP:
        case RobotType::ROBOT_2026_COMP:
            return frc::RobotBase::IsReal() ? Mode::REAL : Mode::REPLAY;
        case RobotType::ROBOT_SIMBOT:
            return Mode::SIM;
        default:
            return Mode::REAL;
    }
}

inline const std::map<RobotType, std::string> logFolders = {
    {RobotType::ROBOT_BRIEFCASE, "/media/sda1"},
    {RobotType::ROBOT_2026_COMP, "/media/sda1"},
    {RobotType::ROBOT_2025_COMP, "/media/sda1"}
};

inline bool disableHAL = false;

inline void DisableHAL() {
    disableHAL = true;
}

} // namespace Constants
