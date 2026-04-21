#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/CommandPtr.h>
#include "IndexerIO.h"
#include <memory>

class Indexer : public frc2::SubsystemBase {
public:
    explicit Indexer(std::unique_ptr<IndexerIO> io);

    void Periodic() override;

    frc2::CommandPtr Run();
    frc2::CommandPtr Reverse();
    frc2::CommandPtr Stop();

private:
    std::unique_ptr<IndexerIO> m_io;
};
