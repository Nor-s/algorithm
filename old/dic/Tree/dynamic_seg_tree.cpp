#include <vector>

using namespace std;
/**
 *  DynamicSegTree : using index 
 *  refer: http://www.secmem.org/blog/2019/09/18/persistent-segment-tree/
 */

class DynamicSegTree
{
    struct Node
    {
    public:
        int l, r, val;
    };

    vector<Node> node;

public:
    DynamicSegTree()
    {
        node.resize(2); // 0번째 : dummy node, 1번째 : root
    }
    void upd(int i, int x, int nidx, int node_st, int node_en)
    {
        if (i < node_st || i > node_en)
            return;
        node[nidx].val += x;
        if (node_st != node_en)
        {
            int mid = (node_st + node_en) / 2;
            if (i <= mid)
            {
                if (node[nidx].l == 0)
                {
                    node.push_back({0, 0, 0});
                    node[nidx].l = node.size() - 1;
                }
                upd(i, x, node[nidx].l, node_st, mid);
            }
            else
            {
                if (node[nidx].r == 0)
                {
                    node.push_back({0, 0, 0});
                    node[nidx].r = node.size() - 1;
                }
                upd(i, x, node[nidx].r, mid + 1, node_en);
            }
        }
    }

    // arr[i]를 x만큼 증가시킨다.
    void upd(int i, int x)
    {
        upd(i, x, 1, 1, 1000000000);
    }

    // nidx번째 노드에서 (i, j) 구간과 겹치는 부분의 합을 반환하는 함수
    int query(int i, int j, int nidx, int node_st, int node_en)
    {
        if (j < node_st || i > node_en)
            return 0;
        else if (i <= node_st && j >= node_en)
            return node[nidx].val;
        int mid = (node_st + node_en) / 2;
        int ret = 0;
        if (i <= mid)
        {
            if (node[nidx].l == 0)
            {
                node.push_back({0, 0, 0});
                node[nidx].l = node.size() - 1;
            }
            ret += query(i, j, node[nidx].l, node_st, mid);
        }
        if (j >= mid + 1)
        {
            if (node[nidx].r == 0)
            {
                node.push_back({0, 0, 0});
                node[nidx].r = node.size() - 1;
            }
            ret += query(i, j, node[nidx].r, mid + 1, node_en);
        }
        return ret;
    }

    // i부터 j까지의 합을 구한다.
    int query(int i, int j)
    {
        return query(i, j, 1, 1, 1000000000);
    }
};