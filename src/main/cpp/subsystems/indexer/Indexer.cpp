#include "subsystems/indexer/Indexer.h"

Indexer::Indexer(std::unique_ptr<IndexerIO> io)
    : m_io(std::move(io)) {}

void Indexer::Periodic() {}

frc2::CommandPtr Indexer::Run() {
    return frc2::cmd::None();
}

frc2::CommandPtr Indexer::Reverse() {
    return frc2::cmd::None();
}

frc2::CommandPtr Indexer::Stop() {
    return frc2::cmd::None();
}
