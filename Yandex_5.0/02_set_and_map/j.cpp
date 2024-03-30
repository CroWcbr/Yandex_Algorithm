/*
J. P2P обновление
В системе умного дома под управлением голосового помощника Лариса n устройств, соединяющихся между собой по сети LoRaWAN. Устройство номер 1 подключено к интернету и на него было скачано обновление, которое необходимо передать на все устройства.
Сеть LoRaWAN очень медленная, поэтому для распространения протокола был придуман peer-to-peer (P2P) протокол. Файл обновления разбивается на k одинаковых по размеру частей, занумерованных от 1 до k.
Передача части обновления происходит во время таймслотов. Каждый таймслот занимает одну минуту. За один таймслот каждое устройство может получить и передать ровно одну часть обновления. То есть устройство во время таймслота может получать новую часть обновления и передавать уже имеющуюуся у него к началу таймслота часть обновления, или совершать только одно из этих действий, или вообще не осуществлять прием или передачу. После приема части обновления устройство может передавать эту часть обновления другим устройствам в следующих таймслотах.
Перед каждым таймслотом для каждой части обновления определяется, на скольких устройствах сети скачана эта часть. Каждое устройство выбирает отсутствующую на нем часть обновления, которая встречается в сети реже всего. Если таких частей несколько, то выбирается отсутствующая на устройстве часть обновления с наименьшим номером.
После этого устройство делает запрос выбранной части обновления у одного из устройств, на котором такая часть обновления уже скачана. Если таких устройств несколько — выбирается устройство, на котором скачано наименьшее количество частей обновления. Если и таких устройств оказалось несколько — выбирается устройство с минимальным номером.
После того, как все запросы отправлены, каждое устройство выбирает, чей запрос удовлетворить. Устройство A удовлетворяет тот запрос, который поступил от наиболее ценного для A устройства. Ценность устройства B для устройства A определяется как количество частей обновления, ранее полученных устройством A от устройства B. Если на устройство A пришло несколько запросов от одинаково ценных устройств, то удовлетворяется запрос того устройства, на котором меньше всего скачанных частей обновления. Если и таких запросов несколько, то среди них выбирается устройство с наименьшим номером.
Далее начинается новый таймслот. Устройства, чьи запросы удовлетворены, скачивают запрошенную часть обновления, а остальные не скачивают ничего.
Для каждого устройства определите, сколько таймслотов понадобится для скачивания всех частей обновления.

Формат ввода
Вводится два числа n и k (2 ≤ n ≤ 100, 1 ≤ k ≤ 200).

Формат вывода
Выведите n-1 число — количество таймслотов, необходимых для скачивания обновления на устройства с номерами от 2 до n.
*/

#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

#define DEBUG 0

class Device
{
private:
    int id;
    int timeslot;
    int update_count;
    std::vector<int> valueDevice;

    int update_next;
    int update_next_rarity;

public:
    Device() = delete;
    ~Device() {}

    Device(int id, int n, int upd = 0)    
    : id(id)
    , timeslot(0)
    , update_count(upd)
    , valueDevice(n, 200)
    {}

    void setUpdateNext(int id) { update_next = id; }
    void setUpdateNextRarity(int rarity) { update_next_rarity = rarity; }
    void setTimeslot(int t) { timeslot = t; }

    int getValue(int id) const { return (valueDevice[id]); }
    int getUpdateCount() const { return update_count; }
    int getUpdateNext() const { return update_next; }
    int getUpdateNextRarity() const { return update_next_rarity; }
    int getTimeslot() const { return timeslot; }

    void updateCount() { update_count++; }
    void updateValueDevice(int id) { valueDevice[id]--; }
};

class NetWork
{
private:
    int n;
    int k;
    int timeslot;

    std::vector<Device*>                        _devices;
    std::set<int>                               _devices_for_update;
    std::vector<std::vector<bool>>              _update_device_map;
    std::map<int, std::set<int>>                _rarity_update;
    std::map<int, std::set<int>>                _update_device;

public:
    NetWork() = delete;

    NetWork(int n, int k)
    : n(n)
    , k(k)
    , timeslot(0)
    , _devices(n)
    , _update_device_map(n, std::vector<bool>(k, false))
    {
        _devices[0] = new Device(0, n, k);
        for (int i = 1; i < n; ++i)
        {
            _devices[i] = new Device(i, n);
            _devices_for_update.insert(i);
        }

        for (int i = 0; i < k; ++i)
        {
            _update_device_map[0][i] = true;
            _rarity_update[1].insert(i);
            _update_device[i].insert(0);
        }
    }

    ~NetWork()
    {
        for (Device* dev : _devices)
            delete dev;
    }

    void chooseUpdate(std::map<int, std::set<int>>& _chooseUpdate)
    {
        for (int dev_id : _devices_for_update)
        {
            bool upd_find = false;
            for (auto& [rarity, upd_id_set] : _rarity_update)
            {
                for (int upd_id : upd_id_set)
                {
                    if (!_update_device_map[dev_id][upd_id])
                    {
                        upd_find = true;
                        _devices[dev_id]->setUpdateNext(upd_id);
                        _devices[dev_id]->setUpdateNextRarity(rarity);
                        _chooseUpdate[upd_id].insert(dev_id);
                        break;
                    }
                }
                if (upd_find)
                    break;
            }
        }
    }

