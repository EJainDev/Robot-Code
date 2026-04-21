#pragma once

#include <pathplanner/lib/config/RobotConfig.h>
#include <units/length.h>
#include <units/moment_of_inertia.h>
#include <units/mass.h>

namespace DriveConstants {

inline const pathplanner::RobotConfig ppConfig{
    units::kilogram_t{50},
    units::kilogram_square_meter_t{4.5},
    pathplanner::MotorConfig{8},
    0.07,
    units::meter_t{0.5},
    units::meter_t{0.5}
};

}
