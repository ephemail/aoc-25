#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

namespace aoc25::d01 {

enum class Direction {
    LEFT,
    RIGHT
};

struct Rotation {
    Direction direction;
    int distance;
};

class Dial {
private:
    int pos = 50;

public:
    Dial() = default;

    int rotate(const Rotation& rotation) {
        switch (rotation.direction) {
            case Direction::LEFT:
                pos = ((pos - rotation.distance) % 100 + 100) % 100;
                break;
            case Direction::RIGHT:
                pos = (pos + rotation.distance) % 100;
                break;
        }
        return pos;
    }
};  // class Dial

int p1(const std::vector<Rotation>& rotations) {
    int ans = 0;
    Dial d{};
    for (const auto& rotation : rotations) {
        if (d.rotate(rotation) == 0) {
            ans++;
        }
    }
    return ans;
}

std::vector<Rotation> read_input(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file at: " + filename);
    }

    std::string line;
    std::vector<Rotation> rotations;
    while (std::getline(file, line)) {
        Rotation r;
        switch (line.at(0)) {
            case 'L':
                r.direction = Direction::LEFT;
                break;
            case 'R':
                r.direction = Direction::RIGHT;
                break;
            default:
                throw std::runtime_error("Invalid direction in input: " + line);
        }
        r.distance = std::stoi(line.substr(1));
        rotations.push_back(r);
    }
    return rotations;
}
}  // namespace aoc25::d01

int main() {
    try {
        auto rotations = aoc25::d01::read_input("input/d01.txt");
        std::cout << aoc25::d01::p1(rotations) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
