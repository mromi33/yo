#pragma once
#include <string_view>
#include <unordered_map>

class env_loader {

    public:
        env_loader(const std::string &path);

        auto get_v() const -> std::unordered_map<std::string, std::string>;

    private:

        auto pars(std::string_view data) const -> void;

        static std::unordered_map<std::string, std::string> e_val;
};