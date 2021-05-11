#include <vector>
#include <random>
#include <iostream>
using namespace std;
//辅助理解跳表
//跳表的headnode可以认为是全局最小，他内部包含随机出来的最大层数。这个层数来自于插入时的随机选择
//增加一个数的时候从最高层开始查起，找到当前层比这个数大的最小数，如果层数等于当前随机出来的层数的时候就创建节点
//之后往下层走
const double PROBABILITY = 0.5;

class skipListNode {
public:
    int val;
    vector<skipListNode*> nextNodes;
    skipListNode(int value) :val(value) {

    }
};

class skipList {
public:
    skipList() :size(0), maxLevel(0) {
        head = new skipListNode(-1);
        head->nextNodes.push_back(nullptr);
    }
    skipListNode* getHead() {
        return head;
    }
    void add(int newValue) {
        if (!contains(newValue)) {
            size++;
            int level = 0;
            random_device r;
            std::mt19937 gen(r());
            uniform_int_distribution<int> uniform(0, 1);
            while (uniform(gen) < PROBABILITY) {
                ++level;
            }
            while (level > maxLevel) {
                head->nextNodes.push_back(nullptr);
                maxLevel++;
            }
            skipListNode* newNode = new skipListNode(newValue);
            skipListNode* cur = head;
            do {
                cur = findNext(newValue, cur, level);
                //新插入的节点前后的链修改
                newNode->nextNodes.insert(newNode->nextNodes.begin(), cur->nextNodes[level]);
                cur->nextNodes[level] = newNode;
            } while (level-- >= 1);
            newNode->nextNodes.insert(newNode->nextNodes.begin(), nullptr);
        }
    }
    void deleteValue(int deleteValue) {
        if (contains(deleteValue)) {
            skipListNode* deleteNode = find(deleteValue);
            size--;
            int level = maxLevel;
            skipListNode* cur = head;
            //删除的时候就是断开连接，找到删除值得前一个数，然后和删除值后面的节点相连接
            do {
                cur = findNext(deleteNode->val - 1, cur, level);
                if (deleteNode->nextNodes.size() > level) {
                    cur->nextNodes[level] = deleteNode->nextNodes[level];
                }
            } while (level-- >= 1);
        }
    }
    int getSize() {
        return size;
    }
    bool contains(int num) {
        skipListNode* node = find(num);
        if (node != nullptr && node->val == num) {
            return true;
        }
        return false;
    }
private:
    skipListNode* find(int num) {
        return find(num, head, maxLevel);
    }
    skipListNode* find(int num, skipListNode* cur, int level) {
        do {
            cur = findNext(num, cur, level);
        } while (level-- >= 1);
        return cur;
    }
    skipListNode* findNext(int num, skipListNode* cur, int level) {
        skipListNode* next = cur->nextNodes[level];
        while (next != nullptr) {
            int value = next->val;
            if (num < value) {
                break;
            }
            cur = next;
            next = cur->nextNodes[level];
        }
        return cur;
    }
private:
    skipListNode* head;
    int maxLevel;
    int size;
};


int main() {
    skipList slt;
    slt.add(3);
    slt.add(5);
    slt.add(6);
    cout << slt.contains(6) << endl;
    cout << slt.contains(3) << endl;
    cout << slt.contains(5) << endl;
    slt.deleteValue(5);
    slt.deleteValue(6);
    cout << slt.contains(6) << endl;
    cout << slt.contains(5) << endl;
}