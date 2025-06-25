#include <cstddef>
#include <cstdint>
#include <ctime>
#include <format>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <utility>

enum class log_level : std::uint8_t{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL
};

class logger{

    public:

    logger(const std::string& path);

    template<typename... Args>
    auto logg(log_level level,std::format_string<Args...> fmt,Args&&... args) -> void{

        auto now = std::time(nullptr);
        auto timeinfo  = localtime(&now);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

        std::ostringstream log_str;

        log_str << "[" << timestamp << "] " << level_to_str(std::forward<log_level>(level)) << ": "<< message(fmt, std::forward<Args>(args)...) <<  '\n'; 

        std::cout << log_str.str();

        if(!_output_file.is_open()) throw std::runtime_error("The logging file was closed. Can't write smth to the file");

        _output_file << log_str.str();
        _output_file.flush();

    };

    private:

    std::ofstream _output_file;

    template<typename... Args>
    auto message(const std::format_string<Args...> fmt, Args&&... args) const -> std::string{

        return std::format(fmt,  std::forward<Args>(args)...);
    }

    auto level_to_str(log_level level) const -> std::string_view;

};