    void print_chooseUpdate(std::map<int, std::set<int>>& _chooseUpdate)
    {
        std::cout << "print_chooseUpdate" << std::endl;
        for (auto& [upd_id, dev_set] : _chooseUpdate)
        {
            std::cout << "\tupd : " << upd_id << "\t comp : ";
            for(auto& dev_id : dev_set)
                std::cout << dev_id << " ";
            std::cout << std::endl;
        }
    }

    void chooseDevice(std::map<int, std::set<int>>& _chooseUpdate,
                        std::map<int, std::map<int, std::map<int, std::set<int>>>>& devFrom_value_count_devTo)
    {
        for (auto& [upd_id, dev_set] : _chooseUpdate)
        {
            std::map<int, std::set<int>> findDevFrom;
            int value_in_set = 0;
            for (auto& dev_id : _update_device[upd_id])
                findDevFrom[_devices[dev_id]->getUpdateCount()].insert(dev_id);

            int choose_dev_id = *(findDevFrom.begin()->second.begin());            

            devFrom_value_count_devTo[choose_dev_id];
            for (auto& dev : dev_set)
                devFrom_value_count_devTo[choose_dev_id][_devices[choose_dev_id]->getValue(dev)][_devices[dev]->getUpdateCount()].insert(dev);
        }
    }

    void print_chooseDevice(std::map<int, std::map<int, std::map<int, std::set<int>>>>& devFrom_value_count_devTo)
    {
        std::cout << "print_chooseDevice" << std::endl;
        for (auto& [dev_id, value_map] : devFrom_value_count_devTo)
        {
            std::cout << "\tdev : " << dev_id << std::endl;
            for(auto& [value, count_map] : value_map)
            {
                std::cout << "\t\tvalue : " << value << std::endl;
                for(auto& [count, dev_set] : count_map)
                {
                    std::cout << "\t\t\tcount : " << count << "\tdev : ";
                    for(auto& dev : dev_set)
                        std::cout  << dev << "(" << _devices[dev]->getUpdateNext() << ") ";
                    std::cout << std::endl;
                }
            }
        }
    }

    void update(std::map<int, std::map<int, std::map<int, std::set<int>>>>& devFrom_value_count_devTo)
    {
        ++timeslot;
        for (auto& [dev_from, map_devTo] : devFrom_value_count_devTo)
        {
            int dev_to = *(map_devTo.begin()->second.begin()->second.begin());

            int tmp_update_count = _devices[dev_to]->getUpdateCount();
            int tmp_update_next = _devices[dev_to]->getUpdateNext();
            int tmp_update_rarity = _devices[dev_to]->getUpdateNextRarity(); 

            _update_device_map[dev_to][tmp_update_next] = true;
            
            if (_rarity_update[tmp_update_rarity].size() == 1)
                _rarity_update.erase(tmp_update_rarity);
            else
                _rarity_update[tmp_update_rarity].erase(tmp_update_next);
            _rarity_update[tmp_update_rarity + 1].insert(tmp_update_next);

            _update_device[tmp_update_next].insert(dev_to);


            _devices[dev_to]->updateCount();
            _devices[dev_to]->updateValueDevice(dev_from);
           

            if (_devices[dev_to]->getUpdateCount() == k)
            {
                _devices[dev_to]->setTimeslot(timeslot);
                _devices_for_update.erase(dev_to);
            }
        }
    }

    void print_all()
    {
        std::cout << "print all: " << std::endl;
        for (auto& i : _update_device_map)
        {
            std::cout << "\t";
            for (auto j : i)
                std::cout << (j ? '#' : '.');
            std::cout << std::endl;
        }
    }

    void doAll()
    {
        while(!_devices_for_update.empty())
        {
            std::map<int, std::set<int>> _chooseUpdate; // upd_id : dev_set
            std::map<int, std::map<int, std::map<int, std::set<int>>>> devFrom_value_count_devTo;

if (DEBUG) std::cout << "timeslot : " << timeslot  << "\tdev : " << _devices_for_update.size() << std::endl;

if (DEBUG) print_rarity();                
            
            chooseUpdate(_chooseUpdate);
if (DEBUG) print_chooseUpdate(_chooseUpdate);

            chooseDevice(_chooseUpdate, devFrom_value_count_devTo);
if (DEBUG) print_chooseDevice(devFrom_value_count_devTo);

            update(devFrom_value_count_devTo);
if (DEBUG) print_all();

if (DEBUG) if (timeslot == 9) break;
if (DEBUG) std::cout  << std::endl;
        }

        for (int i = 1; i < n; ++i)
            std::cout << _devices[i]->getTimeslot() << " ";
    }

    void print_rarity()
    {
        std::cout << "RARITY: ";
        for (auto& [rarity, upd_id_set] : _rarity_update)
        {
            std::cout << "rarity : " << rarity << " upd : ";
            for (int upd_id : upd_id_set)
            {
                std::cout << upd_id << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    int n, k;
if (!DEBUG) std::cin >> n >> k;
if (DEBUG) n = 4;
if (DEBUG) k = 4;

    NetWork net(n, k);

    net.doAll();

    return 0;
}
