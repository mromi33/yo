#pragma once
#include "logger.hpp"
#include <memory>

class core{

    public:

    core();

    auto smth() -> void;

    private:

    std::shared_ptr<logger> _logger;
};