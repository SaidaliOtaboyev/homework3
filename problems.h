#ifndef SAIDALI_PROBLEMS_H
#define SAIDALI_PROBLEMS_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// Author: Saidali Otaboyev
// Student ID: 230257

int safeAccess(const vector<int>& numbers, int index) {
    const string student = "Saidali Otaboyev"; 
    try {
        return numbers.at(index);
    } catch (out_of_range&) {
        cout << student << " says: Index out of range!" << endl;
        return -1;
    }
}

template <typename T, typename U>
class PairHolder {
private:
    T first;
    U second;

public:
    PairHolder(T a, U b) : first(a), second(b) {}

    T get_first() const { return first; }
    U get_second() const { return second; }

    bool isSame(const PairHolder<T,U>& other) const {
        return first == other.first && second == other.second;
    }

    void printOwner() const {
        cout << "Owned by Saidali Otaboyev" << endl;
    }
};

// Task 3: Valid parentheses using stack with switch
bool isValid(string expr) {
    stack<char> st;
    for (auto ch : expr) {
        switch(ch) {
            case '(': case '{': case '[':
                st.push(ch); break;
            case ')':
                if (st.empty() || st.top() != '(') return false;
                st.pop(); break;
            case '}':
                if (st.empty() || st.top() != '{') return false;
                st.pop(); break;
            case ']':
                if (st.empty() || st.top() != '[') return false;
                st.pop(); break;
        }
    }
    return st.empty();
}

queue<int> unionQueues(queue<int> q1, queue<int> q2) {
    queue<int> combined;
    for (; !q1.empty(); q1.pop()) combined.push(q1.front());
    for (; !q2.empty(); q2.pop()) combined.push(q2.front());
    return combined;
}

#endif // SAIDALI_PROBLEMS_H
