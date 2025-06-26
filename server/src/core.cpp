#include "core.hpp"
#include "envloader.hpp"
#include <stdexcept>

core::core(){

    env_loader env_file(".env");
    auto env_val = env_file.get_v();

    auto val1 = env_val["LOGGER_FILE_PATH"];

    if(val1.empty()) 
        throw std::runtime_error("The path to the logger file is incorrect. "
                                    "Indicate the correct path to the logger file");

    _logger = std::make_shared<logger>(val1);
}

auto core::smth() -> void{

        _logger->logg(log_level::INFO, "Some error has occured:{}{}" , 123 , " code of the error" );
    }