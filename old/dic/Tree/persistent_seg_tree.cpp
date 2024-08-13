#include <vector>

using namespace std;
/**
 *  과거상태를 모두 보존하는 자료구조
 *  baekjoon 20045
 *  PersistentSegmentTree  : using index 
 *     dummy tree[0] : 0, 0, 0
 *  PersistentSegmentTree2 : using pointer
 * 
 *  refer : https://justicehui.github.io/medium-algorithm/2020/02/29/PST/
 */

class PST
{
    using ll = int;
    struct Node
    {
        Node *l, *r;
        ll v;
        Node()
        {
            l = r = NULL;
            v = 0;
        }
    };

    //root[i] = i번째 세그먼트 트리의 루트
    vector<Node *> root; //root[0] 할당 필수
    int size;

public:
    PST(int N)
    {
        size = N;
        root.push_back(new Node());
    }

    PST(vector<int> &arr)
    {
        size = arr.size();
        root.push_back(new Node());
        init(arr, root[0], 0, size - 1);
    }

    ll op(const ll &a, const ll &b)
    {
        return a + b;
    }

    void init(vector<int> &arr, Node *node, int s, int e)
    { //0번 트리 생성
        if (s == e)
        {
            node->v = arr[s];
            return;
        }
        int m = s + e >> 1;

        node->l = new Node();
        node->r = new Node();

        init(arr, node->l, s, m);
        init(arr, node->r, m + 1, e);

        node->v = op(node->l->v, node->r->v);
    }

    void update(Node *prv, Node *now, int s, int e, int pos, int v)
    {
        if (s == e)
        {
            now->v = v;
            return;
        }
        int m = s + e >> 1;
        if (pos <= m)
        {
            //왼쪽 자식에 업데이트 하는 경우
            //왼쪽 자식은 새로운 정점 생성, 오른쪽 자식은 재활용
            now->l = new Node();
            now->r = prv->r;
            update(prv->l, now->l, s, m, pos, v);
        }
        else
        {
            //오른쪽 자식에 업데이트 하는 경우
            //오른쪽 자식은 새로운 정점 생성, 왼쪽 자식은 재활용
            now->l = prv->l;
            now->r = new Node();
            update(prv->r, now->r, m + 1, e, pos, v);
        }
        now->v = op(now->l->v, now->r->v);
    }

    void add(int pos, int v)
    {
        root.push_back(new Node());
        update(root[root.size() - 2], root.back(), 0, size - 1, pos, v);
    }

    ll query(Node *node, int s, int e, int l, int r)
    {
        if (r < s || e < l)
            return 0;
        if (l <= s && e <= r)
            return node->v;

        int m = s + e >> 1;

        return op(query(node->l, s, m, l, r), query(node->r, m + 1, e, l, r));
    }

    ll query(int r, int lo, int hi)
    {
        return query(root[r], 0, size - 1, lo, hi);
    }
};

class PersistentSegmentTree
{
    struct Node
    {
        int l, r, val;
        Node(int l, int r, int val) : l(l), r(r), val(val) {}
    };
    // tree[root[i]] = i번째 세그먼트 트리, tree[0] = dummy
    vector<Node> tree;
    vector<int> root; // 세그먼트 트리의 루트 노드 인덱스를 저장
    int size;

public:
    PersistentSegmentTree(int n)
    {
        size = n;
        tree.emplace_back(0, 0, 0);
        root.emplace_back(0);
    }
    void expand_tree(int lo, int hi, int pos, int old_root, int new_root)
    { // 값 변경 -> 몇번째 인지 알기위해 이전에 + 1
        tree[new_root].val = tree[old_root].val + 1;
        if (lo == hi)
            return;
        int mid = lo + hi >> 1;

        // 왼쪽에 새로운 노드 생성
        if (pos <= mid)
        {
            // 새로운 노드의 번호
            tree[new_root].l = tree.size();
            // 오른쪽은 기존 루트의 오른쪽
            tree[new_root].r = tree[old_root].r;
            // 새로운 노드 생성
            tree.emplace_back(0, 0, 0);
            // 새로 생성한 노드로 이동
            expand_tree(lo, mid, pos, tree[old_root].l, tree[new_root].l);
        }
        // 오른쪽에 새로운 노드 생성
        else
        {
            // 새로운 노드의 루트번호
            tree[new_root].r = tree.size();
            // 왼쪽은 기존 루트의 왼쪽
            tree[new_root].l = tree[old_root].l;
            // 새로운 노드 생성
            tree.emplace_back(0, 0, 0);
            // 새로 생성한 노드로 이동
            expand_tree(mid + 1, hi, pos, tree[old_root].r, tree[new_root].r);
        }
    }

    void make_new(int pos)
    { // 새로운 세그먼트 트리의 루트 번호
        root.emplace_back(tree.size());
        // 새로운 세그먼트 트리의 최상위 루트
        tree.emplace_back(0, 0, 0);
        expand_tree(0, size, pos, root[root.size() - 2], root.back());
    }
    // cur_node에서 k 번째 찾기
    int get_kth(int lo, int hi, int cur_node, int k)
    {
        if (lo == hi)
            return lo;

        int count = tree[tree[cur_node].l].val;
        int mid = lo + hi >> 1;

        if (count >= k)
            return get_kth(lo, mid, tree[cur_node].l, k);
        else
            return get_kth(mid + 1, hi, tree[cur_node].r, k - count);
    }
    int get_kth(int r, int k)
    {
        return get_kth(0, size, root[r], k);
    }
};

class PersistentSegmentTree2
{
    struct node
    {
        int sum;
        node *ls, *rs;
        node()
        {
            ls = rs = NULL;
            sum = 0;
        }
    } * root[250005];

    void init(int s, int e, node *p)
    {
        if (s == e)
            return;
        p->ls = new node();
        p->rs = new node();
        int m = (s + e) / 2;
        init(s, m, p->ls);
        init(m + 1, e, p->rs);
    }

    void add(int pos, int s, int e, node *prev, node *cur)
    {
        if (s == e)
        {
            cur->sum = prev->sum + 1;
            return;
        }
        int m = (s + e) / 2;
        if (pos <= m)
        {
            cur->ls = new node();
            cur->rs = prev->rs;
            add(pos, s, m, prev->ls, cur->ls);
        }
        else
        {
            cur->ls = prev->ls;
            cur->rs = new node();
            add(pos, m + 1, e, prev->rs, cur->rs);
        }
        cur->sum = cur->ls->sum + cur->rs->sum;
    }

    int search(node *prev, node *cur, int s, int e, int x)
    {
        if (s == e)
            return s;
        int m = (s + e) / 2;
        int tmp = cur->ls->sum - prev->ls->sum;
        if (x <= tmp)
        {
            return search(prev->ls, cur->ls, s, m, x);
        }
        return search(prev->rs, cur->rs, m + 1, e, x - tmp);
    }
};