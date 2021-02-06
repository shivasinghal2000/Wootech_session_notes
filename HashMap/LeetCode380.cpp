//Leetcode 380
class RandomizedSet
{
public:
    unordered_map<int, int> map;
    vector<int> arr;

    RandomizedSet()
    {
        //constructor
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (map.find(val) != map.end())
            return false;

        map[val] = arr.size();
        arr.push_back(val);

        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (map.find(val) == map.end())
            return false;

        int idx = map[val];
        swap(arr[idx], arr[arr.size() - 1]);

        map[arr[idx]] = idx;

        arr.pop_back();
        map.erase(val);

        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        int idx = rand() % arr.size();
        return arr[idx];
    }
};