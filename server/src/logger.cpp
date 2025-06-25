#include "logger.hpp"

logger::logger(const std::string& path){
    
    _output_file.open(path);

    if(!_output_file.is_open()) 
        throw std::runtime_error("The path to the logging file is invalid");
}

auto logger::level_to_str(log_level level) const -> std::string_view{

        switch (level) {

            case log_level::DEBUG:
                return "DEBUG";
            
            case log_level::INFO:
                return "INFO";

            case log_level::WARNING:
                return "WARNING";
            
            case log_level::ERROR:
                return "ERROR";

            case log_level::CRITICAL:
                return "CRITICAL";
            
            default:
                return "UNKNOWN";
        }
    }