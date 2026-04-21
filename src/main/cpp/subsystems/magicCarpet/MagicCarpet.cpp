#include "subsystems/magicCarpet/MagicCarpet.h"

MagicCarpet::MagicCarpet(std::unique_ptr<MagicCarpetIO> io)
    : m_io(std::move(io)) {}

void MagicCarpet::Periodic() {}

frc2::CommandPtr MagicCarpet::Run() {
    return frc2::cmd::None();
}

frc2::CommandPtr MagicCarpet::Stop() {
    return frc2::cmd::None();
}
