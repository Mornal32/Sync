#include "Sync.h"

const int ITEMS_AMOUNT = 1000000;
const int8_t VALUE_MIN = 1;
const int8_t VALUE_MAX = 9;
const int DELETE_COUNT_MIN = 1;
const int DELETE_COUNT_MAX = 50000;


int fRand(int min, int max) {
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
    return dist(randNum::rng);
}

class Containers {
private:
    std::vector<int> vector;
    std::map<int, int> map;
    std::vector<int> isInVec{ 0,0,0,0,0,0,0,0,0 };
    std::vector<int> isInMap{ 0,0,0,0,0,0,0,0,0 };
    int delNum{};
    void initVec() {
        for (int i = 0; i < ITEMS_AMOUNT; ++i) {
            vector.push_back(fRand(VALUE_MIN, VALUE_MAX));
        }
    }
    void initMap() {
        for (auto i = 0; i < ITEMS_AMOUNT; ++i) {
            map.insert({ i, fRand(VALUE_MIN, VALUE_MAX) });
        }
    }
    void deleleRandomItemsAmountOfVec() {
        std::vector<int> pos;
        for (int i = 0; i < delNum; ++i) {
            pos.push_back(fRand(0, vector.size()));
        }
        std::sort(pos.begin(), pos.end());

        std::vector<int> tmp;
        int j = 0;
        for (auto i = 0; i < vector.size();++i) {
            if (pos[j] != i) {
                tmp.push_back(vector[i]);
            }
            else
                j++;
        }
        vector = tmp;
    }
    void deleleRandomItemsAmountOfMap() {
        for (auto i = 0; i < delNum; ++i) {
            map.erase(fRand(1, static_cast<int>(map.size()) - 1));
        }
    }
    void initRand() {
        delNum = fRand(DELETE_COUNT_MIN, DELETE_COUNT_MAX);
    }
    void countNumbersInVec() {
        for (auto it = vector.begin(); it != vector.end(); ++it) {
            isInVec[*it - static_cast<long long>(1)]++;
        }
    }
    void countNumbersInMap() {
        for (auto it = map.begin(); it != map.end(); ++it) {
            isInMap[(it->second) - static_cast<long long>(1)]++;
        }
    }
    void compareNumbers() {
        for (auto i = 0; i < isInVec.size();++i) {
            if (isInMap[i] < isInVec[i])
                isInVec[i] = isInMap[i];
            else
                isInMap[i] = isInVec[i];
        }
    }
    void substractNumbersInVec() {
        for (auto it = vector.begin(); it != vector.end(); ) {
            if (isInVec[*it - static_cast<long long>(1)] != 0) {
                isInVec[*it - static_cast<long long>(1)]--;
                ++it;
            }
            else {
                it = vector.erase(it);
            }
        }
    }
    void substractNumbersInMap() {
        for (auto it = map.begin(); it != map.end();) {
            if (isInMap[(it->second) - static_cast<long long>(1)] != 0) {
                isInMap[(it->second) - static_cast<long long>(1)]--;
                ++it;
            }
            else {
                it = map.erase(it);
            }
            
        }
    }
public:
    Containers() {
        initRand();
        std::thread th1(&Containers::initMap, this);
        std::thread th2(&Containers::initVec, this);
        th1.join();
        th2.join();
    }
    ~Containers() {
        vector.clear();
        map.clear();
    }
    void print() {
        std::cout << "Vector: \n";
        for (auto i : vector) {
            std::cout << i << " ";
        }
        std::cout << "\n";
        std::cout << "Map: \n";
        for (auto i : map) {
            std::cout << i.second << " ";
        }
        std::cout << "\n";
    }
    void deleleRandomItemsAmount() {
        std::thread th1(&Containers::deleleRandomItemsAmountOfVec, this);
        std::thread th2(&Containers::deleleRandomItemsAmountOfMap, this);
        th1.join();
        th2.join();
    }
    void countNumbers() {
        std::thread th1(&Containers::countNumbersInMap, this);
        std::thread th2(&Containers::countNumbersInVec, this);
        th1.join();
        th2.join();        
        compareNumbers();
    }
    void syncContainers() { // дописать
        std::thread th1(&Containers::substractNumbersInVec, this);
        std::thread th2(&Containers::substractNumbersInMap, this);
        th1.join();
        th2.join();
    }
};

int main() {
    while (true) {
        auto start = std::chrono::system_clock::now();
        Containers *containers = new Containers();
        std::cout << "Generating vector and map\n";
        containers->deleleRandomItemsAmount();
        std::cout << "Remove random items from vector and map\n";
        containers->countNumbers();
        std::cout << "Okey. What we have now?\n";
        containers->syncContainers();
        std::cout << "Sync what we have.\n";
        auto end = std::chrono::system_clock::now();
        std::cout << std::chrono::duration<double>(end - start).count() << std::endl;
        std::cout << "\n0 - Quit, 1 - Countinue: \n";
        bool q;
        std::cin >> q;
        if (!q) {
            exit(EXIT_SUCCESS);
        }
        delete containers;
    }
    
}
