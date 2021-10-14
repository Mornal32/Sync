#include "Sync.h"

const int ITEMS_AMOUNT = 1000000;
const __int8 VALUE_MIN = 1;
const __int8 VALUE_MAX = 9;
const int DELETE_COUNT_MIN = 1;
const int DELETE_COUNT_MAX = 50000;



int fRand(int min, int max) {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
    return dist(rng);
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
            vector.push_back( fRand(VALUE_MIN, VALUE_MAX));
        }
    }
    void initMap() {
        for (auto i = 0; i < ITEMS_AMOUNT; ++i) {
            map.insert({ i, fRand(VALUE_MIN, VALUE_MAX) });
        }
    }
    void deleleRandomItemsAmountOfVec() {
        for (auto i = 0; i < delNum; ++i) {
            auto pos = fRand(0, static_cast<int>(vector.size()) - 1);
            vector.erase(vector.begin() + pos);
        }
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
        std::thread th0(&Containers::initRand, this);
        std::thread th1(&Containers::initMap, this);
        std::thread th2(&Containers::initVec, this);
        th0.join();
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
        /*for (auto i : isInMap) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
        for (auto i : isInVec) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
        
        for (auto i : isInMap) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
        for (auto i : isInVec) {
            std::cout << i << ", ";
        }
        std::cout << std::endl;*/
    }
    void syncContainers() { // дописать
        std::thread th1(&Containers::substractNumbersInVec, this);
        std::thread th2(&Containers::substractNumbersInMap, this);
        th1.join();
        th2.join();

        std::cout << "\nVECTOR size = " << vector.size() << "     " << vector.capacity();
        std::cout << "\nMAP size = " << map.size() ;
    }
};

int main() {
    while (true) {
        Containers *containers = new Containers();
        std::cout << "1\n";
        containers->deleleRandomItemsAmount();
        std::cout << "2\n";
        containers->countNumbers();
        std::cout << "3\n";
        containers->syncContainers();
        std::cout << "4\n";
        std::cout << "\n0 - Quit, 1 - Countinue: \n";
        bool q;
        std::cin >> q;
        if (!q) {
            exit(EXIT_SUCCESS);
        }
        delete containers;
    }
    
}
