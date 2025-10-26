#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <vector>

using namespace std;

int getRandomDiceNumber()
{
    std::vector<int> dice{1, 2, 3, 4, 5, 6};
    std::random_device device;
    std::mt19937 generatore{device()};
    std::shuffle(dice.begin(), dice.end(), generatore);
    return dice.front();
}

int main()
{
    auto check_ones = [](std::vector<int> &v) {
        int score{0};
        std::vector<int> t;
        for (auto &x : v) {
            if (x == 1) {
                score += 100;
            } else {
                t.push_back(x);
            }
        }
        v = t;
        return score;
    };

    auto check_fives = [](std::vector<int> &v) {
        int score{0};
        std::vector<int> t;
        for (auto &x : v) {
            if (x == 5) {
                score += 50;
            } else {
                t.push_back(x);
            }
        }
        v = t;
        return score;
    };

    std::vector<int> result;
    for (int i{0}; i < 6; ++i) {
        auto r{getRandomDiceNumber()};
        result.push_back(r);
        std::cout << (char) (65 + i) << "->" << r << ",";
    }

    cout << "Quali dadi vuoi tenere?" << std::endl;
    std::string keep;
    std::getline(cin, keep);
    if (!keep.empty()) {
        std::set<int> keep_positions;
        for (const auto &c : keep) {
            if (c >= 65 && c <= 71) {
                keep_positions.insert(c - 65);
            }
        }
        std::cout << "Vuoi tenere:" << std::endl;
        std::vector<int> to_keep;
        for (const auto &p : keep_positions) {
            to_keep.push_back(result.at(p));
        }
        // TODO: Verifica punteggi
    }

    return 0;
}
