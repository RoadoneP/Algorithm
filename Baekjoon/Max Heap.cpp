#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MAX 200001

using namespace std;

template<typename T>

class HEAP {
private:
    int _sz;
    T* heapArr;

    int max(int a, int b) {
        return a > b;
    }
    /*k��° ����� �ڽ� k*2,k*2+1 
    �θ�� k
    */
    
    void push_swap(int cur) {
        if (cur == 1)
            return;
        int par = cur / 2;
        if (heapArr[par] < heapArr[cur]) {
            T tmp = heapArr[par];
            heapArr[par] = heapArr[cur];
            heapArr[cur] = tmp;
            push_swap(cur / 2); //��ü������ �ö� Ž��
        }
    }


    /*���� �ڽ��� �����Ѵٸ� cur*2�� ���� ũ�⺸�� �۰ų� ���ƾ� �Ѵ�==�ڽ� ���� ���� �Ǵ�.
    left�� right�� ���� ���� ������� ���ϰ� �ڽ��� ���ٸ� -1�̶�� ������ set
    ���� ���� ���� Ʈ�� ����̱� ������ ���� �ڽ��� ������ �翬�� ������ �ڽ��� ����.*/
    void pop_swap(int cur) {
        int left, right, child;
        left = (cur * 2 <= _sz ? cur * 2 : -1);
        right = (cur * 2 + 1 <= _sz ? cur * 2 + 1 : -1);

        if (left == -1 && right == -1)
            child = -1;
        else if (left != -1 && right == -1)
            child = left;
        else
            child = (heapArr[left] > heapArr[right] ? left : right);
        if (child == -1)
            return;
        if (heapArr[child] > heapArr[cur]) {
            T tmp = heapArr[child];
            heapArr[child] = heapArr[cur];
            heapArr[cur] = tmp;
            pop_swap(child);
        }
    }
public:
    HEAP(int n) {
        int _sz = 0;
        heapArr = new int[n + 1];
    }
    ~HEAP() {
        delete[] heapArr;
    }
    int empty() {
        return !_sz;
    }
    int size() {
        return _sz;
    }
    T top() {
        return !_sz ? -1 : heapArr[1];
    }
    /*
    * Heap�� ������ �κп� ���� (_sz = ���� ũ��)
    */
    void push(int val) {
        heapArr[++_sz] = val;
        push_swap(_sz);
    }

    /*
    * !_sz == 0 �̸� pop �Ұ��� ������ return
    * ���� root�� �켱 �������ְ� ���� �������� ��ġ�� ���� root�� �־��ش� == heapArr[1] = heapArr[_sz--];
    */
    void pop() {
        if (!_sz)
            return;

        heapArr[1] = heapArr[_sz--];
        pop_swap(1);
    }
};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size;
    cin >> size;
    HEAP<int> pq(size);
    int a;

    for (int i = 0; i < size; i++) {
        cin >> a;
        if (a == 0)
        {
            if (pq.empty()) {
                cout << 0 << endl;
            }
            else
            {
                cout << pq.top()<<endl;
                pq.pop();
            }
        }
        else
            pq.push(a);
    }

}
